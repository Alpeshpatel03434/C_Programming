# Breadth-first search

class Graph:
    adjMatrix = []

    # Function to fill empty adjacency matrix
    def __init__(self, v, e):
        self.v = v
        self.e = e

        Graph.adjMatrix = [[0 for i in range(v)] for j in range(v)]

    # Function to add an edge to the graph
    def addEdge(self, start, e):

        # Considering a bidirectional edge
        Graph.adjMatrix[start][e] = 1
        Graph.adjMatrix[e][start] = 1

    def displayAdjacencyMatrix(self):
        print("\n\n The Adjacency matrix for the Graph :", end="")

        # displaying the 2D array
        for i in range(0, self.v):
            print()
            for j in range(0, self.v):
                print("", Graph.adjMatrix[i][j], end="")

                # Function to perform DFS on the graph

    def BFS(self, start):

        # Visited vertex
        visited = [False] * self.v
        queue = [start]

        # Set source as visited
        visited[start] = True

        while queue:
            vis = queue[0]

            # Print current node
            print(vis, end=' ')
            queue.pop(0)

            # For every adjacent vertex to the current vertex
            for i in range(self.v):
                if (Graph.adjMatrix[vis][i] == 1 and (not visited[i])):
                    # append the adjacent node in queue
                    queue.append(i)
                    # set visited
                    visited[i] = True


if __name__ == '__main__':
    print("\n The Breadth-First Search Algorithm ")
    print("\n ----------------------------------- \n\n")

    number_of_vertex = int(input(" Enter number of Vertex :\t"))
    number_of_Edges = int(input(" Enter number of Edges :\t"))
    print("\n")

    graph = Graph(number_of_vertex, number_of_Edges)

    for i in range(0, number_of_Edges):
        v1 = int(input("  Enter v1:\t"))
        v2 = int(input("  Enter v2:\t"))
        print("\n")
        graph.addEdge(v1, v2)

    graph.displayAdjacencyMatrix()

    print("\n")
    search = int(input("\n Enter the Vertex from which you want to Traverse: \t"))
    print("\n The Breadth First Search of the Graph is :")
    graph.BFS(search)

    complexity = number_of_vertex + number_of_Edges;
    print("\n\n The Complexity of BFS Algorithm is O(V + E) = \t", complexity);
    print("\n")
