cmake_minimum_required(VERSION 3.10)
project(SystemMonitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/cpu_monitor.cpp
    src/memory_monitor.cpp
    src/disk_monitor.cpp
    src/network_monitor.cpp
    src/utils.cpp
)

set(HEADERS
    include/cpu_monitor.h
    include/memory_monitor.h
    include/disk_monitor.h
    include/network_monitor.h
    include/utils.h
)

add_executable(SystemMonitor ${SOURCES} ${HEADERS})

# ✅ Link required Windows libraries
if(WIN32)
    target_link_libraries(SystemMonitor pdh iphlpapi)
endif()
