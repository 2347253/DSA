#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS 3
#define COLS 3

struct teamStruct
{
    char team_name[25];
    int performance[ROWS][COLS];
};

struct teamStruct esports_team;

void insertionDisplay();
void displayPerformance();
int linearSearch(int value);
void addPerformance();
void mulPerformance();

int main()
{
    int choice, value, count = ROWS * COLS, row, col;
    int continueMenu = 1;
    clrscr();
    while (continueMenu)
    {
	printf("----------------------Esports_Team_Management---------------------------\n");
	printf("Enter your Choice (1: Insert Team, 2: Display Performance, 3: Searching, 4: Add Performance, 5: Multiply Performance, 0: Exit): ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
	    printf("Enter Team Name: ");
	    scanf("%s", esports_team.team_name);
	    printf("Enter the performance data for the last %d matches:\n", count);
	    insertionDisplay();
	    break;
	case 2:
	    displayPerformance();
	    break;
	case 3:
	    printf("Enter the value to search in performance data: ");
	    scanf("%d", &value);
	    linearSearch(value);
	    break;
	case 4:
	    printf("----------------PERFORMANCE ADDITION----------------------");
	    addPerformance();
	    break;
	case 5:
	    printf("----------------PERFORMANCE MULTIPLICATION----------------------");
	    mulPerformance();
	    break;
	case 0:
	    continueMenu = 0;
	    break;
	default:
	    printf("Invalid choice. Please try again.\n");
	}
    }

    return 0;
}

void addPerformance()
{
    int i, j, sum[3][3];
    for (i = 0; i < ROWS; ++i)
	for (j = 0; j < COLS; ++j)
	{
	    sum[i][j] = esports_team.performance[i][j] + esports_team.performance[i][j];
	}

    printf("Performance after addition:\n");

    for (i = 0; i < ROWS; i++)
    {
	printf(" ");
	for (j = 0; j < COLS; j++)
	{
	    printf("%d     ", sum[i][j]);
	}
	printf("\n");
    }
}

void mulPerformance()
{
    int i, j, mul[3][3];
    for (i = 0; i < ROWS; ++i)
	for (j = 0; j < COLS; ++j)
	{
	    mul[i][j] = esports_team.performance[i][j] * esports_team.performance[i][j];
	}

    printf("Performance after multiplication:\n");

    for (i = 0; i < ROWS; i++)
    {
	printf(" ");
	for (j = 0; j < COLS; j++)
	{
	    printf("%d     ", mul[i][j]);
	}
	printf("\n");
    }
}

void displayPerformance()
{
    int i, j;
    printf("----------------------3x3 Performance Data---------------------------\n");
    for (i = 0; i < ROWS; i++)
    {
	printf(" ");
	for (j = 0; j < COLS; j++)
	{
	    printf("%d     ", esports_team.performance[i][j]);
	}
	printf("\n");
    }
}

void insertionDisplay()
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
	for (j = 0; j < COLS; j++)
	{
	    scanf("%d", &esports_team.performance[i][j]);
	}
    }

    printf("----------------------Performance Data for Team %s---------------------------\n", esports_team.team_name);

    for (i = 0; i < ROWS; i++)
    {
	printf(" ");
	for (j = 0; j < COLS; j++)
	{
	    printf("%d     ", esports_team.performance[i][j]);
	}
	printf("\n");
    }
}

int linearSearch(int value)
{
    int i, j;
    printf("----------------------------Searching----------------------------------\n");

    for (i = 0; i < ROWS; i++)
    {
	for (j = 0; j < COLS; j++)
	{
	    if (esports_team.performance[i][j] == value)
	    {
		return printf("Value %d is found in performance data at position [%d %d]\n", value,i+1,j+1);
	    }
	}
    }
    return printf("Value is not found in performance data\n");
}
