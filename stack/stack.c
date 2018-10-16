#include <stdio.h>
#include <stdlib.h>

int stack_pos = 0;

int push(int *stack, int value) {
    if(stack_pos < 100) {
        stack[stack_pos] = value;
        stack_pos++;
    } 
    return 0;
}

int pop(int *stack) {
    if(stack_pos != 0) {
        stack_pos--;
        stack[stack_pos] = 0;
    } else {
        printf("The stack is empty.\n");
    }
    return 0;
}

int main() {
    int *stack;
    int stack_len;

    stack = (int *)malloc(100);
    push(stack, 3);
    push(stack, 5);
    pop(stack);
    pop(stack);
    pop(stack);

    stack_len = sizeof(stack) / sizeof(int);

    for(int i = 0; i < stack_len; i++) {
        if(stack[i] != 0) {
            printf("%d\n", stack[i]);
        }
    }

    free(stack);
}
