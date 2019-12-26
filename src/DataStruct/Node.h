#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    struct Node *next;
    union {
        uint32_t _uint32_data;
        float _float_data;
        void *_any_data;
    } data;
} Node, *PNode;

typedef struct NodeList
{
    int num;
    struct Node *head;
    struct Node *tail;
} NodeList;

NodeList *create(int num)
{
    NodeList *node_list = (NodeList *)malloc(sizeof(NodeList));
    Node *new_node;

    node_list->head = (Node *)malloc(sizeof(Node));
    if (node_list->head == NULL)
    {
        return NULL;
    }

    node_list->tail = node_list->head;
    node_list->head->prev = node_list->head->next = NULL;

    for (int i = 1; i < num; i++)
    {
        new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL)
        {
            return NULL;
        }
        new_node->prev = node_list->tail;
        node_list->tail->next = new_node;
        new_node->next = NULL;
        node_list->tail = new_node;
    }
    node_list->num = num;
    return node_list;
}

void change_node_data(NodeList *node_list, Node *new_node, int index)
{
    if (node_list->num < index)
    {
        return;
    }

    Node *node = node_list->head;

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    node->data = new_node->data;
}

Node *select_node(NodeList *node_list, int index)
{
    if (node_list->num < index)
    {
        return NULL;
    }

    Node *node = node_list->head;
    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    return node;
}

int add_node_to_head(NodeList *node_list, Node *add_node)
{
    add_node->prev = NULL;
    add_node->next = node_list->head;
    node_list->head->prev = add_node;
    node_list->head = add_node;

    return node_list->num++;
}

int add_node_to_tail(NodeList *node_list, Node *add_node)
{
    add_node->next = NULL;
    add_node->prev = node_list->tail;
    node_list->tail->next = add_node;
    node_list->tail = add_node;

    return node_list->num++;
}

/**
 * index 限制
 */
int add_node(NodeList *node_list, Node *add_node, int index)
{
    if (node_list->num < index)
    {
        return 0;
    }

    Node *node = node_list->head;

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    add_node->prev = node;
    add_node->next = node->next;
    node->next->prev = add_node;
    node->next = add_node;

    return node_list->num++;
}

Node *delete_node(NodeList *node_list, int index)
{
    if (node_list->num < index)
    {
        return NULL;
    }

    Node *node = node_list->head;

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    node->next->prev = node->prev;
    node->prev->next = node->next;

    return node;
}

