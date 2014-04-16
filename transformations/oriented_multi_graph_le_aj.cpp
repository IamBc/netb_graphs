#include <iostream>

using namespace std;

const int MAX = 1024;
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
        A[j][k] += 1;
        A[k][j] += 1;
    }
   for(int i = 1; i <=vertice_num; i++)
   {
      for(int j = 1; j <= vertice_num; j++)
      {
        cout << A[i][j];
      }
      cout << endl;
   }

   return 0;
}
