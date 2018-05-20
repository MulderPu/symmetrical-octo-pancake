#include <stdio.h>
#include <stdlib.h>

/* Global Variables*/
char playerName[20];


/* Create player struct */
typedef struct {
    char *name;
    int score;
} player;

/* Function declaration */
void print_star(int star);
void print_title(int num, char* title);
void print_record(int num, char* title);
void setPlayerName(player* thePlayer, char* newName);
void getPlayerName();

int main() {
    // variables
    int number_of_star = 10;
    int record_star = 17;
    int greeting_star = 3;
    char title[] = " Welcome To Manhattan Tourist Problem ! ";
    char record_title[] = " Previous Player's Record ";

    // set default player
    player player1 = {
        "James",
        100
    };

    // show title
    print_title(number_of_star, title);
    print_record(record_star, record_title);

    // get player name
    getPlayerName();
    // set player name
    setPlayerName(&player1 , playerName);
    print_star(greeting_star);
    printf("Good day %s, let\'s start the game... all the best!!!", player1.name);
    print_star(greeting_star);
    printf("\n\nPress any key to start the game ...");

    return 0;
}

void getPlayerName() {
    printf("Please key in your name: ");
    scanf("%s", playerName);
}

void setPlayerName(player *thePlayer, char* newName) {
    thePlayer->name = newName;
}

void print_record(int num, char* title) {
    print_star(num);
    printf("%s", title);
    print_star(num);
    printf("\n");
    printf("\t Name \t\t Score (Attractions visited)\n");

    // score print here
    printf("\t Fake_user \t\t 100\n");
    printf("\n");
}

void print_title(int num, char* title) {
    print_star(num);
    printf("%s", title);
    print_star(num);
    printf("\n");
}

void print_star(int star) {
    for (int i = 0; i < star; i++) {
        printf("*");
    }
}
