#include <stdio.h>
#include <stdlib.h>

// Define a structure for a player
struct Player {
    char playerName[50];
    int playerID;
    struct Player* next;
};

// Define the queue structure
struct Queue {
    struct Player* front;
    struct Player* rear;
};

// Function to initialize an empty queue
void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue a player into the queue
void enqueue(struct Queue* queue, char playerName[], int playerID) {
    struct Player* newPlayer = (struct Player*)malloc(sizeof(struct Player));
    if (newPlayer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Set player information
    strcpy(newPlayer->playerName, playerName);
    newPlayer->playerID = playerID;
    newPlayer->next = NULL;

    // If the queue is empty, set both front and rear to the new player
    if (isEmpty(queue)) {
        queue->front = newPlayer;
        queue->rear = newPlayer;
    } else {
        // Otherwise, add the new player to the rear and update the rear pointer
        queue->rear->next = newPlayer;
        queue->rear = newPlayer;
    }

    printf("Player %s (ID: %d) has been added to the team.\n", playerName, playerID);
}

// Function to dequeue a player from the queue
void dequeue(struct Queue* queue) {

    struct Player* removedPlayer = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty. No players to remove.\n");
        return;
    }

      queue->front = removedPlayer->next;

    printf("Player %s (ID: %d) has been removed from the team.\n", removedPlayer->playerName, removedPlayer->playerID);

    // Free the memory of the removed player
    free(removedPlayer);

    // If the queue becomes empty after dequeue, update the rear pointer to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
}

// Function to display the players in the queue
void displayQueue(struct Queue* queue) {
    struct Player* current = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }


    printf("Players in the team:\n");
    while (current != NULL) {
        printf("Player %s (ID: %d)\n", current->playerName, current->playerID);
        current = current->next;
    }
}

// Function to free the memory allocated for the queue
void freeQueue(struct Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
}

int main() {
    struct Queue teamQueue;


    int choice;
    char playerName[50];
    int playerID;

    initializeQueue(&teamQueue);

    do {
        // Display menu
        printf("\nEsports Team Management Menu:\n");
        printf("1. Add Player to Team\n");
        printf("2. Remove Player from Team\n");
        printf("3. Display Team\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter player name: ");
                scanf("%s", playerName);
                printf("Enter player ID: ");
                scanf("%d", &playerID);
                enqueue(&teamQueue, playerName, playerID);
                break;

            case 2:
                dequeue(&teamQueue);
                break;

            case 3:
                displayQueue(&teamQueue);
                break;

            case 4:
                freeQueue(&teamQueue);
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
