#include <stdio.h>
#include <stdlib.h>

void mergeSortedArrays(int* array1, int size1, int* array2, int size2, int* mergedArray) {
    int i = 0, j = 0, k = 0;

    
    while (i < size1 && j < size2) {
        if (array1[i] <= array2[j]) {
            mergedArray[k++] = array1[i++];
        } else {
            mergedArray[k++] = array2[j++];
        }
    }

    while (i < size1) {
        mergedArray[k++] = array1[i++];
    }

    while (j < size2) {
        mergedArray[k++] = array2[j++];
    }
}

int main() {
    int array1[] = {1, 3, 5};
    int array2[] = {2, 4, 6};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int* mergedArray = (int*)malloc((size1 + size2) * sizeof(int));

    if (mergedArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    mergeSortedArrays(array1, size1, array2, size2, mergedArray);

    printf("Merged Sorted Array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    free(mergedArray);
    return 0;
}
