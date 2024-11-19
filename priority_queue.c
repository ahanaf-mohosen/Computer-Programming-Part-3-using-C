#include <stdio.h>

int left(int index);
int right(int index);
int parent(int index);
int is_max_heap(int heap[], int size);
void max_heapify(int heap[], int size, int index);
void print_heap(int heap[], int size);
void build_max_heap(int heap[], int size);
void heap_sort(int heap[], int size);
int get_maximum(int heap[]);
int extract_max(int heap[], int *size);
int insert_node(int heap[], int *size, int node);

int main()
{
    int heap[] = {0, 19, 7, 12, 3, 5, 17, 10, 1, 2}; // 0 is unused
    int size = sizeof(heap) / sizeof(heap[0]) - 1;
    int max;

    // Check if it's a max heap
    max = is_max_heap(heap, size);
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

    // Build max heap
    printf("After building max heap:\n");
    build_max_heap(heap, size);
    print_heap(heap, size);

    // Get maximum element
    printf("Maximum element: %d\n", get_maximum(heap));

    // Extract maximum element
    int extracted_max = extract_max(heap, &size);
    printf("Extracted maximum element: %d\n", extracted_max);
    printf("Heap after extraction:\n");
    print_heap(heap, size);

    // Insert a new element
    int new_node = 15;
    size = insert_node(heap, &size, new_node);
    printf("Heap after inserting %d:\n", new_node);
    print_heap(heap, size);

    // Sort the heap
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
        if (p > 0 && heap[p] < heap[i])
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
    int original_size = size;  // Store the original size
    for (int i = size; i >= 2; i--)
    {
        temp = heap[1];
        heap[1] = heap[i];
        heap[i] = temp;
        size--;
        max_heapify(heap, size, 1);
    }
    size = original_size;  // Restore the original size
}

int get_maximum(int heap[])
{
    return heap[1];
}

int extract_max(int heap[], int *size)
{
    int max = heap[1];
    heap[1] = heap[*size];
    (*size)--;
    max_heapify(heap, *size, 1);
    return max;
}

int insert_node(int heap[], int *size, int node)
{
    int i, p, t;
    (*size)++;
    i = *size;
    heap[i] = node;

    while (i > 1 && heap[i] > heap[parent(i)])
    {
        p = parent(i);

        t = heap[p];
        heap[p] = heap[i];
        heap[i] = t;
        i = p;
    }
    return *size;
}
