#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    cout << "請輸入字串: ";
    string originalInput;
    getline(cin, originalInput);
    string reversedInput = originalInput;

    reverse(reversedInput.begin(), reversedInput.end());

    if (originalInput == reversedInput)
    {
        cout << originalInput << " 是迴文" << endl;
    }
    else
    {
        cout << originalInput << " 不是迴文" << endl;
    }

    return 0;
}