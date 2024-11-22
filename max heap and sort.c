#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  

typedef struct {
    int size;
    int array[MAX_SIZE];
} MaxHeap;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void maxHeapify(MaxHeap* heap, int i) {
    int largest = i;  
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->array[left] > heap->array[largest]) {
        largest = left;
    }

    if (right < heap->size && heap->array[right] > heap->array[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&heap->array[i], &heap->array[largest]);
        maxHeapify(heap, largest);
    }
}

int extractMax(MaxHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);

    return root;
}

void insert(MaxHeap* heap, int key) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap overflow\n");
        return;
    }

    int i = heap->size;
    heap->array[i] = key;
    heap->size++;

    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapSort(int arr[], int n) {
    MaxHeap heap;
    heap.size = 0;

    for (int i = 0; i < n; i++) {
        insert(&heap, arr[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        arr[i] = extractMax(&heap);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}