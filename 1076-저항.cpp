#include <iostream>
#include <string>
#include <utility>
#include <cmath>
using namespace std;

int main(void)
{
	
	string first;
	string second;
	string third;
	int one;
	int two;
	int three;

	cin >> first >> second >> third;

	if (first == "black")
	{
		 one = 0;
	}

	else if (first == "brown")
	{
		one = 1;
	}
	else if (first == "red")
	{
		one = 2;
	}
	else if (first == "orange")
	{
		one = 3;
	}
	else if (first == "yellow")
	{
		one = 4;
	}
	else if (first == "green")
	{
		one = 5;
	}
	else if (first == "blue")
	{
		one = 6;
	}
	else if (first == "violet")
	{
		one = 7;
	}
	else if (first == "grey")
	{
		one = 8;
	}
	else if (first == "white")
	{
		one = 9;
	}




	if (second == "black")
	{
		two = 0;
	}

	else if (second == "brown")
	{
		two = 1;
	}
	else if (second == "red")
	{
		two = 2;
	}
	else if (second == "orange")
	{
		two = 3;
	}
	else if (second == "yellow")
	{
		two = 4;
	}
	else if (second == "green")
	{
		two = 5;
	}
	else if (second == "blue")
	{
		two = 6;
	}
	else if (second == "violet")
	{
		two = 7;
	}
	else if (second == "grey")
	{
		two = 8;
	}
	else if (second == "white")
	{
		two = 9;
	}



	if (third == "black")
	{
		three = 0;
	}

	else if (third == "brown")
	{
		three = 1;
	}
	else if (third == "red")
	{
		three = 2;
	}
	else if (third == "orange")
	{
		three = 3;
	}
	else if (third == "yellow")
	{
		three = 4;
	}
	else if (third == "green")
	{
		three = 5;
	}
	else if (third == "blue")
	{
		three = 6;
	}
	else if (third == "violet")
	{
		three = 7;
	}
	else if (third == "grey")
	{
		three = 8;
	}
	else if (third == "white")
	{
		three = 9;
	}
	
	
	pair<int, long long> p[10];

	for (int i = 0; i <= 9; i++)
	{
		p[i].first = i;
		p[i].second =(long long) pow(10,i); //지수 계산 -> 자료형 pow로 변환
	}

	//출력값 계산;
	int sum = one * 10 + two;
	long long result = sum * p[three].second;
	cout << result;

	return 0;
	

	
	
}
