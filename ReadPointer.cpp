#include "ReadPointer.h"

DWORD ReadPointer(DWORD address, std::vector<DWORD> offsets)
{
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());
    ReadProcessMemory(hProcess, (LPCVOID)address, &address, sizeof(address), NULL);
    for (int i = 0; i < offsets.size() - 1; ++i)
    {
        ReadProcessMemory(hProcess, (LPCVOID)(address + offsets.at(i)), &address, sizeof(address), NULL);
    }
    address += offsets.back();
    CloseHandle(hProcess);
    return address;
}