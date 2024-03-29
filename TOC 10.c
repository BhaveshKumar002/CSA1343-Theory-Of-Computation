#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 100

struct Node
{
    int state;
    struct Node* next;
};

struct List
{
    struct Node* head;
};

struct Node* createNode(int state)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->state = state;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct List* adjList, int src, int dest)
{
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src].head;
    adjList[src].head = newNode;
}

void computeEpsilonClosure(int state, struct List* adjList, int epsilonClosure[])
{
    if (epsilonClosure[state])
        return;
    epsilonClosure[state] = 1;
    struct Node* curr = adjList[state].head;
    while (curr != NULL)
	{
        if (curr->state != state) 
            computeEpsilonClosure(curr->state, adjList, epsilonClosure);
        curr = curr->next;
    }
}

void printEpsilonClosure(int numStates, struct List* adjList, int epsilonClosure[])
{
    printf("Epsilon-Closure of States:\n");
    for (int i = 0; i < numStates; i++)
	{
        printf("e-closure(q%d) = { ", i);
        computeEpsilonClosure(i, adjList, epsilonClosure);
        for (int j = 0; j < numStates; j++)
		{
            if (epsilonClosure[j])
                printf("q%d ", j);
        }
        printf("}\n");
        for (int k = 0; k < numStates; k++)
            epsilonClosure[k] = 0;
    }
}

int main()
{
    int numStates, numTransitions;
    printf("Enter the number of states: ");
    scanf("%d", &numStates);
    printf("Enter the number of transitions: ");
    scanf("%d", &numTransitions);
    struct List* adjList = (struct List*)malloc(numStates * sizeof(struct List));
    int epsilonClosure[MAX_STATES] = {0};
    for (int i = 0; i < numStates; i++)
        adjList[i].head = NULL;
    printf("Enter transitions in the format (src dest):\n");
    for (int i = 0; i < numTransitions; i++)
	{
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(adjList, src, dest);
    }
    printEpsilonClosure(numStates, adjList, epsilonClosure);
    return 0;
}
