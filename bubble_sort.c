#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int *arr, int size);
bool isSorted(int *arr, int size);
void print(int *arr, int size);
int main()
{
    int arr[] = {4, 5, 2, 1, 8, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Before Sort = ");
    print(arr, size);
    if (isSorted(arr, size))
    {
        printf("\nArray is already sorted.\n");
    }
    else
    {
        bubbleSort(arr, size);
        printf("\nAfter Sort = ");
        print(arr, size);
    }
    return 0;
}
void bubbleSort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
bool isSorted(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}