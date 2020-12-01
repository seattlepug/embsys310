// this is the header file for stack
#ifndef __STACK_H__
#define __STACK_H__

// the function to intialize stack
void stack_init(void);

// function to push an element onto the stack
int stack_push(int data);

// function to pop an element off the stack
int stack_pop(void);

// function to check if stack is empty, return 1 if so
int stack_isEmpty(void);

// function to check if stack is full, returns 1 if full
int stack_isFull(void);

#endif