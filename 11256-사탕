#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool compare(int i, int j) //내림차순 정렬 비교 함수
{
	return i > j;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc = 0;
	cin >> tc;

	while (tc--)
	{
		int candy = 0;
		int box = 0;
		cin >> candy >> box;

		vector<int> boxSises; //가로 세로 곱한 박스 크기 저장할 배열
		while (box--)
		{
			int height = 0;
			int width = 0;
			cin >> height >> width;
			int size = height * width;
			boxSises.push_back(size);
		}

		sort(boxSises.begin(), boxSises.end(),compare); //박스 크기 내림차순 정렬

		int result = 0;//필요한 박스의 개수
		int i = 0; //박스 순회 시 필요한 변수

		while (candy > 0) //캔디가 0이하인 경우 더이상 반복문 진행할 필요가 없음
		{
			
			candy -= boxSises[i]; //캔디 수 해당 박스에 들어가는 개수만큼 빼주기
			i++; //다음 박스 순회를 위해 i값 1증가
			result++; //사용한 박스 개수 1 증가
		}

		cout << result << '\n';

		
		
	}
}
