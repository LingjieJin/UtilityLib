#include <stdint.h>
#include <stdbool.h>
#include "type.h"

typedef struct _LS_Stack
{
    int size;
    Node32_SP_t *top;
} LS_Stack;

typedef struct _LS_StackAPI
{
    /* 按照输入大小初始化 */
    LS_Stack *(*Create)(int num);
    /* 销毁指定栈的内存 */
    bool (*Destroy)(LS_Stack *stack);
    /* 将指定栈清空 即大小重置为0 */
    bool (*Clear)(LS_Stack *stack);
    /* 删除栈顶元素 并返回该元素 如不需要请手动删除  */
    Node32_SP_t *(*Pop)(LS_Stack *Stack);
    /* 压栈 */
    bool (*Push)(LS_Stack *stack, Node32_SP_t *add_node);
    /* 返回栈顶元素 */
    Node32_SP_t *(*Peek)(LS_Stack *stack);
    /* 判断栈是否为空 */
    bool (*isEmpty)(LS_Stack *stack);
} LS_StackAPI;

/* 保存实现函数 通过结构体调用 */
const LS_StackAPI _stack_api;
