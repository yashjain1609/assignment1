#include <stdio.h>

int iterativeBinarySearch(int array[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        
        if (array[mid] == target)
            return mid;

        
        if (array[mid] < target)
            left = mid + 1;

      
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int array[] = {2, 3, 4, 10, 40};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 10;

    int result = iterativeBinarySearch(array, size, target);

    if(result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found in the array\n");

    return 0;
}
