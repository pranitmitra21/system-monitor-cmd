#ifndef NETWORK_MONITOR_H
#define NETWORK_MONITOR_H

#include <string>
#include <windows.h>
#include <iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")

class NetworkMonitor {
public:
    NetworkMonitor();
    ~NetworkMonitor();

    void update();
    double getDownloadSpeedKBps() const;
    double getUploadSpeedKBps() const;

private:
    unsigned long long prevInBytes;
    unsigned long long prevOutBytes;
    double downloadSpeed;
    double uploadSpeed;

    void getNetworkBytes(unsigned long long &inBytes, unsigned long long &outBytes);
};

#endif
