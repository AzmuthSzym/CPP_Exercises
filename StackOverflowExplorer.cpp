#include <iostream>
#include <vector>

int funcIteration = 1;

void OverflowFunction()
{
    std::cout << "Iteration: " << funcIteration << std::endl;
    funcIteration++;
    OverflowFunction();
}

void OverflowFunctionLocalVar() {
    int large_array[100];
    std::cout << "Iteration: " << funcIteration << std::endl;
    funcIteration++;
    OverflowFunctionLocalVar();
}

void OverflowFunctionParam(int depth) {
    std::cout << "Iteration: " << depth << std::endl;
    OverflowFunctionParam(depth + 1);
}

void IterativeOverflow()
{
    for (int i = 0; i < 10000; i++)
    {
        std::cout << "Iteration: " << i << std::endl;
    }
}

int factorial_recursive(int n)
{
    return (n <= 1) ? 1 : n * factorial_recursive(n - 1);
}

long long factorial_iterative(int n)
{
    long long res = 1;
    for (int i = 1; i <= n; ++i)
    {
        res = res * i;
    }
    return res;
}
int main()
{
    // Crash around 4800 iteration
    //OverflowFunction();
    //OverflowFunctionParam(1);

    //Crash aorund 1600 iteration
    //OverflowFunctionLocalVar();
    
    //No crash
    //IterativeOverflow();

    //Crash in both cases - stack overflow and integer overflow
    //std::cout << factorial_recursive(10000) << std::endl;
    //std::cout << factorial_iterative(10000) << std::endl;

    //Integer overlow
    std::cout << factorial_recursive(100) << std::endl;

    //Both work fine
    std::cout << "factorial_recursive(10): " << factorial_recursive(10) << std::endl;
    std::cout << "factorial_iterative(10): " << factorial_iterative(10) << std::endl;
    return 0;
}

