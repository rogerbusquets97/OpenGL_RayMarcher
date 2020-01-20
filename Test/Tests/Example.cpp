#include <gtest/gtest.h>
#include "Camera/OrthogonalCamera.h"
#include <vec3.hpp>

TEST(SillyTest, IsFourPositive)
{
    EXPECT_GT(4, 0);
}

using namespace Engine;

TEST(Camera, GetPosition)
{
     auto Camera = OrthogonalCamera();
     EXPECT_EQ(Camera.GetPosition(), glm::vec3( 0.f, 0.f, 0.f));
}

