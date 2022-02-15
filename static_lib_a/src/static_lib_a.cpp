#include "pch.h"
#include "framework.h"
#include "static_lib_a.h"

int sliba::get(const std::string& i_Question)
{
  if(i_Question.compare("The answer to life, the universe, everything.") == 0)
  {
    return 42;
  }
  return 0;
}
