#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
//거꾸로 답을 찾아가기
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a = 0;
	int b = 0;
	cin >> a >> b;

	int result = 0;
	
	while (1)
	{
		if (a > b)
		{
			cout << -1;
			
			break;
		}

		if (a == b)
		{
			result += 1;
			cout << result;
			break;
		}

		if (b % 10 == 1)
		{
			
			b = (b - 1) / 10;
		}

		else if (b % 2 == 0)
		{
			
			b = b / 2;
		}
		else
		{
			cout << -1;
			break;
		}
		result++;
	}

	
	return 0;

}
