#include <gtest/gtest.h>

#include "A/index.h"
#include "B/lib.h"

TEST(Test1, CheckTen) {
 EXPECT_EQ(10, ten());
}

TEST(Test2, CheckFive) {
 EXPECT_EQ(5, five());
}
