/*!;
 *  \file       graph_adjacent_matrix.c
 *  \brief
 *
 */


#include "graph_adjacent_matrix.h"

#include <stdio.h>
#include <stdlib.h>

GraphAdjacentMatrix* createGraphAdjacentMatrix()
{
    GraphAdjacentMatrix* graph = (GraphAdjacentMatrix*)calloc(1, sizeof(struct GraphAdjacentMatrix));
    graph->size = 0;
    for (int index = 0; index < VERTEX_NUM; ++index)
    {
        graph->vertices[index] = 0;
        for (int j = 0; j < VERTEX_NUM; ++j)
        {
            graph->adjacent_matrix[index][j] = 0;
        }
    }
    return graph;
}

void destroyGraphAdjacentMatrix(GraphAdjacentMatrix* graph)
{
    if (graph != NULL)
    {
        free(graph);
    }
    graph = NULL;
}

void addVertex(GraphAdjacentMatrix* graph, VertexElemType vertex_value)
{
    if (graph->size >= VERTEX_NUM)
    {
        fprintf(stderr, "The vertex number had exceeded the max. value.\n");
        return;
    }

    int n = graph->size;    // get the number of already existed vertices
    graph->vertices[n] = vertex_value;

    for (int i = 0; i <= n; ++i)
    {
        graph->adjacent_matrix[n][i] = graph->adjacent_matrix[i][n] = 0;
    }
    graph->size++;
}

void removeVertex(GraphAdjacentMatrix* graph, int vertex_index)
{
    if ((vertex_index < 0) || (vertex_index >= graph->size))
    {
        fprintf(stderr, "The vertex index had exceeded the array boundary.\n");
        return;
    }
    // Remove the vertex from the vertices array
    for (int index = vertex_index; index < graph->size - 1; ++index)
    {
        graph->vertices[index] = graph->vertices[index + 1];
    }
    // Remove the row whose index is vertex_index from the adjacent matrix
    for (int row = vertex_index; row < graph->size - 1; ++row)
    {
        for (int col = 0; col < graph->size; ++col)
        {
            graph->adjacent_matrix[row][col] = graph->adjacent_matrix[row + 1][col];
        }
    }
    // Remove the col whose index is vertex_index from the adjacent matrix
    for (int row = 0; row < graph->size; ++row)
    {
        for (int col = vertex_index; col < graph->size - 1; ++col)
        {
            graph->adjacent_matrix[row][col] = graph->adjacent_matrix[row][col + 1];
        }
    }
    graph->size--;
}

void addEdge(GraphAdjacentMatrix* graph, int from_vertex_index, int to_vertex_index)
{
    if ((from_vertex_index < 0) || (to_vertex_index < 0) ||
        (from_vertex_index >= graph->size) || (to_vertex_index >= graph->size) ||
        (from_vertex_index == to_vertex_index))
    {
        fprintf(stderr, "The edge index had exceeded the boundary.\n");
        return;
    }
    graph->adjacent_matrix[from_vertex_index][to_vertex_index] = 1;
    graph->adjacent_matrix[to_vertex_index][from_vertex_index] = 1;
}

void removeEdge(GraphAdjacentMatrix* graph, int from_vertex_index, int to_vertex_index)
{
    if ((from_vertex_index < 0) || (to_vertex_index < 0) ||
        (from_vertex_index >= graph->size) || (to_vertex_index >= graph->size) ||
        (from_vertex_index == to_vertex_index))
    {
        fprintf(stderr, "The edge index had exceeded the boundary.\n");
        return;
    }
    graph->adjacent_matrix[from_vertex_index][to_vertex_index] = 0;
    graph->adjacent_matrix[to_vertex_index][from_vertex_index] = 0;
}

void printGraphAdjacentMatrix(GraphAdjacentMatrix* graph)
{
    printf("\n");
    printf("Graph vertex array = \n");
    printf("%12s", " ");     // 输出指定长度的字符串，不足部分以空格补充。
    for (int i = 0; i < graph->size; ++i)
    {
        printf(" %4d   ", graph->vertices[i]);
    }
    printf("\n");

    printf("Graph adjacent matrix = \n\n");
    printf("%12s|", " ");
    for (int col = 0; col < graph->size; ++col)
    {
        printf("col #%-2d|", col+1);    // -表示在右边补空格，
    }
    printf("\n%12s+", " ");
    for (int col = 0; col < graph->size; ++col)
    {
        printf("-------+");
    }
    printf("\n");
    for (int row = 0; row < graph->size; ++row)
    {
        printf("row #%-2d %4s|", row + 1, " ");
        for (int col = 0; col < graph->size; ++col)
        {
            printf("% 4d   |", graph->adjacent_matrix[row][col]);   // +号表示在左边补空格
        }
        printf("\n");
        printf("%12s+", " ");
        for (int col = 0; col < graph->size; ++col)
        {
            printf("-------+");
        }
        printf("\n");
    }
    printf("\n");
}