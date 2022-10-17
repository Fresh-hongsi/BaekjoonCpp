#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);


	int N = 0;
	cin >> N;
	cin.ignore(); //버퍼 비우기
	vector<string> arr;

	for (int i = 1; i <= N; i++)
	{
		string temp;
		getline(cin, temp);
		arr.push_back(temp);
	}

	for (int i = 0; i < N; i++)
	{
		cout << i + 1 << ". " << arr[i]<<'\n';
	}

	return 0;
}
