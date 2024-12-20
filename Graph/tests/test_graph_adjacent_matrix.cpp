/*!
 *  \file       test_graph_adjacent_matrix.cpp
 *  \brief
 *
 */


#include "../graph/graph_adjacent_matrix.hpp"
#include "../graph/graph_adjacent_matrix.cpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Make the unit test for the data structure of Graph adjacent matrix",
          "[graph_adjacent_matrix]")
{
    SECTION("Check the addVertex function")
    {
        GraphAdjacentMatrix<int> graph;

        graph.addVertex(15);
        graph.addVertex(48);
        graph.addVertex(-305);

        CHECK(graph.size() == 3);
    }

    SECTION("Check the removeVertex")
    {
        GraphAdjacentMatrix<int> graph;

        graph.addVertex(15);
        graph.addVertex(48);
        graph.addVertex(-305);

        CHECK(graph.size() == 3);

        graph.removeVertex(1);
        CHECK(graph.size() == 2);

        graph.removeVertex(1);
        CHECK(graph.size() == 1);

        CHECK_THROWS_AS(graph.removeVertex(3), std::out_of_range);
        CHECK(graph.size() == 1);
    }

    SECTION("Check the addEdge and print 2 functions")
    {
        GraphAdjacentMatrix<int> graph;

        graph.addVertex(15);
        graph.addVertex(48);
        graph.addVertex(-305);
        graph.addVertex(37);

        graph.addEdge(GraphAdjacentMatrix<int>::Edge{0, 2});
        graph.addEdge({1, 3});

        graph.print();
    }

    SECTION("Check the addEdge and removeEdge functions")
    {
        GraphAdjacentMatrix<int> graph;

        graph.addVertex(15);
        graph.addVertex(48);
        graph.addVertex(-305);
        graph.addVertex(37);

        graph.addEdge(GraphAdjacentMatrix<int>::Edge{0, 2});
        graph.addEdge({1, 3});

        graph.addVertex(56);
        graph.addVertex(-100);

        graph.addEdge({4, 5});
        graph.addEdge({3, 5});
        graph.addEdge({5, 1});
        graph.print();

        graph.addVertex(94);
        graph.removeEdge({5, 4});
        graph.print();

        CHECK(graph.size() == 7);
    }
}