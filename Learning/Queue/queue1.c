#include <stdio.h>
void printArr(int array[], int size){
    
    for(int i = 0;i<size;i++){
        printf("%d\t",array[i]); 
    }
    printf("\n");
}

int isEmpty(int q[], int f, int r)
{
    if (f == r)
    {
        return 1;
    }
    return 0;
}
int isFull(int q[], int r, int size)
{
    if (r >= size)
    {
        return 1;
    }
    return 0;
}
int enqueue(int q[], int r,int size,  int data)
{
    if (isFull(q, r, size))
    {
        printf("queue is overflow");
        return 0;
    }
    q[r] = data;
    r++;
    return r;
}
int dequeue(int q[],int f){
    int value = q[f];
    f++;
    return f;
}

int peek(int q[], int f){
    return q[f];
}

int maxElement(int q[], int r, int f){
    int max = 0;
    for(f;f<r;f++){
        if(q[f]>max){
            max = q[f];
        }
    }
    return max;
}
   
   
int main(){
    int q[8]={0};
    int  r = 0;
    int f = 0;

    if (isEmpty(q,f,r))
    {
        printf("Its empty rn\n");
    }
    r = enqueue(q , r,8, 5);
    r = enqueue(q , r,8, 6);
    r = enqueue(q , r,8, 7);
    r = enqueue(q , r,8, 8);
    r = enqueue(q , r,8, 9);
    r = enqueue(q , r,8, 1);

    printArr(q, 8);

    
    int a = peek(q, f);
    f = dequeue(q, f);
    printf("%d \n", a);
    printArr(q, 8);

    int b = peek(q, f);
    f = dequeue(q, f);
    printf("%d \n", b);
    printArr(q, 8);

    printf("%d", maxElement(q, r, f));
    
    }
