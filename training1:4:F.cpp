#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main ()
{
    string consumer, product; 
    long number;
    map<string, map<string,int> > list;
    while( cin >> consumer >> product)
    {
        cin >> number;
        list[consumer][product] += number;
    }


    for ( auto key : list )
    {
        cout << key.first << ":" << endl;
        for ( auto key2 : key.second )
        {   
           cout << key2.first << " " << key2.second << endl;
           
        }
    }
    return 0;
}