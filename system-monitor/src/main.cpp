#include <iostream>
#include <thread>
#include <chrono>
#include "cpu_monitor.h"
#include "memory_monitor.h"
#include "disk_monitor.h"
#include "network_monitor.h"
#include "utils.h"

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
        
        net.update(); // Update network stats

        std::cout << "\rCPU: " << cpuUsage << "% | "
                  << "Memory: " << memUsage << "% | "
                  << "Disk Used: "
                  << Utils::formatBytes(diskInfo.usedSpace) << " / "
                  << Utils::formatBytes(diskInfo.totalSpace)
                  << " (" << diskInfo.usedPercent << "%) | "
                  << "Down: " << net.getDownloadSpeedKBps() << " KB/s | "
                  << "Up: " << net.getUploadSpeedKBps() << " KB/s    "
                  << std::flush;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
