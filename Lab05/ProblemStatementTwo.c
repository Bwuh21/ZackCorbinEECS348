#include <stdio.h>

void print_combinations(int score) {
    if (score == 0) {
        printf("0 TD + 2pt, 0 TD + FG, 0 TD, 0 3pt FG, 0 Safety\n");
        return;
    }

    for (int touchdown = 0; touchdown <= score / 6; touchdown++) {
        for (int fieldgoal = 0; fieldgoal <= score / 3; fieldgoal++) {
            for (int safety = 0; safety <= score / 2; safety++) {
                for (int touchdown_2pt = 0; touchdown_2pt <= (score - (touchdown * 6 + fieldgoal * 3 + safety * 2)) / 8; touchdown_2pt++) {
                    for (int touchdown_fieldgoal = 0; touchdown_fieldgoal <= (score - (touchdown * 6 + fieldgoal * 3 + safety * 2 + touchdown_2pt * 8)) / 7; touchdown_fieldgoal++) {
                        int remaining_score = score - (touchdown * 6 + fieldgoal * 3 + safety * 2 + touchdown_2pt * 8 + touchdown_fieldgoal * 7);
                        if (remaining_score == 0) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", touchdown_2pt, touchdown_fieldgoal, touchdown, fieldgoal, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }
        
        printf("Possible combinations of scoring plays:\n");
        print_combinations(score);
    }

    return 0;
}
