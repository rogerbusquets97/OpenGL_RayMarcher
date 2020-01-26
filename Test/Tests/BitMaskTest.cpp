#include <gtest/gtest.h>
#include "Utilities/BitMask.h"

using namespace Engine;

TEST(BitMask, GetSet)
{
    BitMask BitMask1;
    BitMask BitMask2;

    BitMask1.SetPosition(30, true);

    EXPECT_TRUE(BitMask1.GetPosition(30));
    EXPECT_FALSE(BitMask1.GetPosition(29));

    BitMask1.SetPosition(30, false);
    EXPECT_FALSE(BitMask1.GetPosition(30));

}

TEST(BitMask, Equal)
{
    BitMask BitMask1;
    BitMask BitMask2;
    for (size_t Bit = 0U; Bit < 32; ++Bit)
    {
        if (Bit % 2)
        {
            BitMask1.SetPosition(Bit, true);
            BitMask2.SetPosition(Bit, true);
        }
    }

    EXPECT_EQ(BitMask1, BitMask2);
}

TEST(BitMask, NoEqual)
{
    BitMask BitMask1;
    BitMask BitMask2;
    for (size_t Bit = 0U; Bit < 4; ++Bit)
    {
        if (Bit % 2)
        {
            BitMask1.SetPosition(Bit, true);
        }
        else
        {
            BitMask2.SetPosition(Bit, true);
        }
    }

    EXPECT_FALSE(BitMask1 == BitMask2);
}

TEST(BitMask, GetSetMoreThanOneChunk)
{
    BitMask BitMask1;
    BitMask BitMask2;
  
    BitMask1.SetPosition(100, true);

    EXPECT_TRUE(BitMask1.GetPosition(100));
    EXPECT_FALSE(BitMask1.GetPosition(99));

    BitMask1.SetPosition(100, false);
    EXPECT_FALSE(BitMask1.GetPosition(100));
}

TEST(BitMask, GetNotCurrentChunk)
{
    BitMask BitMask1;
    BitMask BitMask2;

    EXPECT_FALSE(BitMask1.GetPosition(100));
}

TEST(BitMask, IsSubset)
{
    BitMask BitMask1;
    BitMask1.SetPosition(20, true);
    BitMask1.SetPosition(40, true);
    BitMask1.SetPosition(60, true);

    BitMask BitMask2;
    BitMask2.SetPosition(20, true);

    EXPECT_TRUE(BitMask2.IsSubset(BitMask1));
    EXPECT_FALSE(BitMask1.IsSubset(BitMask2));


    BitMask BitMask3;
    BitMask3.SetPosition(20, true);
    BitMask3.SetPosition(40, true);
    BitMask3.SetPosition(60, true);

    BitMask BitMask4;
    BitMask4.SetPosition(30, true);
    
    EXPECT_FALSE(BitMask4.IsSubset(BitMask3));
}