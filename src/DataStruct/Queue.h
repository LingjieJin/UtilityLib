#include <stdint.h>
#include <stdbool.h>
#include "type.h"

/* -----------------------------------*/

/* 
-----------------------------------
| | | | | | | | | | | | | | | | |X|
-----------------------------------
^                                ^
front                            rear (index)


*/
#define SQ_QUEUE_LENGTH 100
typedef struct _SQ_Queue
{
    UData32_t sq_queue_array[SQ_QUEUE_LENGTH];
    int front;
    int rear; /* 指向一个空的节点 */
} SQ_Queue;

typedef struct _SQ_QueueAPI
{
    SQ_Queue (*Create)();
    bool (*isEmpty)(SQ_Queue *sq_queue);
    bool (*Entry)(SQ_Queue *sq_queue, UData32_t add_node);
    UData32_t (*Delete)(SQ_Queue *sq_queue);
    void (*Clear)(SQ_Queue *sq_queue);
    UData32_t (*GetFront)(SQ_Queue *sq_queue);
    UData32_t (*GetRear)(SQ_Queue *sq_queue);
    int (*GetSize)(SQ_Queue *sq_queue);
} SQ_QueueAPI;

const SQ_QueueAPI sq_queue_api;

/* 链表队列 ---------------------------------------*/

typedef struct _LQ_Query
{
    int MaxSize;
    int count;
    Node32_SP_t *front;
    Node32_SP_t *rear;
} LQ_Query;

typedef struct _QueryAPI
{
    /* 队列初始化 必须指定队列长度 */
    LQ_Query *(*Create)(int size);
    bool (*isEmpty)(LQ_Query *queue);
    bool (*Destroy)(LQ_Query *queue);
    bool (*Clear)(LQ_Query *queue);
    bool (*Entry)(LQ_Query *queue, Node32_SP_t *node);
    Node32_SP_t *(*Delete)(LQ_Query *queue);
    Node32_SP_t *(*GetFront)(LQ_Query *queue);
    Node32_SP_t *(*GetRear)(LQ_Query *queue);
    int (*GetSize)(LQ_Query *queue);
} LQ_QueryAPI;

const LQ_QueryAPI lq_queue_api;