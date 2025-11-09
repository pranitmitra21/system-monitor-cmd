#ifndef DISK_MONITOR_H
#define DISK_MONITOR_H

#include <windows.h>
#include <string>

class DiskMonitor {
public:
    struct DiskInfo {
        unsigned long long totalSpace;
        unsigned long long freeSpace;
        unsigned long long usedSpace;
        double usedPercent;
    };

    DiskInfo getDiskUsage(const std::wstring& drive = L"C:\\");
};

#endif
