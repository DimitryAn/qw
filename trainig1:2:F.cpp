#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> fun(int n, vector<int> sequence)
{
    vector<int> answer;
    for (int i = 0; i < n; ++i)
    {
        int x = i;
        int y = sequence.size() - 1;
        while (sequence[x] == sequence[y] && x < n && y >= 0)
        {
            ++x;
            --y;
        }
        if (x > y)
        {
            for (int j = 0; j < i; ++j)
            {
                cout << i;
                answer.push_back(sequence[j]);
            }
            return answer;
        }
    }
}

int main()
{
    int n, f;
    vector<int> sequence;
    vector<int> answer;
    cin >> n;
    f = n;
    while (f != 0)
    {
        int temp;
        cin >> temp;
        sequence.push_back(temp);
        --f;
    }
    answer = fun(n, sequence);
    cout << answer.size() << endl;
    reverse(answer.begin() , answer.end());
    for (auto now : answer)
    {
        cout << now << " ";
    }
    return 0;
}
