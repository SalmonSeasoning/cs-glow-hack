#pragma once

#include "hacks.h"

class Entity {
public:

  int& GetHealth()
  {
    return *reinterpret_cast<int*>(this + m_iHealth);
  }
  int& GetTeamNum()
  {
    return *reinterpret_cast<int*>(this + m_iTeamNum);
  }
  int& GetFlashDuration()
  {
    return *reinterpret_cast<int*>(this + m_flFlashDuration);
  }
  uintptr_t& GetGlowIndex()
  {
    return *reinterpret_cast<uintptr_t*>(this + m_iGlowIndex);
  }
  bool GetDormant()
  {
    return *reinterpret_cast<bool*>(this + m_bDormant);
  }
  uintptr_t& GetBoneMatrix()
  {
    return *reinterpret_cast<uintptr_t*>(this + m_dwBoneMatrix);
  }
};
