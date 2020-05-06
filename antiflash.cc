#include "antiflash.h"

void AntiFlash()
{
  if(addresses.pLocalPlayer->GetFlashDuration() > 0)
    addresses.pLocalPlayer->GetFlashDuration() = 0;
}
