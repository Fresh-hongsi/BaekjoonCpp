#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N; //대상이 되는 수 입력

	int F = 0;
	cin >> F; //나누는 수 입력

	int num_2 = (N % 100) / 10; //10의 자리수 숫자
	int num_1 = (N % 10); //1의 자리수 숫자

	
	

	for (int i = 0; i <= 99; i++)
	{
		int	temp_n = N - ((num_2 * 10) + num_1); //temp_n은 N수의 뒤에 두 자리수를 0으로 만듦
		
		temp_n += i; //1씩 증가시켜보면서 나눌 수 있는 지 확인

		if (temp_n % F == 0) //만약 나눌 수 있다면
		{
			if (i >= 0 && i <= 9) //한자리 수로 끝나면 0붙여야함
			{
				cout << '0' << i << endl;
				break; //최소 수 찾았으므로 탈출
			}

			cout << i << endl; //한자리 수가 아니면 그냥 출력
			break; //최소 수 찾았으므로 탈출
		}
	}

	return 0;

}
