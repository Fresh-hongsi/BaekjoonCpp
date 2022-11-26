#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    
    int a = 300;
    int b = 60;
    int c = 10;

    int total = 0;
    cin >> total;

    if (total % c != 0)
    {
        cout << "-1" << '\n';
        return 0;
    }

   
    int anum = total / a;
    total = total - (anum * a);

    int bnum = total / b;
    total = total - (bnum * b);

    int cnum = total / c;
    total = total - (cnum * c);
    

    cout << anum << ' ' << bnum << ' ' << cnum;



    return 0;


}
