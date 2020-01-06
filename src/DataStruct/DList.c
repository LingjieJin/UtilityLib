#include "List.h"
#include "type.h"
#include <stdio.h>
#include <stdlib.h>

static int _add_node_to_head(List *list, Node32_DP_t *add_node)
{
    add_node->prev = NULL;
    add_node->next = list->head;
    ((Node32_DP_t *)list->head)->prev = add_node;
    list->head = add_node;

    return list->size++;
}

static List *_Init()
{
    List *list = (List *)malloc(sizeof(List));
    if (list == NULL)
    {
        return NULL;
    }
    list->head = list->tail = NULL;
    list->size = 0;
    return list;
}

static List *_Create(int num)
{
    List *list = _Init();

    for (int i = 0; i < num; i++)
    {
        Node32_DP_t *new_node = (Node32_DP_t *)malloc(sizeof(Node32_DP_t));
        if (new_node == NULL)
        {
            return NULL;
        }
        new_node->prev = new_node->next = NULL;
        new_node->elemData._uint32 = 0;

        if (list->head == NULL)
        {
            list->head = new_node;
        }
        else
        {
            ((Node32_DP_t *)list->tail)->next = new_node;
            new_node->prev = list->tail;
        }

        list->tail = new_node;
    }

    list->size = num;
    return list;
}

static bool _Destory(List *list)
{
    Node32_DP_t *cursor;
    for (int i = 0; i < list->size; i++)
    {
        cursor = (Node32_DP_t *)list->head;
        list->head = ((Node32_DP_t *)list->head)->next;
        free(cursor);
    }

    free(list);
    return true;
}

static bool _isEmpty(List *list)
{
    return list->size == 0;
}

static Node *_Select(List *list, int index)
{
    if (list->size <= index)
    {
        return NULL;
    }

    Node32_DP_t *node = (Node32_DP_t *)list->head;
    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    return node;
}

static int _Append(List *list, Node *add_node)
{
    if (list->head == NULL)
    {
        list->head = add_node;
    }
    else
    {
        ((Node32_DP_t *)list->tail)->next = add_node;
        ((Node32_DP_t *)add_node)->prev = (Node32_DP_t *)list->tail;
    }
    list->tail = add_node;

    return list->size++;
}

static int _Insert(List *list, Node *add_node, int index)
{
    if (list->size <= index)
    {
        return 0;
    }

    Node32_DP_t *node = list->head;

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    if (index == 0)
    {
        node->prev = add_node;
        ((Node32_DP_t *)add_node)->next = node;
        list->head = add_node;
    }
    else
    {
        ((Node32_DP_t *)add_node)->prev = node->prev->next;
        ((Node32_DP_t *)add_node)->next = node;
        node->prev->next = add_node;
        node->prev = add_node;
    }

    return list->size++;
}

static Node *_Remove(List *list)
{
    if (_isEmpty(list))
    {
        return NULL;
    }
    Node32_DP_t *end = ((Node32_DP_t *)list->tail)->prev;
    Node32_DP_t *ret = (Node32_DP_t *)list->tail;

    end->next = NULL;
    list->tail = end;

    // list->tail = ((Node32_DP_t *)list->tail)->prev;
    // ((Node32_DP_t *)list->tail)->next = NULL;
    list->size--;
    return ret;
}

static Node *_Delete(List *list, int index)
{
    if (list->size < index)
    {
        return NULL;
    }

    Node32_DP_t *node = list->head;

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    node->next->prev = node->prev;
    node->prev->next = node->next;

    return node;
}

static void _Show(List *list)
{
}

static void _Sort(List *list, int (*comp)(const void *, const void *))
{
}

const ListAPI _Dlist_api = {
    _Init,
    _Create,
    _Destory,
    _isEmpty,
    _Select,
    _Append,
    _Insert,
    _Remove,
    _Delete,
    _Show,
    _Sort,
};