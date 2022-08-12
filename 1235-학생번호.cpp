//String
//Implementation

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0; //학생 수
	cin >> n;
	int sizeOfnum = n; //학생 수 복사
	vector<string> students;

	while (n--) //학생 번호를 students배열에 입력받아 저장
	{
		string temp;
		cin >> temp;
		students.push_back(temp);
	}

	int k = 1;
	int startIndex = students[0].length() - 1; //학생 번호의 마지막 인덱스
	vector<string> tester(sizeOfnum,""); //학생 번호의 마지막 인덱스로부터 현재 인덱스까지 문자열을 합쳐서 저장해 겹치는 게 있는 지 확인할 용도의 string 배열

	bool flag = false; //flag가 true가 되면 겹치는 값이 있다는 것임

	for (int i = startIndex; i >= 0; i--)
	{
		flag = false;

		for (int j = 0; j < students.size(); j++) //현재 인덱스까지 문자를 합쳐봄
		{

			tester[j] += students[j][startIndex];
			
		}

		vector<string> copy = tester;
		sort(copy.begin(), copy.end());

		for (int j = 0; j < tester.size()-1; j++)
		{
			if (copy[j] == copy[j + 1])
			{
				startIndex--;
				k++;
				flag = true;
				break;
			}
		}

		if (flag == false)
		{
			cout << k;
			break;
		}
	}
	

	return 0;
}
