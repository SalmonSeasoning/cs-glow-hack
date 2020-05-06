#include <Windows.h>
#include "hacks.h"

DWORD WINAPI fnMain(HMODULE hMod)
{
    // Get the Module Handle
    uintptr_t client = (uintptr_t)GetModuleHandle(TEXT("client_panorama.dll"));
    uintptr_t engine = (uintptr_t)GetModuleHandle(TEXT("engine.dll"));

    //  MessageBox(NULL, "Success!", "Injected successfully!", MB_OK | MB_ICONINFORMATION);
    Beep(250, 200);

    // Hack loop
    while (true)
    {
        // End if END key is pressed
        if (GetAsyncKeyState(VK_END) & 1) break;

        // Check if in game
        if(*reinterpret_cast<int*>(*reinterpret_cast<uintptr_t*>(engine + dwClientState) + dwClientState_State) != 6)
            continue;

        // Set addresses
        if((addresses.pLocalPlayer = *reinterpret_cast<Entity**>(client + dwLocalPlayer)) == nullptr) continue;
        if((addresses.GlowObjectManager = *reinterpret_cast<uintptr_t*>(client + dwGlowObjectManager)) == 0) continue;

        // Anti Flash
        AntiFlash();

        glow_t teamGlow{};
        teamGlow.b = 2.0f;
        teamGlow.a = 1.7f;

        glow_t enemyGlow{};
        enemyGlow.r = 2.0f;
        enemyGlow.a = 1.7f;

        for (short i = 0; i < 64; ++i)
        {
          Entity* entity = *reinterpret_cast<Entity**>(client + dwEntityList + i * 0x10);

          if(entity == nullptr || entity->GetDormant()) continue;

          if(addresses.pLocalPlayer->GetTeamNum() == entity->GetTeamNum())
            Glow(teamGlow, entity); // teammate
          else
            Glow(enemyGlow, entity); // enemy
        }


        Sleep(1);
    }

    // FreeLibrary(hMod);
    FreeLibraryAndExitThread(hMod, 0);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hMod, DWORD fdwReason, LPVOID lpReserved)
{
    DisableThreadLibraryCalls(hMod);
    if (fdwReason == DLL_PROCESS_ATTACH)
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)fnMain, hMod, 0, nullptr);
    return TRUE;
}
