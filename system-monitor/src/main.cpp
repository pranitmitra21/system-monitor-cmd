#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <windows.h>

#include "cpu_monitor.h"
#include "memory_monitor.h"
#include "disk_monitor.h"
#include "network_monitor.h"
#include "utils.h"

// Function to clear the current console line safely in Windows PowerShell
void clearLine() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        DWORD written;
        COORD startPos = {0, csbi.dwCursorPosition.Y};
        FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X, startPos, &written);
        SetConsoleCursorPosition(hConsole, startPos);
    }
}

int main() {
    CpuMonitor cpu;
    MemoryMonitor memory;
    DiskMonitor disk;
    NetworkMonitor net;

    std::cout << "================= SYSTEM MONITOR =================" << std::endl;
    std::cout << "Press Ctrl + C to exit\n" << std::endl;

    while (true) {
        double cpuUsage = cpu.getUsage();
        double memUsage = memory.getUsage();
        auto diskInfo = disk.getDiskUsage(L"C:\\");
        net.update();

        std::ostringstream line;
        line << std::fixed << std::setprecision(2)
             << "CPU: " << cpuUsage << "% | "
             << "Memory: " << memUsage << "% | "
             << "Disk Used: "
             << Utils::formatBytes(diskInfo.usedSpace) << " / "
             << Utils::formatBytes(diskInfo.totalSpace)
             << " (" << diskInfo.usedPercent << "%) | "
             << "Down: " << net.getDownloadSpeedKBps() << " KB/s | "
             << "Up: " << net.getUploadSpeedKBps() << " KB/s";

        clearLine(); // ✅ Cleanly clears the previous console line
        std::cout << line.str() << std::flush;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
