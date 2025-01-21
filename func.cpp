#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int modify_our_map(map<char, int>* S_map, map<char, int> W_map, char symbol, int operation)
{
    int answer = 0;
    if (S_map->find(symbol) == S_map->end())
    {
        (*S_map)[symbol] = 0;
    }
    if ((W_map.find(symbol) != W_map.end()) && (*S_map)[symbol] == W_map[symbol] )
    {
        answer = -1;
    }
    (*S_map)[symbol] += operation;
    if ((W_map.find(symbol) != W_map.end()) && (*S_map)[symbol] == W_map[symbol] )
    {
        answer = 1;
    }
    return answer;
}


int main()
{
    ifstream f_in("input.txt");
    ofstream f_out("output.txt");
    int w_size, s_size, ans = 0, matches_symbol = 0;
    string W, S;
    map<char, int> W_map, S_map;
    f_in >> w_size >> s_size;
    f_in >> W >> S;
    s_size = fabs(s_size);
    for (auto now : W)
    {
        W_map[now] += 1;
    }
    
    for (int i = 0; i < w_size; ++i)
    {
        S_map[S[i]] += 1;
    }
    for (auto key : W_map)
    {
        if (W_map[key.first] == S_map[key.first])
        {
            matches_symbol += 1;
        }
    }
    int Wsize = W_map.size();
    if (matches_symbol == Wsize)
    {
        ans += 1;
    }

    for (int i = w_size; i < s_size; ++i)
    {
        matches_symbol += modify_our_map(&S_map, W_map, S[i - w_size], -1);
        f_out << matches_symbol << endl;
        matches_symbol += modify_our_map(&S_map, W_map, S[i], +1);
        f_out << matches_symbol << endl;
        if(matches_symbol == Wsize)
        {
            ans += 1;
        }
    }
    f_out << ans;
    f_in.close();
    f_out.close();
    return 0;
}