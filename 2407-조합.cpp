#include <iostream>
#include <string>
#include <algorithm> // reverse 함수

using namespace std;

int n, m;
string factorial[101][101];

string bigNumAdd(string n1, string n2)
{
    int sum = 0;
    string result;

    while (sum || !n1.empty() || !n2.empty())
    {
        if (!n1.empty())
        {
            sum += n1.back() - '0';
            n1.pop_back();
        }

        if (!n2.empty())
        {
            sum += n2.back() - '0';
            n2.pop_back();
        }

        result.push_back((sum % 10) + '0');
        sum /= 10; //carry
    }

    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int r)
{
    if (n == r || r == 0)
        return "1";
    string& result = factorial[n][r];

    if (result != "")
    {
        return result;
    }
    else
    {
        result = bigNumAdd(combination(n - 1, r - 1), combination(n - 1, r));
        factorial[n][r] = result;
        return result;
    }
}



int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;
    // 조합 구하기
    cout << combination(n, m);

    return 0;
}
