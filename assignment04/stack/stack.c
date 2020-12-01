// actual implementation of stack structure
// include the stack.h header file
#include "stack.h"

// predefine a size, use size 10
#define STACK_SIZE 10

// actual underlying data structure, an array
int StackStore[STACK_SIZE];

// in this case, since it is a stack, which is first in, last out
// you only need to track the current size of the stack
// note that current_size can be used to find the "top most" element to pop
int current_size; 

// now to define stack initialization
void stack_init(void)
{
    // initialize the array, with all elements to be 0 first
    // also, initialize current_size to be 0, meaning the stack is empty
    current_size = 0;
    for (int i = 0; i < STACK_SIZE; i++) {
        StackStore[i] = 0;
    }
}

// function to check if stack is empty, return 1 if so
// it will return 0 if not so
int stack_isEmpty(void)
{
    // if current size is zero, then the stack is empty
    // the boolean value will convert into 1 if empty
    // will return 0 if non zero
    return current_size == 0;
}

// function to check if stack is full, returns 1 if full
// it will return 0 if not so
int stack_isFull(void)
{
    // use similar approach like stack_isEmpty
    return current_size == STACK_SIZE;
}

// function to push an element onto the stack
int stack_push(int data)
{
    // only proceed if stack is not full
    if (!stack_isFull())
    {
        StackStore[current_size] = data;
        current_size++;
        return 0; // operation success!
    }
    else
    {
        return -1; // failed!
    }
}

// function to pop an element off the stack
int stack_pop(void)
{
    // only proceed if stack is not empty
    if (current_size != 0)
    {
        current_size--;
        return (StackStore[current_size]);
    }
    else
    {
        return -1; // failed!
    }
}