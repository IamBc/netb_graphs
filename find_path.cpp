// Given LE of G and 2 vertices u, v. Is there a path from u to v
// LE is list of edges, G is the matrix.
// IMPORTANT: For Multigraphs there can be many paths. If you are interested in the number of paths
// you simply need to look at the value of the proper index.
#include <iostream>
#include <string>

using namespace std;

const int MAX = 1024; // theorethical max for the course
int matrix_a[MAX][MAX] = { 0 };
int matrix_b[MAX][MAX] = { 0 };
int matrix_c[MAX][MAX] = { 0 };

// will be used to obtain the proper matrix we need.
// To find path of length N you need to transform the matrix to the power of N
void multiply_matrix(int size)
{
   for (int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            matrix_c[i][j] = 0;
            for(int k = 1; k <= size; k++)
            {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];             
            }
        }    
    }
}


int main()
{
   int edge_num; 
   int vertice_num;
   cin >> vertice_num;
   cin >> edge_num;    
    
   //get value of the matrix. Set matrix_a to be the same as matrix_b
   //for the power of 2 
   for (int i = 1; i <= edge_num; i++)
   {
       int j = 0;
       int k = 0;
       cin >> j >> k;
       matrix_a[j][k] += 1;
       matrix_b[j][k] += 1;
   }
   
   int u, v;
   cin >> u >> v;
   
   // check if path exists for length 1
   if(matrix_a[u][v] == 1){
      cout << "YES" << endl;
      return 0;
   }
   
   // matrix_check for paths of length from 2 to n-1
   for(int i = 1; i <= vertice_num - 1 ; i++)
   {
      multiply_matrix(edge_num);
      if(matrix_c[u][v] == 1){
         cout <<  "YES" << endl;
         return 0;
      }else{
         // Make val of matrix_c to matrix_b so we can obtain next power of matrix
         for (int k = 1; k <= edge_num; k++)
         {
            for (int j = 1; j <= edge_num; j++)
            {
               matrix_b[k][j] = matrix_c[k][j];
            }
         }
      }
   }

   return 0;
}
