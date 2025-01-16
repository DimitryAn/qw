#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double *intersection(double where_mike_can_be[4], double points_from_navigator[4])
{
    where_mike_can_be[0] = max(where_mike_can_be[0], points_from_navigator[0]);
    where_mike_can_be[1] = min(where_mike_can_be[1], points_from_navigator[1]);
    where_mike_can_be[2] = max(where_mike_can_be[2], points_from_navigator[2]);
    where_mike_can_be[3] = min(where_mike_can_be[3], points_from_navigator[3]);
    return where_mike_can_be;
}

int main()
{
    double t, d, n, x, y;
    vector<pair<double, double> > answer;
    double where_mike_can_be[4] = {0, 0, 0, 0};
    double points_from_navigator[4];

    cin >> t >> d >> n;
    for (int i = 0; i < n; ++i)
    {
        where_mike_can_be[0] = (where_mike_can_be[0] - t);
        where_mike_can_be[1] = (where_mike_can_be[1] + t);
        where_mike_can_be[2] = (where_mike_can_be[2] - t);
        where_mike_can_be[3] = (where_mike_can_be[3] + t);

        cin >> x >> y;

        points_from_navigator[0] = x + y - d;
        points_from_navigator[1] = x + y + d;
        points_from_navigator[2] = x - y - d;
        points_from_navigator[3] = x - y + d;
        intersection(where_mike_can_be, points_from_navigator);
    }

    for (int XplusY = where_mike_can_be[0]; XplusY <= where_mike_can_be[1]; ++XplusY)
    {
        for (int XminusY = where_mike_can_be[2]; XminusY <= where_mike_can_be[3]; ++XminusY)
        {
            if ((XminusY + XplusY) % 2 == 0)
            {
                pair<double, double> temp_pair;
                x = (XminusY + XplusY) / 2;
                y = XplusY - x;
                temp_pair = make_pair(x, y);
                answer.push_back(temp_pair);
            }
        }
    }

    cout << answer.size() << endl;
    for (auto now : answer)
    {
        cout << now.first << " " << now.second << endl;
    }
    return 0;
}