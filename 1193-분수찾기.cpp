//Math
//Implementation

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	
	int input = 0;
	cin >> input;
	

	bool flag = false; //false: 아래, 분모고정 / true: 위, 분자고정


	int i = 1;
	while (input >= 0)
	{
		if ((input - i) > 0) //한번더 다음항 계산
		{
			input -= i; //input값을 계속 감소시키며 진행
			i++;
			flag = (!flag); //계속해서 토글시킴
		}

		else if ((input - i) == 0) //끝항에 걸릴 경우는 특수한 경우
		{
			if (flag == true)
			{
				int sum = i + 1;
				cout << i << '/' << sum - i;
				break;
			}
			

			else 
			{
				int sum = i + 1;
				cout << sum - i << '/' << i;
				break;

			}
		}

		else if ((input - i) < 0) //항 계산 //그 외의 경우는 분자고정, 분모고정 기법 통해 분자든 분모든 알아냄
		{
			if (flag == true) //만약 대각선 위방향이라면-> 분자고정
			{
				int sum = i + 1;
				cout << input << '/' << sum-input; 
				break;
			}

			else //만약 대각선 아래방향이라면-> 분모고정
			
			{
				int sum = i + 1;
				cout << sum-input << '/' << input;
				break;
			}
		}
	}
}
