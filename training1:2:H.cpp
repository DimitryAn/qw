#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long find_max_min_el3(vector<long long> numbers, long long max_min_el, long long max_min_el2)
{
    long long max_min_el3;
    if ((max_min_el == numbers[0] && max_min_el2 == numbers[1]) || (max_min_el == numbers[1] && max_min_el2 == numbers[0]))
    {
        max_min_el3 = numbers[2];
    }
    else if ((max_min_el == numbers[1] && max_min_el2 == numbers[2]) || (max_min_el == numbers[2] && max_min_el2 == numbers[1]))
    {
        max_min_el3 = numbers[0];
    }
    else if ((max_min_el == numbers[0] && max_min_el2 == numbers[2]) || (max_min_el == numbers[2] && max_min_el2 == numbers[0]))
    {
        max_min_el3 = numbers[1];
    }
    return max_min_el3;
}

long long find_max_combination(long long max_el, long long max_el2, long long max_el3, long long min_el, long long min_el2, long long min_el3)
{
    long long result1 = min_el * max_el3 * max_el2;
    long long result2 = max_el * min_el * max_el2;
    long long result3 = max_el * max_el3 * min_el;
    long long result4 = min_el3 * max_el3 * max_el2;
    long long result5 = max_el * min_el3 * max_el2;
    long long result6 = max_el * max_el3 * min_el3;
    long long result7 = min_el2 * max_el3 * max_el2;
    long long result8 = max_el * min_el2 * max_el2;
    long long result9 = max_el * max_el3 * min_el2;
    long long result10 = min_el * min_el3 * max_el;
    long long result11 = min_el * max_el * min_el2;
    long long result12 = max_el * min_el3 * min_el2;
    long long result13 = min_el * min_el3 * max_el2;
    long long result14 = min_el * max_el2 * min_el2;
    long long result15 = max_el2 * min_el3 * min_el2;
    long long result16 = min_el * min_el3 * max_el3;
    long long result17 = min_el * max_el3 * min_el2;
    long long result18 = max_el3 * min_el3 * min_el2;
    long long result19 = max_el * max_el3 * max_el2;
    long long result20 = min_el * min_el3 * min_el2;
    long long finres = max(max(max(max(result1, result2), max(result3, result4)), max(max(result5, result6), max(result7, result8))), max(result9, result20));
    long long finres_2 = max(max(max(max(result9, result10), max(result11, result12)), max(max(result13, result14), max(result15, result16))), max(result19, result18));
    long long answer = max(finres, finres_2);
    if (answer == result1)
    {
        cout << min_el << " " << max_el3 << " " << max_el2;
        return 0;
    }
    if (answer == result2)
    {
        cout << max_el << " " << min_el << " " << max_el2;
        return 0;
    }
    if (answer == result3)
    {
        cout << max_el << " " << max_el3 << " " << min_el;
        return 0;
    }
    if (answer == result4)
    {
        cout << min_el3 << " " << max_el3 << " " << max_el2;
        return 0;
    }
    if (answer == result5)
    {
        cout << max_el << " " << min_el3 << " " << max_el2;
        return 0;
    }
    if (answer == result6)
    {
        cout << max_el << " " << max_el3 << " " << min_el3;
        return 0;
    }
    if (answer == result7)
    {
        cout << min_el2 << " " << max_el3 << " " << max_el2;
        return 0;
    }
    if (answer == result8)
    {
        cout << max_el << " " << min_el2 << " " << max_el2;
        return 0;
    }
    if (answer == result9)
    {
        cout << max_el << " " << max_el3 << " " << min_el2;

        return 0;
    }
    if (answer == result10)
    {
        cout << min_el << " " << min_el3 << " " << max_el;
        return 0;
    }
    if (answer == result11)
    {
        cout << min_el << " " << max_el << " " << min_el2;
        return 0;
    }
    if (answer == result12)
    {
        cout << max_el << " " << min_el3 << " " << min_el2;
        return 0;
    }
    if (answer == result13)
    {
        cout << min_el << " " << min_el3 << " " << max_el2;
        return 0;
    }
    if (answer == result14)
    {
        cout << min_el << " " << max_el2 << " " << min_el2;
        return 0;
    }
    if (answer == result15)
    {
        cout << max_el2 << " " << min_el3 << " " << min_el2;
        return 0;
    }
    if (answer == result16)
    {
        cout << min_el << " " << min_el3 << " " << max_el3;
        return 0;
    }
    if (answer == result17)
    {
        cout << min_el << " " << max_el3 << " " << min_el2;
        return 0;
    }
    if (answer == result18)
    {
        cout << max_el3 << " " << min_el3 << " " << min_el2;
        return 0;
    }
    if (answer == result19)
    {
        cout << max_el << " " << max_el3 << " " << max_el2;
        return 0;
    }
    if (answer == result20)
    {
        cout << min_el << " " << min_el3 << " " << min_el2;
        return 0;
    }

    return 0;
}
long long find_max_product(vector<long long> numbers)
{
    long long size = numbers.size();
    long long max_el = max(max(numbers[0], numbers[1]), numbers[2]);
    long long max_el2 = min(min(numbers[0], numbers[1]), numbers[2]);
    long long max_el3 = find_max_min_el3(numbers, max_el, max_el2);

    long long min_el = min(min(numbers[0], numbers[1]), numbers[2]);
    long long min_el2 = max(max(numbers[0], numbers[1]), numbers[2]);
    long long min_el3 = find_max_min_el3(numbers, min_el, min_el2);

    for (long long i = 3; i < size; ++i)
    {
        if (numbers[i] > max_el)
        {
            max_el2 = max_el3;
            max_el3 = max_el;
            max_el = numbers[i];
        }
        else if (numbers[i] > max_el3)
        {
            max_el2 = max_el3;
            max_el3 = numbers[i];
        }
        else if (numbers[i] > max_el2)
        {
            max_el2 = numbers[i];
        }

        if (numbers[i] < min_el)
        {
            min_el2 = min_el3;
            min_el3 = min_el;
            min_el = numbers[i];
        }
        else if (numbers[i] < min_el3)
        {
            min_el2 = min_el3;
            min_el3 = numbers[i];
        }
        else if (numbers[i] < min_el2)
        {
            min_el2 = numbers[i];
        }
    }

    if ((size - 1) > 3)
    {
        if (find_max_combination(max_el, max_el2, max_el3, min_el, min_el2, min_el3) == 0);
        return 0;
    }
    else if ( (size - 1) <= 3)
    {
        if ((max_el * max_el2 * max_el3) > ((min_el * min_el2 * min_el3)))
        {
            cout << max_el2 << " " << max_el << " " << max_el3;
        }
        else
        {
            cout << min_el << " " << min_el2 << " " << min_el3;
        }
    }
    return 0;
}

int main()
{
    long long n;
    vector<long long> numbers;
    while (cin >> n)
    {
        numbers.push_back(n);
    }
    find_max_product(numbers);
}