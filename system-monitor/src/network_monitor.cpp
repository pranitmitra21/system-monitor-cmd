#include "network_monitor.h"
#include <chrono>
#include <thread>
#include <iostream>

NetworkMonitor::NetworkMonitor() : prevInBytes(0), prevOutBytes(0), downloadSpeed(0), uploadSpeed(0) {
    getNetworkBytes(prevInBytes, prevOutBytes);
}

NetworkMonitor::~NetworkMonitor() {}

void NetworkMonitor::getNetworkBytes(unsigned long long &inBytes, unsigned long long &outBytes) {
    MIB_IFTABLE *pIfTable;
    DWORD dwSize = 0;
    DWORD dwRetVal = 0;

    // First call to determine the required buffer size
    GetIfTable(NULL, &dwSize, FALSE);
    pIfTable = (MIB_IFTABLE *)malloc(dwSize);

    if (GetIfTable(pIfTable, &dwSize, FALSE) == NO_ERROR) {
        inBytes = 0;
        outBytes = 0;
        for (DWORD i = 0; i < pIfTable->dwNumEntries; i++) {
            MIB_IFROW row = pIfTable->table[i];
            // Only count active (non-loopback) interfaces
            if (row.dwOperStatus == MIB_IF_OPER_STATUS_OPERATIONAL && !(row.dwType == IF_TYPE_SOFTWARE_LOOPBACK)) {
                inBytes += row.dwInOctets;
                outBytes += row.dwOutOctets;
            }
        }
    }
    free(pIfTable);
}

void NetworkMonitor::update() {
    unsigned long long curInBytes = 0, curOutBytes = 0;
    getNetworkBytes(curInBytes, curOutBytes);

    // Calculate KB/s
    downloadSpeed = (curInBytes - prevInBytes) / 1024.0;
    uploadSpeed = (curOutBytes - prevOutBytes) / 1024.0;

    prevInBytes = curInBytes;
    prevOutBytes = curOutBytes;
}

double NetworkMonitor::getDownloadSpeedKBps() const {
    return downloadSpeed;
}

double NetworkMonitor::getUploadSpeedKBps() const {
    return uploadSpeed;
}
