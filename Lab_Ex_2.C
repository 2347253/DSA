#include <stdio.h>
#include <stdlib.h>

struct Player {
    char playerName[50];
    int playerID;
    struct Player *next;
};

struct Player *head = NULL; // Global head variable

void beginsert();
void begin_delete();
void random_delete();
void display();
void search();

void main()
{
    int choice = 0;
    while (choice != 6)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in begining\n2.Delete from Beginning\n3.Delete at any random location\n"
               "4.Search for a player\n5.Display\n6.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            begin_delete();
            break;
        case 3:
            random_delete();
            break;
        case 4:
            search();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Please enter a valid choice..\n");
        }
    }
}

void beginsert()
{
    struct Player *ptr, *temp;
    ptr = (struct Player *)malloc(sizeof(struct Player));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter player name: ");
        scanf("%s", ptr->playerName);
        printf("\nEnter player ID: ");
        scanf("%d", &ptr->playerID);

        if (head == NULL)
        {
            head = ptr;
            ptr->next = head; // Point to itself for the first node
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head; // Point back to the head to make it circular
            head = ptr;
        }

        printf("\nPlayer inserted\n");
    }
}

void begin_delete()
{
    struct Player *temp, *ptr;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        if (temp == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            ptr = head;
            head = head->next;
            temp->next = head;
            free(ptr);
        }

        printf("\nPlayer deleted from the beginning ...\n");
    }
}

void random_delete()
{
    struct Player *ptr, *prev;
    int loc, i = 1;
    printf("\nEnter the location of the player after which you want to perform deletion: ");
    scanf("%d", &loc);
    ptr = head;

    if (head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    while (i < loc)
    {
        prev = ptr;
        ptr = ptr->next;

        if (ptr == head)
        {
            printf("\nCan't delete\n");
            return;
        }

        i++;
    }

    prev->next = ptr->next;
    if (ptr == head)
    {
        head = head->next;
    }

    free(ptr);
    printf("\nDeleted player at location %d\n", loc);
}

void display()
{
    struct Player *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print\n");
    }
    else
    {
        printf("\nPrinting player details...\n");
        do
        {
            printf("\nPlayer Name: %s, Player ID: %d", ptr->playerName, ptr->playerID);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

void search()
{
    struct Player *ptr;
    int id, flag = 0;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter player ID you want to search: ");
        scanf("%d", &id);
        do
        {
            if (ptr->playerID == id)
            {
                printf("Player found: %s at location %d\n", ptr->playerName, flag + 1);
                flag = 1;
            }
            ptr = ptr->next;
            flag++;
        } while (ptr != head);

        if (flag == 0)
        {
            printf("Player not found\n");
        }
    }
}
