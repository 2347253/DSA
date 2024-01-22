#include <stdio.h>    
#include <limits.h>    
#define teams 6  /*Define the number of esports teams in the graph*/  

/* create minimum_key() method for finding the team that has minimum key-value and that is not added in MST yet */   
int minimum_key(int k[], int mst[])    
{  
    int minimum = INT_MAX, min, i;    
      
    /*iterate over all teams to find the team with minimum key-value*/  
    for (i = 0; i < teams; i++)  
        if (mst[i] == 0 && k[i] < minimum)   
            minimum = k[i], min = i;    
    return min;    
}    

/* create prim() method for constructing and printing the MST.  
The g[teams][teams] is an adjacency matrix that defines the graph for MST.*/  
void prim(int g[teams][teams])    
{    
    /* create array of size equal to total number of teams for storing the MST*/  
    int parent[teams];    
    /* create k[teams] array for selecting an edge having minimum weight*/  
    int k[teams];       
    int mst[teams];      
    int i, count, team, v; /*Here 'v' is the team*/  

    for (i = 0; i < teams; i++)  
    {  
        k[i] = INT_MAX;  
        mst[i] = 0;    
    }  

    k[0] = 0; /*It selects the first team as the root of MST*/  
    parent[0] = -1;   /* set first value of parent[] array to -1 to make it root of MST*/  

    for (count = 0; count < teams - 1; count++)    
    {    
        /*select the team having minimum key and that is not added in the MST yet from the set of teams*/  
        team = minimum_key(k, mst);    
        mst[team] = 1;    
        
        for (v = 0; v < teams; v++)    
        {  
            if (g[team][v] && mst[v] == 0 && g[team][v] < k[v])    
            {  
                parent[v] = team, k[v] = g[team][v];    
            }  
        }  
    }    
    /*Print the constructed Minimum Spanning Tree*/  
    printf("\n Edge \t  Weight\n");  
    for (i = 1; i < teams; i++)    
        printf(" %d <-> %d    %d \n", parent[i], i, g[i][parent[i]]);    
}    

int main()    
{    
    int g[teams][teams] = {
        {0, 4, 4, 0, 0, 0},
        {4, 0, 2, 0, 0, 0},
        {4, 2, 0, 3, 4, 0},
        {0, 0, 3, 0, 3, 0},
        {0, 0, 4, 3, 0, 0},
        {0, 0, 2, 0, 3, 0}
    };   

    prim(g);    
    return 0;  
}

