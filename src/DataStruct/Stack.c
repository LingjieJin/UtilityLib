#include "Stack.h"
#include <stdbool.h>

static S_Node_t *_Pop(Stack *stack)
{
    if (stack->size == 0)
    {
        return NULL;
    }
    S_Node_t *temp = stack->top;
    stack->top = stack->top->next;

    stack->size--;
    return temp;
}

static bool _Push(Stack *stack, S_Node_t *add_node)
{
    if (stack->max_size == stack->size)
    {
        return false;
    }

    add_node->next = stack->top;
    stack->top = add_node;

    stack->size++;
    return true;
}

static S_Node_t *_Peek(Stack *stack)
{
    return stack->top == NULL ? NULL : stack->top;
}

static bool _isEmpty(Stack *stack)
{
    return stack->size == 0 ? true : false;
}

const StackAPI _stack_api = {
    _Pop,
    _Push,
    _isEmpty,
    _Peek,
};