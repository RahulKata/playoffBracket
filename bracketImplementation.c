/*
Project Title: Tournament Bracket Formatter
Developers: Sreejesh Saya, Rahul Kata
Language used: C
Domain: Data Structures
Project Description: This project implements the most common type of Tournament Brackets, the Single Elimination bracket using the Binary Tree data structures in C language. The default number of teams is 8 for this project. These 8 teams play against each other in a seeded manner or completely randomized. The winner moves on to the next round while the loser is knocked off the tournament. The winner of the finals is the Champion of the tournament.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct team
{
	char tName[20];
	struct team *rTeam;
	struct team *lTeam;
} Team;

void rules();
void singleElimination();
Team *createTeam();
Team **getTeams(char *);
void seedOrganize(Team **teams);
void randOrganize(Team **teams);
Team *createSEBracket(Team *root, Team *teams[], int *t, int i);
Team *getChampion(Team *root);
Team *findWinner(Team *root, int level);

#define bSize 8
#define height 4

int main()
{
	int option = 1;
	printf("\n||||-------Welcome to the Single Elimination Tournament-------||||\n");
	while (option)
	{
		printf("\n		1.Generate\n		2.Rules\n		0.Exit\n> ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
		{
			singleElimination();
			option = 0;
			break;
		}
		case 2:
		{
			rules();
			break;
		}
		case 0:
			break;
		default:
			printf("Invalid Choice, please try again.\n");
		}
	}
}

void rules()
{
	printf("Rules:--\n       --Type: Single elimination tournament\n       --You need to pick the winner in each match\n       --Losers are knocked out!\n       --Default number of teams are 8\n||||-------.........................................-------||||\n");
}

void singleElimination()
{
	int op = 1;
	Team **teams;
	int i = 0, m = 0;
	int t = 0;
	Team *root = NULL;
	printf("\n");
	printf("1.Seeded\n2.Unseeded\n");
	while (op)
	{
		printf("> ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
		{
			char type[6] = "Seed";
			teams = getTeams(type);
			seedOrganize(teams);
			op = 0;
			break;
		}
		case 2:
		{
			char type[6] = "Team";
			teams = getTeams(type);
			randOrganize(teams);
			op = 0;
			break;
		}
		case 0:
			break;
		default:
			printf("Invalid choice, please try again.\n");
		}
	}

	root = createSEBracket(root, teams, &t, i);
	root = getChampion(root);
	printf("\n||||-------.........................................-------||||\n		   Tournament Champion: %s\n||||-------.........................................-------||||\n\n", root->tName);
}

Team *createTeam()
{
	Team *t = (Team *)malloc(sizeof(Team));
	t->rTeam = t->lTeam = NULL;
	t->tName[0] = '\0';
	return t;
}

Team **getTeams(char *type)
{
	Team *t;
	printf("\nTeams ---\n");
	Team **teams;
	teams = (Team **)malloc(sizeof(Team *) * bSize);
	for (int i = 0; i < bSize; i++)
	{
		t = createTeam();
		printf("%s %d: ", type, i + 1);
		scanf("%s", (t->tName));
		teams[i] = t;
	}
	return teams;
}

void seedOrganize(Team **teams)
{
	Team *t;
	t = teams[1];
	teams[1] = teams[7];
	teams[7] = teams[5];
	teams[5] = t;
	t = teams[6];
	teams[6] = teams[2];
	teams[2] = teams[3];
	teams[3] = t;
	t = teams[4];
	teams[4] = teams[5];
	teams[5] = teams[3];
	teams[3] = t;
}

void randOrganize(Team **teams)
{
	int i;
	srand(time(NULL));

	// Start from the last element and swap one by one[excluding last element]
	for (i = bSize - 1; i > 0; i--)
	{
		// Pick a random index from 0 to i
		int j = rand() % (i + 1);

		// Swap arr[i] with the element at random index
		Team *temp = teams[j];
		teams[j] = teams[i];
		teams[i] = temp;
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

Team *getChampion(Team *root)
{
	int round = 1;
	for (int i = height; i >= 2; i--)
	{
		if (round == 1)
			printf("----------------ROUND 1---------------- \n");
		if (round == 2)
			printf("----------------ROUND 2 / SEMI-FINALS----------------\n");
		if (round == 3)
			printf("----------------FINALS----------------\n");
		root = findWinner(root, i);
		round++;
	}
	return root;
}

Team *findWinner(Team *root, int level)
{
	if (level == 2)
	{
		char w[20];
		printf("%s vs %s\n", root->lTeam->tName, root->rTeam->tName);
		printf("Winner ");
		while (1)
		{
			printf(">");
			scanf("%s", w);
			printf("\n");
			if (strcmp(w, root->lTeam->tName) == 0)
				return root->lTeam;
			else if (strcmp(w, root->rTeam->tName) == 0)
				return root->rTeam;
			else
				printf("Invalid choice, please try again.\n");
		}
	}
	else if (level > 2)
	{
		root->lTeam = findWinner(root->lTeam, level - 1);
		root->rTeam = findWinner(root->rTeam, level - 1);
	}
}
