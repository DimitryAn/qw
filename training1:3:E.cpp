#include <iostream>
#include <set>
#include <string>
using namespace std;

set<char> make_a_set()
{
    set<char> symboles;
    string input_line;
    getline(cin, input_line);
    for (auto now : input_line)
    {
        if (now != ' ' && now != '\n')
        {
            symboles.insert(now);
        }
    }

    return symboles;
}

int main()
{
    set<char> numbers;
    set<char> symbol_from_N;
    string num;
    string N;
    int count_of_add_symbol = 0;

    numbers = make_a_set();
    symbol_from_N = make_a_set();

    for (auto now : symbol_from_N)
    {
        if (numbers.find(now) == numbers.end())
        {
            ++count_of_add_symbol;
        }
    }

    cout << count_of_add_symbol;
    return 0;
}