#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int ar;
	int ac;

	int br;
	int bc;

	cin >> ar >> ac;

	int arr1[100][100]={0,};
	int arr2[100][100] = { 0, };
	int arr3[100][100] = { 0, };
	for (int i = 0; i < ar; i++)
	{
		for (int j = 0; j < ac; j++)
		{
			cin >> arr1[i][j];

		}
	}


	cin >> br >> bc;
	for (int i = 0; i < br; i++)
	{
		for (int j = 0; j < bc; j++)
		{
			cin >> arr2[i][j];

		}
	}

	for (int i = 0; i < ar; i++)
	{
		for (int j = 0; j < bc; j++)
		{
			for (int k = 0; k < ac; k++)
			{
				arr3[i][j] += (arr1[i][k] * arr2[k][j]);
			}
		}
	}

	for (int i = 0; i < ar; i++)
	{
		for (int j = 0; j < bc; j++)
		{
			cout << arr3[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;


}
