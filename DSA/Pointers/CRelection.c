#include <stdio.h>
#include <string.h>

// Candidate structure
typedef struct {
    char name[100];
    int regNum;  // Registration number for each candidate
    int votes;   // Votes received by the candidate
} Candidate;

int main() {
    int numOfStudents, numOfCandidates, foulVotes = 0;

    // Input number of candidates
    printf("Enter number of candidates: ");
    scanf("%d", &numOfCandidates);

    // Array of candidates
    Candidate candidates[numOfCandidates];

    // Initialize candidates and vote count
    for (int i = 0; i < numOfCandidates; i++) {
        printf("Enter name of candidate %d: ", (i + 1));
        scanf("%s", candidates[i].name);
        printf("Enter registration number of candidate %d: ", (i + 1));
        scanf("%d", &candidates[i].regNum);
        candidates[i].votes = 0;  // Initialize vote count to 0
    }

    // Input number of students
    printf("Enter number of students (voters): ");
    scanf("%d", &numOfStudents);

    printf("Press 'b' to start the voting process...\n");
    getchar();  // To consume the newline after the last input
    char b = getchar();  // Simulate the faculty pressing the key to start voting

    if (b == 'b') {
        for (int i = 0; i < numOfStudents; i++) {
            int regNum;
            printf("\nStudent %d, enter the candidate's registration number to cast your vote: ", i + 1);
            scanf("%d", &regNum);

            // Check if the registration number is valid
            int validVote = 0;
            for (int j = 0; j < numOfCandidates; j++) {
                if (candidates[j].regNum == regNum) {
                    candidates[j].votes++;  // Increment the vote for the correct candidate
                    printf("Vote cast for %s (Registration Number: %d)\n", candidates[j].name, candidates[j].regNum);
                    validVote = 1;
                    break;
                }
            }

            // If the vote is not valid (registration number doesn't match any candidate)
            if (!validVote) {
                printf("Invalid registration number! Foul vote counted.\n");
                foulVotes++;
            }
        }

        // Display total votes and foul votes
        printf("\nVoting Results:\n");
        for (int i = 0; i < numOfCandidates; i++) {
            printf("Candidate %s (Registration Number: %d) received %d votes.\n", candidates[i].name, candidates[i].regNum, candidates[i].votes);
        }
        printf("Number of foul votes: %d\n", foulVotes);

        // Determine the winner
        int maxVotes = -1;
        int winnerIndex = -1;
        for (int i = 0; i < numOfCandidates; i++) {
            if (candidates[i].votes > maxVotes) {
                maxVotes = candidates[i].votes;
                winnerIndex = i;
            }
        }

        // Declare the winner
        if (winnerIndex != -1) {
            printf("\nThe new class representative is %s with %d votes!\n", candidates[winnerIndex].name, candidates[winnerIndex].votes);
        } else {
            printf("\nNo valid votes were cast.\n");
        }
    } else {
        printf("Invalid input. Voting process not started.\n");
    }

    return 0;
}
