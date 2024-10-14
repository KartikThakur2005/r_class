#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Swap function for generic data types
void swap(void *a, void *b, size_t size) {
    char temp;
    char *ptr_a = (char *)a;
    char *ptr_b = (char *)b;

    for (size_t i = 0; i < size; i++) {
        temp = ptr_a[i];
        ptr_a[i] = ptr_b[i];
        ptr_b[i] = temp;
    }
}

// Partition function for generic quicksort
int partition(void *arr, int low, int high, size_t size, int (*cmp)(const void *, const void *)) {
    char *array = (char *)arr;
    void *pivot = array + high * size;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (cmp(array + j * size, pivot) <= 0) {
            i++;
            swap(array + i * size, array + j * size, size);
        }
    }
    swap(array + (i + 1) * size, array + high * size, size);
    return (i + 1);
}

// Generic Quick Sort function
void quicksort(void *arr, int low, int high, size_t size, int (*cmp)(const void *, const void *)) {
    if (low < high) {
        int pi = partition(arr, low, high, size, cmp);
        quicksort(arr, low, pi - 1, size, cmp);
        quicksort(arr, pi + 1, high, size, cmp);
    }
}

// Integer comparison function
int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Character comparison function
int compare_char(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// String comparison function
int compare_string(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    // Sorting integers
    int int_arr[] = {24, 17, 13, 22, 35, 16};
    int int_size = sizeof(int_arr) / sizeof(int_arr[0]);
    quicksort(int_arr, 0, int_size - 1, sizeof(int), compare_int);
    printf("Sorted integers: ");
    for (int i = 0; i < int_size; i++) {
        printf("%d ", int_arr[i]);
    }
    printf("\n");

    // Sorting characters
    char char_arr[] = {'g', 'e', 'n', 'e', 'r', 'i', 'c'};
    int char_size = sizeof(char_arr) / sizeof(char_arr[0]);
    quicksort(char_arr, 0, char_size - 1, sizeof(char), compare_char);
    printf("Sorted characters: ");
    for (int i = 0; i < char_size; i++) {
        printf("%c ", char_arr[i]);
    }
    printf("\n");

    // Sorting strings
    const char *str_arr[] = {"banana", "apple", "grape", "cherry", "mango"};
    int str_size = sizeof(str_arr) / sizeof(str_arr[0]);
    quicksort(str_arr, 0, str_size - 1, sizeof(char *), compare_string);
    printf("Sorted strings: ");
    for (int i = 0; i < str_size; i++) {
        printf("%s ", str_arr[i]);
    }
    printf("\n");

    return 0;
}
