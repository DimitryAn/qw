#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long n, width, height, max_pyramid = 0, max_el;
    map<int, vector<int> > blocks;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> width >> height;
        blocks[width].push_back(height);
    }

    for (auto key : blocks)
    {
        max_el = -1;
        for (auto elements : key.second)
        {
            if (elements > max_el)
            {
                max_el = elements;
            }
        }
        max_pyramid += max_el;
    }

    cout << max_pyramid;

    return 0;
}
