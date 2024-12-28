#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

const double MAX_right_limit = 4000;
const double MIN_left_limit = 30;

struct input_data
{
    double numbers;
    string diff;
};

pair<double, double> find_left_right_limit (int n, vector<input_data> massive, double right_limit, double left_limit)
{
    for (int i = 1; i < n; ++i)
    {

        if (massive[i].diff == "closer")
        {
            if (massive[i - 1].numbers > massive[i].numbers)
            {
                right_limit = min(((massive[i - 1].numbers + massive[i].numbers) / 2), right_limit);
            }
            else if (massive[i - 1].numbers < massive[i].numbers)
            {
                left_limit = max(((massive[i - 1].numbers + massive[i].numbers) / 2), left_limit);
            }
        }
        else if (massive[i].diff == "further")
        {
            if (massive[i - 1].numbers < massive[i].numbers)
            {
                right_limit = min(((massive[i - 1].numbers + massive[i].numbers) / 2), right_limit);
            }
            else if (massive[i - 1].numbers > massive[i].numbers)
            {
                left_limit = max(((massive[i - 1].numbers + massive[i].numbers) / 2), left_limit);
            }
        }
    }
    return pair<double, double> (left_limit, right_limit);
}

int main()
{
    int n, f;
    double temp_numbers, left_limit = MIN_left_limit, right_limit = MAX_right_limit;
    string temp_diff;
    input_data struct_temp;
    cin >> n;
    f = n;
    vector<input_data> massive;
    cin >> temp_numbers;
    struct_temp.numbers = temp_numbers;
    struct_temp.diff = "";
    massive.push_back(struct_temp);

    while (f != 1)
    {
        cin >> temp_numbers >> temp_diff;
        struct_temp.numbers = temp_numbers;
        struct_temp.diff = temp_diff;
        massive.push_back(struct_temp);
        --f;
    }
    cout << setprecision(6) << fixed;
    cout << find_left_right_limit(n, massive, right_limit, left_limit).first << " ";
    cout << find_left_right_limit(n, massive, right_limit, left_limit).second;
    return 0;
}
