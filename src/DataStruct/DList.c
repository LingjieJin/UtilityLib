#include "List.h"

static int _add_node_to_head(List *list, ListNode_t *add_node)
{
    add_node->prev = NULL;
    add_node->next = list->head;
    list->head->prev = add_node;
    list->head = add_node;

    return list->size++;
}


static bool _isEmpty(List *list)
{
    if (list->size == 0)
    {
        return true;
    }
    return false;
}

static List *_create(int num)
{
    List *list = (List *)malloc(sizeof(List));
    ListNode_t *new_node;

    list->head = (ListNode_t *)malloc(sizeof(ListNode_t));
    if (list->head == NULL)
    {
        return NULL;
    }

    list->tail = list->head;
    list->head->prev = list->head->next = NULL;

    for (int i = 1; i < num; i++)
    {
        new_node = (ListNode_t *)malloc(sizeof(ListNode_t));
        if (new_node == NULL)
        {
            return NULL;
        }
        new_node->prev = list->tail;
        list->tail->next = new_node;
        new_node->next = NULL;
        list->tail = new_node;
    }
    list->size = num;
    return list;
}

static ListNode_t *_select_node(List *list, int index)
{
    if (list->size < index)
    {
        return NULL;
    }

    ListNode_t *node = list->head;
    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    return node;
}

static int _append_node_to_list(List *list, ListNode_t *add_node)
{
    add_node->next = NULL;
    add_node->prev = list->tail;
    list->tail->next = add_node;
    list->tail = add_node;

    return list->size++;
}

static int _insert_node_to_list(List *list, ListNode_t *add_node, int index)
{
    if (list->size < index)
    {
        return 0;
    }

    ListNode_t *node = list->head;

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    add_node->prev = node;
    add_node->next = node->next;
    node->next->prev = add_node;
    node->next = add_node;

    return list->size++;
}

static ListNode_t *_delete_node_in_list(List *list, int index)
{
    if (list->size < index)
    {
        return NULL;
    }

    ListNode_t *node = list->head;

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    node->next->prev = node->prev;
    node->prev->next = node->next;

    return node;
}

static void _show_list(List *list)
{
}

static void _sort_list(List *list, int (*comp)(const void *, const void *))
{

}

const ListAPI _Dlist_api = {
    _isEmpty,
    _create,
    _select_node,
    _append_node_to_list,
    _insert_node_to_list,
    _delete_node_in_list,
    _show_list,
    _sort_list,
};