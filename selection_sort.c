#include <stdio.h>
#include <stdbool.h>

void selectionSort(int *arr, int size);
bool isSorted(int *arr, int size);
void print(int *arr, int size);
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Before Sort = ");
    print(arr, size);
    if (isSorted(arr, size))
    {
        printf("\nArray is already sorted.\n");
    }
    else
    {
        selectionSort(arr, size);
        printf("\nAfter Sort = ");
        print(arr, size);
    }
    return 0;
}

void selectionSort(int *arr, int size)
{
    int minValue, temp;
    for (int i = 0; i < size - 1; i++)
    {
        minValue = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minValue])
            {
                minValue = j;
            }
        }
        if (minValue != i)
        {
            temp = arr[i];
            arr[i] = arr[minValue];
            arr[minValue] = temp;
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