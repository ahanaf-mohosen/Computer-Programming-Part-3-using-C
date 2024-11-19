#include <stdio.h>

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void print(int arr[], int size);

int main()
{
    int arr[] = {5, 7, 2, 9, 1, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print(arr, size);

    mergeSort(arr, 0, size - 1); // Correct range
    printf("\nSorted array: ");
    print(arr, size);

    return 0;
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void merge(int arr[], int left, int mid, int right)
{
    int size_left = mid - left + 1;
    int size_right = right - mid;

    int L[size_left], R[size_right];

    // Copy data to temporary arrays
    for (int i = 0; i < size_left; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < size_right; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int index_l = 0, index_r = 0, index_a = left;

    // Merge the temporary arrays back into the original array
    while (index_l < size_left && index_r < size_right)
    {
        if (L[index_l] <= R[index_r])
        {
            arr[index_a] = L[index_l];
            index_l++;
        }
        else
        {
            arr[index_a] = R[index_r];
            index_r++;
        }
        index_a++;
    }

    // Copy remaining elements from L[], if any
    while (index_l < size_left)
    {
        arr[index_a] = L[index_l];
        index_a++;
        index_l++;
    }

    // Copy remaining elements from R[], if any
    while (index_r < size_right)
    {
        arr[index_a] = R[index_r];
        index_a++;
        index_r++;
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
