// this code is to answer 01 for Assignment05
// this code is based on demo during class for pointer
// the main function will test the function
// using Arrange-Act-Assert test pattern

// it should be noted that there are two slighly different ways to 
// declare this function, they are both doing the same thing
// but have different signature, and thus will need to be called
// differently

// include assert library
#include <assert.h>


// ************** Test swapPtr1************** //
#if 1
// this swapPtr1 function allows the user to directly pass in the pointer
// pointed address values
// NOTE: only pointer swapped, the underlying value do not!
void swapPtr1(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}


int main(void)
{
    // to test swapPtr1 function first
    // Arrange:
    int x = 627;
    int y = 55;
    int* xPtr = &x;
    int* yPtr = &y;
    
    // Act:
    swapPtr1(&xPtr, &yPtr);
    
    // Assert:
    assert(xPtr == &y); // xPtr now points to y
    assert(yPtr == &x); // yPtr now points to x
    assert(x == 627); // x value stays the same
    assert(y == 55); // y value stays the same
    
    
    return 0;
}

#endif

// ************** Test swapPtr2************** //
#if 0
// this swapPtr2 function needs user to pass in the pointer de-referenced value
// which are basically the address they point to, as pointers
// NOTE: only pointer swapped, the underlying value do not!
void swapPtr2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(void)
{
    // to test swapPtr1 function first
    // Arrange:
    int x = 627;
    int y = 55;
    int* xPtr = &x;
    int* yPtr = &y;
    
    // Act:
    swapPtr2((int*) &xPtr, (int*) &yPtr);
    
    // Assert:
    assert(xPtr == &y); // xPtr now points to y
    assert(yPtr == &x); // yPtr now points to x
    assert(x == 627); // x value stays the same
    assert(y == 55); // y value stays the same
    
    
    return 0;
}

#endif
