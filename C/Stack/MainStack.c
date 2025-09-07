// #include "./StackInHeaderFiles/StackHeader.c"
#include "./StackInHeaderFiles/LinkedListStack.c"

void main(){
    Stack myStack;
    init(&myStack);
    printf("Stack initialized with top at %d\n", myStack.top);
    push(&myStack, 10);
    push(&myStack, 40);
    push(&myStack, 20);
      display(&myStack);
    printf("%d popped from stack\n", pop(&myStack));
    printf("%d popped from stack\n", pop(&myStack));
    printf("Stack after pop operation: ");
    display(&myStack);
}