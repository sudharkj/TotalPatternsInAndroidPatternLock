#include <iostream>
#include "defines.h"
#include "pattern.h"
using namespace std;

int main()
{
    long long adj_mat[][nodes] = {{0,1,0,1,1,1,0,1,0},
        {1,0,1,1,1,1,1,0,1},
        {0,1,0,1,1,1,0,1,0},
        {1,1,1,0,1,0,1,1,1},
        {1,1,1,1,0,1,1,1,1},
        {1,1,1,0,1,0,1,1,1},
        {0,1,0,1,1,1,0,1,0},
        {1,0,1,1,1,1,1,0,1},
        {0,1,0,1,1,1,0,1,0}
    };

    pattern initial_pattern(adj_mat,1), current_pattern(adj_mat,1);
    long long count, local_count;
    int i;

    fora(i,2) current_pattern.combine(initial_pattern);

    count = 0;
    fora(i,6)
    {
        current_pattern.combine(initial_pattern);
        local_count = current_pattern.count();
        count = count + local_count;
        cout << "patterns of length " << current_pattern.m_length << ": " << local_count << endl;
    }

    cout << "total valid patterns: " << count << endl;

    return 0;
}
