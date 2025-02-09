/*!
 *  \file       graph_adjacent_list.cpp
 *  \brief
 *
 */


#include "graph_adjacent_list.hpp"

#include <stdexcept>

template<typename T>
GraphAdjacentList<T>::GraphAdjacentList()
{
}

template<typename T>
GraphAdjacentList<T>::~GraphAdjacentList()
{
}

template<typename T>
int GraphAdjacentList<T>::size()
{
    return adjacent_lists.size();
}

template<typename T>
void GraphAdjacentList<T>::addVertex(Vertex* vertex)
{
    if (adjacent_lists.count(vertex))
    {
        return;
    }
    adjacent_lists[vertex] = std::vector<Vertex *>();
}

template<typename T>
void GraphAdjacentList<T>::removeVertex(Vertex* vertex)
{
    if (adjacent_lists.count(vertex) == 0)
    {
        throw std::invalid_argument("The vertex does not exist.");
    }
    adjacent_lists.erase(vertex);
    for (auto& list : adjacent_lists)
    {
        remove(list.second, vertex);
    }
}

template<typename T>
void GraphAdjacentList<T>::remove(std::vector<Vertex *>& vertices, Vertex* vertex)
{
    for (int index = 0; index < vertices.size(); ++index)
    {
        if (vertices[index] == vertex)
        {
            vertices.erase(vertices.begin() + index);
            break;
        }
    }
}