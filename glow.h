#pragma once

#include "hacks.h"

struct glow_t {
  float r = 0.f,
    g = 0.f,
    b = 0.f,
    a = 0.f;
};

void Glow(glow_t& glow, Entity* entity);
