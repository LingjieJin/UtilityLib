#include "sort.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{

    srand(time(0));
    int arr[10];
    for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        arr[i] = rand() % 100;
    }

    bubbleSort(arr, 10, 1);

    return 0;
}