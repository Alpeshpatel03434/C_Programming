# Depth-first search

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
        print("\n\n The Adjacency matrix for the Graph : ", end="")

        # displaying the 2D array
        for i in range(0, self.v):
            print()
            for j in range(0, self.v):
                print(" ", Graph.adjMatrix[i][j], end="")

                # Function to perform DFS on the graph

    def DFS(self, start, visited):

        # Print current node
        print(start, end=' ')

        # Set current node as visited
        visited[start] = True

        # For every node of the graph
        for i in range(self.v):

            # If some node is adjacent to the
            # current node and it has not
            # already been visited
            if (Graph.adjMatrix[start][i] == 1 and (not visited[i])):
                self.DFS(i, visited)


if __name__ == '__main__':
    print("\n The Depth-First Search Algorithm ")
    print("\n --------------------------------- \n\n")

    number_of_vertex = int(input(" Enter number of Vertex :\t"))
    number_of_Edges = int(input(" Enter number of Edges :\t"))
    print("\n")

    graph = Graph(number_of_vertex, number_of_Edges)

    for i in range(0, number_of_Edges):
        v1 = int(input(" Enter v1:\t"))
        v2 = int(input(" Enter v2:\t"))
        print("\n")
        graph.addEdge(v1, v2)

    graph.displayAdjacencyMatrix()

    visited = [False] * number_of_vertex
    search = int(input("\n\n Enter the Vertex from which you want to Traverse: \t"))
    print("\n The Depth First Search of the Graph is")
    graph.DFS(search, visited)

    complexity = number_of_vertex + number_of_Edges;
    print("\n\n The Complexity of BFS Algorithm is O(V + E) = \t", complexity)
    print("\n")
