#include <gtest/gtest.h>
#include "Utilities/BitMask.h"

using namespace Engine;

TEST(BitMask, GetSet)
{
    BitMask BitMask1;
    BitMask BitMask2;

    BitMask1.SetBit(30);

    EXPECT_TRUE(BitMask1.IsBitSetted(30));
    EXPECT_FALSE(BitMask1.IsBitSetted(29));

    BitMask1.ClearBit(30);
    EXPECT_FALSE(BitMask1.IsBitSetted(30));

}

TEST(BitMask, Equal)
{
    BitMask BitMask1;
    BitMask BitMask2;
    for (size_t Bit = 0U; Bit < 32; ++Bit)
    {
        if (Bit % 2)
        {
            BitMask1.SetBit(Bit);
            BitMask2.SetBit(Bit);
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
            BitMask1.SetBit(Bit);
        }
        else
        {
            BitMask2.SetBit(Bit);
        }
    }

    EXPECT_FALSE(BitMask1 == BitMask2);
}

TEST(BitMask, GetSetMoreThanOneChunk)
{
    BitMask BitMask1;
    BitMask BitMask2;
  
    BitMask1.SetBit(100);

    EXPECT_TRUE(BitMask1.IsBitSetted(100));
    EXPECT_FALSE(BitMask1.IsBitSetted(99));

    BitMask1.ClearBit(100);
    EXPECT_FALSE(BitMask1.IsBitSetted(100));
}

TEST(BitMask, GetSetMoreThanOneChunkWithoutResizing)
{
    BitMask BitMask1(100U);
    BitMask BitMask2(100U);
  
    BitMask1.SetBit(100);

    EXPECT_TRUE(BitMask1.IsBitSetted(100));
    EXPECT_FALSE(BitMask1.IsBitSetted(99));

    BitMask1.ClearBit(100);
    EXPECT_FALSE(BitMask1.IsBitSetted(100));
}

TEST(BitMask, GetNotCurrentChunk)
{
    BitMask BitMask1;
    BitMask BitMask2;

    EXPECT_FALSE(BitMask1.IsBitSetted(100));
}

TEST(BitMask, ClearAll)
{
    BitMask BitMask1;
    size_t BitChecks = 40U;
    for (size_t Bit = 0U; Bit <= BitChecks; ++Bit)
    {
        BitMask1.SetBit(Bit);
    }

    BitMask1.ClearAll();

    for (size_t Bit = 0U; Bit <= BitChecks; ++Bit)
    {
        EXPECT_FALSE(BitMask1.IsBitSetted(Bit));
    }
}

TEST(BitMask, SetAll)
{
    size_t BitChecks = 40U;
    BitMask BitMask1(BitChecks);

    BitMask1.SetAll();

    for (size_t Bit = 0U; Bit <= BitChecks; ++Bit)
    {
        EXPECT_TRUE(BitMask1.IsBitSetted(Bit));
    }
}


TEST(BitMask, IsSubset)
{
    BitMask BitMask1;
    BitMask1.SetBit(20);
    BitMask1.SetBit(40);
    BitMask1.SetBit(60);

    BitMask BitMask2;
    BitMask2.SetBit(20);

    EXPECT_TRUE(BitMask2.IsSubset(BitMask1));
    EXPECT_FALSE(BitMask1.IsSubset(BitMask2));

    BitMask1.ClearAll();
    BitMask1.SetBit(20);
    BitMask1.SetBit(40);
    BitMask1.SetBit(60);

    BitMask2.ClearAll();
    BitMask2.SetBit(30);
    
    EXPECT_FALSE(BitMask2.IsSubset(BitMask1));
}