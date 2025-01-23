#include <iostream>
#include <set>
#include <unordered_map>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

void C_yes_D_yes(string words, unordered_map<string, int> *answer)
{
    if (words.size() > 1)
    {
        (*answer)[words] += 1;
    }
    else if (words.size() == 1 && (isdigit(words[0]) == 0))
    {
        (*answer)[words] += 1;
    }
}

void C_yes_D_no(string words, unordered_map<string, int> *answer)
{
    if (words.size() > 1 && (isdigit(words[0]) == 0))
    {
        (*answer)[words] += 1;
    }
    else if (words.size() == 1 && (isdigit(words[0]) == 0))
    {
        (*answer)[words] += 1;
    }
}

void C_no_D_yes(string words, unordered_map<string, int> *answer)
{
    transform(words.begin(), words.end(), words.begin(), ::tolower);
    if (words.size() > 1)
    {
        (*answer)[words] += 1;
    }
    else if (words.size() == 1 && (isdigit(words[0]) == 0))
    {
        (*answer)[words] += 1;
    }
}

void C_no_D_no(string words, unordered_map<string, int> *answer)
{
    transform(words.begin(), words.end(), words.begin(), ::tolower);
    if (words.size() > 1 && (isdigit(words[0]) == 0))
    {
        (*answer)[words] += 1;
    }
    else if (words.size() == 1 && (isdigit(words[0]) == 0))
    {
        (*answer)[words] += 1;
    }
}

int main()
{
    int n;
    string C, D, prog;
    set<string> vocabular;
    vector<string> sort_words;
    vector<string> up_sort_words;
    unordered_map<string, int> answer;
    cin >> n >> C >> D;
    while (n != 0)
    {
        string el;
        cin >> el;
        vocabular.insert(el);
        if (C == "no")
        {
            transform(el.begin(), el.end(), el.begin(), ::tolower);
            vocabular.insert(el);
            transform(el.begin(), el.end(), el.begin(), ::toupper);
            vocabular.insert(el);
        }
        --n;
    }
    while (cin >> prog)
    {
        string temp_word = "";
        for (auto now : prog)
        {
            if (isalpha(now) || now == '_' || (isdigit(now) == 1))
            {
                temp_word += now;
            }
            else
            {
                sort_words.push_back(temp_word);
                transform(temp_word.begin(), temp_word.end(), temp_word.begin(), ::tolower);
                up_sort_words.push_back(temp_word);
                temp_word.clear();
            }
        }
        sort_words.push_back(temp_word);
        transform(temp_word.begin(), temp_word.end(), temp_word.begin(), ::tolower);
        up_sort_words.push_back(temp_word);
    }

    for (auto words : sort_words)
    {
        if (vocabular.find(words) == vocabular.end())
        {
            if (C == "yes" && D == "yes")
            {
                C_yes_D_yes(words, &answer);
            }
            if (C == "yes" && D == "no")
            {
                C_yes_D_no(words, &answer);
            }
            if (C == "no" && D == "yes")
            {
                C_no_D_yes(words, &answer);
            }
            if (C == "no" && D == "no")
            {
                C_no_D_no(words, &answer);
            }
        }
    }

    int max_count = -1;
    string max_el;
    for (auto key : answer)
    {
        if (key.second > max_count)
        {
            max_count = key.second;
            max_el = key.first;
        }
        else if (key.second == max_count)
        {
            if (C == "yes")
            {
                int index1 = find(sort_words.begin(), sort_words.end(), key.first) - sort_words.begin();
                int index2 = find(sort_words.begin(), sort_words.end(), max_el) - sort_words.begin();
                if (index1 < index2)
                {
                    max_count = key.second;
                    max_el = key.first;
                }
            }
            else
            {
                int index1 = find(up_sort_words.begin(), up_sort_words.end(), key.first) - up_sort_words.begin();
                int index2 = find(up_sort_words.begin(), up_sort_words.end(), max_el) - up_sort_words.begin();
                if (index1 < index2)
                {
                    max_count = key.second;
                    max_el = key.first;
                }
            }
        }
    }
    cout << max_el;
    return 0;
}