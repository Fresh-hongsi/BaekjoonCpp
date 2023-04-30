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

	
	double total = 0;

	while (1)
	{
		string s;
		cin >> s;

		
		if (s == "EOI")
		{
			break;
		}

		if (s == "Paper")
		{
			total += 57.99;
		}

		else if (s == "Printer")
		{
			total += 120.50;
		}

		else if (s == "Planners")
		{
			total += 31.25;
		}

		else if (s == "Binders")
		{
			total += 22.50;
		}

		else if (s == "Calendar")
		{
			total += 10.95;
		}

		else if (s == "Notebooks")
		{
			total += 11.20;
		}

		else if (s == "Ink")
		{
			total += 66.95;
		}

		


	}

	cout << "$" << total << endl;
	return 0;
}
