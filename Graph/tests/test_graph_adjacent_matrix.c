/*!
 *  \file       test_graph_adjacent_matrix.c
 *  \brief      
 *  
 */


#include <unity_fixture.h>

#include "../graph/graph_adjacent_matrix.h"

TEST_GROUP(UTest4GraphAdjacentMatrix);

TEST_SETUP(UTest4GraphAdjacentMatrix)
{
}

TEST_TEAR_DOWN(UTest4GraphAdjacentMatrix)
{
}

TEST(UTest4GraphAdjacentMatrix, CreateAndDestroyGraphAdjacentMatrix)
{
    GraphAdjacentMatrix* graph = createGraphAdjacentMatrix();
    CHECK(graph != NULL);

    CHECK(graph->size == 0);
    for (int i = 0; i < VERTEX_NUM; ++i)
    {
        TEST_ASSERT_EQUAL(graph->vertices[i], 0);
        for (int j = 0; j < VERTEX_NUM; ++j)
        {
            TEST_ASSERT_EQUAL(graph->adjacent_matrix[i][j], 0);
        }
    }

    destroyGraphAdjacentMatrix(graph);
    // TEST_ASSERT_EQUAL(graph, NULL);
    TEST_ASSERT_EQUAL(graph->size, 0);
}

TEST_GROUP_RUNNER(UTest4GraphAdjacentMatrix)
{
    RUN_TEST_CASE(UTest4GraphAdjacentMatrix, CreateAndDestroyGraphAdjacentMatrix);
}