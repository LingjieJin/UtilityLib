#include <stdio.h>

#include <stdint.h>

static void printArray(int *arr, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        if (i % 8 == 7)
            printf("\n");
        printf("%d \t", *(arr + i));
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_exclusive(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

/* 泛型交换 */
void swap_ge(void *a, void *b, size_t type_size)
{
    char *p1 = (char *)a;
    char *p2 = (char *)b;
    char temp;
    while (type_size--)
    {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2++;
    }
}

/**
 * 冒泡排序
 * 
 * 从数据首位开始 逐位与后一位比较大小
 * 每一轮当前首位都与后面所有数据比较
 * 排序结果为升序
 */
void bubbleSort(int *arr, int n, int debug)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            /* 升序 */
            if ((*(arr + i)) > (*(arr + j)))
                swap(arr + i, arr + j);
        }

        /* debug print */
        if (debug)
        {
            printf("%d:\n", i + 1);
            printArray(arr, n);
            printf("\n");
        }
    }
}