#include <iostream>
#include <set>

using namespace std;

const int turtel_place = 1;

set<pair<int, int>> make_a_set(int n)
{
    set<pair<int, int>> turtels_answer;
    int a,b;
    pair<int, int> answer;
    while (n != 0)
    {
        cin >> a >> b;
        if (a < 0)
        {
            a *= -1;
        }
        if (b < 0)
        {
            b *= -1;
        }
        answer = make_pair(a, b);
        turtels_answer.insert(answer);
        --n;
    }
    return turtels_answer;
}

int main()
{
    int n, a, b, M = 0;
    set<pair<int, int>> turtels_answer;
    cin >> n;
    turtels_answer = make_a_set(n);

    for (auto now : turtels_answer)
    {

        if ((now.first + now.second + turtel_place) == n)
        {
            ++M;
        }
    }
    cout << M;
    return 0;
}