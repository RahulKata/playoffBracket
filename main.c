#include <tournamentTypeFunctions.h>
#include <stdio.h>
#include <stdlib.h>

int main () {
	int tType;

	while(tType) {
		printf("Choose Tournament Type:\n\
			1.Single Elimination\n\
			2.Double Elimination\n\
			3.Round Robin\n\
			:");
		scanf("%d", tType);

		switch(tType) {
				case 1: {
					singleElimination();
					break;
				}
				case 2: {
					doubleElimination();
					break;
				}
				case 3: {
					roundRobin();
					break;
				}
				case 0: {break;}
				default: { printf("Invalid Choice. Please try again.\n");}
			}
	}
}	
