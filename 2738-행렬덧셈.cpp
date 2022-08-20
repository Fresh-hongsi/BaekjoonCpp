#include <iostream>
#include <vector>
using namespace std;

int arr1[100][100] = { 0, };
int arr2[100][100] = { 0, };


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int M = 0;

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp = 0;
			cin >> temp;
			arr1[i][j] = temp;
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp = 0;
			cin >> temp;
			arr2[i][j] = temp;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp = 0;
			temp = arr1[i][j] + arr2[i][j];
			arr1[i][j] = temp;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			
			cout<<arr1[i][j]<<' ';
		}
		cout << '\n';
	}
}
