#include <stdio.h>

void countingSort(int arr[], int n);
void print(int arr[], int size);

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print(arr, size);

    countingSort(arr, size);

    printf("\nSorted array: ");
    print(arr, size);

    return 0;
}

void countingSort(int arr[], int n)
{
    // Find the maximum value in the array
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Initialize count array
    int count[max + 1];
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // Count the occurrences of each element
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Update the count array to store positions
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // Create an output array
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}