/*!
 *  \file       graph_adjacent_matrix.c
 *  \brief      
 *  
 */


#include "graph_adjacent_matrix.h"

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