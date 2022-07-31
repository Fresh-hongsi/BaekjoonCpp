//DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int counter0 = 0;
//int counter1 = 0;

long long counter0[41] = { 1,0, }; //0 함수 부르는 개수 저장할 배열
long long counter1[41] = { 0,1 }; //1함수 부르는 개수 저장할 배열



int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 0;
    cin >> t;

    int n = 0;

    while (t--)
    {
        cin >> n;
        
        if (n == 0) //초기세팅
        {
            cout << '1' << ' ' << '0'<<endl;
        }

        else if (n == 1) //초기 세팅
        {
            cout << '0' << ' ' << '1'<<endl;
        }

        else //규칙 활용한 점화식
        {
            for (int i = 2; i <= n; i++)
            {
                counter0[i] = counter0[i - 1] + counter0[i - 2];
                counter1[i] = counter1[i - 1] + counter1[i - 2];
            }

            cout << counter0[n] << ' ' << counter1[n] << endl;
        }
       
    }

    return 0;
}


