#include <stdlib.h>

typedef struct(array) {
    int *data;
    int size;
    int capacity;
} 

void append(Array *arr, int element) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = (int *) realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size] = element;
    arr->size++;
}

int main() {
    int n = 5; 
    Array arr;
    arr.size = 0;
    arr.capacity = 1;
    arr.data = (int *) malloc(sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr.capacity; j++) {
            append(&arr, arr.data[j] * 2);
        }
    }

    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");

    free(arr.data);
    return 0;
}

