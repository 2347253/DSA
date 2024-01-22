#include <stdio.h>  
#define MAX 30  
typedef struct edge {  
  int u, v, w;  // u and v represent team indices, w represents the weight (e.g., team synergy)
} edge;  
typedef struct edge_list {  
  edge data[MAX];  
  int n;  
} edge_list;  
edge_list elist;  
int Graph[MAX][MAX], n;  
edge_list spanlist;  

void kruskalAlgo();  
int find(int belongs[], int vertexno);  
void applyUnion(int belongs[], int c1, int c2);  
void sort();  
void print();  

// Applying Kruskal Algo  
void kruskalAlgo() {  
  int belongs[MAX], i, j, cno1, cno2;  
  elist.n = 0;  

  // Assuming n is the number of esports teams
  for (i = 1; i < n; i++)  
    for (j = 0; j < i; j++) {  
      // The weight of the edge could represent team synergy or some other relevant metric
      if (Graph[i][j] != 0) {  
        elist.data[elist.n].u = i;  
        elist.data[elist.n].v = j;  
        elist.data[elist.n].w = Graph[i][j];  
        elist.n++;  
      }  
    }  

  sort();  
  for (i = 0; i < n; i++)  
    belongs[i] = i;  

  spanlist.n = 0;  
  for (i = 0; i < elist.n; i++) {  
    cno1 = find(belongs, elist.data[i].u);  
    cno2 = find(belongs, elist.data[i].v);  
  
    if (cno1 != cno2) {  
      spanlist.data[spanlist.n] = elist.data[i];  
      spanlist.n = spanlist.n + 1;  
      applyUnion(belongs, cno1, cno2);  
    }  
  }  
}  

int find(int belongs[], int vertexno) {  
  return (belongs[vertexno]);  
}  

void applyUnion(int belongs[], int c1, int c2) {  
  int i;  
  for (i = 0; i < n; i++)  
    if (belongs[i] == c2)  
      belongs[i] = c1;  
}  

// Sorting algo  
void sort() {  
  int i, j;  
  edge temp;  
  for (i = 1; i < elist.n; i++)  
    for (j = 0; j < elist.n - 1; j++)  
      if (elist.data[j].w > elist.data[j + 1].w) {  
        temp = elist.data[j];  
        elist.data[j] = elist.data[j + 1];  
        elist.data[j + 1] = temp;  
      }  
}  

// Printing the result  
void print() {  
  int i, cost = 0;  
  printf("Esports Team Synergy Graph:\n");
  for (i = 0; i < spanlist.n; i++) {  
    printf("%d - %d : Synergy %d\n", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);  
    cost = cost + spanlist.data[i].w;  
  }  
  printf("\nTotal Synergy Cost: %d\n", cost);  
}  

int main() {  
  int i, j;  

  // Assuming n is the number of esports teams
  n = 6;  

  // Synergy values between teams (adjust as needed)
  int synergyValues[6][6] = {
    {0, 4, 4, 0, 0, 0},
    {4, 0, 2, 0, 0, 0},
    {4, 2, 0, 3, 4, 0},
    {0, 0, 3, 0, 3, 0},
    {0, 0, 4, 3, 0, 0},
    {0, 0, 2, 0, 3, 0}
  };

  // Fill the Graph matrix based on synergy values
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      Graph[i][j] = synergyValues[i][j];
    }
  }

  kruskalAlgo();  
  print();  

  return 0;
}

