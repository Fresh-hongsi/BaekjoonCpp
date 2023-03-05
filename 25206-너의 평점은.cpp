#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

double solveGrade(string g)
{
	if (g == "A+")
	{
		return 4.5;
	}

	else if (g == "A0")
	{
		return 4.0;
	}

	else if (g == "B+")
	{
		return 3.5;
	}

	else if (g == "B0")
	{
		return 3.0;
	}

	else if (g == "C+")
	{
		return 2.5;
	}

	else if (g == "C0")
	{
		return 2.0;
	}

	else if (g == "D+")
	{
		return 1.5;
	}

	else if (g == "D0")
	{
		return 1.0;
	}

	else if (g == "F")
	{
		return 0;
	}

	else
	{
		return -1.0;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	double counter=0;
	double total=0;

	for (int i = 0; i < 20; i++)
	{
		string subject;
		double credit;
		string grade;

		cin >> subject >> credit >> grade;

		double gradePoint = solveGrade(grade);

		if (gradePoint == -1)
		{
			continue;
		}

		else
		{
			counter += credit;
			total += (credit * gradePoint);
		}
	}

	cout << total / counter;
	return 0;


}
