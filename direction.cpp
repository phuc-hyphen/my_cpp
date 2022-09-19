
#include <iostream>
#include <string>
#include <vector>

/*
Write a function dirReduc which will take an array of strings and returns an array of strings with the needless directions removed (W<->E or S<->N side by side).

    The Haskell version takes a list of directions with data Direction = North | East | West | South.
    The Clojure version returns nil when the path is reduced to nothing.
    The Rust version takes a slice of enum Direction {North, East, West, South}.

EX : ["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"]. => ["WEST"]
 */    


class DirReduction
{
public:
    static void print_v(std::vector<std::string> &arr)
    {
        for (std::string dir : arr)
        {
            std::cout << dir << " ";
        }
        std::cout << std::endl;
    }

    static bool isexist(std::vector<std::string> &arr)
    {
        std::vector<std::string> pNS{ "NORTH", "SOUTH" };
        std::vector<std::string> pWE{ "WEST", "EAST" };
        std::vector<std::string> pSN{ "SOUTH", "NORTH" };
        std::vector<std::string> pEW{ "EAST", "WEST" };
        std::vector<std::string> p;
        for (size_t i = 0, j = 1; i < arr.size() && j < arr.size(); i++, j++)
        {
            p.push_back(arr[i]);
            p.push_back(arr[j]);
            if (p == pEW || p == pNS || p == pSN || p == pWE)
                return true;
            p.clear();
        }
        return false;
    }
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr)
    {
        size_t i = 0, j = 1;
        std::vector<std::string> pNS{ "NORTH", "SOUTH" };
        std::vector<std::string> pWE{ "WEST", "EAST" };
        std::vector<std::string> pSN{ "SOUTH", "NORTH" };
        std::vector<std::string> pEW{ "EAST", "WEST" };

        while (isexist(arr))
        {
            if (i < arr.size() && j < arr.size())
            {
                std::vector<std::string> p{ arr[i], arr[j] };
                if (p == pNS || p == pEW || p == pSN || p == pWE)
                {
                    arr.erase(arr.begin() + i, arr.begin() + j + 1);
                    i = 0;
                    j = 1;
                }
                else
                    i++, j++;
            }
        }

        return arr;
    }
};

int main()
{
    std::vector<std::string> d1 = { "SOUTH", "EAST", "WEST", "NORTH", "WEST" };
    std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
    (void)ans1;
    DirReduction::print_v(ans1);
    return 0;
}


// another way 
// class DirReduction
// {
// public:
//     static std::vector<std::string> dirReduc(std::vector<std::string> &arr)
//     {
//       for (int i = 1; i < arr.size(); i++)
//       {
//         if (arr[i] == "NORTH" && arr[i - 1] == "SOUTH" ||
//             arr[i] == "EAST"  && arr[i - 1] == "WEST"  ||
//             arr[i] == "SOUTH" && arr[i - 1] == "NORTH" ||
//             arr[i] == "WEST"  && arr[i - 1] == "EAST")
//           {
//             arr.erase(arr.begin() + i - 1);
//             arr.erase(arr.begin() + i - 1);
//             i = 0;
//           }
//       }
//       return arr;
//     }
// };