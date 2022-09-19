#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

// Three 1's => 1000 points
//  Three 6's =>  600 points
//  Three 5's =>  500 points
//  Three 4's =>  400 points
//  Three 3's =>  300 points
//  Three 2's =>  200 points
//  One   1   =>  100 points
//  One   5   =>   50 point

int score(const std::vector<int> &dice)
{
    int score = 0;
    int points[6] = { 0, 0, 0, 0, 0, 0 };
    int three[6] = { 1000, 200, 300, 400, 500, 600 };
    int one[6] = { 100, 0, 0, 0, 50, 0 };
    for (int point : dice)
        points[point - 1] += 1;

    for (int i = 0; i < 6; i++)
    {
        score += (points[i]/3*three[i] + points[i]%3*one[i]);
    }
    return score;
}

int main()
{
    printf("score of {1,1,1,1 ,2, 4}: %d\n", score({ 1, 1, 1, 1, 2, 4 }));
    return 0;
}
