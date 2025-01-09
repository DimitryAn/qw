#include <iostream>
#include <set>
using namespace std;

set<int> make_a_set(int l)
{
    set<int> result_cube;
    for (int i = 0; i < l; ++i)
    {
        int el;
        cin >> el;
        result_cube.insert(el);
    }
    return result_cube;
}

void c_out_set(set<int> c_out_cube)
{
    for (auto now : c_out_cube)
    {
        cout << now << " ";
    }
    cout << endl;
}

set<int> make_united_set(set<int> ann_cube, set<int> bor_cube)
{
    set<int> friends_cube;
    for (auto now : ann_cube)
    {
        if (bor_cube.find(now) != bor_cube.end())
        {
            friends_cube.insert(now);
        }
    }
    return friends_cube;
}

int main()
{
    int n, m;
    set<int> ann_cube, bor_cube, friends_cube;
    cin >> n >> m;
    ann_cube = make_a_set(n);
    bor_cube = make_a_set(m);
    friends_cube = make_united_set(ann_cube, bor_cube);
    cout << friends_cube.size() << endl;
    c_out_set(friends_cube);
    for (auto now : friends_cube)
    {
        if (ann_cube.find(now) != ann_cube.end())
        {
            ann_cube.erase(now);
            bor_cube.erase(now);
        }
    }
    cout << ann_cube.size() << endl;
    c_out_set(ann_cube);
    cout << bor_cube.size() << endl;
    c_out_set(bor_cube);

    return 0;
}