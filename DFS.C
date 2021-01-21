#include<stdio.h>

#define size 20
#define True 1
#define False 0

int graph[size][size], visit[size];
int stack[size];
int top = -1, n;

void Create_Graph(int n)
{
    int v1, v2;
    char ans='y';

    for(v1=0; v1<n; v1++){
        for(v2=0; v2<n; v2++){
            graph[v1][v2] = False;
        }
    }

    printf("\n Enter the Vertices no. starting from '0' ");
    do{
        printf("\n Enter the vertices v1 & v2 \n");
        scanf("%d %d", &v1, &v2);
        if(v1>=n || v2>=n){
            printf("Invalid Vertex");
        }
        else{
            graph[v1][v2]=True;
            graph[v2][v1]=False;
        }
         printf("\n Add more edges ? (y/n) : \t");
         ans = getche();
    } while(ans=='y');

}

void DFS(int v)
{
      int i, n;

      printf("%d, \t", v);
      visit[v] = True;
      for(i=1; i<=size; i++)
      {
          if(graph[v][i]==True && visit[i]==False)
            {
               DFS(i);
            }
      }

      for(i=size-1; i>=0; i--)
      {
          if(graph[v][i]==True && visit[i]==False)
            {
               DFS(i);
            }
      }

}

void main()
{
    int v1, v2, edges;
    float complexity;
    char ans='y';

    printf("\n  The Depth-First Search Algorithm \n\n");

     printf("\n Enter no. of Nodes or Vertices  : \t");
    scanf("%d", &n);

    printf("\n Your  node or Vertex allocated like 0, 1, 2, 3,....");

 printf("\n Enter the no. of edges : \t");

 scanf("%d", &edges);
    Create_Graph(n);

    printf("\n The Adjacency matrix for the Graph \n");
    for(v1=0; v1<n; v1++)
    {
        for(v2=0; v2<n; v2++)
            printf(" %d", graph[v1][v2]);
        printf("\n");
    }
      getch() ;

    do{
        for(v1=0; v1<n; v1++)
            visit[v1]=False;

        printf("\n Enter the Vertex from which you want to Traverse : \t");
        scanf("%d", &v1);
        if(v1>=n)
            printf("Invalid Vertex \n");
        else{
            printf("\nThe Breadth First Search of the Graph is \n");
            DFS(v1);
            getch();
        }
        printf("\n Do you want to traverse from any other node? (y/n) : \t");
        ans = getche();
    } while(ans == 'y');

    complexity = n + edges;
    printf("\n\n The Complexity of DFS Algorithm  is O(V + E) = \t %.2f ", complexity);
    printf("\n\n");
    
    return 0;
}