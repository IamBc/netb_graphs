#include <iostream>

using namespace std;

const int MAX = 500000;
int A[MAX][MAX] = { 0 };

int main()
{
    int vertice_num;
    int edge_num;
    cin >> vertice_num;
    cin >> edge_num;    
    
    for (int i = 1; i <= edge_num; i++)
    {
        int j = 0;
        int k = 0;
        cin >> j >> k;
        A[j][k] = 1;
    }
   return 0;
}
