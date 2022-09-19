#include <iostream>
using namespace std;

static int problem(int A, int B)
{
    int answer = A - B;
    int count = 1, tmp = answer;
    while (true)
    {
        if(tmp > 10){

            tmp = tmp / 10;
        count=count*10;
        }
        else break;
    }
    return answer - count;
}
int main()
{
    cout << problem(5858, 1234);
    return 0;
}
