//Data Structure
//Vector
//Map
//Sorting
//String

//stl map 자료형 가지고는 sort함수 사용 불가하므로 vector에 값을 옮겨놓고 정렬해야함!!!!!

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool comp(pair<string, int> a, pair<string, int>b)
{
	if (a.second == b.second) //만약 팔린 책 개수가 같다면 사전식 순서로 정렬
	{
		return a.first < b.first;
	}

	else //팔린 책 개수가 다르다면 팔린 개수가 많은 순서로 정렬
	{
		return a.second > b.second;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	int N = 0;
	cin >> N;

	map<string, int> board;

	for (int i = 0; i < N; i++)
	{
		string bookName;
		cin >> bookName;

		board[bookName]++;
	}

	vector<pair<string, int>> vectorCopy(board.begin(), board.end()); //벡터에 map값 복사해서 초기화
	sort(vectorCopy.begin(), vectorCopy.end(), comp); //vector기반 정렬

	cout << vectorCopy[0].first;
	
	
	
	return 0;
}
