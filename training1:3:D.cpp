#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string text, words = "";
    set<string> unique_words_from_text;

    while (getline(cin, text))
    {
        for (auto now : text)
        {
            if (now != ' ')
            {
                words += now;
            }
            else
            {
                unique_words_from_text.insert(words);
                words.clear();
            }
        }
        if (words != " " && words != "\0")
        {
            unique_words_from_text.insert(words);
        }

        words.clear();
    }

    cout << unique_words_from_text.size();

    return 0;
}