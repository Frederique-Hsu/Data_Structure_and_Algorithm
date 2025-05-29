/*!
 *  \file       graph_adjacent_list.hpp
 *  \brief
 *
 */


#pragma once

#include <unordered_map>
#include <vector>

template<typename T>
class GraphAdjacentList
{
public:
    struct Vertex
    {
        T   elem;
        Vertex(T val) : elem{val} {}
    };
public:
    GraphAdjacentList();
    ~GraphAdjacentList();
public:
    int size();
    void addEdge(Vertex* from_vertex, Vertex* to_vertex);
    void removeEdge(Vertex* from_vertex, Vertex* to_vertex);
    void addVertex(Vertex* vertex);
    void removeVertex(Vertex* vertex);
    void print();
private:
    std::unordered_map<Vertex *, std::vector<Vertex *>> adjacent_lists;
private:
    void remove(std::vector<Vertex *>& vertices, Vertex* vertex);
};