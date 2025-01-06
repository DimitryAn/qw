#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, n, m, min1,min2,max1,max2;
    cin >> a >> b >> n >> m;
    min1 = n + a * (n-1);
    max1 = n + a * (n-1) + 2*a ;
    min2 = m + b * (m-1);
    max2 = m + b * (m-1) + 2*b ;
    int mint = max(min1, min2);
    int maxt = min(max1, max2);
    if ( maxt < mint )
    {
        cout << -1;
        return 0;
    }
    cout << mint << " " << maxt;
    return 0;
}