#include "List.h"

#include <stdio.h>

int main()
{
    List *node_list = _Dlist_api.Creat(5);

    ListNode_t *node = _Dlist_api.Select(node_list, 2);

    node->ElemData._uint32_data = (uint32_t)1000;
    printf("%d\n", node->ElemData);

    ListNode_t *node_1 = _Dlist_api.Select(node_list, 3);
    node_1->ElemData._float_data = (float)1000;

    printf("%f, %f\n", node->next->ElemData._float_data, (float)node->next->ElemData._uint32_data);

    printf("%p, %p, %d\n", &node->next->ElemData._float_data, &node->next->ElemData._uint32_data, sizeof(node->next->ElemData));

    return 0;
}