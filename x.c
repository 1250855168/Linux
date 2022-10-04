#include <stdio.h>
#include<stdlib.h>
int isPrime(int k)
{
    int j;
    for (j = 2; j < k; j++)
    {
        if (k % j == 0) // 如果不为素数返回0
        {
            return 0;
        }
    }
    return 1; // 反之则返回1
}

int main()
{
    int m = 999;
    int temp1;
    int temp2;
    int count = 0;
    for (size_t i = 6; i <= m; i = i + 2)
    {
        count = 0;
        for (size_t j = 2; j < i; j++)
        {
            if (isPrime(j))
            {
                temp1 = j;
            }
            for (size_t k = j + 1; k < i; k++)
            {
                if (isPrime(k))
                {
                    temp2 = k;
                }
                if (i == temp1 + temp2)
                {
                    count++;
                    temp1 = temp2 = 0;
                    break;
                }
            }
        }
        if (count == 10)
        {
            printf("%ld\n", i);
        }
    }

    return 0;
}