#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Global Variables*/
char playerName[20];
// board
char board[8][17];
int b_row = 8;
int b_column = 17;

char cposition = ' ';


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
void clearScreen();
void print_greeting(int star, char* name);
void display_board();
void print_score(player* thePlayer);
void game_activity(player* thePlayer);
void update_board();
void print_result(player* thePlayer);

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
        0
    };

    // show title
    print_title(number_of_star, title);
    print_record(record_star, record_title);
    // get player name
    getPlayerName();
    // set player name
    setPlayerName(&player1 , playerName);
    // greetings
    print_greeting(greeting_star, player1.name);
    clearScreen();

    display_board(b_row, b_column);

    game_activity(&player1);
    //board[0][0] = '4';
    //printf("%c\n", board[0][2]);
    return 0;
}

void game_activity(player* thePlayer) {
    int continue_game = 1;
    char input = ' ';
    int x = 0;
    int y = 2;
    cposition = board[x][y];
    thePlayer->score = cposition - '0';

    while (continue_game == 1) {
        print_score(thePlayer);
        printf("Each number in the map represents the number of attractions along each street.\n");
        printf("You may only move to the right or move down!\n\n");

        printf("Press \'R\' to move right\n");
        printf("Press \'D\' to move down\n");
        printf("Press \'Q\' to quit\n");
        printf("Please choose your next action:\n");
        scanf("%c", &input);

        if (input == 'Q') {
            continue_game = 0; 
        } else if (input == 'R') {
            y = y + 4;
            // append score
            thePlayer->score += board[x][y] - '0';

            // add line
            board[x][y-1] = '|'; 
            board[x][y+1] = '|'; 

            // check end
            if (x == 7 && y == 14) {
                print_result(thePlayer);
                return;
            }
        } else if (input == 'D') {
           x = x + 1;
           // append score
           thePlayer->score += board[x][y] - '0';

           // add line
            board[x][y-1] = '|'; 
            board[x][y+1] = '|'; 

            // check end
            if (x == 7 && y == 14) {
                print_result(thePlayer);
                return;
            }
        } else {
           // do nothing 
        }

        clearScreen();
        update_board();
    }
    
}

void print_result(player* thePlayer) {
    printf("Congratulation! You have completed your tour!\n\n");
    printf("Total attractions you have visited = %d\n\n", thePlayer->score);
    printf("Thanks for playing!!! See you again ...");
}

void update_board() {
    /* Display Board */
	for(int row = 0;row<b_row;row++) {
		for(int column = 0;column<b_column;column++) {
			printf("%c", board[row][column]);
		}
		printf("\n");
	}
	
	printf("\n");
}

void print_score(player* thePlayer) {
    printf("Number of attraction visited so far: %d\n\n", thePlayer->score);
}

void display_board() {
	/* Insert values into Board */
    srand((unsigned)time(NULL));
	for(int row = 0; row < b_row; row++) {
        for(int column = 0; column < b_column; column++) {
            int random_number = rand() % 10;

            if (column == 0 || column % 4 == 0) {
                board[row][column] = '-';
            } else if (column % 2 == 0) {
                // convert int to char
                char c_rand = random_number + '0';
                board[row][column] = c_rand;
            } else {
                if (row == 0 && column == 3) {
                    board[row][column] = '|';
                } else if (row == 0 && column == 1) {
                    board[row][column] = '|';
                } else if (row == 7 && column == 15) {
                    board[row][column] = '|';
                } else if (row == 7 && column == 13) {
                    board[row][column] = '|';
                } else {
                    board[row][column] = ' ';
                }
            }
        }
	}

	/* Display Board */
	for(int row = 0; row < b_row; row++) {
		for(int column = 0; column < b_column; column++) {
			printf("%c", board[row][column]);
		}
		printf("\n");
	}
	printf("\n");
}

void print_greeting(int star, char* name) {
    print_star(star);
    printf("Good day %s, let\'s start the game... all the best!!!", name);
    print_star(star);
    printf("\n\nPress any key to start the game ... \n");
    getchar();    
}

void clearScreen() {
    system("@cls||clear");
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
