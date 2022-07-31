#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int hansoo(int num)
{
	int count = 0;
	if (num / 100 == 0) //두 자리 수 또는 한 자리 수
	{
		count = num;
	}

	else //세 자리 수
	{
		count = 99;
		for (int i = 100; i <=num; i++)
		{
			int c = (i % 100) % 10; //1의 자리 수
			int b = (i % 100) / 10; //10의 자리 수
			int a = i / 100; //100의 자리 수

			if (a - b == b - c) //세 숫자 사이의 간격이 일정하면 등차수열을 이루는 한수임
			{
				count++;
			}
		}
		

		
	}
	return count;


}
int main(void)
{
	int count = 0;
	int n = 0;
	cin >> n;

	int result = hansoo(n);
	cout << result;

	
}
