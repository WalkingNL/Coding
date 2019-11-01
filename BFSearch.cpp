#include <iostream>
#include <ctime>

using namespace std;

struct node
{
	int info;
	node* next;
};

class Queue
{
private:
	node* front;
	node* rear;
public:
	Queue();
	~Queue();
	bool isEmpty();
	void enqueue(int);
	int dequeue();
	void display();
};

void Queue::display()
{
	node* p = new node;
	p = front;
	if (front == NULL)
	{
		cout << "\n Nothing to display\n";
	}
	else
	{
		while (p != NULL)
		{
			cout << endl << p->info;
			p = p->next;
		}
	}
}

Queue::Queue()
{
	front = NULL;
	rear = NULL;
}

Queue::~Queue()
{
	delete front;
}

void Queue::enqueue(int data)
{
	node* tmp = new node;
	tmp->info = data;
	tmp->next = NULL;
	if (front == NULL)
		front = tmp;
	else
		rear->next = tmp;
	rear = tmp;
}

int Queue::dequeue()
{
	node* tmp = new node;
	int value;
	if (front == NULL)
		cout << "\n Queue is Empty\n";
	else
	{
		tmp = front;
		value = tmp->info;
		front = front->next;
		delete tmp;
	}
	return value;
}

bool Queue::isEmpty()
{
	return (front == NULL);
}

class Graph
{
private:
	int numsOfVertices; // to represent the number of vertices in the graph
	int **A; // the function of A is storing the edge between two vertices
public:
	Graph(int size = 2);
	~Graph();
	bool isConnected(int, int);
	void addEdge(int u, int v);
	void BFS(int);
};

Graph::Graph(int size)
{
	int i, j;
	if (size < 2)
		numsOfVertices = 2;
	else
		numsOfVertices = size;	

	A = new int*[numsOfVertices];
	for (i = 0; i < numsOfVertices; i++)
		A[i] = new int[numsOfVertices];
	for (i = 0; i < numsOfVertices; i++)
		for (j = 0; j < numsOfVertices; j++)
			A[i][j] = 0;
}

Graph::~Graph()
{
	for (int i = 0; i < numsOfVertices; i++)
		delete[] A[i];
	delete[] A;
}

bool Graph::isConnected(int u, int v)
{
	return (A[u - 1][v - 1] == 1);
}

void Graph::addEdge(int u, int v)
{
	A[u - 1][v - 1] = A[v - 1][u - 1] = 1;
}

void Graph::BFS(int s)
{
	Queue queue;

	bool* explored = new bool[numsOfVertices + 1]; // it keeps track of explored vertices
	for (int i = 0; i <= numsOfVertices; i++) // Initialization of all vertices as unexplored
		explored[i] = false;

	queue.enqueue(s); // Pushing of initial vertex to the queue;

	explored[s] = true; // marking it as explored;

	cout << "Breadth first search starting from vertex ";
	cout << s << " : " << endl;

	while (!queue.isEmpty())
	{
		// to pop the vertex from the queue
		int v = queue.dequeue();

		// to display the explored vertices
		cout << v << " ";

		// From the explored v try to explore all the connected vertices
		for (int w = 1; w <= numsOfVertices; w++)
		{
			// to explore the vertex w if it is connected to v and if it is unexplored
			if (isConnected(v, w) && !explored[w])
			{
				// to add the vertex w to the queue
				queue.enqueue(w);
				// to mark the vertex w as visited
				explored[w] = true;
			}
		}
	}
	
	cout << endl;
	delete[] explored;

}

int main(int argc, char* argv[])
{
	// Creates a graph with 12 vertices	
	Graph g(12);
	
	// to add edge to the graph
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(3, 6);
	g.addEdge(4, 7);
	g.addEdge(5, 6);
	g.addEdge(5, 7);

	clock_t t1;
	t1 = clock();

	// explore all vertices findable from vertex 1
	g.BFS(1);
	float diff = (double)(clock() - t1) / CLOCKS_PER_SEC;
	cout << endl << "the time taken for Breadth first search: " << diff << endl;

	return 0;
}

