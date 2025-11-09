#include "cpu_monitor.h"
#include <windows.h>
#include <pdh.h>
#pragma comment(lib, "pdh.lib")

CpuMonitor::CpuMonitor() {
    // Open PDH query
    PdhOpenQueryW(NULL, 0, &cpuQuery);
    // Add total CPU usage counter
    PdhAddEnglishCounterW(cpuQuery, L"\\Processor(_Total)\\% Processor Time", 0, &cpuTotal);
    PdhCollectQueryData(cpuQuery);
}

CpuMonitor::~CpuMonitor() {
    PdhCloseQuery(cpuQuery);
}

double CpuMonitor::getUsage() {
    PDH_FMT_COUNTERVALUE counterVal;
    PdhCollectQueryData(cpuQuery);
    PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal);
    return counterVal.doubleValue;
}
