#include "Queue.h"
#include <stdio.h>

static bool _isFull(SQ_Queue *queue)
{
    return (queue->front + 1) % SQ_QUEUE_LENGTH == queue->rear;
}

static SQ_Queue _SQ_Create()
{
    SQ_Queue new_sq;
    new_sq.front = new_sq.rear = 0;
    return new_sq;
}

static bool _SQ_isEmpty(SQ_Queue *queue)
{
    return (queue->front == queue->rear);
}

static bool _SQ_Entry(SQ_Queue *queue, UData32_t add_node)
{
    queue->sq_queue_array[queue->rear] = add_node;
    queue->rear = (queue->rear + 1) % SQ_QUEUE_LENGTH;
}

static UData32_t _SQ_Delete(SQ_Queue *queue)
{
    UData32_t delete_node = queue->sq_queue_array[queue->front];
    queue->front = (queue->front + 1) % SQ_QUEUE_LENGTH;
    return delete_node;
}

static void _SQ_Clear(SQ_Queue *queue)
{
    if (_SQ_isEmpty(queue))
    {
        return;
    }

    /* 数据清空 */
    for (int i = 0; i < SQ_QUEUE_LENGTH; i++)
    {
        queue->sq_queue_array[i]._uint32 = 0;
    }

    queue->front = queue->rear = 0;
}

static UData32_t _SQ_GetFront(SQ_Queue *queue)
{
    return queue->sq_queue_array[queue->front];
}

static UData32_t _SQ_GetRear(SQ_Queue *queue)
{
    return queue->sq_queue_array[queue->rear - 1];
}

static int _SQ_GetSize(SQ_Queue *queue)
{
    if (queue->rear >= queue->front)
    {
        return queue->rear - queue->front;
    }
    else
    {
        return (queue->rear + SQ_QUEUE_LENGTH) - queue->front;
    }
}

const SQ_QueueAPI sq_queue_api = {
    _SQ_Create,
    _SQ_isEmpty,
    _SQ_Entry,
    _SQ_Delete,
    _SQ_Clear,
    _SQ_GetFront,
    _SQ_GetRear,
    _SQ_GetSize,
};
