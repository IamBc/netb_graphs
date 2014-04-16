//transforms an ajency matrix to list of edges. 
//Single Graph edition
#include <iostream>
using namespace std;

int G[9][9] = {
                        {9, 0, 0, 0, 0, 0, 0, 0, 0},            
                        {9, 0, 1, 0, 0, 0, 0, 1, 0},
                        {9, 1, 0, 0, 1, 0, 1, 0, 0},
                        {9, 0, 0, 0, 0, 0, 0, 1, 1},
                        {9, 0, 1, 0, 0, 1, 0, 0, 0},
                        {9, 0, 0, 0, 1, 0, 1, 0, 1},
                        {9, 0, 1, 0, 0, 1, 0, 1, 1},
                        {9, 1, 0, 1, 0, 0, 1, 0, 0},
                        {9, 0, 0, 1, 0, 1, 1, 0, 0}
                   };
int main()
{
  for(int i = 1; i <= 8; i++)
  {
    for(int j = 1; j <= 8; j++)
    {
        if(G[i][j] == 1)
        {
            cout << i << "  " << j << endl;
        }
    }
  }
}
