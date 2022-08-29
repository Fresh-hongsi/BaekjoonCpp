#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	vector<string> name;
	vector<int>age;
	vector<int>weight;

	while (1)
	{
		string N;
		int A;
		int W;

		cin >> N >> A >> W;	

		if (N == "#" && A == 0 && W == 0)
			break;

		if (A > 17 || W >= 80)
		{
			cout << N << ' ' << "Senior"<<'\n';
		}

		else
		{
			cout << N << ' ' << "Junior"<<'\n';
		}


	}

	return 0;
}
