#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

vector<string> list_everyone_know_language(multiset<vector<string> > students_language, int N)
{
    int count_everyone = 0;
    vector<string> every_one_know, min_know;
    for (auto now : students_language)
    {
        min_know = now;
        break;
    }

    for (auto el : min_know)
    {
        for (auto now : students_language)
        {
            for (auto temp : now)
            {
                if (el == temp)
                {
                    ++count_everyone;
                }
            }
        }
        if (count_everyone == N)
        {
            every_one_know.push_back(el);
        }
        count_everyone = 0;
    }
    return every_one_know;
}

void do_cout(vector<string> every_one_know, set<string, greater<string> > know_maybe_one_language)
{
    cout << every_one_know.size() << endl;

    for (auto now : every_one_know)
    {
        cout << now << endl;
    }
    int size = know_maybe_one_language.size();
    cout << size << endl;
    for (auto now : know_maybe_one_language)
    {
        cout << now << endl;
    }
}

int main()
{
    int N, count_of_language;
    cin >> N;
    multiset<vector<string> > students_language;
    set<string, greater<string> > know_maybe_one_language;
    vector<string> every_one_know;
    for (int i = 0; i < N; ++i)
    {
        string name, fck_getline;
        vector<string> temp_language;
        cin >> count_of_language;
        getline(cin, fck_getline);
        for (int j = 0; j < count_of_language; ++j)
        {
            getline(cin, name);
            temp_language.push_back(name);
            know_maybe_one_language.insert(name);
        }
        students_language.insert(temp_language);
    }
    every_one_know = list_everyone_know_language(students_language, N);
    do_cout(every_one_know, know_maybe_one_language);
    return 0;
}