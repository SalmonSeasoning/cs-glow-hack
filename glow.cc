#include "glow.h"

void Glow(glow_t& glow, Entity* entity)
{
  if (entity->GetHealth() <= 0)
    return;

  uintptr_t glowIndex = entity->GetGlowIndex();

  *reinterpret_cast<float*>((addresses.GlowObjectManager)+((glowIndex * 0x38) + 0x4)) = glow.r;
  *reinterpret_cast<float*>((addresses.GlowObjectManager)+((glowIndex * 0x38) + 0x8)) = glow.g;
  *reinterpret_cast<float*>((addresses.GlowObjectManager)+((glowIndex * 0x38) + 0xC)) = glow.b;
  *reinterpret_cast<float*>((addresses.GlowObjectManager)+((glowIndex * 0x38) + 0x10)) = glow.a;

  *reinterpret_cast<bool*>((addresses.GlowObjectManager)+((glowIndex * 0x38) + 0x24)) = true;
  *reinterpret_cast<bool*>((addresses.GlowObjectManager)+((glowIndex * 0x38) + 0x25)) = false;
}
