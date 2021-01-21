#include<stdio.h>

#define size 20
#define True 1
#define False 0


int graph[size][size], visit[size];
int queue[size];
int front=-1,  rear=-1, n;

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

void BFS(int v1)
{
    int v2, i;

    visit[v1] = True;
    front=rear= -1;
    queue[++rear]=v1;

    while(front!=rear)
    {
        v1 = queue[++front];
        printf("%d \n", v1);
        for(v2=0; v2<n; v2++)
        {
            if(graph[v1][v2]==True && visit[v2]==False)
            {
                queue[++rear] = v2;
                visit[v2] = True;
            }
        }
    }
   	for(i=1; i<=n; i++){
  if(graph[v1][i] && !visit[i])
     queue[++rear]=i;
	}
}

void main()
{
    int v1, v2, edges;
    float complexity;
    char ans='y';

    printf("\n  The Breadth-First Search Algorithm \n\n");

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
            printf("The Breadth First Search of the Graph is \n");
            BFS(v1);
            getch();
        }
        printf("\n Do you want to traverse from any other node? (y/n) : \t");
        ans = getche();
    } while(ans == 'y');

    complexity = n + edges;
    printf("\n\n The Complexity of BFS Algorithm  is O(V + E) = \t %.2f ", complexity);
    printf("\n\n");

    return 0;
}