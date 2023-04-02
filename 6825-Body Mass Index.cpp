#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	double height;
	double weight;

	cin >> weight >> height;

	double bmi = weight / (height * height);

	if (bmi > 25)
	{
		cout << "Overweight";
	}

	else if (bmi >= 18.5 && bmi <= 25.0)
	{
		cout << "Normal weight";
	}

	else
	{
		cout << "Underweight";
	}

	return 0;

}
