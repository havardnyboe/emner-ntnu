#include "std_lib_facilities.h"

// oppg a)
int maxOfTwo(int a, int b)
{
    if (a > b)
    {
        cout << "A is greater than B" << endl;
        return a;
    }
    else
    {
        cout << "B is greater than or equal to A" << endl;
        return b;
    }
}

// oppg c)
int fibonacci(int n)
{
    int a{0};
    int b{1};
    cout << "Fibonacci numbers:" << endl;
    for (int i{0}; i <= n; i++)
    {
        cout << i << ": " << b << endl;
        int temp{b};
        b += a;
        a = temp;
    }
    cout << "----" << endl;
    return b;
}

// oppg d)
int sqareNumberSum(int n)
{
    int totalSum{0};
    for (int i{0}; i < n; i++)
    {
        totalSum += i * i;
        cout << i * i << endl;
    }
    cout << totalSum << "\n----" << endl;
    return totalSum;
}

// oppg e)
int triangleNumbersBelow(int n)
{
    int acc{1};
    int num{2};
    cout << "Triangle numbers below " << n << ':' << endl;
    int i{0};
    while (acc < n)
    {
        cout << acc << endl;
        acc += num;
        num++;
        ++i;
    }
    cout << "----" << endl;
    return i;
}

// oppg f)
bool isPrime(int n)
{
    for (int i{2}; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// oppg g)
void naivePrimeNumberSearch(int n)
{
    for (int i{2}; i < n; i++)
    {
        if (isPrime(i))
        {
            cout << i << " is a prime." << endl;
        }
    }
    cout << "----" << endl;
}

// oppg h)
int findGreatestDivisor(int n)
{
    for (int i{n - 1}; i > 0; i--)
    {
        if (n % i == 0)
        {
            return i;
        }
    }
    return 1;
}

// oppg b)
int main()
{
    // oppg a)
    cout << "Oppgave a)" << endl;
    maxOfTwo(5, 6);
    cout << "----" << endl;
    // oppg c)
    cout << "\nOppgave c)" << endl;
    fibonacci(10);
    // oppg d)
    cout << "\nOppgave d)" << endl;
    sqareNumberSum(10);
    // oppg e)
    cout << "\nOppgave e)" << endl;
    triangleNumbersBelow(22);
    // oppg f)
    cout << "\nOppgave f)" << endl;
    cout << isPrime(7) << endl;
    cout << isPrime(6) << endl;
    cout << "----" << endl;
    // oppg g)
    cout << "\nOppgave g)" << endl;
    naivePrimeNumberSearch(10);
    // oppg h)
    cout << "\nOppgave h)" << endl;
    cout << findGreatestDivisor(12) << endl;
    cout << findGreatestDivisor(1729) << endl;
    cout << "----" << endl;
}
