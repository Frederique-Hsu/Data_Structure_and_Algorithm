/*!
 *  \file       graph_adjacent_matrix.h
 *  \brief
 *
 */


#pragma once

#define VERTEX_NUM      20

typedef int     VertexElemType;

typedef struct GraphAdjacentMatrix
{
    VertexElemType vertices[VERTEX_NUM];
    int adjacent_matrix[VERTEX_NUM][VERTEX_NUM];
    int size;
}
GraphAdjacentMatrix;

GraphAdjacentMatrix* createGraphAdjacentMatrix();
void destroyGraphAdjacentMatrix(GraphAdjacentMatrix* graph);
void addVertex(GraphAdjacentMatrix* graph, VertexElemType vertex_value);
void removeVertex(GraphAdjacentMatrix* graph, int vertex_index);
void addEdge(GraphAdjacentMatrix* graph, int from_vertex_index, int to_vertex_index);
void removeEdge(GraphAdjacentMatrix* graph, int from_vertex_index, int to_vertex_index);
void printGraphAdjacentMatrix(GraphAdjacentMatrix* graph);