/**
 * @file
 * @brief Link to problem statement
 * https://cs50.harvard.edu/x/2021/psets/3/tideman/ 
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
char* candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, char* name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool willCycleExist(int start, int current);

int main(int argc, char* argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count;
    printf("Number of voters: ");
    scanf("%d", &voter_count);

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char name[50];
            printf("Rank %i: ", j + 1);
            scanf("%s", name);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, char* name, int ranks[])
{
    for(int i = 0; i < candidate_count; i++) {
        if(strcmp(candidates[i], name) == 0) {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for(int i = 0; i < candidate_count - 1; i++) {
        for(int j = i + 1; j < candidate_count; j++) {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;
    for(int i = 0; i < candidate_count - 1; i++) {
        for(int j = i + 1; j < candidate_count; j++) {
            if(preferences[i][j] == preferences[j][i]) {
                break;
            }
            if(preferences[i][j] > preferences[j][i]) {
                pair temp;
                temp.winner = i;
                temp.loser = j;
                pairs[pair_count++] = temp;
            } else {
                pair temp;
                temp.winner = j;
                temp.loser = i;
                pairs[pair_count++] = temp;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    bool swapped;
    for(int i = 0; i < pair_count - 1; i++) {
        swapped = false;
        for(int j = 0; j < pair_count - i; j++) {
            if(preferences[pairs[j].winner][pairs[j].loser] < preferences[pairs[j+1].winner][pairs[j+1].loser]) {
                pair temp = pairs[j];
                pairs[j] = pairs[j+1];
                pairs[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) {
            break;
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for(int i = 0; i < pair_count; i++) 
        locked[pairs[i].winner][pairs[i].loser] = !willCycleExist(pairs[i].winner, pairs[i].loser);;
}

// Go through the graph to find if there exist a cycle
bool willCycleExist(int start, int current) {
    if(current == start) return true;

    for(int i = 0; i < candidate_count; i++)
        if(locked[current][i])
            return willCycleExist(start, i);

    return false;
}

// Print the winner of the election
void print_winner(void)
{
    int trueCounts;
     for(int i = 0; i < candidate_count; i++) {
        trueCounts = 0;
        for(int j = 0; j < candidate_count; j++) {
            if(locked[j][i]) trueCounts++;
            if(j == candidate_count - 1 && trueCounts == 0) {
                    printf("%s\n", candidates[i]);
                    return;
            }
        }
    }
}

