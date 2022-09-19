#include "headers.hpp"

using namespace std;

std::string number_to_string(int num)
{
    std::string tmp = "", result = "";
    std::string num_list = "0123456789";
    if (num < 0)
    {
        result += "-";
        num = -num;
    }
    while (num > 0)
    {
        tmp += num_list.at(num % 10);
        std::cout << tmp << std::endl;
        num /= 10;
    }
    std::cout << tmp << std::endl;
    for (int i = tmp.size() - 1; i >= 0; i--)
        result += tmp.at(i);
    std::cout << result << std::endl;

    return result;
}
std::string disemvowel(const std::string &str)
{
    std::string vowels = "euoaiEUOAI";
    std::string tmp = "";
    for (char ch : str)
    {
        int voe = 0;
        for (char vo : vowels)
        {
            if (ch == vo)
            {
                voe = 1;
                break;
            }
        }
        if (voe == 0)
            tmp += ch;
    }
    return tmp;
}

# include <regex>
std::string disemvowel2(std::string str)
{
  std::regex vowels("[aeiouAEIOU]");
  return std::regex_replace(str, vowels, "");
}
int main()
{
    std::string test = disemvowel("EAST");
    cout << test << endl;
    (void)test;
    // std::vector<std::string> pNS{ "NORTH", "SOUTH", "SOUTH", "EAST",
    //                               "WEST",  "NORTH", "WEST" };

    // for (std::string dir : pNS)
    // {
    //     std::cout << dir << " ";
    // }
    //     std::cout << std::endl;

    // pNS.erase(pNS.begin() + 0, pNS.begin() + 2);

    // for (std::string dir : pNS)
    // {
    //     std::cout << dir<<" ";
    // }
    // if (1 != 2 || 3 == 3)
    //     std::cout << "Ok";

    // vector<int> j{ 5,2,5,6};
    // j.erase(1,3);
    // cout << j << endl;
    // for (int i = 0; i < 5; i++)
    //     cout << j << endl, cout << i << endl, cout << i + 1;
    // // std::string text1 = "hello  world";
    // // std::cout<<text1<<std::endl;
    // std::string test = to_camel_case("the_stealth_warrior");
    // cout << test << endl;
    // vector<string> test = split("", "-");

    // (void)test;
    return 0;
}
