// include the stack.h and assert header files
#include<assert.h>
#include"stack.h"


int main()
{
    // *******************************************************************
    // Test1a: initialize a stack, and check isEmpty and isFull function
    // *******************************************************************
    stack_init();
    
    // Assert:
    assert(stack_isEmpty() == 1);
    assert(stack_isFull() == 0);
    
    // *******************************************************************
    // Test1b: add one element to the stack, 
    // and check isEmpty and isFull function again
    // *******************************************************************
    stack_push(1); // add one element
    
    // Assert:
    assert(stack_isEmpty() == 0);
    assert(stack_isFull() == 0);
    
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the stack
    // insert in total three different elements
    // the pop them all out, making sure that the stack is indeed empty
    // *******************************************************************    
    stack_init();
    stack_push(1);
    stack_push(2);
    stack_push(3);
    
    // Assert:
    int result1 = stack_pop();
    assert(result1 == 3);
    
    result1 = stack_pop();
    assert(result1 == 2);
    
    result1 = stack_pop();
    assert(result1 == 1);
    
    assert(stack_isEmpty() == 1);
    
    // *******************************************************************
    // Test3: Fill stack, then get all items.
    // *******************************************************************    
    stack_init();
    // fill the stack
    for (int i = 0; i < 10; i++) 
    {
        stack_push(i);
    }                                   
    
    // then, take all the elements out, and aseert at the same time
    // Assert:
    for (int i = 9; i >= 0; i--)
    {
        result1 = stack_pop();
        assert(result1 == i); 
    }
    
    // *******************************************************************
    // Test4: Fill stack, then put one more item, should fail
    // returns -1;
    // *******************************************************************
    stack_init();
    // fill the stack
    for (int i = 0; i < 10; i++) 
    {
        stack_push(i);
    } 
    
    // Assert:
    assert(-1 == stack_push(10));    
    
    
    // ***********************************************************************
    // Test5: Fill stack, retrieve one item, then add item, then retieve all
    // ***********************************************************************
    stack_init();
    // fill the stack
    for (int i = 0; i < 10; i++) 
    {
        stack_push(i);
    } 
    
    // Assert first:
    assert(9 == stack_pop());
    
    // then add one element back in and assert
    assert(0 == stack_push(9));

    // then, take all the elements out, and aseert at the same time
    // Assert:
    for (int i = 9; i >= 0; i--)
    {
        result1 = stack_pop();
        assert(result1 == i); 
    }
    
    
    // ***********************************************************************
    // Test6: Fill stack and retrieve all items. Do it twice in a row.
    // this is basically doing test4 twice
    // ***********************************************************************
     stack_init();
    // fill the stack
    for (int i = 0; i < 10; i++) 
    {
        stack_push(i);
    }                                   
    
    // then, take all the elements out, and aseert at the same time
    // Assert:
    for (int i = 9; i >= 0; i--)
    {
        result1 = stack_pop();
        assert(result1 == i); 
    }
    
    // second time around
    for (int i = 0; i < 10; i++) 
    {
        stack_push(i);
    }                                   
    
    // then, take all the elements out, and aseert at the same time
    // Assert:
    for (int i = 9; i >= 0; i--)
    {
        result1 = stack_pop();
        assert(result1 == i); 
    }
    
    // ***********************************************************************
    // DONE!
    // ***********************************************************************
    return 0;
}
