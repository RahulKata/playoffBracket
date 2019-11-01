#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct team {
	char tName[20];
	struct team *rTeam;
	struct team *lTeam;
} Team;

#define bSize 8

void singleElimination();

//singleElimination
void organizeTeams(Team **);
void inorder(Team *);
void singleElimination();
Team* createSEBracket(Team* root, Team *teams[], int *t, int i);
Team** getTeams();
Team* createTeam();
Team* findWinner(Team *t, int m);
void displayTeams(Team **teams);


int main () {
	int tType;

	while(tType) {
		printf("Choose Tournament Type:\n\
1.Single Elimination\n\
2.Double Elimination\n\
:");
		scanf("%d", &tType);

		switch(tType) {
				case 1: {
					singleElimination();
					tType=0;
					break;
				}
				case 2: {
					// doubleElimination();
					tType=0;
					break;
				}
				case 0: {break;}
				default: { printf("Invalid Choice. Please try again.\n");}
			}
	}
}


void singleElimination() {
	int i = 0, m = 0;
	int t = 0;
	Team *root = NULL;
	Team **teams = getTeams();
	printf("\n");
	organizeTeams(teams);
	root = createSEBracket(root, teams, &t, i);
	root = findWinner(root, m);
	printf("Winner of the Finals: %s\n", root->tName);
}

void organizeTeams(Team **teams) {
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
	teams[4]=teams[5];
	teams[5]=teams[3];
	teams[3] = t;
}

Team* createSEBracket(Team* root, Team **teams, int *t, int i) {
	root = createTeam();
	if(i == 2) {
    root->lTeam = teams[(*t)++];
    root->rTeam = teams[(*t)++];
	}
  else {
    root->lTeam = createSEBracket(root->lTeam, teams, t, i+1);
    root->rTeam = createSEBracket(root->rTeam, teams, t, i+1);
  }
  return root;
}

Team* createTeam() {
	Team *t = (Team*) malloc(sizeof(Team));
	t->rTeam = t->lTeam = NULL;
	t->tName[0] = '\0';
	return t;
}

Team** getTeams() {
	Team *t;
  printf("Teams ---\n");
  Team **teams;
	teams = (Team **) malloc(sizeof(Team*) * bSize);
  for(int i=0; i<bSize; i++) {
    t = createTeam();
    printf("Seed %d: ", i+1);
    scanf("%s", (t->tName));
    teams[i] = t;
  }
  return teams;
}

Team* findWinner(Team *root, int m) {
	if(root->tName[0] == '\0') {
		int t;
		root->lTeam = findWinner(root->lTeam, m+1);
		root->rTeam = findWinner(root->rTeam, m+1);
		printf("Team 1 --- %s\nTeam 2 --- %s\n", root->lTeam->tName, root->rTeam->tName);
		printf("Winner: ");
		scanf("%d", &t);
		if(t == 1)
			return root->lTeam;
		else if (t == 2)
			return root->rTeam;
		}
	return root;
}
