#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(int argc, char **argv)
{
    int int_10;
    cout << "請輸入十進制數字: ";
    cin >> int_10;

    string int_2;
    int num = int_10;
    do
    {
        int_2 += to_string(num % 2);
        num /= 2;
    } while (num != 1);
    int_2 += to_string(num);

    reverse(int_2.begin(), int_2.end());

    cout << "將十進制 " << int_10 << " 轉換為二進制為 " << int_2 << endl;

    return 0;
}
