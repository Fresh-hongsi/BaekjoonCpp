//Implementation
//String

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<bool>>arr(8, vector<bool>(8, 0)); //일단 전체 체스판 모두 검은칸으로 색칠

//하얀칸: 0
//검은칸: 1
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int counter = 0; //하얀칸에 있는 말의 개수

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 1) //i+j가 짝수이면 하얀칸임
			{
				arr[i][j] = true;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < 8; j++)
		{
			if (temp[j] == 'F' && arr[i][j] == false) //말이 있고 하얀칸이라면 값 증가
			{
				counter++;
			}

			
		}
	}

	cout << counter << '\n';
	return 0;

}
