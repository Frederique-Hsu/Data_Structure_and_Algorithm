/*!
 *  \file       test_graph_adjacent_list.c
 *  \brief
 *
 */


#include "../graph/graph_adjacent_list.h"

#include <unity_fixture.h>


TEST_GROUP(UTest4GraphAdjacentList);

TEST_SETUP(UTest4GraphAdjacentList)
{
}

TEST_TEAR_DOWN(UTest4GraphAdjacentList)
{
}

TEST(UTest4GraphAdjacentList, CheckCreateAndDestroyGraphAdjacentList)
{
    GraphAdjacentList* graph = createGraphAdjacentList();

    TEST_ASSERT_EQUAL(graph->size, 0);
    for (int index = 0; index < GRAPH_NODE_NUM; ++index)
    {
        TEST_ASSERT_EQUAL(graph->nodes[index], NULL);
    }

    destroyGraphAdjacentList(graph);
}

TEST(UTest4GraphAdjacentList, CheckAddVertex)
{
    GraphAdjacentList* graph = createGraphAdjacentList();
    addVertex(graph, createVertex(12));
    addVertex(graph, createVertex(-36));

    printGraph(graph);

    destroyGraphAdjacentList(graph);
}

TEST(UTest4GraphAdjacentList, CheckRemoveVertex)
{
    Vertex* vertices[] = {createVertex(45), createVertex(-18), createVertex(120), createVertex(56)};
    int count = sizeof(vertices)/sizeof(vertices[0]);

    GraphAdjacentList* graph = createGraphAdjacentList();
    for (int index = 0; index < count; ++index)
    {
        addVertex(graph, vertices[index]);
    }
    TEST_ASSERT_EQUAL(graph->size, 4);
    printGraph(graph);

    removeVertex(graph, vertices[2]);
    TEST_ASSERT_EQUAL(graph->size, 3);
    printGraph(graph);
}

TEST_GROUP_RUNNER(UTest4GraphAdjacentList)
{
    RUN_TEST_CASE(UTest4GraphAdjacentList, CheckCreateAndDestroyGraphAdjacentList);
    RUN_TEST_CASE(UTest4GraphAdjacentList, CheckAddVertex);
    // RUN_TEST_CASE(UTest4GraphAdjacentList, CheckRemoveVertex);
}