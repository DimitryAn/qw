#include <iostream>
#include <set>
#include <string>

using namespace std;

multiset<string> make_pair_from_genome()
{
    multiset<string> pairs;
    string genome, temp;
    getline(cin, genome);
    for (auto now : genome)
    {
        temp += now;
        if (temp.size() == 2)
        {
            pairs.insert(temp);
            temp.erase(0, 1);
        }
    }
    return pairs;
}

int main()
{
    string first_genome, second_genome, temp;
    multiset<string> first_pair, second_pair;
    int degree_of_near = 0;
    first_pair = make_pair_from_genome();
    second_pair = make_pair_from_genome();
    for (auto now : first_pair)
    {
        if (second_pair.find(now) != second_pair.end())
        {
            ++degree_of_near;
        }
    }
    
    cout << degree_of_near;

    return 0;
}