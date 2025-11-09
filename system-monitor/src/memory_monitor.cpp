#include "memory_monitor.h"

double MemoryMonitor::getUsage() {
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);

    DWORDLONG total = memInfo.ullTotalPhys;
    DWORDLONG used = total - memInfo.ullAvailPhys;

    return (used * 100.0) / total;
}
