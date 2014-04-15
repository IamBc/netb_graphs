// Task1: Which vertice is the root / Кой е корена
// Task2: Number of leafs / Брой листа
// Task3: If it is a tree or a forest  / Дърво или гора
// Task4: The number of children / Разклонеността
// Task5: Length
#include <iostream>
#include <string>
 
using namespace std;
 
const int MAX = 512;
int tree[MAX] = {-1};
 
 
int main()
{
   // Get tree input
   int edge_num;
   cin >> edge_num;
 
   int parent;
   for(int i = 1; i <= edge_num; i++)
   {
      cin >> parent;
      tree[i] = parent;
     
      // task 1
      if(parent == 0)
      {
         cout << i  << "   ROOT" << endl;
      }
   }
 
   //task2
   for(int i = 1; i <= edge_num; i++)
   {
      int leaf = -2;
      for(int j = 1; j <= edge_num; j++)
      {
         if(i == tree[j])
         {
            leaf = 0;  
         }
      }
     if(leaf != 0)
     {
         cout << i << "  is leaf" << endl;
     }
   }
 
   //task3
   int root_num = 0;
   for(int i = 0; i <= edge_num; i++)
   {
      if (tree[i] == 0)
      {
         root_num++;
      }
   }
   if(root_num > 1)
   {
      cout << "Forest" << endl;
   }
 
   //task4
    for(int i = 1; i <= edge_num; i++)
   {
      int child_num = 0;
      for(int j = 1; j <= edge_num; j++)
      {
         if(i == tree[j])
         {
            child_num++;  
         }
      }
         cout << i << "  has " <<  child_num << "  children"<< endl;
   }
  //task5
  // You need to start from every leaf and move up to the root.
 
   return 0;
}
