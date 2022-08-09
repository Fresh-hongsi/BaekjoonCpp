//math
//string
//greedy
//parsing


#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string expression; 
	cin >> expression; //수식 입력받음

	

	vector<int> number; //숫자를 순서에 따라 저장할 벡터
	vector<char> op; //연산자를 순서에 따라 저장할 벡터
	string num; //문자열로 된 숫자를 숫자 벡터에 넣기 전에 int형으로 바꿔주기 위해 필요한 string변수

	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '+' || expression[i] == '-') //수식 문자열의 해당 인덱스에 +또는 -가 들어있다면
		{
			op.push_back(expression[i]); //연산자 벡터에 push back
			int n = stoi(num); //지금까지 앞에 담아뒀던 숫자 문자열을 int형 숫자 n으로 변환
			number.push_back(n); //n을 숫자 벡터에 넣어줌
			num = ""; //다시 숫자 문자열을 빈 string으로 만들어줌
		}

		else //그 외의 경우는 반드시 숫자로 된 문자가 있으므로 num string에 문자 추가해나가면 됨
		{
			num += expression[i];
		}


	}
	
	int n = stoi(num); //마지막 숫자로 된 문자열을 int형 숫자 n으로 바꿔줌
	number.push_back(n); //숫자배열에 n push back
	bool flag = false; //만일 앞 연산이 -이면 true로 변환. +앞에 하나라도 -가 있으면 그 뒤에 나오는 +는 다 -화 시켜줘야함

	int result = number[0]; //초기 결과값은 숫자배열의 첫번째 인덱스

	for (int i = 0; i < number.size() - 1; i++) //수식을 순회하며 결과값 도출해내는 반복문
	{
		int front = result; //앞의 피연산자
		int back = number[i + 1]; //뒤의 피연산자
		
		if (op[i] == '-') //만약 연산자가 -라면
		{
			flag = true; //flag를 true로 만들어줘 뒤에 나오는 +를 다 -연산하게 만들 것
			result = result - back; //-연산
		}

		if (op[i] == '+') //만약 연산자가 +라면
		{
			if (flag == true) //앞에 -연산자가 하나라도 있었다면 뒤 +연산자는 다 -처리
			{
				result = result - back;
			}

			else //만일 앞에 하나도 -연산자가 없었다면 +연산 진행
			{
				result = result + back;
			}

			
		}

	}

	cout << result; //결과값 출력
	return 0;
}
