#include <bracketGenerator.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct team {
	char tName[20];
	struct team *rTeam;
	struct team *lTeam;
} Team;

#define bSize 8


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
