#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> call;
	int N = 0; //통화 수
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		call.push_back(temp);
	}

	int ys=0; //영식 요금제로 했을 떄의 요금
	int ms=0; //민식 요금제로 했을 떄의 요금

	for (int i = 0; i < N; i++)
	{
		int ysTemp = ((call[i] / 30) + 1) * 10;
		int msTemp = ((call[i] / 60) + 1) * 15;

		ys += ysTemp;
		ms += msTemp;
	}

	if (ys < ms)
	{
		cout << 'Y' << ' ' << ys;
	}

	else if (ys > ms)
	{
		
		cout << 'M' << ' ' << ms;
	}

	else
	{
		cout << 'Y' << ' ' <<'M'<<' ' << ys << '\n';
		
	}

	return 0;
}
