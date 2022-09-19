#include "headers.hpp"

using namespace std;

// you will write a function that returns the positions and the values of the
// "peaks" (or local maxima) of a numeric array.

// The output will be returned as an object of type PeakData which has two
// members: pos and peaks. Both of these members should be vector<int>s.

// The first and last elements of the array will not be considered as peaks (in
// the context of a mathematical function, we don't know what is after and
// before and therefore, we don't know if it is a peak or not).

// Also, beware of plateaus !!! [1, 2, 2, 2, 1] has a peak while [1, 2, 2, 2, 3]
// and [1, 2, 2, 2, 2] do not.
// In case of a plateau-peak, please only return the position and value of the
// beginning of the plateau. For example: pickPeaks([1, 2, 2, 2, 1]) returns
// {pos: [1], peaks: [2]} (or equivalent in other languages)
struct PeakData
{
    vector<int> pos, peaks;
};

PeakData pick_peaks(const std::vector<int> &v)
{
    PeakData result;
    if (v.size() == 2)
        return result;
    // int s_plateaus = -1, ps_plateau = 0;
    for (size_t i = 0, j = 1, k = 2;
         i < v.size() && j < v.size() && k < v.size(); i++, j++, k++)
    {
        // std::cout << i << " " << j << " " << k << std::endl;
        if (v[i] < v[j])
        {
            if (v[j] > v[k])
            {
                result.pos.push_back(j);
                result.peaks.push_back(v[j]);
            }
            else if (v[j] == v[k] && k + 1 < v.size())
            {
                if (v[k] > v[k + 1])
                {
                    result.pos.push_back(j);
                    result.peaks.push_back(v[j]);
                }
            }
            // std::cout << v[j] << std::endl;
        }

        if (v[i] == v[j] && v[j] == v[k] && i != 0
            && v[i] != v[i - 1]) // plateaus
        {
            int up = 0, down = 0;
            for (int l = i; l >= 0; l--)
            {
                if (v[l] != v[i])
                {
                    if (v[l] < v[i])
                        up = 1;
                    break;
                }
            }
            for (size_t h = k; h < v.size(); h++)
            {
                if (v[h] != v[k])
                {
                    if (v[h] < v[k])
                        down = 1;
                    break;
                }
            }
            if (down == 1 && up == 1)
            {
                result.peaks.push_back(v[i]);
                result.pos.push_back(i);
                // std::cout << v[i] << std::endl;
            }
        }
    }

    return result;
}

PeakData pick_peaks_2(vector<int> v)
{
    PeakData result;
    int i, t;
    for (t = 0, i = 1; i < v.size(); i++)
        if (v[i] > v[i - 1])
            t = i;
        else if (t && v[i] < v[i - 1])
            result.pos.push_back(t), result.peaks.push_back(v[t]), t = 0;
    return result;
}

int main()
{
    PeakData actual;

    actual = pick_peaks(std::vector<int>{ 6, -4, 13, 7, -1, -3, 14, -2, 20, 20,
                                          -3, 8, -5, 17, 14 });
    printf("\n peaks:\n");
    for (int i : actual.peaks)
    {
        printf("%d,", i);
    }
    printf("\n positions : \n");
    for (int i : actual.pos)
    {
        printf("%d,", i);
    }
    // 1, 4, 8, 13, 17, 22, 24, 26, 29, 33, 37, 39
    // 11, 12, 19, 11, 8, 14, 17, 19, 17, 20, 14, 2
    return 0;
}

// if (v.size() == 2)
//     return result;
// // int s_plateaus = -1, ps_plateau = 0;
// for (size_t i=0 ; i< v.size();i++)
//   {
//   result.peaks.push_back(v[i]);
//   result.pos.push_back(i);

// }