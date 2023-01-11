#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	unsigned int s = 0;

	cin >> s;
	long long curSum = 0;
	int counter = 0;
	int num = 1;

	while (1)
	{
		curSum += num;
		counter++;

		if (curSum > s) //이 부분이 중요! 계속 더해나간 curSum은 num을 1에서부터 1씩 증가해나가며 갔음
			//만약 curSum이 s보다 커지는 순간, 그 차액크기만큼의 수는 반드시 반복해서 더해나간 num중 하나일 수밖에 없으므로 curSum을 s로 만들수밖에 없음. 그때 기존에 더해나갔던 num을 하나 빼주면 되므로 counter값 1 빼주고 반복문 탈출
		{
			counter--;
			break;
		}

		num++;
	}

	cout << counter;
	return 0;
}
