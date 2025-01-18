#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int N;
    map<string,string> vocabulary;
    string find_word;
    cin >> N;
    while( N != 0 )
    {
        string word_first, word_second;
        cin >> word_first >> word_second;
        vocabulary[word_first] = word_second;
        vocabulary[word_second] = word_first;
        --N;
    }
    cin >> find_word;
    cout << vocabulary[find_word];
    return 0;
}