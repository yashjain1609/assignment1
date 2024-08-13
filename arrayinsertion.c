#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30, 40, 50,60};  
    int size = 6;  
    int element = 70;  

    
    arr[size] = element;
    size++;  

  
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
