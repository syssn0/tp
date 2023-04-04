#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct graph {
    int num_nodes;
    node** adj_list;
} graph;

graph* create_graph(int num_nodes) {
    graph* g = (graph*) malloc(sizeof(graph));
    g->num_nodes = num_nodes;
    g->adj_list = (node**) calloc(num_nodes, sizeof(node*));
    return g;
}

void add_edge(graph* g, int u, int v) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->val = v;
    new_node->next = g->adj_list[u];
    g->adj_list[u] = new_node;

    

