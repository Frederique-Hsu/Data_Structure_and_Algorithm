/*!
 *  \file   utest_Functions.c++
 *  \brief  Make the unit testing for the functions template in Functions.hpp file.
 *  \author Frederique Hsu
 *  \date   Sat.    11 Dec. 2021
 * 
 */


#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Functions.hpp"
#include "Swap.hpp"

TEST(UTest4Functions, CheckSwapFnct)
{
    unsigned char a = 15, b = 28;
    My::swap(a, b);

    ASSERT_TRUE(a == 28);
    ASSERT_TRUE(b == 15);

    uint64_t m = 0xFF7D5A8F;
    unsigned long n = 0x653EB80A;
    My::swap(m, n);

    ASSERT_TRUE(m == 0x653EB80A);
    ASSERT_TRUE(n == 0xFF7D5A8F);

    unsigned p = 1280;
    unsigned q = 45269035;
    My::swap<unsigned>(p, q);
    ASSERT_TRUE(p == 45269035);
    ASSERT_TRUE(q == 1280);
}

TEST(UTest4Functions, CheckPrimitiveTypeSize)
{
    ASSERT_TRUE(sizeof(unsigned char) == 1);
    ASSERT_TRUE(sizeof(char) == 1);
    ASSERT_TRUE(sizeof(unsigned short) == 2);
    ASSERT_TRUE(sizeof(short) == 2);
    ASSERT_TRUE(sizeof(unsigned int) == 4);
    ASSERT_TRUE(sizeof(int) == 4);
    ASSERT_TRUE(sizeof(unsigned long) == 8);
    ASSERT_TRUE(sizeof(long) == 8);
    ASSERT_TRUE(sizeof(unsigned long long) == 8);
    ASSERT_TRUE(sizeof(long long) == 8);
    ASSERT_TRUE(sizeof(float) == 4);
    ASSERT_TRUE(sizeof(double) == 8);
    // ASSERT_TRUE(sizeof(unsigned double) == 4);       /* float or double cannot be signed or unsigned. */
    EXPECT_TRUE(sizeof(void*) == 8);
    EXPECT_TRUE(sizeof(int*) == 8);

    ASSERT_TRUE(sizeof(unsigned) == sizeof(unsigned int));
    ASSERT_TRUE(sizeof(unsigned) != sizeof(unsigned short));
    EXPECT_TRUE(sizeof(unsigned) != sizeof(unsigned long));
    EXPECT_TRUE(sizeof(size_t) == sizeof(unsigned long));

    class Empty
    {
    public:
        Empty() {}
        ~Empty() {}
    };

    ASSERT_TRUE(sizeof(Empty) == 1);

    struct MemoryAlignIn8Bytes
    {
        unsigned short small;
        long large;
        int middle;
    };

    struct MemoryAlignIn4Bytes
    {
        unsigned short small;
        int middle;
        long large;
    };

    struct  __attribute__((packed, aligned(1))) MemoryAlignInOneByte
    {
        unsigned short small;
        int middle;
        long large;
    };
    struct __attribute__((packed, aligned(2))) MemoryAlignIn2Bytes
    {
        unsigned short small;
        int middle;
        long large;
    };
    // struct __attribute__((packed, aligned(3))) MemoryAlignIn3Bytes {};  /* Error: requested alignment is not a power of 2. */

    ASSERT_TRUE(sizeof(MemoryAlignIn8Bytes) == (sizeof(long) * 3));
    ASSERT_TRUE(sizeof(MemoryAlignIn4Bytes) == (sizeof(long) * 2));
    ASSERT_TRUE(sizeof(MemoryAlignInOneByte) == (sizeof(unsigned short) + sizeof(int) + sizeof(long)));
    ASSERT_TRUE(sizeof(MemoryAlignIn2Bytes) == (sizeof(unsigned short) + sizeof(int) + sizeof(long)));
}

TEST(UTest4Swap, Validate5DifferentSwaps)
{
    int a = -5, b = 13;
    My::swap<int>(a, b);
    EXPECT_TRUE(a == 13);
    EXPECT_TRUE(b == -5);

    unsigned long p = 45, q = 108;
    My::swap(p, q);
    ASSERT_TRUE(p == 108 && q == 45);

    unsigned m = 125, n = 520;
    My::swap(m, n);
    EXPECT_TRUE(m == 520 && n == 125);

    std::vector<std::string> alice {"Hello", "Alice"};
    std::vector<std::string> love {"I", "love", "you"};

#if ( (SWAP == SWAP_USING_3_COPIES) || \
      (SWAP == SWAP_USING_TYPE_CAST) || \
      (SWAP == SWAP_USING_MOVE_SEMANTICS) )
    My::swap(alice, love);
#elif (SWAP == SWAP_USING_STD_LIB)
    std::swap(alice, love);
#endif

    ASSERT_THAT(alice, std::vector<std::string>({"I", "love", "you"}));
    ASSERT_TRUE(love == std::vector<std::string>({"Hello", "Alice"}));
}
