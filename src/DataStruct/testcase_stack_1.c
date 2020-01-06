#include "Stack.h"
#include <stdio.h>

int main()
{
    Stack *stack = _stack_api.Create(30);
    S_Node_t *node = _stack_api.Peek(stack);
    node->ElemData._uint32_data = 999;

    S_Node_t *new_node = (S_Node_t *)malloc(sizeof(S_Node_t));
    new_node->ElemData._uint32_data = 666;
    _stack_api.Push(stack, new_node);
    node = _stack_api.Peek(stack);

    /**
     * top num:666
     * top next num:999
     * unknow num:0
     * stack size:31
     */
    printf("top num:%d\n", node->ElemData._uint32_data);
    printf("top next num:%d\n", node->next->ElemData._uint32_data);
    printf("unknow num:%d\n", node->next->next->ElemData._uint32_data);
    printf("stack size:%d\n", stack->size);

    return 0;
}