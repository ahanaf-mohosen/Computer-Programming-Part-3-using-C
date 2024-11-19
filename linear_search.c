#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *arr, int size, int search);
int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int search = 10;
    int result = linearSearch(arr, size, search);
    (result == -1) ? printf("Element is not present in array") : printf("Element is present in array in position %d", result);
    return 0;
}
int linearSearch(int *arr, int size, int search)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == search)
        {
            return i;
        }
    }
    return -1;
}