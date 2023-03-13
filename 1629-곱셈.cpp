#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//분할정복을 이용한 거듭제곱
// C^n일 경우
//n이 짝수 -> C^(n/2) * C^(n/2)
//n이 홀수 -> C^(n/2의 몫) * C^(n/2의 몫)* C


long long func(long long a1, long long b1, long long c1)
{
	long long x;

	if (b1 == 1)
	{
		return a1;
	}

	else
	{
		x=(func(a1, b1/2, c1))%c1;
	}

	if (b1 % 2 == 0) //b1이 짝수였다면  C^(n/2) * C^(n/2)
	{
		return ((x%c1)*(x%c1))%c1;
	}

	else //b1이 홀수였다면 C^(n/2의 몫) * C^(n/2의 몫)* C
	{
		return ((((x % c1) * (x % c1))%c1)*(a1%c1)) % c1;
	}


}
int main(void)
{
	long long a = 0; //밑
	long long b = 0; //지수
	long long c = 0; //나눠줄 수

	cin >> a >> b >> c;

	long long result = func(a, b, c)%c;
	cout << result;
	return 0;
}
