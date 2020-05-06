#pragma once
#include <cstdint>
#include <cstddef>

#include "csgo.hpp"
using namespace hazedumper::signatures;
using namespace hazedumper::netvars;

#include "entity.h"

struct addresses {
  Entity* pLocalPlayer = nullptr;
  uintptr_t GlowObjectManager = 0;
};

inline addresses addresses{};

#include "antiflash.h"
#include "glow.h"
