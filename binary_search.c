#include <stdio.h>

int binarySearch(int *arr, int size, int search);
int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int search = 10;
    int result = binarySearch(arr, size, search);
    (result == -1) ? printf("Element is not present in array") : printf("Element is present in array in position %d", result);
    return 0;
}

int binarySearch(int *arr, int size, int search)
{
    int left = 0, right = size - 1, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] == search)
        {
            return mid;
        }
        else if (arr[mid] < search)
        {
            left = mid + 1;
        }
        else if (arr[mid] > search)
        {
            right = mid - 1;
        }
    }
    return -1; // Element not present in array
}