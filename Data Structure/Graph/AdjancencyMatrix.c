// C program for the above approach
#include <stdio.h>

// N vertices and M Edges
int N, M;

// Function to create Adjacency Matrix
void createAdjMatrix(int Adj[][N],
					int arr[][2])
{

	// Initialise all value to this
	// Adjacency list to zero
	for (int i = 0; i < N ; i++) {

		for (int j = 0; j < N ; j++) {
			Adj[i][j] = 0;
		}
	}

	// Traverse the array of Edges
	for (int i = 0; i < M; i++) {

		// Find source and destination of vertices
		int source = arr[i][0];
		int destination = arr[i][1];
        
		// Update value to 1
		Adj[source][destination] = 1;
		Adj[source][destination] = 1;
	}
}

// Function to print the created
// Adjacency Matrix
void printAdjMatrix(int Adj[][N])
{

	// Traverse the Adj[][]
	for (int i = 0; i < N ; i++) {
		for (int j = 0; j < N ; j++) {

			// Print the value at Adj[i][j]
			printf("%d ", Adj[i][j]);
		}
		printf("\n");
	}
}

// Driver Code
int main()
{

	// Number of vertices
	N = 6;

	// Given Edges
	int arr[][2]
		= { { 0, 1 },{ 0, 2 },{ 1, 2 }, { 2, 3 }, { 4, 5 }, { 5, 1 } };

	// Number of Edges
	M = sizeof(arr) / sizeof(arr[0]);
    printf("Number of Edges : %d,\n\n",M);
	// For Adjacency Matrix
	int Adj[N][N];

	// Function call to create
	// Adjacency Matrix
	createAdjMatrix(Adj, arr);

	// Print Adjacency Matrix
	printAdjMatrix(Adj);

	return 0;
}
