/*!
 *  \file       test_graph_adjacent_matrix.c
 *  \brief
 *
 */


#include <unity_fixture.h>

#include "../graph/graph_adjacent_matrix.h"

TEST_GROUP(UTest4GraphAdjacentMatrix);

GraphAdjacentMatrix* g_graph = NULL;

TEST_SETUP(UTest4GraphAdjacentMatrix)
{
    g_graph = createGraphAdjacentMatrix();
}

TEST_TEAR_DOWN(UTest4GraphAdjacentMatrix)
{
    destroyGraphAdjacentMatrix(g_graph);
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

TEST(UTest4GraphAdjacentMatrix, CheckAddVertex)
{
    addVertex(g_graph, 8);
    TEST_ASSERT_EQUAL(g_graph->size, 1);

    addVertex(g_graph, -15);
    addVertex(g_graph, 102);
    addVertex(g_graph, -32);
    TEST_ASSERT_EQUAL(g_graph->size, 4);
}

TEST(UTest4GraphAdjacentMatrix, CheckRemoveVertex)
{
    addVertex(g_graph, 8);
    addVertex(g_graph, -15);
    addVertex(g_graph, 102);
    TEST_ASSERT_EQUAL(g_graph->size, 3);

    removeVertex(g_graph, 1);
    TEST_ASSERT_EQUAL(g_graph->size, 2);

    removeVertex(g_graph, 0);
    TEST_ASSERT_EQUAL(g_graph->size, 1);
}

TEST(UTest4GraphAdjacentMatrix, CheckAddEdges)
{
    addVertex(g_graph, 8);
    addVertex(g_graph, -15);
    addVertex(g_graph, 102);
    addVertex(g_graph, -32);
    addVertex(g_graph, 46);
    TEST_ASSERT_EQUAL(g_graph->size, 5);

    addEdge(g_graph, 0, 1);
    addEdge(g_graph, 1, 3);
    addEdge(g_graph, 2, 4);

    printGraphAdjacentMatrix(g_graph);

    addVertex(g_graph, 39);
    addEdge(g_graph, 2, 5);
    printGraphAdjacentMatrix(g_graph);
}

TEST(UTest4GraphAdjacentMatrix, CheckRemoveEdge)
{
    addVertex(g_graph, 8);
    addVertex(g_graph, -15);
    addVertex(g_graph, 102);
    addVertex(g_graph, -32);
    addVertex(g_graph, 46);

    addEdge(g_graph, 0, 1);
    addEdge(g_graph, 1, 3);
    addEdge(g_graph, 2, 4);

    addVertex(g_graph, 39);
    addEdge(g_graph, 2, 5);

    removeEdge(g_graph, 1, 3);
    printGraphAdjacentMatrix(g_graph);

    removeVertex(g_graph, 3);
    printGraphAdjacentMatrix(g_graph);

    removeVertex(g_graph, 0);
    printGraphAdjacentMatrix(g_graph);
}

TEST(UTest4GraphAdjacentMatrix, CheckComprehensiveGraph)
{
    addVertex(g_graph, 8);
    addVertex(g_graph, -15);
    addVertex(g_graph, 102);
    addVertex(g_graph, -32);
    addVertex(g_graph, 46);

    addEdge(g_graph, 0, 1);
    addEdge(g_graph, 1, 3);
    addEdge(g_graph, 2, 4);

    addVertex(g_graph, 39);
    addEdge(g_graph, 2, 5);

    addVertex(g_graph, -512);
    addVertex(g_graph, 204);
    addVertex(g_graph, 1007);
    addVertex(g_graph, 180);
    addVertex(g_graph, 0xFF);
    addVertex(g_graph, 0x5E);

    addEdge(g_graph, 5, 9);
    addEdge(g_graph, 10, 2);
    addEdge(g_graph, 8, 4);
    addEdge(g_graph, 11, 7);

    printGraphAdjacentMatrix(g_graph);
}

TEST_GROUP_RUNNER(UTest4GraphAdjacentMatrix)
{
    RUN_TEST_CASE(UTest4GraphAdjacentMatrix, CreateAndDestroyGraphAdjacentMatrix);
    RUN_TEST_CASE(UTest4GraphAdjacentMatrix, CheckAddVertex);
    RUN_TEST_CASE(UTest4GraphAdjacentMatrix, CheckRemoveVertex);
    RUN_TEST_CASE(UTest4GraphAdjacentMatrix, CheckAddEdges);
    RUN_TEST_CASE(UTest4GraphAdjacentMatrix, CheckRemoveEdge);
    RUN_TEST_CASE(UTest4GraphAdjacentMatrix, CheckComprehensiveGraph);
}