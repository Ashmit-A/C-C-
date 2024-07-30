#include<stdio.h>
void printArr(int array[], int size){
    
    for(int i = 0;i<size;i++){
        printf("%d\t",array[i]); 
    }
    printf("\n");
}

void main() {
    int arr[] = {4, 6, 1, 3, 2, 8, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num = 5;

    printArr(arr, n);

    int i, j = n-1, temp;
    
    for(i = 0; i < j;) {
        if(arr[i] < num) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
        } 
        else 
            i++;
    }

    printArr(arr, n);
}
