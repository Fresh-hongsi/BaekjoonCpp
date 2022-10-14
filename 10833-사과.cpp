#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> student;
	vector<int> apple;

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int st = 0;
		int app = 0;

		cin >> st >> app;
		student.push_back(st);
		apple.push_back(app);


	}


	int totalRemain = 0;

	for (int i = 0; i < N; i++)
	{
		int quotient = apple[i] / student[i];
		int remain = apple[i]-quotient * student[i];
		totalRemain+=remain;
	}

	cout << totalRemain;
	return 0;
}
