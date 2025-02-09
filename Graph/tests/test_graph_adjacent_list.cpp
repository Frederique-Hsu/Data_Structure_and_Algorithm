/*!
 *  \file       test_graph_adjacent_list.cpp
 *  \brief
 *
 */


#include "../graph/graph_adjacent_list.hpp"
#include "../graph/graph_adjacent_list.cpp"

#include <catch2/catch_test_macros.hpp>


TEST_CASE("Make the unit testing for Graph's adjacent list", "[graph_adjacent_list]")
{
    SECTION("Check the addVertex function")
    {
        GraphAdjacentList<int> graph;

        CHECK(graph.size() == 0);

        GraphAdjacentList<int>::Vertex vertex1(15);
        graph.addVertex(&vertex1);
        CHECK(graph.size() == 1);
    }
}