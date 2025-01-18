#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n,k;
    vector <int> count_click;
    map<int,int> user_tab;
    cin >> n;
    while( n != 0 )
    {
        int c;
        cin >> c;
        count_click.push_back(c);
        --n;
    }
    cin >> k;
    while ( k !=0 )
    {
        int p;
        cin >> p;
        if ( user_tab.find(p) == user_tab.end() )
        {
            user_tab[p] = 0;
        }
        user_tab[p] +=1;
        --k;
    }

    int i = 0;
    for ( auto key : user_tab )
    {
        if(user_tab[key.first] > count_click[i] )
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        ++i;
    }

    return 0;
}
