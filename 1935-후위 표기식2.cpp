#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//입력 값들 입력
	vector<double> arr;
	string str;
	int n = 0;
	cin >> n;
	cin >> str;
	stack<double> st;
	for (int i = 0; i < n; i++)
	{
		double temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}


	//str의 문자를 하나씩 보면서 연산자 또는 피연산지를 구분해서 stack에서 할 작업 정리
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '*') //곱하기 연산자가 나온 경우, 스택에서 두개 뽑고, 연산 후 결과를 다시 스택에 삽입
		{
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();

			double c = b * a;
			st.push(c);


		}

		else if (str[i] == '/') //나누기 연산자가 나온 경우, 스택에서 두개 뽑고, 연산 후 결과를 다시 스택에 삽입
		{
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();

			double c = b / a;
			st.push(c);
		}

		else if (str[i] == '+') //더하기 연산자가 나온 경우, 스택에서 두개 뽑고, 연산 후 결과를 다시 스택에 삽입
		{
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();

			double c = b + a;
			st.push(c);

		}

		else if (str[i] == '-') //뺴기 연산자가 나온 경우, 스택에서 두개 뽑고, 연산 후 결과를 다시 스택에 삽입
		{
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();

			double c = b - a;
			st.push(c);

		}

		else //피연산자인 경우, arr에 있는 해당 값을 찾아 스택에 넣어준다.
		{
			st.push(arr[str[i] - 65]);
		}
	}

	//소수점 두자리까지 출력
	cout << fixed;
	cout.precision(2);
	cout << st.top();
	st.pop();
	return 0;
}
