/*!
 *  \file       test_hash_optimization.cc
 *  \brief      
 *  
 */


#include <gtest/gtest.h>

#include <random>

#include "hash_optimization.hpp"
#include "hash_optimization.cpp"

class UTester4HashOpt : public ::testing::Test
{
public:
    virtual void SetUp() override;
    // virtual void TearDown() override;
protected:
    std::vector<int> m_nums;
    int sum;
private:
    const int COUNT = 50;
};

void UTester4HashOpt::SetUp()
{
    std::random_device seed;
    std::ranlux48 engine(seed());
    std::uniform_int_distribution<> distribution(0, 1000);

    m_nums.resize(COUNT);
    for (int index = 0; index < COUNT; ++index)
    {
        m_nums[index] = distribution(engine);
    }

    sum = m_nums[distribution(engine) % COUNT] + 
          m_nums[distribution(engine) % COUNT];
}

TEST_F(UTester4HashOpt, CheckFunction_twoSumHashTable)
{
    auto result = twoSumHashTable(m_nums, sum);
    EXPECT_EQ(result.size(), 2);
}

TEST_F(UTester4HashOpt, CheckFunction_twoSumBruteForce)
{
    auto result = twoSumBruteForce(m_nums, sum);
    EXPECT_EQ(result.size(), 2);
}