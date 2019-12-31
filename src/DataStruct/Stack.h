#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
    S_Node_t *next;
    union {
        uint32_t _uint32_data;
    } ElemData;
} S_Node_t;

typedef struct Stack
{
    int max_size;
    int size;
    S_Node_t *top;
} Stack;

typedef struct StackAPI
{
    S_Node_t *(*Pop)(Stack *Stack);
    bool (*Push)(Stack *stack, S_Node_t *add_node);
    S_Node_t *(*Peek)(Stack *stack);
    bool (*isEmpty)(Stack *stack);
} StackAPI;

const StackAPI _stack_api;
