#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _ListNode_t
{
    struct _ListNode_t *prev;
    struct _ListNode_t *next;
    union {
        uint32_t _uint32_data;
        float _float_data;
        void *_any_data;
    } ElemData;
} ListNode_t, *PListNode_t;

typedef struct _List
{
    int size;
    ListNode_t *head;
    ListNode_t *tail;
} List;

typedef struct _ListAPI
{
    bool (*isEmpty)(List *list);
    List *(*Creat)(int num);
    ListNode_t *(*Select)(List *list, int index);
    int (*Append_to_list)(List *list, ListNode_t *add_ListNode_t);
    int (*Insert_to_list)(List *list, ListNode_t *add_ListNode_t, int index);
    ListNode_t *(*Delete_ListNode_t_in_list)(List *list, int index);
    void (*Show_list)(List *list);

    bool (*Sort_list)(List *list, int (*comp)(const void *, const void *));
} ListAPI;

const ListAPI _Dlist_api;