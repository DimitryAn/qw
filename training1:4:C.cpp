#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

map<string, int> read_data(map<string, int> words)
{   
    string el_from_text;
    while( cin >> el_from_text )
    {
        if( words.find(el_from_text) == words.end() )
        {
            words[el_from_text] = 0;
        }
        words[el_from_text] +=1;
    }
    return words;
}

int find_max_length (map<string, int> words)
{
    int max_count_meet = 0;
    for ( auto key : words )
    {
        if( words[key.first] > max_count_meet)
        {
            max_count_meet = words[key.first];
        }
    }
    return max_count_meet;
}

string find_lexicographic_order(map<string, int> words, int max_count_meet)
{   
    vector<string> order;
    for( auto key : words )
    {
        if( words[key.first] == max_count_meet )
        {
            order.push_back(key.first);
        }
    }
    sort(begin(order), end(order) );
    string answer = order[0];
    return answer;
}



int main()
{
    map<string, int> words; 
    int max_count_meet;
    words = read_data(words);
    max_count_meet = find_max_length(words);
    cout << find_lexicographic_order(words, max_count_meet);
    return 0;
}
