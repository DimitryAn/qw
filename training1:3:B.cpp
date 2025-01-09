
#include <set>
#include <string>
#include <fstream>
using namespace std;

int main()
{

    ifstream f_in("input.txt");
    ofstream f_out("out.txt");
    set<int> sequence_numbers_first;
    set<int> sequence_numbers_second;
    int number;
    while (  f_in.peek() != '\n')
    {
        f_in >> number;
        sequence_numbers_first.insert(number);
    }
    while (f_in >> number )
    {   
        sequence_numbers_second.insert(number);
    }

    for (auto now : sequence_numbers_first)
    {
        if (sequence_numbers_second.find(now) != sequence_numbers_second.end())
        {
            f_out << now << " ";
        }
    }

    f_in.close();
    f_out.close();
    return 0;
}