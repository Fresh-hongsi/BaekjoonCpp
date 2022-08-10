//math
//implementation
//brute-force
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	int ans = 0;
	
	for (int i = 1; i <= n; i++)
	{
		string s = to_string(i);
		bool flag = false; //금민수일 조건은 flag값이 false일 때임

		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '4' || s[j] == '7') //4거나 7이면 다음 인덱스 문자열 조사
			{
				continue;
			}

			else //만약 이외의 문자가 있다면 true처리하고 반복문 탈출
			{
				flag = true;
				break;
			}
			

		}

		if (flag == false) //최종 결과가 false였을 때만 금민수 처리
		{
			ans = i;
		}
	}

	cout << ans;
	return 0;
}
