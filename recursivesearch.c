#include <stdio.h>

int recursiveBinarySearch(int array[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (array[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (array[mid] < target)
            return recursiveBinarySearch(array, mid + 1, right, target);

        // If target is smaller, ignore the right half
        return recursiveBinarySearch(array, left, mid - 1, target);
    }

    // Target was not found
    return -1;
}

int main() {
    int array[] = {2, 3, 4, 10, 40};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 10;

    int result = recursiveBinarySearch(array, 0, size - 1, target);

    if(result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found in the array\n");

    return 0;
}
