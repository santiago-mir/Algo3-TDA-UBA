#include <iostream>
#include <vector>
#include <tuple>

#define INF 1000000000
using namespace std;
int n;
vector<int> billetes;
int costo;
// resolucion por backtracking
tuple<int, int> optiPagoBT(vector<int> B, int c, int i)
{
    // llegue al final y no cumpli el costo
    if (i == B.size() && c > 0)
    {
        return make_tuple(INF, 0);
    }
    // llegue al final y cumpli el costo
    if (i == B.size() && c <= 0)
    {
        return make_tuple(0, 0);
    }
    // llegue al costo en algun punto
    if (c <= 0)
    {
        return make_tuple(0, 0);
    }
    tuple<int, int> no_agrego = optiPagoBT(B, c, i + 1);
    tuple<int, int> agrego = optiPagoBT(B, c - B[i], i + 1);
    agrego = make_tuple(get<0>(agrego) + B[i], get<1>(agrego) + 1);
    tuple<int, int> res = min(no_agrego, agrego);
    return res;
}

int main()
{
    cin >> n >> costo;
    billetes.resize(n);
    int elem;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        billetes[i] = elem;
    }
    tuple<int, int> value = optiPagoBT(billetes, costo, 0);

    cout << "el costo minimo es " << get<0>(value) << " la cantidad de billetes minima es " << get<1>(value) << endl;
}
