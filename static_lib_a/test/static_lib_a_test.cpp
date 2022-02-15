#include "..\src\static_lib_a.h"
#include <gtest/gtest.h>

TEST(static_lib_a_test, 0)
{
  EXPECT_EQ(0, sliba::get("something"));
}

TEST(static_lib_a_test, 42)
{
  EXPECT_EQ(42, sliba::get("The answer to life, the universe, everything."));
}
