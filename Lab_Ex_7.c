#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Esports Player Node
struct PlayerNode
{
    int playerID;
    char playerName[50];
    struct PlayerNode *left;
    struct PlayerNode *right;
};

// Function to create a new player node
struct PlayerNode *createPlayerNode(int playerID, const char *playerName)
{
    struct PlayerNode *newNode = (struct PlayerNode *)malloc(sizeof(struct PlayerNode));
    newNode->playerID = playerID;
    strcpy(newNode->playerName, playerName);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a player into the esports team using level order traversal
struct PlayerNode *insertLevelOrder(int playerIDs[], const char *playerNames[], struct PlayerNode *teamRoot, int i, int n)
{
    if (i < n)
    {
        struct PlayerNode *temp = createPlayerNode(playerIDs[i], playerNames[i]);
        teamRoot = temp;

        teamRoot->left = insertLevelOrder(playerIDs, playerNames, teamRoot->left, 2 * i + 1, n);
        teamRoot->right = insertLevelOrder(playerIDs, playerNames, teamRoot->right, 2 * i + 2, n);
    }
    return teamRoot;
}

// Function to perform preorder traversal of the esports team
void preOrder(struct PlayerNode *teamRoot)
{
    if (teamRoot != NULL)
    {
        printf("%d - %s\n", teamRoot->playerID, teamRoot->playerName);
        preOrder(teamRoot->left);
        preOrder(teamRoot->right);
    }
}

// Function to perform inorder traversal of the esports team
void inOrder(struct PlayerNode *teamRoot)
{
    if (teamRoot != NULL)
    {
        inOrder(teamRoot->left);
        printf("%d - %s\n", teamRoot->playerID, teamRoot->playerName);
        inOrder(teamRoot->right);
    }
}

// Function to perform postorder traversal of the esports team
void postOrder(struct PlayerNode *teamRoot)
{
    if (teamRoot != NULL)
    {
        postOrder(teamRoot->left);
        postOrder(teamRoot->right);
        printf("%d - %s\n", teamRoot->playerID, teamRoot->playerName);
    }
}

// Function to display the esports team management menu
void displayMenu()
{
    printf("\nEsports Team Management Menu:\n");
    printf("1. Display Team Roster (Level Order Traversal)\n");
    printf("2. Exit\n");
}

int main()
{
    int playerIDs[] = {1, 2, 3, 4, 5, 6, 7},i;
    const char *playerNames[] = {"Player1", "Player2", "Player3", "Player4", "Player5", "Player6", "Player7"};
    int n = sizeof(playerIDs) / sizeof(playerIDs[0]);

    // Creating esports team using level order traversal
    struct PlayerNode *teamRoot = insertLevelOrder(playerIDs, playerNames, NULL, 0, n);
    
    printf("Player IDs:\n");
    for ( i = 0; i < n; ++i) {
        printf("%d ", playerIDs[i]);
    }

    printf("\n\nPlayer Names:\n");
    for ( i = 0; i < n; ++i) {
        printf("%s ", playerNames[i]);
	}
	
	printf("\n");
    
    int choice;
    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nTeam Roster (Level Order Traversal):\n");
            printf("Preorder Traversal:\n");
            preOrder(teamRoot);
            printf("\nInorder Traversal: \n");
            inOrder(teamRoot);
            printf("\nPostorder Traversal: \n");
            postOrder(teamRoot);
            break;

        case 2:
            printf("Exiting the program\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 2);

    return 0;
}

