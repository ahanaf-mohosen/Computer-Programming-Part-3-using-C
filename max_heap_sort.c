#include <stdio.h>

// int heap[10];
// heap[1] = 19;
// heap[2] = 7;
// heap[3] = 17;
// heap[2 * 2] = 3;
// heap[2 * 2 + 1] = 5;
// heap[3 * 2] = 12;
// heap[3 * 2 + 1] = 10;
// heap[4 * 2] = 1;
// heap[4 * 2 + 1] = 2;
int left(int index);
int right(int index);
int parent(int index);
int is_max_heap(int heap[], int size);
void max_heapify(int heap[], int size, int index);
void print_heap(int heap[], int size);
void build_max_heap(int heap[], int size);
void heap_sort(int heap[], int size);

int main()
{
    int heap[] = {0, 19, 7, 12, 3, 5, 17, 10, 1, 2};
    int size = sizeof(heap) / sizeof(heap[0]) - 1;
    int max = is_max_heap(heap, size);
    if (max == 0)
    {
        printf("This is not a max heap\n");
    }
    else
    {
        printf("This is a max heap\n");
    }
    printf("Initial Heap:\n");
    print_heap(heap, size);
    printf("After building max heap:\n");
    build_max_heap(heap, size);
    print_heap(heap, size);
    printf("After sorting in descending order:\n");
    heap_sort(heap, size);
    print_heap(heap, size);
    return 0;
}

int left(int index)
{
    return 2 * index;
}
int right(int index)
{
    return 2 * index + 1;
}
int parent(int index)
{
    return index / 2;
}
int is_max_heap(int heap[], int size)
{
    int p;
    for (int i = size; i >= 1; i--)
    {
        p = parent(i);
        // printf("i = %d, p = %d\theap[%d] = %d, heap[%d] = %d\n", i, p, i, p, heap[i], heap[p]);
        if (heap[p] < heap[i])
        {
            return 0;
        }
    }
    return 1;
}

void max_heapify(int heap[], int size, int index)
{
    int l, r, largest, t;
    l = left(index);
    r = right(index);

    if (l <= size && heap[l] > heap[index])
    {
        largest = l;
    }
    else
    {
        largest = index;
    }

    if (r <= size && heap[r] > heap[largest])
    {
        largest = r;
    }
    if (largest != index)
    {
        t = heap[index];
        heap[index] = heap[largest];
        heap[largest] = t;
        max_heapify(heap, size, largest);
    }
}

void print_heap(int heap[], int size)
{
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n\n");
}

void build_max_heap(int heap[], int size)
{
    for (int i = size / 2; i >= 1; i--)
    {
        max_heapify(heap, size, i);
    }
}
void heap_sort(int heap[], int size)
{
    int temp;
    for (int i = size; i >= 1; i--)
    {
        temp = heap[1];
        heap[1] = heap[i];
        heap[i] = temp;
        size--;
        max_heapify(heap, size, 1);
    }
}