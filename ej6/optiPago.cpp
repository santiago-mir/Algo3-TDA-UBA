#include <iostream>
#include <vector>
#include <tuple>

#define INF 1000000000
using namespace std;
int n;
vector<int> billetes;
int costo;
vector<vector<tuple<int, int>>> matriz;
// resolucion con pd
tuple<int, int> optiPagoBT(vector<int> B, int c, int i)
{
    // llegue al costo en algun punto
    if (c <= 0)
    {
        return make_tuple(0, 0);
    }
    // llegue al final
    if (i == B.size())
    {
        if (c > 0)
        {

            return make_tuple(INF, 0);
        }
        return make_tuple(0, 0);
    }

    // si esta definido el valor, lo devuelvo
    if (get<0>(matriz[i][c]) != -1)
    {
        return matriz[i][c];
    }
    tuple<int, int> no_agrego = optiPagoBT(B, c, i + 1);
    tuple<int, int> agrego = optiPagoBT(B, c - B[i], i + 1);
    agrego = make_tuple(get<0>(agrego) + B[i], get<1>(agrego) + 1);
    matriz[i][c] = min(no_agrego, agrego);
    return matriz[i][c];
}

int main()
{
    cin >> n >> costo;
    billetes.resize(n);
    int elem;
    matriz.resize(n, vector<tuple<int, int>>(costo + 1, make_tuple(-1, 0)));
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        billetes[i] = elem;
    }
    tuple<int, int> value = optiPagoBT(billetes, costo, 0);

    cout << "el costo minimo es " << get<0>(value) << " la cantidad de billetes minima es " << get<1>(value) << endl;
}
