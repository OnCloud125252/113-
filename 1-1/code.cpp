#include <iostream>

using namespace std;

int main()
{
    int height;
    cout << "請輸入三角形的高: ";
    cin >> height;

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            cout << "@";
        }
        cout << endl;
    }

    return 0;
}