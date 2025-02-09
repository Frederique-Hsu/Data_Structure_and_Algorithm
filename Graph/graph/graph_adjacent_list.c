/*!
 *  \file       graph_adjacent_list.c
 *  \brief
 *
 */


#include "graph_adjacent_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static Vertex** convertElementsToVertices(ElemType* elements, int element_count);

GraphAdjacentList* createGraphAdjacentList()
{
    GraphAdjacentList* graph = (GraphAdjacentList*)malloc(sizeof(struct GraphAdjacentList));
    if (graph == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for graph.");
        return graph;
    }
    graph->size = 0;
    for (int index = 0; index < GRAPH_NODE_NUM; ++index)
    {
        graph->nodes[index] = NULL;
    }

    return graph;
}

void destroyGraphAdjacentList(GraphAdjacentList* graph)
{
    int size = graph->size;
    for (int index = 0; index < size; ++index)
    {
        GraphAdjacentListNode* curr_node = graph->nodes[index];
        while (curr_node != NULL)
        {
            GraphAdjacentListNode* next_node = curr_node->next;
            if (curr_node != graph->nodes[index])
            {
                free(curr_node);
            }
            curr_node = next_node;
        }
        free(graph->nodes[index]->vertex);
        free(graph->nodes[index]);
        graph->size--;
    }
    free(graph);
}

void addVertex(GraphAdjacentList* graph, Vertex* vertex)
{
    assert(graph != NULL && graph->size < GRAPH_NODE_NUM);

    GraphAdjacentListNode* new_node = (GraphAdjacentListNode*)malloc(sizeof(struct GraphAdjacentListNode));
    if (new_node == NULL)
    {
        fprintf(stderr, "Failed to allocate the memory for graph's node.");
        return;
    }

    new_node->vertex = vertex;
    new_node->next = NULL;

    graph->nodes[graph->size++] = new_node;
}

void removeVertex(GraphAdjacentList* graph, Vertex* vertex)
{
    GraphAdjacentListNode* node = findNode(graph, vertex);
    assert(node != NULL);

    /*!
     *  \remark Remove the linked-list corresponding to vertex you want to delete
     *          from the adjacent lists.
     */
    GraphAdjacentListNode *curr_node = node;
    GraphAdjacentListNode *prev_node = NULL;
    while (curr_node != NULL)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
        free(prev_node);
    }

    /*!
     *  \remark Tranverse other adjacent lists, and remove the edges which contained
     *          the specified vertex
     */
    for (int index = 0; index < graph->size; ++index)
    {
        curr_node = graph->nodes[index];
        prev_node = NULL;
        while (curr_node != NULL)
        {
            prev_node = curr_node;
            curr_node = curr_node->next;    // slide to next node
            if (curr_node && curr_node->vertex == vertex)
            {
                prev_node->next = curr_node->next;
                free(curr_node);
                break;
            }
        }
    }

    int i;
    for (i = 0; i < graph->size; ++i)
    {
        if (graph->nodes[i] == node)
        {
            break;
        }
    }
    for (int j = i; j < graph->size; ++j)
    {
        graph->nodes[j] = graph->nodes[j + 1];
    }
    graph->size--;
    free(vertex);
}

GraphAdjacentListNode* findNode(GraphAdjacentList* graph, Vertex* vertex_to_find)
{
    for (int index = 0; index < graph->size; ++index)
    {
        if (graph->nodes[index]->vertex == vertex_to_find)
        {
            return graph->nodes[index];
        }
    }
    return NULL;
}

void printGraph(const GraphAdjacentList* graph)
{
    printf("\n");
    printf("Graph adjacent list = \n");
    for (int index = 0; index < graph->size; ++index)
    {
        GraphAdjacentListNode* node = graph->nodes[index];
        printf("% 4d : [", node->vertex->elem);
        node = node->next;
        while (node != NULL)
        {
            printf("% 4d ", node->vertex->elem);
            node = node->next;
        }
        printf("]\n");
    }
    printf("\n");
}

Vertex* createVertex(ElemType elem)
{
    Vertex* new_vertex = (Vertex*)malloc(sizeof(struct Vertex));
    if (new_vertex == NULL)
    {
        fprintf(stderr, "Failed to create a new vertex.\n");
        return NULL;
    }
    new_vertex->elem = elem;
    return new_vertex;
}

Vertex** convertElementsToVertices(ElemType* elements, int element_count)
{
    Vertex** vertices = (Vertex**)malloc(element_count * sizeof(Vertex *));
    for (int index = 0; index < element_count; ++index)
    {
        vertices[index] = createVertex(elements[index]);
    }
    return vertices;
}

void deleteVerter(Vertex* vertex)
{
    if (vertex != NULL)
    {
        free(vertex);
    }
    vertex = NULL;
}

void addEdge(GraphAdjacentList* graph, Vertex* from_vertex, Vertex* to_vertex)
{
    GraphAdjacentListNode* from_node = findNode(graph, from_vertex);
    GraphAdjacentListNode* to_node = findNode(graph, to_vertex);
    assert(from_node != NULL && to_node != NULL);

    addEdgeHelper(from_node, to_vertex);
    addEdgeHelper(to_node, from_vertex);
}

void addEdgeHelper(GraphAdjacentListNode* head, Vertex* vertex)
{
    GraphAdjacentListNode* node = (GraphAdjacentListNode*)malloc(sizeof(struct GraphAdjacentListNode));
    node->vertex = vertex;

    node->next = head->next;
    head->next = node;
}

void removeEdge(GraphAdjacentList* graph, Vertex* from_vertex, Vertex* to_vertex)
{
    GraphAdjacentListNode* from_node = findNode(graph, from_vertex);
    GraphAdjacentListNode* to_node = findNode(graph, to_vertex);
    assert(from_node != NULL && to_node != NULL);

    removeEdgeHelper(from_node, to_node->vertex);
    removeEdgeHelper(to_node, from_node->vertex);
}

void removeEdgeHelper(GraphAdjacentListNode* head, Vertex* vertex)
{
    GraphAdjacentListNode* prev = head;
    GraphAdjacentListNode* curr = head->next;

    while (curr != NULL && curr->vertex != vertex)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return;
    }
    prev->next = curr->next;
    free(curr);
}