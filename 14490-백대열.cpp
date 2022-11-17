#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int gcd(int a, int b)
{
	int smaller = min(a, b);
	int result = 0;
	for (int i = 1; i <= smaller; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			result = i;
		}
	}

	return result;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string temp;

	cin >> temp;
	int partitionIdx = 0;
	for (int i = 0; i < temp.length(); i++)
	{
		
		if (temp[i] == ':')
		{
			partitionIdx = i;
		}

		



	}
	
	string a;
	string b;
	int input1 = 0;
	int input2 = 0;


	for (int i = 0; i < partitionIdx; i++)
	{
		a += temp[i];
	}

	for (int i = partitionIdx + 1; i < temp.length(); i++)
	{
		b += temp[i];
	}

	input1 = stoi(a);
	input2 = stoi(b);

	int gcd1 = gcd(input1, input2);

	int output1 = input1 / gcd1;
	int output2 = input2 / gcd1;


	cout << output1 << ':' << output2;

	return 0;

}
