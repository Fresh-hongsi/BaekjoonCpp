#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;


int N = 0;
map<string,int,greater<string>> m; //key기준 내림차순 정렬
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		
		string name;
		cin >> name;

		string work;
		cin >> work;
		
		if (work == "enter")
		{
			m.insert({ name, i });
		}

		if (work == "leave")
		{
			m.erase(name);
		}
		
		
	}

	for (auto iter : m)
	{
		cout << iter.first << '\n';
	}

	return 0;




}
