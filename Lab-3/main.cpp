#include <iostream>

long long int condition(int K, int L, int M)
{
    return static_cast<long long int>(pow(3, K) * pow(5, L) * pow(7, M));
}

void print(int K, int L, int M, long long int x_i)
{
    std::cout << "3^" << K << " * " << "5^" << L << " * " << "7^" << M << " = " << x_i << "\n";
}

int main()
{
    long long int x;
    std::cout << "Enter x: ";
    std::cin >> x;

    int K = 0, L = 0, M = 0;

    while (condition(K, L, M) <= x)
    {
        while (condition(K, L, M) <= x)
        {
            while (condition(K, L, M) <= x)
            {
                if (condition(K, L, M) <= x)
                    print(K, L, M, condition(K, L, M));
                ++K;
            }
            if (condition(K, L, M) <= x)
                print(K, L, M, condition(K, L, M));
            ++L;
            K = 0;
        }
        ++M;
        L = 0;
    }

    return 0;
}
