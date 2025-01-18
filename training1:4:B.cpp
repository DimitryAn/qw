#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> words; 
    string word_from_text;
    while(cin >> word_from_text)
    {
        if( words.find(word_from_text) == words.end() )
        {   
            cout << 0 << " ";
            words[word_from_text] = 1;
        }
        else if ( words.find(word_from_text) != words.end() )
        {
            cout << words[word_from_text] << " ";
            words[word_from_text] += 1;
        }
    }
    return 0;
}
