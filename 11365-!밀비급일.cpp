#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1)
	{
		vector<string> plan;
		string temp;
		string t;
		getline(cin, temp);
		
		if (temp == "END")
			break;
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == ' ')
			{
				reverse(t.begin(), t.end());
				plan.push_back(t);
				t = "";
			}

			else
			{
				t += temp[i];
			}
		}
		reverse(t.begin(), t.end());
		plan.push_back(t);


		for (int i = plan.size()-1; i >=0 ; i--)
		{
			cout << plan[i] << ' ';
		}
		cout << '\n';



	}
	return 0;
}
