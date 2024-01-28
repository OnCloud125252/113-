#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    int chinese;
    int english;
    int math;
    int basic_electricity;
    int electronic;
    cout << "輸入國文分數: ";
    cin >> chinese;
    cout << "輸入英文分數: ";
    cin >> english;
    cout << "輸入數學分數: ";
    cin >> math;
    cout << "輸入基本電學分數: ";
    cin >> basic_electricity;
    cout << "輸入電子學分數: ";
    cin >> electronic;
    int scores[] = {chinese, english, math, basic_electricity, electronic};
    const int SCORE_LENGTH = sizeof(scores) / sizeof(scores[0]);

    sort(scores, scores + SCORE_LENGTH);

    int sum;
    int below_60_index = 0;
    for (int i = 0; i < SCORE_LENGTH; i++)
    {
        int score = scores[i];
        if (score < 60)
        {
            below_60_index = i + 1;
        }
        sum += score;
    }

    int avg = sum / SCORE_LENGTH;

    cout << "\n";
    cout << "國文 " << chinese << "分" << endl;
    cout << "英文 " << english << "分" << endl;
    cout << "數學 " << math << "分" << endl;
    cout << "基本電學 " << basic_electricity << "分" << endl;
    cout << "電子學 " << electronic << "分" << endl;
    cout << "總分 " << sum << "分" << endl;
    cout << "平均 " << avg << "分" << endl;
    cout << "不及格共有 " << below_60_index << "科" << endl;
    cout << "最高 " << scores[SCORE_LENGTH - 1] << "分" << endl;
    cout << "最低 " << scores[0] << "分" << endl;
}
