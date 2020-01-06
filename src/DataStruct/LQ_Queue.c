#include "Queue.h"

#include <stdio.h>
#include <stdlib.h>

static bool _LQ_isEmpty(LQ_Query *queue)
{
    return queue->count == 0;
}

static LQ_Query *_LQ_Create(int size)
{
    LQ_Query *queue = (LQ_Query *)malloc(sizeof(LQ_Query));
    if (queue == NULL)
    {
        return NULL;
    }

    queue->MaxSize = size;
    queue->count = 0;
    queue->front = queue->rear = NULL;
    return queue;
}

static bool _LQ_Destroy(LQ_Query *queue)
{
    if (queue == NULL)
    {
        return true;
    }

    while (queue->count)
    {
        Node32_SP_t *temp = queue->front->next;
        free(queue->front);
        queue->front = temp;
        queue->count--;
    }

    free(queue);

    return true;
}

static bool _LQ_Clear(LQ_Query *queue)
{
    while (queue->count)
    {
        Node32_SP_t *temp = queue->front->next;
        free(queue->front);
        queue->front = temp;
        queue->count--;
    }
    queue->front = queue->rear = NULL;

    return true;
}

static bool _LQ_Entry(LQ_Query *queue, Node32_SP_t *node)
{
    if (queue == NULL || queue->count >= queue->MaxSize)
    {
        return false;
    }
    /* 可选操作 */
    node->next = NULL;

    /* 当队列为空时 加入操作不同 */
    if (queue->front == NULL)
    {
        queue->front = node;
    }
    else
    {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->count++;

    return true;
}

static Node32_SP_t *_LQ_Delete(LQ_Query *queue)
{
    if (queue == NULL || queue->count == 0)
    {
        return NULL;
    }

    Node32_SP_t *ret = queue->front;
    queue->front = queue->front->next;
    queue->count--;

    /* 队列仅有一个元素时候 删除后需要检查 */
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    return ret;
}

static Node32_SP_t *_LQ_GetFront(LQ_Query *queue)
{
    return queue->front;
}

static Node32_SP_t *_LQ_GetRear(LQ_Query *queue)
{
    return queue->rear;
}

static int _LQ_GetSize(LQ_Query *queue)
{
    return queue->count;
}

const LQ_QueryAPI lq_queue_api = {
    _LQ_Create,
    _LQ_isEmpty,
    _LQ_Destroy,
    _LQ_Clear,
    _LQ_Entry,
    _LQ_Delete,
    _LQ_GetFront,
    _LQ_GetRear,
    _LQ_GetSize,
};