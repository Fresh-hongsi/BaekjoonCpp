//Brute-Force

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int num = 0; //연산 대상이 되는 수의 개수
vector<int> number; //연산 대상이 되는 수를 담을 벡터
vector<int> operation; //연산자의 개수를 담을 벡터
vector<string> op; //가능한 모든 연산 순서를 저장할 벡터 (0:+ , 1:- , 2:* , 3:/)
vector<int> result; //가능한 모든 연산을 적용했을 때 그 때의 값을 저장할 벡터

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> num;

	for (int i = 0; i < num; i++) //피연산자 입력받음
	{
		int temp = 0;
		cin >> temp;

		number.push_back(temp);
	}

	for (int i = 0; i < 4; i++) //연산자 입력받음
	{
		int temp = 0;
		cin >> temp;

		operation.push_back(temp);
	}

	string opCode = ""; //가장 첫번쨰로 연산될 코드를 만들어냄
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < operation[i]; j++)
		{
			opCode += to_string(i);
		}
	}

	do //연산될 코드를 바탕으로 순열을 만듦으로써 모든 연산코드를 만들어 op란 배열에 저장함
	{
		op.push_back(opCode);
	} while (next_permutation(opCode.begin(), opCode.end()));


	//모든 연산코드를 적용시켜보는 과정
	for (int i = 0; i < op.size(); i++)
	{
		string curOp = op[i]; //현재 사용될 연산코드
		int curResult = number[0]; //한 연산코드에 대응하는 결과값

		for (int j = 0; j < curOp.length(); j++)
		{
			if (curOp[j] == '0') //현재 연산코드의 인덱스에 해당하는 값이 0이라면 +하기
			{
				curResult += number[j + 1];
			}

			else if (curOp[j] == '1') //현재 연산코드의 인덱스에 해당하는 값이 1이라면 -하기
			{
				curResult -= number[j + 1];
			}

			if (curOp[j] == '2') //현재 연산코드의 인덱스에 해당하는 값이 2이라면 *하기
			{
				curResult *= number[j + 1];
			}

			if (curOp[j] == '3') //현재 연산코드의 인덱스에 해당하는 값이 3이라면 /하기
			{
				curResult /= number[j + 1];
			}
		}

		result.push_back(curResult); //계산된 결과값을 result배열에 저장
	}

	sort(result.begin(), result.end()); //result배열에 저장된 값을 정렬
	cout << result[op.size() - 1] << '\n'; //최대값
	cout << result[0]; //최소값
	
	return 0;

}
