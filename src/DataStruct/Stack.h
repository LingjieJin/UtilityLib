#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _S_Node_t
{
    /* next指向栈底 */
    struct _S_Node_t *next;
    union {
        uint32_t _uint32_data;
        void *_p_data;
    } ElemData;
} S_Node_t;

typedef struct _Stack
{
    int size;
    S_Node_t *top;
} Stack;

typedef struct _StackAPI
{
    /* 按照输入大小初始化 */
    Stack *(*Create)(int num);
    /* 销毁指定栈的内存 */
    bool (*Destroy)(Stack *stack);
    /* 将指定栈清空 即大小重置为0 */
    bool (*Clear)(Stack *stack);
    /* 删除栈顶元素 并返回该元素 如不需要请手动删除  */
    S_Node_t *(*Pop)(Stack *Stack);
    /* 压栈 */
    bool (*Push)(Stack *stack, S_Node_t *add_node);
    /* 返回栈顶元素 */
    S_Node_t *(*Peek)(Stack *stack);
    /* 判断栈是否为空 */
    bool (*isEmpty)(Stack *stack);
} StackAPI;

/* 保存实现函数 通过结构体调用 */
const StackAPI _stack_api;
