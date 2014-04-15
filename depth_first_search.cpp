// This file contains two implementations of the depth first search http://en.wikipedia.org/wiki/Breadth-first_search
// The first one is iterative, which is a bit easier to understand
// The second one is recursive which offers easier modability.
#include <iostream>
using namespace std;
const int MAXN = 1024;

// Sample input
/*
10 10
1 3
2 1
3 10
4 2
5 4
6 7
7 3
8 4
9 10
10 5
*/
 
int U[MAXN+1],P[MAXN],G[MAXN][MAXN],N;
int S[MAXN],top;
void make_empty(){top =-1;}
void push(int x){S[++top]=x;}
void pop(){top--;}
int look(){return S[top];}
bool not_empty(){return top>-1;}
// spisuk s obhodenite durveta
// U -> used vertices/ vurhove
// s -> stack
// P -> the tree which we are obtaining / durvoto koeto se polu4ava
 
//depth first search (iterative)
void DFS (int r)
{  
   for(int i=1;i<=N;i++)
      U[i]=0;
   make_empty();
   push(r);
   U[r]=1;
   P[r]=0;
   
   while(not_empty())
   {  
      int t=look();
      if(G[t][0]>0)
      {
         int v=G[t][G[t][0]--];
         if(!U[v])
         {
            U[v]=1; P[v]=t; push(v);
         }
      }
      else
      {
         pop();
      }
   }
}
 
// depth first search (recursion)
void DFS_R(int r)
{   int y;
    while(G[r][0]>0)
    {  
         y=G[r][G[r][0]--];
         if(!U[y])
         {
               U[y]=1; P[y]=r; DFS_R(y);
         }
    }
}
 
void first_call()
{
      int i;
      for(i=1;i<=N;i++)
         U[i]=0;
      for(i=1;i<=N;i++)
         if(U[i]==0) DFS_R(i);
}
 
int main()
{
   // null the matrix
   for(int i = 1; i < MAXN; i++)
   {
      for(int j = 1; j < MAXN; j++)
      {
         G[i][j] = 0;
      }
   }
   
   //get the user input
   int vertice_max;
   int edge_num;
   cin >> vertice_max;
   cin >> edge_num;
   N = vertice_max;
   
 
   int vertice_from = 0;
   int vertice_to = 0;
 
   for(int i =1; i <=edge_num; i++)
   {
      cin >> vertice_from;
      cin >> vertice_to;
      G[vertice_from][++G[vertice_from][0]] = vertice_to;
      G[vertice_to][++G[vertice_to][0]] = vertice_from;
   }

   //call the algorithm
   cout << "Calling DFS" << endl;
   DFS(1);
   // print the output
   for(int i = 1; i <= edge_num; i++)
   {
      cout << "   " << i << "  " << P[i] << endl;
   }

   // call the recursive version
   cout << "Calling DFS_R" << endl;
   DFS_R(1);
   // print the tree again (they should be the same
   for(int i = 1; i <= edge_num; i++)
   {
      cout << "  " << i << "  " << P[i] << endl;
   }
   return 0;
}
