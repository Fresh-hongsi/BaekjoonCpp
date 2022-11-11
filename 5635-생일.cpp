#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<pair<string, int>> students;

bool compare(pair<string, int>a, pair<string, int>b) {

	return a.second < b.second;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;

	

	string name;
	string birth;
	string day;
	string month;
	string year;

	for (int i = 0; i < n; i++)
	{
		cin >> name;
		cin >> day;
		cin >> month;
		cin >> year;

		if (day.length() == 1 && (day[0] >= 49 && day[0] <= 57))
		{
			day = '0' + day;
		}

		if (month.length() == 1 && (month[0] >= 49 && month[0] <= 57))
		{
			month = '0' + month;
		}

		birth = year + month + day;
		int birthInt = stoi(birth);

		students.push_back(pair<string, int>(name, birthInt));
	}

	sort(students.begin(), students.end(), compare);

	cout << students[n - 1].first << '\n';
	cout << students[0].first;

	return 0;
	
}
