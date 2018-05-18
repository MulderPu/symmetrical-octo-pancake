#include <stdio.h>
#include <stdlib.h>

/* Function declaration */
void print_star(int star);
void print_title(int num, char* title);

int main() {
    int number_of_star = 10;
    char title[] = "Welcome To Manhattan Tourist Problem !";

    // show title
    print_title(number_of_star, title);

    return 0;
}

void print_title(int num, char* title) {
    print_star(num);
    printf("%s", title);
    print_star(num);
}

void print_star(int star) {
    for (int i = 0; i < star; i++) {
        printf("*");
    }
}
