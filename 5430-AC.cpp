//Implementation
//Data Structure
//String
//Parsing
//Deque

#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc = 0; //테스트 케이스 수
	cin >> tc;

	while (tc--)
	{
		string cmdLine; //명령어 길이
		int dataSize; //큐에 들어갈 자료 수
		string dataLine; //자료에 대한 입력 방식
		deque<int> dq; //각 tc에 적용될 큐
		string temp = ""; //2자리수 이상의 문자열로 된 숫자를 받기 위한 임시 문자열

		int Rnum = 0; //Rnum이 홀수일 때 D 나오면 맨 뒤에서 pop, 짝수일 때 D나오면 맨 앞에서 pop
		bool flag = true; //true이면 현재 순행, false이면 역순방향이 맞다는 표시
		bool errorflag = false; //에러가 발생할 경우 이 flag 통해 error코드 출력 후 다음 tc를 받음

		cin >> cmdLine >> dataSize >> dataLine;

		if (dataSize > 0) //데이터의 개수가 1개 이상이라면
		{
			for (int i = 0; i < dataLine.length(); i++) //덱에 데이터 넣는 과정
			{
				if (dataLine[i] == '[') // [ 만나면 다시 조건 검사
				{
					continue;
				}

				else if (dataLine[i] == ',' || dataLine[i] == ']') //콤마나 [ 만나면 임시 문자열에 있던 값을 정수로 바꿔서 덱에 저장
				{
					int t = stoi(temp); 
					temp = "";
					dq.push_back(t);
				}

				else // 그 외의 임시 문자열에 문자로된 숫자 값을 문자열에 합침
				{
					temp += dataLine[i];
				}
			}

			for (int i = 0; i < cmdLine.length(); i++) //명령어 라인을 하나씩 순차적으로 실행하며 명령어처리
			{
				if (cmdLine[i] == 'R') //R만나면 Rnum개수 1 증가시키고, Rnum이 홀수라면 역순행, 짝수라면 순행 표시
				{
					Rnum++;
					if (Rnum % 2 == 1)
					{
						flag = false;
					}
					else
					{
						flag = true;
					}
				}

				if (cmdLine[i] == 'D') //D만날 시 덱이 비어있으면 에러표시, 덱이 안비어있고 순행이라면 앞에서 POP, 역행이라면 뒤에서 POP 
				{
					if (dq.empty())
					{
						cout << "error" << '\n';
						errorflag = true;
						break;
					}

					else
					{
						if (flag == true)
						{
							dq.pop_front();
						}

						if (flag == false)
						{
							dq.pop_back();
						}
					}
				}
			}

			if (errorflag == true) //데이터 개수가 양수 개일 때 에러 발생한 경우 처리-> 에러 출력하고 다음 TC받음
			{
				continue;
			}


			//정상적인 명령어였을 경우 순행, 역행인 지에 따라 데이터 방향을 달리 하여 순차적으로 출력

			if (flag == true) //순행의 경우 앞에서부터 POP해나가며 데이터 출력
			{
				int size = dq.size();
				cout << '[';
				for (int i = 0; i < size; i++)
				{

					int temp = dq.front();
					cout << temp;
					if (i != size - 1)
					{
						cout << ',';
					}
					dq.pop_front();



				}
				cout << ']' << '\n';
			}

			if (flag == false) //역행의 경우 뒤에서부터 POP해나가며 데이터 출력
			{
				int size = dq.size();
				cout << '[';
				for (int i = 0; i < size; i++)
				{

					int temp = dq.back();
					cout << temp;
					if (i != size - 1)
					{
						cout << ',';
					}
					dq.pop_back();



				}
				cout << ']' << '\n';
			}
		}

		else //만약 데이터 개수가 0개로 시작했으면
		{
			bool noD = true; //D이라는 명령어가 있는 지 없는 지에 대한 flag

			for (int i = 0; i < cmdLine.size(); i++) //만약 하나라도 D라는 명령어가 있었다면 빈 덱에서 POP하려고 하는 경우이므로 ERROR처리 해줘야함
			{
				if (cmdLine[i] == 'D')
				{
					cout << "error\n";
					noD = false; //D가 있으므로 noD는 false처리
					break;
				}

				
			}

			if (noD==true) //이 경우는 R밖에 없었던 경우이므로 빈 덱 출력
			{
				cout << "[]\n";
				
			}
			
		}
		



	}
}

