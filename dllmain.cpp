#include "ReadPointer.h"
DWORD WINAPI main(LPVOID lpParameter)
{
    FILE* f;
    AllocConsole();
    freopen_s(&f, "CONOUT$", "w", stdout);
    std::vector<DWORD> offset = { 0xC };
    DWORD address = (DWORD)GetModuleHandle(NULL) + 0x00329E34;
    DWORD pointer_address = ReadPointer(address, offset);
    FreeLibraryAndExitThread((HMODULE)lpParameter, NULL);
}
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(NULL, 0, main, hModule, 0, NULL);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

