#ifndef CPU_MONITOR_H
#define CPU_MONITOR_H

#include <windows.h>
#include <pdh.h>

class CpuMonitor {
public:
    CpuMonitor();
    ~CpuMonitor();
    double getUsage();

private:
    PDH_HQUERY cpuQuery;
    PDH_HCOUNTER cpuTotal;
};

#endif
