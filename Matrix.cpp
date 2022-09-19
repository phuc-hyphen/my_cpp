#include "headers.hpp"

/*
Write a function that accepts a square matrix (N x N 2D array) and returns the
determinant of the matrix.

How to take the determinant of a matrix -- it is simplest to start with the
smallest cases:

A 1x1 matrix |a| has determinant a.

A 2x2 matrix [ [a, b], [c, d] ]
*/
using namespace std;
void print_v(vector<vector<long long>> m)
{
    printf("matrix %ldx%ld : \n", m.size(), m.size());
    for (vector<long long> i : m)
    {
        for (long long j : i)
            cout << j << " ";
        cout << endl;
    }
}
long long determinant(vector<vector<long long>> m)
{
    if (m.size() == 1)
        return m[0][0];
    if (m.size() == 2)
        return m[0][0] * m[1][1] - m[1][0] * m[0][1];
    //  otherwise
    int signe = 1;
    long long det = 0;
    size_t col, line;
    for (col = 0; col < m[0].size(); col++, signe *= -1)
    {
        // each column
        vector<vector<long long>> sm;

        for (line = 1; line < m.size(); line++) // we don't need the first line
        {
            // each line remove the col th element
            vector<long long> tmp = m[line];
            tmp.erase(tmp.begin() + col, tmp.begin() + col + 1);
            sm.push_back(tmp);
        }
        det += signe * m[0][col] * determinant(sm);
        // printf("%lld , %d", m[0][col],signe);
        // print_v(sm);
    }

    return det;
}

int main()
{
    vector<vector<long long>> test;

    test = { vector<long long>{ 2, 5, 3 }, vector<long long>{ 1, -2, -1 },
             vector<long long>{ 1, 3, 4 }

    };
    print_v(test);
    printf("%lld", determinant(test));
    // print_v(vector<vector<long long>>{ vector<long long>{ 1, 3 },
    //                                    vector<long long>{ 2, 5 } });
    return 0;
}