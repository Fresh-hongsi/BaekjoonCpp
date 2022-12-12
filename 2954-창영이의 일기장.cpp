#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
	string diary;
	getline(cin, diary);

	for (int i = 0; i < diary.length(); i++)
	{
		if (diary[i] == 'a' || diary[i] == 'i' || diary[i] == 'u' || diary[i] == 'e' || diary[i] == 'o')
		{
			cout << diary[i];
			i += 2;
			continue;
		}
		else
		{
			cout << diary[i];
		}
	}
	cout << endl;
	return 0;
}
