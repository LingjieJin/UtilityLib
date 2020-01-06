/*
 gcc SQ_Queue.c testcase_sq_queue_1.c -o 1.out
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Queue.h"

int main()
{
    srand(time(NULL));
    SQ_Queue queue = sq_queue_api.Create();

    for (int i = 0; i < 50; i++)
    {
        UData32_t new_data;
        new_data._uint32 = rand() % 100;
        sq_queue_api.Entry(&queue, new_data);
    }

    for (size_t i = 0; i < 50; i++)
    {
        printf("index %d, %d\n", i, queue.sq_queue_array[i]._uint32);
    }

    UData32_t get_1 = sq_queue_api.GetFront(&queue);
    UData32_t get_2 = sq_queue_api.GetRear(&queue);
    int size = sq_queue_api.GetSize(&queue);

    printf("front %d, rear %d, size %d.\n", get_1._uint32, get_2._uint32, size);

    return 0;
}
