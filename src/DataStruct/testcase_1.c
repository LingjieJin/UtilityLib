#include "Node.h"

#include <stdio.h>

int main()
{
    NodeList *node_list = create(5);

    Node *node = select_node(node_list, 2);

    node->data._uint32_data = (uint32_t)1000;
    printf("%d\n", node->data);

    Node *node_1 = select_node(node_list, 3);
    node_1->data._float_data = (float)1000;

    printf("%f, %f\n", node->next->data._float_data, (float)node->next->data._uint32_data);

    printf("%p, %p, %d\n", &node->next->data._float_data, &node->next->data._uint32_data, sizeof(node->next->data));

    return 0;
}