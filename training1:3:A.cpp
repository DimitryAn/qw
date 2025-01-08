#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    set<int> numbers;
    while (cin >> n)
    {
        numbers.insert(n);
    }
    cout << numbers.size();
    return 0;
}