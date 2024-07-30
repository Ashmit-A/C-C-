#include <stdio.h>
#include <stdbool.h>
 
#define size_limit 100
 
typedef struct
{
char data[size_limit];
char top_element;
} Stack;
void initialize(Stack* stack)
{
stack->top_element = -1;
} 
bool isFull(Stack* stack)
{
return stack-> top_element == size_limit - 1;
}
bool isEmpty(Stack* stack) {
return stack-> top_element == -1;
} 
void push(Stack* stack, char value)
{
if (isFull(stack)) {
    printf("Stack is overflow! It cannot push element anymore %d.\n", value);
}
else
{
    stack->top_element++;
    stack->data[stack->top_element] = value;
}
}
char pop(Stack* stack)
{
if (isEmpty(stack))
{
    printf("Stack is underflow! It cannot pop out element from an empty stack.\n");
    return -1; // returns a sentinel value or corrects error uniquely
}
else
{
    char value = stack->data[stack->top_element];
    stack->top_element--;
        printf("The stack has popped element %c from the stack.\n", value);
    return value;
}
}
int peek(Stack* stack) {
if (isEmpty(stack)) {
    printf("The stack is empty.\n");
    return -1;
} 
else 
{
    return stack->data[stack->top_element];
}
}
 
int main() {
    char str[100] = "Hello World";
    int size = sizeof(str)/sizeof(str[0]);
    Stack stack;
    initialize(&stack);
    for(int i = 0;i<size;i++)
        push(&stack, str[i]);
    do{
        printf("%c",pop(&stack));
    }
    while (!isEmpty);
    
}