#include <stdio.h>

typedef struct {
    int totalRuns;
    int wickets;
    int overs;
} MatchStats;

MatchStats match = {0, 0, 0};

void printMatchStatistics();
void printRunsScored();
void updateScore();
void showResults();

int main() {
    int choice;

    while (1) {
        printf("\nCricket Score Display\n");
        printf("1. Print Match Statistics\n");
        printf("2. Print Runs Scored\n");
        printf("3. Update Score\n");
        printf("4. Show Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printMatchStatistics();
                break;
            case 2:
                printRunsScored();
                break;
            case 3:
                updateScore();
                break;
            case 4:
                showResults();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void printMatchStatistics() {
    printf("\nMatch Statistics:\n");
    printf("Total Runs: %d\n", match.totalRuns);
    printf("Wickets: %d\n", match.wickets);
    printf("Overs: %d\n", match.overs);
}

void printRunsScored() {
    printf("\nRuns Scored: %d\n", match.totalRuns);
}

void updateScore() {
    int runs, wickets;
    printf("Enter runs scored in the last over: ");
    scanf("%d", &runs);
    match.totalRuns += runs;

    printf("Enter number of wickets fallen: ");
    scanf("%d", &wickets);
    match.wickets += wickets;

    printf("Enter total number of overs played: ");
    scanf("%d", &match.overs);

    printf("Score updated successfully.\n");
}

void showResults() {
    if (match.wickets >= 10) {
        printf("All wickets fallen. Match Over.\n");
    } else {
        printf("Match is ongoing.\n");
    }
}
