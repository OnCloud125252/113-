#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int target;
    cout << "請輸入目標數字: ";
    cin >> target;

    int sum = 0;
    for (int i = 1; i <= target; i++)
    {
        sum += i;
    }
    cout << "1 ~ " << target << " 中，所有整數的和為 " << sum << endl;

    return 0;
}
