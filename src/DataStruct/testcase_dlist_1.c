#include "type.h"
#include "ListAbstract.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    Node32_DP_t *cursor;
    Node32_DP_t *new_node;

    /* Unit test */
    List *list = _Dlist_api.Creat(10);

    printf("Append test--------------------------------\n");

    /* Append test 1 */
    for (int i = 0; i < 20; i++)
    {
        Node32_DP_t *new_node = (Node32_DP_t *)malloc(sizeof(Node32_DP_t));
        new_node->next = new_node->prev = NULL;
        new_node->elemData._uint32 = rand() % 100;
        _Dlist_api.Append(list, new_node);
    }

    cursor = list->head;
    for (int i = 0; i < list->size; i++)
    {
        printf("index %d, num %d\n", i, cursor->elemData._uint32);
        cursor = cursor->next;
    }

    printf("Append test ok!\n");

    printf("random insert test-------------------------------------\n");

    /* random insert test */
    for (int i = 0; i < 50; i++)
    {
        int index = (rand() % (list->size - 1));
        Node32_DP_t *new_node = (Node32_DP_t *)malloc(sizeof(Node32_DP_t));
        if (new_node == NULL)
        {
            return 0;
        }
        new_node->next = new_node->prev = NULL;
        new_node->elemData._uint32 = rand() % 100;
        _Dlist_api.Insert(list, new_node, index);
        printf("%d: Insert index %d, val %d\n", i, index, new_node->elemData._uint32);
        printf("List check val %d\n", ((Node32_DP_t *)_Dlist_api.Select(list, index))->elemData._uint32);
    }

    cursor = list->head;
    for (int i = 0; i < list->size; i++)
    {
        printf("index %d, num %d\n", i, cursor->elemData._uint32);
        cursor = cursor->next;
    }

    printf("random insert test Ok!\n");

    printf("head and tail insert test--------------------------------------\n");

    /* head and tail insert test */
    new_node = (Node32_DP_t *)malloc(sizeof(Node32_DP_t));
    new_node->next = new_node->prev = NULL;
    new_node->elemData._uint32 = rand() % 100;
    _Dlist_api.Insert(list, new_node, 0);
    printf("Head insert: insert val %d, check val %d\n", new_node->elemData._uint32, ((Node32_DP_t *)list->head)->elemData._uint32);

    new_node = (Node32_DP_t *)malloc(sizeof(Node32_DP_t));
    new_node->next = new_node->prev = NULL;
    new_node->elemData._uint32 = rand() % 100;
    _Dlist_api.Insert(list, new_node, list->size - 1);
    printf("Tail insert: insert val %d, check val %d\n", new_node->elemData._uint32, ((Node32_DP_t *)list->tail)->prev->elemData._uint32);

    /* Traversal test */
    cursor = list->head;
    for (int i = 0; i < list->size; i++)
    {
        printf("index %d, num %d\n", i, cursor->elemData._uint32);
        cursor = cursor->next;
    }

    /* reverse test */
    cursor = list->tail;
    for (int i = 0; i < list->size; i++)
    {
        printf("Reverse index %d, val %d\n", list->size - i - 1, cursor->elemData._uint32);
        cursor = cursor->prev;
    }
    printf("Reverse test ok!\n");

    /* Remove and Delete test */

    for (int i = 0; i < 100; i++)
    {
        int index = (rand() % (list->size - 1));
        Node32_DP_t *temp = _Dlist_api.Delete(list, index);
        printf("Delete %d val %d\n", i, temp->elemData._uint32);
        free(temp);
    }
    printf("Delete test ok!\n");

    for (int i = 0; i < 100; i++)
    {
        Node32_DP_t *temp = _Dlist_api.Remove(list);
        printf("Remove %d val %d\n", i, temp->elemData._uint32);
        free(temp);
    }

    printf("Remove test ok!\n");

    return 0;
}