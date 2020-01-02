#include "Stack.h"
#include <stdbool.h>

static bool _Push(Stack *stack, S_Node_t *add_node);

static Stack *_Create(int num)
{
    if (num < 0)
        return NULL;

    Stack *new_stack = (Stack *)malloc(sizeof(Stack));
    new_stack->size = 0;
    new_stack->top = NULL;
    if (num > 0)
    {
        while (num)
        {
            S_Node_t *new_node = (S_Node_t *)malloc(sizeof(S_Node_t));
            new_node->next = NULL;
            new_node->ElemData._uint32_data = 0;
            _Push(new_stack, new_node);
            num--;
        }
    }
    return new_stack;
}

static bool _Destroy(Stack *stack)
{
    S_Node_t *next = stack->top->next;
    while (stack->top != NULL)
    {
        free(stack->top);
        stack->top = next;
        next = next->next;
    }

    free(stack);

    return true;
}

static bool _Clear(Stack *stack)
{
    S_Node_t *next = stack->top->next;
    while (stack->top != NULL)
    {
        free(stack->top);
        stack->top = next;
        next = next->next;
    }

    return true;
}

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
    _Create,
    _Destroy,
    _Clear,
    _Pop,
    _Push,
    _Peek,
    _isEmpty,
};