#ifndef LIST_H
#define LIST_H

typedef struct node_t
{
    char *data;
    struct node_t *next;
} node_t;

node_t *create_node(char *data);
void free_list(node_t **node);
void print_list(node_t *node, FILE *f);
int push_back(node_t **node, char *data);
char *pop_front(node_t **node);

#endif // LIST_H
