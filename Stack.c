#include <stdio.h>

#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Stack

{

int top_idx;    //index of latest data

int buffer[MAX_SIZE];

} Stack;

void initStack(Stack *stack){

stack->top_idx = -1;

}

int isFull(Stack *stack){

if(stack->top_idx == MAX_SIZE-1){

return 1;

}

else{

return 0;

}

}

int isEmpty(Stack *stack){

if(stack->top_idx == -1){

return 1;

}

else{

return 0;

}

}

void Push(Stack *stack, int data){

if(isFull(stack)){

printf("Stack is FULL!");

}

else{

stack->buffer[stack->top_idx++] = data;

}

}

int Pop(Stack *stack){

if(isEmpty(stack)){

printf("Stack is EMPTY!");

return -1;

}

else{

return stack->buffer[stack->top_idx--];

}

}

int Peek(Stack *stack){

if(isEmpty(stack)){

printf("Stack is EMPTY!");

return -1;

}

else{

return stack->buffer[stack->top_idx];

}

}

void printStack(Stack *stack){

for(int i=0; i<=stack->top_idx;i++){

printf("%d\n", stack->buffer[i]);

}

}

int main(){

struct Stack s1;

int input=1;

initStack(&s1);

while (input!=-1){

scanf("%d", &input);

if(input==-1) break;

Push(&s1, input);

printStack(&s1);

}

return 0;

}