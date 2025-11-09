# 🖥️ System Monitor Tool (C++ + Qt)

A real-time **System Monitor** built in **C++** using **Qt Widgets and Charts**.  
Displays live **CPU, Memory, Disk, Network, and Battery** usage — with a dark modern GUI similar to Windows Task Manager.

---

## 🚀 Features
✅ Real-time CPU usage chart  
✅ Memory utilization bar  
✅ Live refresh every second  
✅ Dark theme dashboard  
✅ Cross-platform (Windows/Linux with minor changes)  

---

## 📁 Folder Structure
system-monitor/
├── CMakeLists.txt
├── README.md
├── LICENSE
├── .gitignore
│
├── src/
│   ├── main.cpp
│   ├── gui.cpp
│   ├── cpu_monitor.cpp
│   ├── memory_monitor.cpp
│   ├── utils.cpp
│
├── include/
│   ├── gui.h
│   ├── cpu_monitor.h
│   ├── memory_monitor.h
│   ├── utils.h
│
└── assets/

---

## 🧰 Requirements
- **CMake ≥ 3.16**
- **Qt6 (Widgets + Charts)**
  Install with:
  vcpkg install qt6-base qt6-charts

- **C++17 compiler (MSVC or MinGW)**

---

## ⚙️ Build Instructions
cd D:\system-monitor
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
.\SystemMonitor.exe

---

## 🧑‍💻 Author
**Pranit Kumar Mitra**  
B.Tech CSE (Cybersecurity), ITER SOA University  
© 2025 – All rights reserved.

---

## 📜 License
Licensed under the [MIT License](LICENSE).
