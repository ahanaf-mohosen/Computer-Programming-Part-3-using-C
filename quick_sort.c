#include <stdio.h>

int partition(int A[], int low, int high);
void quickSort(int A[], int low, int high);
void print(int arr[], int size);
int main()
{
    int A[] = {1, 5, 6, 3, 5, 8, 7, 2, 9};
    int size = sizeof(A) / sizeof(A[0]);
    printf("Original array: ");
    print(A, size);
    printf("Sort Array: ");
    quickSort(A, 0, size - 1);
    print(A, size);
    return 0;
}

int partition(int A[], int low, int high)
{
    int pivot = A[high];
    int i, j, temp;

    for (i = low - 1, j = low; j < high; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[high];
    A[high] = A[i + 1];
    A[i + 1] = temp;

    return (i + 1);
}

void quickSort(int A[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int p = partition(A, low, high);
    quickSort(A, low, p - 1);
    quickSort(A, p + 1, high);
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
