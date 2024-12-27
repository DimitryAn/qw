#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int find_max_product(vector<double> numbers)
{
    double size = numbers.size();
    double max_el = max(numbers[0], numbers[1]);
    double before_max_el = min(numbers[0], numbers[1]);

    double min_el = min(numbers[0], numbers[1]);
    double before_min_el = max(numbers[0], numbers[1]);

    for (int i = 2; i < size; ++i)
    {
        if (numbers[i] > max_el)
        {
            before_max_el = max_el;
            max_el = numbers[i];
        }
        else if (numbers[i] > before_max_el)
        {
            before_max_el = numbers[i];
        }

        if (numbers[i] < min_el)
        {
            before_min_el = min_el;
            min_el = numbers[i];
        }
        else if (numbers[i] < before_min_el)
        {
            before_min_el = numbers[i];
        }
    }
    if ((max_el * before_max_el) > (min_el * before_min_el))
    {
        cout << before_max_el << " " << max_el;
    }
    else
    {
        cout << min_el << " " << before_min_el;
    }
    return 0;
}

int main()
{
    double n;
    vector<double> numbers;
    while (cin >> n)
    {
        numbers.push_back(n);
    }
    find_max_product(numbers);
}