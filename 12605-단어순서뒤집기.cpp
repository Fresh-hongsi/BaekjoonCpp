#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc = 0;
	cin >> tc;
	cin.ignore();
	for (int i = 1; i <= tc; i++)
	{
		string statement;
		getline(cin, statement);
		
		vector<string> arr;
		string voca;

		for (int j = 0; j < statement.length(); j++)
		{
			if (statement[j] == ' ')
			{
				arr.push_back(voca);
				voca = "";
			}

			else
			{
				voca += statement[j];
			}
		}

		arr.push_back(voca);

		cout << "Case #" << i << ": ";
		for (int j = arr.size()-1; j >=0; j--)
		{
			cout << arr[j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
