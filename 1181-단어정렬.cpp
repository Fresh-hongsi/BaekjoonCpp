#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(string s1, string s2)
{
	if (s1.length() != s2.length()) //길이가 다르다면
		return s1.length() < s2.length(); //길이에 대한 오름차순 정렬

	else //길이가 같다면
	{
		return s1 < s2; //사전식 정렬
	}
	


}

int main(void)
{
	int n = 0;
	cin >> n;

	string arr[20000];

	int i = 0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		
	}

	sort(arr, arr+n, compare);

	for (int k = 0; k < n; k++)
	{
		if (arr[k] == arr[k - 1]) //혹시나 중복되는 요소가 있다면 출력 따로 안함
		{
			continue;
		}
		cout << arr[k] << endl;
	}
}
