#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

int f(vector<int> A, vector<int> B)
{
    int n = 0;
    int k = 0;
    int res = 0;
    while (n < A.size() && k < size(B))
    {
        if (abs(A[n] - B[k]) <= 1)
        {
            res++;
            n++;
            k++;
        }
        else
        {
            if (A[n] > B[k])
            {
                k++;
            }
            else
            {
                n++;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> a = {1, 1, 1, 1, 1};
    vector<int> b = {1, 2, 3};
    int value = f(a, b);
    cout << value;
}