#include <iostream>
#include <set>
#include <string>

using namespace std;

multiset<string> make_pair_from_genome()
{
    multiset<string> pairs;
    string genome, temp, buf;
    int top = -1;
    getline(cin, genome);
    for (auto now : genome)
    {
        temp += now;
        ++top;
        if (top == 1)
        {
            pairs.insert(temp);
            buf += temp[1];
            temp = "";
            temp += buf[0];
            buf = "";
            top = 0;
        }
    }
    return pairs;
}

void degree_of_near_cout(multiset<string> first_pair, multiset<string> second_pair)
{

    int degree_of_near = 0;
    for (auto now : first_pair)
    {
        if (second_pair.find(now) != second_pair.end())
        {
            ++degree_of_near;
        }
    }
    cout << degree_of_near;
}

int main()
{
    string first_genome, second_genome, temp;
    multiset<string> first_pair, second_pair;
    first_pair = make_pair_from_genome();
    second_pair = make_pair_from_genome();
    degree_of_near_cout(first_pair, second_pair);
    return 0;
}