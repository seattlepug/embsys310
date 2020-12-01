// this section of the code answers Q2 of assignment04
// this is based on example shared during the lecture

// declare the signature of the function first
// so that complier will not have any warnings
int func1(int var0, int var1, int var2, int var3, int var4);
void func2();


// main function only calls func1 and func2
int main()
{
    func2();
    return 0;
}


// function 1, which has 5 varuments
int func1(int var0, int var1, int var2, int var3, int var4)
{
    int lvar0;
    int lvar1;
    int lvar2;
    int lvar3;
    int lvar4;
    int sum;
    
    lvar0 = var0;
    lvar1 = var1;
    lvar2 = var2;
    lvar3 = var3;
    lvar4 = var4;
        
    sum = lvar0 + lvar1 + lvar2 + lvar3 + lvar4;
    
    return sum;
}

// function 2 calls function 1
// function 2 also needs to define variables, and pass these 
// variables as varuments into function1
void func2()
{
    int var0 = 0;
    int var1 = 1;
    int var2 = 2;
    int var3 = 3;
    int var4 = 4;
    int sum = func1(var0, var1, var2, var3, var4);
    
    // display the value, cannot display the value
    // i think it is not as straighforward as 
    // display the value on command window
    // printf("the value is: " + sum);
}