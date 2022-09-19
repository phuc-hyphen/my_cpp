
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
int findSmallest(const std::vector<int> &xs)
{
    return *std::min_element(xs.cbegin(), xs.cend());
}

int findSmallest2(std::vector<int> list)
{
    std::sort(list.begin(), list.end());
    return list[0];
}

bool betterThanAverage(const std::vector<int> &classPoints,
                       const int yourPoints)
{
    return std::accumulate(classPoints.cbegin(), classPoints.cend(), 0)
        < int(classPoints.size()) * yourPoints;
}
int min(std::vector<int> list)
{
    return *(min_element(list.begin(), list.end()));
}

int max(std::vector<int> list)
{
    return *(max_element(list.begin(), list.end()));
}
std::vector<std::string> split(std::string text, std::string delimite)
{
    std::vector<std::string> list_w;
    while (text.find(delimite) != std::string::npos)
    {
        size_t new_pos = text.find(delimite);
        list_w.push_back(text.substr(0, new_pos));
        text = text.substr(new_pos + 1, text.size() - new_pos);
    }
    if (list_w.size() != 0)
        list_w.push_back(text);

    return list_w;
}
std::string to_camel_case(std::string s)
{
    for (int i{ 0 }; i < int(s.size()); ++i)
        if (s[i] == '-' || s[i] == '_')
            s.erase(i, 1), s[i] = toupper(s[i]);
    return s;
}

// A Narcissistic Number is a positive number which is the sum of its own
// digits, each raised to the power of the number of digits in a given base. In
// this Kata, we will restrict ourselves to decimal (base 10).
// For example, take 153 (3 digits), which is narcisstic:
//     1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
// and 1652 (4 digits), which isn't:
//     1^4 + 6^4 + 5^4 + 2^4 = 1 + 1296 + 625 + 16 = 1938
#include <cmath>
bool narcissistic(int value)
{
    int number_length = 0, tmp = value, nar = 0;
    while (tmp > 0)
    {
        number_length += 1;
        tmp /= 10;
    }
    tmp = value;
    while (tmp > 0)
    {
        nar += pow(tmp % 10, number_length);
        tmp /= 10;
    }
    return nar == value ? true : false;
}
bool narcissistic2(int value)
{
    int n = value;
    int i = log10(value) + 1; // get the number of digits in "number"
    int sum = 0;

    while (n)
    {
        sum += pow(n % 10, i);
        n /= 10;
    }

    return sum == value;
}
int main()
{
    cout << std::boolalpha << narcissistic(7);

    return 0;
}