#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct team
{
    char tName[20];
    struct team *rTeam;
    struct team *lTeam;
} Team;

// #define bSize 8

//singleElimination
void singleElimination(int);

void organizeTeams(Team **, int);
void inorder(Team *);
void singleElimination();
Team *createSEBracket(Team *root, Team *teams[], int *t, int i);
Team **getTeams(int);
Team *createTeam();
Team *findWinner(Team *t, int m);
void displayTeams(Team **teams);

int main()
{
    int tType;

    printf("||||-------Welcome to The ultimate Bracket Generator-------||||\n\n    Rules:--\n       --This is a single elimination tournament\n       --You need to pick the winner in each match\n       --Losers are knocked out!\n       --Default number of teams are 8\n||||-------.........................................-------||||\n\n1.Play/Replay\n0.Exit:\n");
    scanf("%d", &tType);
    int bSize = 8;
    switch (tType)
    {
    case 1:
    {
        while (1)
        {
            printf("\nNumber of teams ----> ");
            scanf("%d", &bSize);
            if (bSize != 0 && bSize != 1)
                break;
        }

        singleElimination(bSize);
        main();
        break;
    }
    case 0:
    {
        break;
    }
    default:
    {
        printf("Invalid Choice. Please try again.\n");
    }
    }
}

void singleElimination(int bSize)
{
    int i = 0, m = 0;
    int t = 0;
    Team *root = NULL;
    Team **teams = getTeams(bSize);
    printf("\n");
    organizeTeams(teams, bSize);
    root = createSEBracket(root, teams, &t, i);
    root = findWinner(root, m);
    printf("\n Winner of the Finals!! -->  %s\n", root->tName);
}

void organizeTeams(Team **teams, int bSize)
{
    int size = bSize;
    if (size > 1)
    {
        int i;
        srand(time(NULL));

        // Start from the last element and swap one by one[excluding last element]
        for (i = size - 1; i > 0; i--)
        {
            // Pick a random index from 0 to i
            int j = rand() % (i + 1);

            // Swap arr[i] with the element at random index
            Team *temp = teams[j];
            teams[j] = teams[i];
            teams[i] = temp;
        }
    }
}

Team *createSEBracket(Team *root, Team **teams, int *t, int i)
{
    root = createTeam();
    if (i == 2)
    {
        root->lTeam = teams[(*t)++];
        root->rTeam = teams[(*t)++];
    }
    else
    {
        root->lTeam = createSEBracket(root->lTeam, teams, t, i + 1);
        root->rTeam = createSEBracket(root->rTeam, teams, t, i + 1);
    }
    return root;
}

Team *createTeam()
{
    Team *t = (Team *)malloc(sizeof(Team));
    t->rTeam = t->lTeam = NULL;
    t->tName[0] = '\0';
    return t;
}

Team **getTeams(int bSize)
{
    Team *t;
    printf("Teams ---\n");
    Team **teams;
    teams = (Team **)malloc(sizeof(Team *) * bSize);
    for (int i = 0; i < bSize; i++)
    {
        t = createTeam();
        printf("Seed %d: ", i + 1);
        scanf("%s", (t->tName));
        teams[i] = t;
    }
    return teams;
}

Team *findWinner(Team *root, int m)
{
    if (root->tName[0] == '\0')
    {
        int t;
        root->lTeam = findWinner(root->lTeam, m + 1);
        root->rTeam = findWinner(root->rTeam, m + 1);
        printf("Team 1 --- %s\nTeam 2 --- %s\n", root->lTeam->tName, root->rTeam->tName);
        printf("Winner: ");
        scanf("%d", &t);
        if (t == 1)
        {
            return root->lTeam;
        }
        else if (t == 2)
        {
            return root->rTeam;
        }
    }
    return root;
}
