#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	

	int n = 0;
	cin >> n;

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		
		stack<char> st;

		
		for (int j = 0; j < s.length(); j++)
		{
			if (st.empty()) //스택이 빈 경우
			{
				st.push(s[j]);
			}

			
			else //스택에 뭐라도 있는 경우
			{
				char top = st.top(); //가장 상단 알파벳 체크
				
				if (s[j] == top) //스택에 넣으려고 하는 것과 top이 같은 경우
				{
					st.pop(); //스택에서 쌍 제거
				}

				else //그 외의 경우 스택에 넣기
				{
					st.push(s[j]);
				}
			}
		}

		if (st.empty()) //만약 스택에 아무것도 남지 않았다면 성공
		{
			result++;
			
		}

		

	}

	cout << result;
	return 0;
}
