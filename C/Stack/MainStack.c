#include "StackArrayyHeader.c"

void main(){
    Stack myStack;
    init(&myStack);
    printf("Stack initialized with top at %d\n", myStack.top);
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
      display(&myStack);
    printf("%d popped from stack\n", pop(&myStack));
    printf("%d popped from stack\n", pop(&myStack));
    printf("Stack after pop operation: ");
    display(&myStack);
}