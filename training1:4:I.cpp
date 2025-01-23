#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main()
{

    int n, mistakes = 0;
    set<string> vocabulary;
    set<string> up_vocabulary;
    string piter_word, voc;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> voc;
        string temp_voc = voc;
        transform(temp_voc.begin(), temp_voc.end(), temp_voc.begin(), ::toupper);
        vocabulary.insert(voc);
        up_vocabulary.insert(temp_voc);
    }

    while (cin >> piter_word)
    {
        string temp = piter_word;
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (vocabulary.find(piter_word) == vocabulary.end())
        {
            int big_let = 0;
            for (auto letters : piter_word)
            {
                if (letters >= 'A' && letters <= 'Z')
                {
                    ++big_let;
                }
            }
            if (big_let != 1)
            {
                ++mistakes;
            }
            else if (big_let == 1 && (up_vocabulary.find(temp) != up_vocabulary.end()))
            {
                ++mistakes;
            }
        }
    }

    cout << mistakes;
    return 0;
}