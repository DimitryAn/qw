#include <iostream>

using namespace std;

int main()
{
    int rows, colums, number_of_bomb, row_of_bomb, colum_of_bomb, count_of_bomb = 0;
    cin >> rows >> colums >> number_of_bomb;
    int field[rows + 2][colums + 2];

    for (int i = 0; i < rows + 2; ++i)
    {
        for (int j = 0; j < colums + 2; ++j)
        {
            field[i][j] = 0;
        }
    }

    for (int i = 0; i < number_of_bomb; ++i)
    {
        cin >> row_of_bomb >> colum_of_bomb;
        field[row_of_bomb][colum_of_bomb] = -1;
    }


    for (int i = 1; i < rows + 1; ++i)
    {
        for (int j = 1; j < colums + 1; ++j)
        {   
            if (field[i][j] == 0)
            {
                if (field[i - 1][j + 1] == -1)
                {
                    ++count_of_bomb;
                }
                if (field[i - 1][j] == -1)
                {
                    ++count_of_bomb;
                }
                if (field[i - 1][j - 1] == -1)
                {
                    ++count_of_bomb;
                }
                if (field[i][j + 1] == -1)
                {
                    ++count_of_bomb;
                }
                if (field[i][j - 1] == -1)
                {
                    ++count_of_bomb;
                }
                if (field[i + 1][j + 1] == -1)
                {
                    ++count_of_bomb;
                }
                if (field[i + 1][j] == -1)
                {
                    ++count_of_bomb;
                }
                if (field[i + 1][j - 1] == -1)
                {
                    ++count_of_bomb;
                }
                cout << count_of_bomb << " ";
            }
            else
            {
                cout << "*" << " ";
            }
            count_of_bomb =  0;
        }
        cout << endl;
    }
    return 0;
}

/*
for (int i = 0; i < rows + 2; ++i)
    {
        for (int j = 0; j < colums + 2; ++j)
        {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
*/