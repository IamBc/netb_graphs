// Implementation of the breadth first algorithm: http://en.wikipedia.org/wiki/Breadth-first_search
// Task: Implement BFS. Call BFS and print the fathers.
// Sample input for the program
/*
10 14
1 2
1 9
1 7
2 4
2 6
3 10
4 8
5 10
6 5
6 7
4 5
6 10
7 3
9 1
*/
 
 
#include <iostream>
using namespace std;
int vertice_max;
const int MAXN = 1024;
// Mapa za tova dali e poseten U
// Q is a queue with a minimal implementation
// G is matrix which represents a list of neibhours
int U[MAXN+1],P[MAXN],G[MAXN][MAXN],N;
int Q[MAXN],b,e;
void make_empty(){b=0;e=-1;}
void push(int x){Q[++e]=x;}
int pop(){return Q[b++];}
bool not_empty(){return b<=e;}
 
void BFS(int r)
{
   int  x,y,i; for(i=1;i<=N;i++) U[i]=0;
   make_empty();push(r);U[r]=1;P[r]=0;
   while(not_empty()) {  
       x=pop();
       for(int z = 1; z <= vertice_max; z++)
       {
         for(int j = 0; j <= vertice_max; j++)
         {
            cout << G[z][j] << "  ";
         }
         cout << endl;
       }
       
       for(i=1;i<=G[x][0];i++) {
       cout<< "Entering FOR LOOP" << endl;
         y=G[x][i];
         if(!U[y]) {push(y);U[y]=1;P[y]=x;} //used is U !!!!
         cout << "P[y] ==" << P[y] << endl;
       }
   }
}
 
 
 
 
int main()
{
        // initialization
        for(int i = 1; i < MAXN; i++)
        {
                for(int j = 1; j < MAXN; j++)
                {
                        G[i][j] = 0;
                }
        }
         vertice_max;
        int edge_num;
        cin >> vertice_max;
        cin >> edge_num;
 
        // fill the G
        int vertice_from = 0;
        int vertice_to = 0;
        for(int i = 1; i <= edge_num; i++)
        {
                cin >> vertice_from;
                cin >> vertice_to;
                G[vertice_from][++G[vertice_from][0]] = vertice_to;
                G[vertice_to][++G[vertice_to][0]] = vertice_from;
        }
 
        //print the G
        for(int i = 1; i <= vertice_max; i++)
        {
                for(int j = 0; j <= vertice_max; j++)
                {
                        cout << G[i][j] << "  ";
                }
                cout << endl;
        }
         
        BFS(1);
        // e to the z
        cout << "===========================================" <<endl;
        for(int i = 1; i<= vertice_max; i++)
        {
         cout << i << "  " << P[i] << endl;    
        }
        
        //Additional information: 
        //If you want to check if this is a tree or a forest, you can simply check U. If you has something different than 1's than it's a forest
        //If you want to know the number of trees add a counter and increment it each time U is different than 1.
        return 0;
}
