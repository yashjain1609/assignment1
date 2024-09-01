#include <stdio.h>
#include <stdlib.h>

void mergeArrays(int* array1, int size1, int* array2, int size2, int* mergedArray) {
    for (int i = 0; i < size1; i++) {
        mergedArray[i] = array1[i];
    }
    for (int i = 0; i < size2; i++) {
        mergedArray[size1 + i] = array2[i];
    }
}

int main() {
    int array1[] = {1, 2, 3};
    int array2[] = {4, 5, 6};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int* mergedArray = (int*)malloc((size1 + size2) * sizeof(int));

    if (mergedArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    mergeArrays(array1, size1, array2, size2, mergedArray);

    printf("Merged Array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    free(mergedArray);
    return 0;
}
