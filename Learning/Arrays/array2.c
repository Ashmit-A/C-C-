#include <stdio.h>

void printArr(int array[], int size){
    
    for(int i = 0;i<size;i++){
        printf("%d\t",array[i]); 
    }
    printf("\n");
}

int isPrime(int n) {
    if (n < 0)
        return 0;
    if (n == 1 || n == 0)
        return 1;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int arr[] = {8, 1, 4, 3, 7, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArr(arr,n);

    for (int i = 1; i < n; i++) {
        if (isPrime(i-1)) {
            if (arr[i-1] >= arr[i]) {
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
            }
        }
    }
    
    printArr(arr, n);

    return 0;
}
