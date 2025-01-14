#include <iostream>
#include <set>
#include <fstream>
using namespace std;

int main()
{
    ifstream f_in("input.txt");
    ofstream f_out("output.txt");
    int x, y, N;
    set<int> pigs_x_coordinates;
    f_in >> N;
    while (N != 0)
    {
        f_in >> x >> y;
        pigs_x_coordinates.insert(x);
        --N;
    }

    f_out << pigs_x_coordinates.size();

    f_in.close();
    f_out.close();
    return 0;
}