#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int pay = 0; //내야할 돈
	cin >> pay;

	int change = 1000 - pay; //거스름돈

	//큰 돈부터 빼나가면서 거스름돈 0이 될 때의 동전 개수를 세면 됨
	int count = 0;

	while (change != 0)
	{
		//500으로 나눌 수 있다면 그 몫만큼 count증가, change값 제거
		if (change / 500 != 0)
		{
			int temp = change / 500;
			change -= (temp * 500);
			count += temp;
			continue;
		}

		//100으로 나눌 수 있다면 그 몫만큼 count증가, change값 제거
		if (change / 100!=0)
		{
			int temp = change / 100;
			change -= (temp * 100);
			count += temp;
			continue;
		}

		//50으로 나눌 수 있다면 그 몫만큼 count증가, change값 제거
		if (change / 50 != 0)
		{
			int temp = change / 50;
			change -= (temp * 50);
			count += temp;
			continue;
		}

		//10으로 나눌 수 있다면 그 몫만큼 count증가, change값 제거
		if (change / 10 != 0)
		{
			int temp = change / 10;
			change -= (temp * 10);
			count += temp;
			continue;
		}

		//5로 나눌 수 있다면 그 몫만큼 count증가, change값 제거
		if (change / 5 != 0)
		{
			int temp = change / 5;
			change -= (temp * 5);
			count += temp;
			continue;
		}

		//1로 나눌 수 있다면 그 몫만큼 count증가, change값을 제거
		if (change / 1 != 0)
		{
			int temp = change / 1;
			change -= (temp * 1);
			count += temp;
			continue;
		}
		
	}

	cout << count << endl;
}
