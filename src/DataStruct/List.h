#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode_t
{
    ListNode_t *prev;
    ListNode_t *next;
    union {
        uint32_t _uint32_data;
        float _float_data;
        void *_any_data;
    } ElemData;
} ListNode_t, *PListNode_t;

typedef struct
{
    int size;
    ListNode_t *head;
    ListNode_t *tail;
} List;

typedef struct
{
    bool (*isEmpty)(List *list);
    List *(*creat)(int num);
    ListNode_t *(*select_ListNode_t)(List *list, int index);
    int (*append_to_list)(List *list, ListNode_t *add_ListNode_t);
    int (*insert_to_list)(List *list, ListNode_t *add_ListNode_t, int index);
    ListNode_t *(*delete_ListNode_t_in_list)(List *list, int index);
    void (*show_list)(List *list);

    bool (*sort_list)(List *list, int (*comp)(const void *, const void *));
} ListAPI;

const ListAPI _Dlist_api;