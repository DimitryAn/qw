#include <map>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream f_in("input.txt");
    ofstream f_out("output.txt");
    int sum, percent;
    map<string, int> base;
    string name, operation, name2;
    while (f_in >> operation)
    {
        if (operation == "DEPOSIT")
        {
            // base = operation_deposit(base, name, operation, sum);
            f_in >> name;
            f_in >> sum;
            if (base.find(name) == base.end())
            {
                base[name] = 0;
            }
            base[name] += sum;
        }
        if (operation == "WITHDRAW")
        {
            f_in >> name;
            f_in >> sum;
            if (base.find(name) == base.end())
            {
                base[name] = 0;
            }
            base[name] -= sum;
        }
        if (operation == "BALANCE")
        {
            f_in >> name;
            if (base.find(name) == base.end())
            {
                f_out << "ERROR" << endl;
            }
            else
            {
                f_out << base[name] << endl;
            }
        }
        if (operation == "TRANSFER")
        {
            f_in >> name;
            f_in >> name2;
            f_in >> sum;
            if (base.find(name) == base.end())
            {
                base[name] = 0;
            }
            if (base.find(name2) == base.end())
            {
                base[name2] = 0;
            }
            base[name] -= sum;
            base[name2] += sum;
        }
        if (operation == "INCOME")
        {
            f_in >> percent;
            for (auto key : base)
            {
                if (base[key.first] > 0)
                {
                    base[key.first] += (base[key.first] * percent) / 100;
                }
            }
        }
    }
    f_in.close();
    f_out.close();
    return 0;
}