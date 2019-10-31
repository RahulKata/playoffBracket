void singleElimination();
void doubleElimination();

//singleElimination
void organizeTeams(Team **);
void inorder(Team *);
void singleElimination();
Team* createSEBracket(Team* root, Team *teams[], int *t, int i);
Team** getTeams();
Team* createTeam();
Team* findWinner(Team *t, int m);
void displayTeams(Team **teams);
