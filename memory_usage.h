#pragma once

#ifdef _WIN32
#include <windows.h>
#include <psapi.h>
#else
#include <unistd.h>
#include <sys/resource.h>
#include <sys/mman.h>
#endif

class MemoryUsage {
public:
    static size_t GetMemoryUsage() {
#ifdef _WIN32
        PROCESS_MEMORY_COUNTERS memInfo;
        GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
        return memInfo.WorkingSetSize;  // Используем реальное потребление памяти в байтах
#else
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        return usage.ru_maxrss * 1024; // В КБ, переводим в байты
#endif
    }
};
