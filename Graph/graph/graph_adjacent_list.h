/*!
 *  \file       graph_adjacent_list.h
 *  \brief
 *
 */


#pragma once


#define GRAPH_NODE_NUM  10

typedef int ElemType;

typedef struct Vertex
{
    ElemType    elem;
}
Vertex;

typedef struct GraphAdjacentListNode
{
    Vertex* vertex;
    struct GraphAdjacentListNode* next;
}
GraphAdjacentListNode;

typedef struct GraphAdjacentList
{
    GraphAdjacentListNode* nodes[GRAPH_NODE_NUM];
    int size;
}
GraphAdjacentList;


GraphAdjacentList* createGraphAdjacentList();
void destroyGraphAdjacentList(GraphAdjacentList* graph);
void addVertex(GraphAdjacentList* graph, Vertex* vertex);
void removeVertex(GraphAdjacentList* graph, Vertex* vertex);
void addEdge(GraphAdjacentList* graph, Vertex* from_vertex, Vertex* to_vertex);
void removeEdge(GraphAdjacentList* graph, Vertex* from_vertex, Vertex* to_vertex);
GraphAdjacentListNode* findNode(GraphAdjacentList* graph, Vertex* vertex_to_find);
void printGraph(const GraphAdjacentList* graph);

Vertex* createVertex(ElemType elem);
void deleteVerter(Vertex* vertex);

void addEdgeHelper(GraphAdjacentListNode* head, Vertex* vertex);
void removeEdgeHelper(GraphAdjacentListNode* head, Vertex* vertex);