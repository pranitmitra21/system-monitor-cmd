#include "utils.h"
#include <sstream>
#include <iomanip>

std::string Utils::formatBytes(unsigned long long bytes) {
    const char* sizes[] = {"B", "KB", "MB", "GB", "TB"};
    int i = 0;
    double dblBytes = static_cast<double>(bytes);

    while (dblBytes >= 1024 && i < 4) {
        dblBytes /= 1024;
        i++;
    }

    std::ostringstream out;
    out << std::fixed << std::setprecision(2) << dblBytes << " " << sizes[i];
    return out.str();
}
