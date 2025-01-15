#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t i;
    int *arr;

    // Using malloc
    printf("Using malloc:\n");
    arr = (int *)malloc(5 * sizeof(int)); 

    if (arr == NULL) {
        printf("Memory allocation failed with malloc.\n");
        return 1;
    }

    // Initialize and print the array allocated by malloc
    for (i = 0; i < 5; i++) {
        arr[i] = i * 10;  
    }
    for (i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }

    // Using calloc
    printf("\nUsing calloc:\n");
    int *arr2 = (int *)calloc(5, sizeof(int));
    if (arr2 == NULL) {
        perror("Memory allocation failed with calloc");
        free(arr); // Free previously allocated memory
        return 1;
    }

    // Initialize and print the array allocated by calloc
    for (i = 0; i < 5; i++) {
        arr2[i] = i * 10;
    }
    for (i = 0; i < 5; i++) {
        printf("%d\n", arr2[i]);
    }

    // Using realloc
    printf("\nUsing realloc:\n");
    arr2 = (int *)realloc(arr2, 10 * sizeof(int));
    if (arr2 == NULL) {
        perror("Memory reallocation failed");
        free(arr);  // Free malloc'd memory
        return 1;
    }

    // Initialize new elements and print the resized array
    for (i = 5; i < 10; i++) {
        arr2[i] = i * 10;
    }
    for (i = 0; i < 10; i++) {
        printf("%d\n", arr2[i]);
    }

    // Free allocated memory
    free(arr);
    free(arr2);

    return 0;
}
