#include "disk_monitor.h"

DiskMonitor::DiskInfo DiskMonitor::getDiskUsage(const std::wstring& drive) {
    ULARGE_INTEGER freeBytesAvailable, totalBytes, freeBytes;
    DiskInfo info{0, 0, 0, 0.0};

    if (GetDiskFreeSpaceExW(drive.c_str(), &freeBytesAvailable, &totalBytes, &freeBytes)) {
        info.totalSpace = totalBytes.QuadPart;
        info.freeSpace = freeBytes.QuadPart;
        info.usedSpace = totalBytes.QuadPart - freeBytes.QuadPart;
        info.usedPercent = (static_cast<double>(info.usedSpace) / totalBytes.QuadPart) * 100.0;
    }

    return info;
}
