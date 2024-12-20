/*!
 *  \file       graph_adjacent_matrix.hpp
 *  \brief
 *
 */


#pragma once

#include <vector>


template<typename T>
class GraphAdjacentMatrix
{
public:
    struct Edge
    {
        int from_vertex_index;  // matrix column
        int to_vertex_index;    // matrix row
    };
public:
    GraphAdjacentMatrix();
    GraphAdjacentMatrix(const std::vector<T>& vertices,
                        const std::vector<std::vector<int>>& edges);
    ~GraphAdjacentMatrix();
private:
    std::vector<T> m_vertices;
    std::vector<std::vector<int>> m_adjacent_matrix;
public:
    int size() const;
    void addVertex(T vertex_val);
    void removeVertex(int vertex_index);
    void addEdge(Edge edge);
    void removeEdge(Edge edge);
    void print();
};