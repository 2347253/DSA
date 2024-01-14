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
struct PlayerNode *insertPlayer(struct PlayerNode *teamRoot, int playerID, const char *playerName)
{
    if (teamRoot == NULL)
    {
        return createPlayerNode(playerID, playerName);
    }

    if (playerID < teamRoot->playerID)
    {
        teamRoot->left = insertPlayer(teamRoot->left, playerID, playerName);
    }
    else if (playerID > teamRoot->playerID)
    {
        teamRoot->right = insertPlayer(teamRoot->right, playerID, playerName);
    }

    return teamRoot;
}

// Function to search for a player in the esports team
struct PlayerNode *searchPlayer(struct PlayerNode *teamRoot, int playerID)
{
    if (teamRoot == NULL || teamRoot->playerID == playerID)
    {
        return teamRoot;
    }

    if (playerID < teamRoot->playerID)
    {
        return searchPlayer(teamRoot->left, playerID);
    }
    else // playerID > teamRoot->playerID
    {
        return searchPlayer(teamRoot->right, playerID);
    }
}

// Function to find the minimum value node in the esports team
struct PlayerNode *minValuePlayerNode(struct PlayerNode *node)
{
    struct PlayerNode *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Function to delete a player from the esports team
struct PlayerNode *deletePlayer(struct PlayerNode *teamRoot, int playerID)
{
    if (teamRoot == NULL)
    {
        return teamRoot;
    }

    if (playerID < teamRoot->playerID)
    {
        teamRoot->left = deletePlayer(teamRoot->left, playerID);
    }
    else if (playerID > teamRoot->playerID)
    {
        teamRoot->right = deletePlayer(teamRoot->right, playerID);
    }
    else
    {
        // Node with only one child or no child
        if (teamRoot->left == NULL)
        {
            struct PlayerNode *temp = teamRoot->right;
            free(teamRoot);
            return temp;
        }
        else if (teamRoot->right == NULL)
        {
            struct PlayerNode *temp = teamRoot->left;
            free(teamRoot);
            return temp;
        }

        // Node with two children
        struct PlayerNode *temp = minValuePlayerNode(teamRoot->right);

        teamRoot->playerID = temp->playerID;
        strcpy(teamRoot->playerName, temp->playerName);

        teamRoot->right = deletePlayer(teamRoot->right, temp->playerID);
    }
    return teamRoot;
}

// Function to calculate the height of the esports team
int calculateTeamHeight(struct PlayerNode *teamRoot)
{
    if (teamRoot == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = calculateTeamHeight(teamRoot->left);
        int rightHeight = calculateTeamHeight(teamRoot->right);

        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

// Function to perform inorder traversal of the esports team
void inOrderPlayer(struct PlayerNode *teamRoot)
{
    if (teamRoot != NULL)
    {
        inOrderPlayer(teamRoot->left);
        printf("Player ID: %d, Player Name: %s\n", teamRoot->playerID, teamRoot->playerName);
        inOrderPlayer(teamRoot->right);
    }
}

// Function to perform preorder traversal of the esports team
void preOrderPlayer(struct PlayerNode *teamRoot)
{
    if (teamRoot != NULL)
    {
        printf("Player ID: %d, Player Name: %s\n", teamRoot->playerID, teamRoot->playerName);
        preOrderPlayer(teamRoot->left);
        preOrderPlayer(teamRoot->right);
    }
}

// Function to perform postorder traversal of the esports team
void postOrderPlayer(struct PlayerNode *teamRoot)
{
    if (teamRoot != NULL)
    {
        postOrderPlayer(teamRoot->left);
        postOrderPlayer(teamRoot->right);
        printf("Player ID: %d, Player Name: %s\n", teamRoot->playerID, teamRoot->playerName);
    }
}

// Function to display the esports team management menu
void displayEsportsMenu()
{
    printf("\nEsports Team Management System Menu:\n");
    printf("1. Insert Player\n");
    printf("2. Search Player\n");
    printf("3. Delete Player\n");
    printf("4. Calculate Team Height\n");
    printf("5. Inorder Traversal\n");
    printf("6. Preorder Traversal\n");
    printf("7. Postorder Traversal\n");
    printf("8. Exit\n");
}

int main()
{
    struct PlayerNode *esportsTeam = NULL;

    int choice;
    int playerID;
    char playerName[50];

    do
    {
        displayEsportsMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Player ID: ");
            scanf("%d", &playerID);
            printf("Enter Player Name: ");
            scanf("%s", playerName);
            esportsTeam = insertPlayer(esportsTeam, playerID, playerName);
            printf("Player inserted successfully!\n");
            break;

        case 2:
            printf("Enter Player ID to search: ");
            scanf("%d", &playerID);
            struct PlayerNode *searchResult = searchPlayer(esportsTeam, playerID);
            if (searchResult != NULL)
            {
                printf("Player ID %d found in the Esports Team.\n", playerID);
            }
            else
            {
                printf("Player ID %d not found in the Esports Team.\n", playerID);
            }
            break;

        case 3:
            printf("Enter Player ID to delete: ");
            scanf("%d", &playerID);
            esportsTeam = deletePlayer(esportsTeam, playerID);
            printf("Player ID %d deleted from the Esports Team.\n", playerID);
            break;

        case 4:
            printf("Height of the Esports Team: %d\n", calculateTeamHeight(esportsTeam));
            break;

        case 5:
            printf("Inorder Traversal:\n");
            inOrderPlayer(esportsTeam);
            printf("\n");
            break;
        case 6:
            printf("Preorder Traversal:\n");
            preOrderPlayer(esportsTeam);
            printf("\n");
            break;

        case 7:
            printf("Postorder Traversal:\n");
            postOrderPlayer(esportsTeam);
            printf("\n");
            break;

        case 8:
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 8);

    return 0;
}

