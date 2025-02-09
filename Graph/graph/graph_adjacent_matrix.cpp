/*!
 *  \file       graph_adjacent_matrix.cpp
 *  \brief
 *
 */


#include "graph_adjacent_matrix.hpp"

#include <stdexcept>
#include <iostream>
#include <ios>
#include <iomanip>


template<typename T>
GraphAdjacentMatrix<T>::GraphAdjacentMatrix() : m_vertices{}, m_adjacent_matrix{}
{
}

template<typename T>
GraphAdjacentMatrix<T>::GraphAdjacentMatrix(const std::vector<T>& vertices,
                                            const std::vector<std::vector<int>>& edges)
{
    for (T vertex : vertices)
    {
        addVertex(vertex);
    }
    for (const std::vector<int>& edge : edges)
    {
        addEdge(edge[0], edge[1]);
    }
}

template<typename T>
GraphAdjacentMatrix<T>::~GraphAdjacentMatrix()
{
}

template<typename T>
int GraphAdjacentMatrix<T>::size() const
{
    return m_vertices.size();
}

template<typename T>
void GraphAdjacentMatrix<T>::addVertex(T vertex_val)
{
    m_vertices.emplace_back(vertex_val);

    m_adjacent_matrix.emplace_back(std::vector<int>(m_vertices.size(), 0));
    for (std::vector<int>& row: m_adjacent_matrix)
    {
        row.push_back(0);
    }
}

template<typename T>
void GraphAdjacentMatrix<T>::removeVertex(int vertex_index)
{
    if (vertex_index >= size())
    {
        throw std::out_of_range("The vertex you specified by index does not exist.");
    }

    m_vertices.erase(m_vertices.begin() + vertex_index);
    m_adjacent_matrix.erase(m_adjacent_matrix.begin() + vertex_index);

    for (std::vector<int>& row : m_adjacent_matrix)
    {
        row.erase(row.begin() + vertex_index);
    }
}

template<typename T>
void GraphAdjacentMatrix<T>::addEdge(Edge edge)
{
    if ((edge.from_vertex_index < 0) or (edge.to_vertex_index < 0) or
        (edge.from_vertex_index >= size()) or (edge.to_vertex_index >= size()))
    {
        throw std::out_of_range("The vertex does not exist.");
    }
    m_adjacent_matrix[edge.from_vertex_index][edge.to_vertex_index] = 1;
    m_adjacent_matrix[edge.to_vertex_index][edge.from_vertex_index] = 1;
}

template<typename T>
void GraphAdjacentMatrix<T>::removeEdge(Edge edge)
{
    if ((edge.from_vertex_index < 0) or (edge.to_vertex_index < 0) or
        (edge.from_vertex_index >= size()) or (edge.to_vertex_index >= size()))
    {
        throw std::out_of_range("The vertex does not exist.");
    }

    m_adjacent_matrix[edge.from_vertex_index][edge.to_vertex_index] = 0;
    m_adjacent_matrix[edge.to_vertex_index][edge.from_vertex_index] = 0;
}

template<typename T>
void GraphAdjacentMatrix<T>::print()
{
    using namespace std;

    cout << "Graph vertex array = " << endl;
    cout << setw(8) << " " << "|";
    for (T vertex : m_vertices)
    {
        cout << setw(7) << vertex << " |";
    }
    cout << endl;

    cout << "Graph adjacent matrix = " << endl;
    cout << setw(8) << " " << "|";
    for (int col = 0; col < size(); ++col)
    {
        cout << right << " col #" << setw(2) << left << col+1 << "|";
    }
    cout << endl;

    cout << setw(8) << " " << "+";
    for (int col = 0; col < size(); ++col)
    {
        cout << "--------+";
    }
    cout << endl;

    for (int row = 0; row < size(); ++row)
    {
        cout << left << "row #" << setw(2) << left << row+1 << " |";
        for (int col = 0; col < size(); ++col)
        {
            cout << setw(5) << right << m_adjacent_matrix[row][col] << "   |";
        }
        cout << endl;

        cout << setw(8) << " " << "+";
        for (int col = 0; col < size(); ++col)
        {
            cout << "--------+";
        }
        cout << endl;
    }
    cout << endl;
}