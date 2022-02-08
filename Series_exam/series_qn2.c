// here A,B,C,D,E,F are the nodes and they are indicated as numeric in the Algorithm
// A=1,B=2,C=3,D=4,E=5,F=6

#include<stdio.h>
void dfs(int);
int g[6][6],visited[10], n;
void main() 
{
    int i, j;
    printf ("Enter the number of vertices:");
    scanf ("%d", &n);
    printf ("\n Enter the Adjacency matrix:");
    for(i = 0; i < n; ++i)
        {   
        for(j = 0; j < n; ++j)     
            {
            printf("\n Edge exist between vertices %d-%d :", i, j);    
            scanf("%d", &g[i][j]);
            }
    }
    for(i = 0; i < n; ++i) 
        {    
        visited[i] = 0; 
        }
    dfs(0);
}
void dfs(int i) 
{
    int j;
    printf ("\n %d", i);
    visited[i] = 1;
    for (j = 0; j < n; j++)
        {    
            if(!visited[j] && g[i][j] == 1)     
            {	
                dfs(j);      
            }
        }
}