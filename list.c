#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

node_t *create_node(char *data)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (!new_node)
        return NULL;

    new_node->data = malloc(sizeof(data));
    strcpy(new_node->data, data);
    new_node->next = NULL;

    return new_node;
}

void free_list(node_t **node)
{
    node_t *tmp = *node;
    while (tmp != NULL)
    {
        node_t *next = tmp->next;
        free(tmp->data);
        free(tmp);
        tmp = next;
    }

    *node = NULL;
}

void print_list(node_t *node, FILE *f)
{
    if (!node)
        return;

    node_t *tmp = node;
    while (tmp)
    {
        fprintf(f, "%s\n", tmp->data);
        tmp = tmp->next;
    }
}

int push_back(node_t **node, char *data)
{
    node_t *new_node = create_node(data);
    if (!new_node)
        return 1;

    if (!(*node))
    {
        (*node) = new_node;
    }
    else
    {
        node_t *tmp = *node;
        while (tmp->next)
            tmp = tmp->next;

        tmp->next = new_node;
    }

    return 0;
}

char *pop_front(node_t **node)
{
    if (!(*node))
        return NULL;

    char *data = (*node)->data;
    node_t *tmp = *node;

    *node = (*node)->next;
    free(tmp);

    return data;
}
