// This file contains a simple algorithm that will find a path by the means of BFS (breadth first search) 
#include <iostream>
using namespace std;
 int vertice_max;
const int MAXN = 1024;
 
/*
10 14
1 2
1 9
1 7
2 4
2 6
3 7
3 10
4 8
4 5
5 6
5 10
6 10
9 10
6 7
8 3 < ---- this  is what we are searching for Hence this is the 11'th pair
!!! Note: You must represent the answer from bottom to top
!!! Probablly a good idea to put in stack then print it
*/
 
 // Declaration of standard variables
int U[MAXN+1],P[MAXN],G[MAXN][MAXN],N;
int Q[MAXN],b,e;
void make_empty(){b=0;e=-1;}
void push(int x){Q[++e]=x;}
int pop(){return Q[b++];}
bool not_empty(){return b<=e;}
int bfs_path_arr[MAXN] = {0};
 
//Breadth First Search 
void BFS(int r)
{
   int  x,y,i; for(i=1;i<=N;i++) U[i]=0;
   make_empty();push(r);U[r]=1;P[r]=0;
   while(not_empty()) {  
       x=pop();
       for(i=1;i<=G[x][0];i++) {
       //cout<< "Entering FOR LOOP" << endl;
         y=G[x][i];
         if(!U[y]) {push(y);U[y]=1;P[y]=x;} //used is U !!!!
         //cout << "P[y] ==" << P[y] << endl;
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
 
        int start_from = 0;
        int search_for = 0;
 
 
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
         
        // !!!!!! Next two lines get what we are searching for
        cin >> search_for >> start_from;
        cout << "Start from  " << start_from << "  Search for "  << search_for << endl;
//print the G
        for(int i = 1; i <= vertice_max; i++)
        {
                for(int j = 0; j <= vertice_max; j++)
                {
                        cout << G[i][j] << "  ";
                }
                cout << endl;
        }
       
        BFS(8); // start it from v 8
        cout << "===================" << endl;
        // Diagnostics print
        for(int i = 1; i<= vertice_max; i++)
        {
         cout << i << "  " << P[i] << endl;    
            bfs_path_arr[i] = P[i];
        }
 
        cout << "============= PATH ==============" << endl;
        int coef = start_from;
        cout << start_from << endl; //print start
        while(bfs_path_arr[coef] != search_for)
        {
          cout << bfs_path_arr[coef] << endl;
          coef = bfs_path_arr[coef];
        }
        cout << bfs_path_arr[coef] << endl; // print end
        return 0;
}
