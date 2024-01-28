#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
    cout << "1 ~ 1000 中，所有的質數列表如下: " << endl;
    for (int i = 2; i <= 1000; i++)
    {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}