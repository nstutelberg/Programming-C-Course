// HW #12, Nolan Stutelberg
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 21
#define NUM_QUIZZES 4

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int id;
    int quizzes[NUM_QUIZZES];
    int exam;
} Student;

// Set fileName as a const since it is never expected to change. Same with the struct that is defined above.
void studentDataReader(const char *fileName, Student *students, int *studentCount);
void printStudentData(const Student *students, int studentCount);
void calculateStudentStats(const Student *students, int studentCount);

int main()
{
    printf("HW #12: Nolan Stutelberg\n");
    Student *students = (Student *)malloc(MAX_STUDENTS * sizeof(Student));

    // run the code if the memory was allocated correctly
    if (students)
    {
        int studentCount = 0;

        studentDataReader("HW12Data.txt", students, &studentCount);
        printStudentData(students, studentCount);
        calculateStudentStats(students, studentCount);
        free(students);
    }

    return 0;
}

void studentDataReader(const char *fileName, Student *students, int *studentCount)
{
    FILE *file = fopen(fileName, "r");

    // Providing info to the user if the file cannot be opened
    if (!file)
    {
        printf("Error opening file");
    }

    // Buffer to hold each line from the file. This makes sure that any value that is 50 characters or less can be read at a time. And fgets() requires a buffer
    char line[50];
    while (fgets(line, sizeof(line), file) && *studentCount < MAX_STUDENTS)
    {
        Student *s = &students[*studentCount];

        // Storing the value of where the read data ends
        int endPoint;

        // Using sscanf vs scanf because sscanf is used for reading data from a string or character array
        int numColumns = sscanf(line, "%20[^0-9]%d %d %d %d %d %d",
                                s->name, &s->id, &s->quizzes[0], &s->quizzes[1],
                                &s->quizzes[2], &s->quizzes[3], &s->exam);

        // There should always be 7 columns and print an error if that is not the case
        if (numColumns != 7)
        {
            printf("Error parsing line: %s\n", line);
        }

        (*studentCount)++;
    }

    fclose(file);
}

void printStudentData(const Student *students, int studentCount)
{
    printf("================================= DATA ==========================\n");
    printf("Set# Name                 ID   Quiz 1 Quiz 2 Quiz 3 Quiz 4  Exam\n");
    printf("---- -------------------- ---- ------ ------ ------ ------ ------\n");

    for (int i = 0; i < studentCount; i++)
    {
        const Student *s = &students[i];
        printf("#%2d: %-20s %4d ", i, s->name, s->id);
        for (int j = 0; j < NUM_QUIZZES; j++)
        {
            printf("%6d ", s->quizzes[j]);
        }
        printf("%6d\n", s->exam);
    }
}

void calculateStudentStats(const Student *students, int studentCount)
{
    // Declaring arrays for the calculations shown in the STATISTICS section. Need to set lowest scores to 100 so that every score that is processed will be lower than 100.
    // highestScores is fine by default since it is initialized to 0.
    int highestScores[NUM_QUIZZES + 1] = {0};
    int lowestScores[NUM_QUIZZES + 1];
    for (int i = 0; i <= NUM_QUIZZES; i++)
    {
        lowestScores[i] = 100;
    }
    int totalScores[NUM_QUIZZES + 1] = {0};
    int scoresCount[NUM_QUIZZES + 1] = {0};

    // In this for loop, the `->` symbol is used to access elements of the students struct by using a pointer to the struct.
    // Another method would be to not use a pointer and acecss the structure directly, but it is less efficient because not using pointers may lead to the struct being copied over and over again
    for (int i = 0; i < studentCount; i++)
    {
        const Student *s = &students[i];
        for (int j = 0; j < NUM_QUIZZES; j++)
        {
            if (s->quizzes[j] > 0)
            {
                if (s->quizzes[j] > highestScores[j])
                    highestScores[j] = s->quizzes[j];
                if (s->quizzes[j] < lowestScores[j])
                    lowestScores[j] = s->quizzes[j];
                totalScores[j] += s->quizzes[j];
                scoresCount[j]++;
            }
        }
        if (s->exam > highestScores[NUM_QUIZZES])
            highestScores[NUM_QUIZZES] = s->exam;
        if (s->exam < lowestScores[NUM_QUIZZES] && s->exam > 0)
            lowestScores[NUM_QUIZZES] = s->exam;
        totalScores[NUM_QUIZZES] += s->exam;
        scoresCount[NUM_QUIZZES]++;
    }

    printf("============================ STATISTICS =========================\n");
    printf("     Highest Scores: ");
    for (int i = 0; i <= NUM_QUIZZES; i++)
    {
        printf("%8d ", highestScores[i]);
    }
    printf("\n     Lowest Scores:  ");
    for (int i = 0; i <= NUM_QUIZZES; i++)
    {
        printf("%8d ", lowestScores[i]);
    }
    printf("\n     Average Scores: ");
    for (int i = 0; i <= NUM_QUIZZES; i++)
    {
        if (scoresCount[i] > 0)
        {
            printf("%8d ", totalScores[i] / scoresCount[i]);
        }
        else
        {
            printf(" NA ");
        }
    }
    printf("\n*** Finished! :) ***\n");
}
/*
Sample output:

HW #12: Nolan Stutelberg
================================= DATA ==========================
Set# Name                 ID   Quiz 1 Quiz 2 Quiz 3 Quiz 4  Exam
---- -------------------- ---- ------ ------ ------ ------ ------
# 0: Julie Adams          1234     52      7    100     78     34
# 1: Harry Smith          2134     90     36     90     77     30
# 2: Tuan Nguyen          3124    100     45     20     90     70
# 3: Jorge Gonzales       4532     11     17     81     32     77
# 4: Amanda Trapp         5678     20     12     45     78     34
# 5: Lou Mason            6134     34     80     55     78     45
# 6: Sarah Black          7874     60    100     56     78     78
# 7: Bryan Devaux         8026     70     10     66     78     56
# 8: Ling Wong            9893     34      9     77     78     20
# 9: Bud Johnson          1947     45     40     88     78     55
#10: Joe Giles            2877     55     50     99     78     80
#11: Jim Nelson           3189     82     80    100     78     77
#12: Paula Hung           4602     89     50     91     78     60
#13: Ted Turner           5405     11     11      0     78     10
#14: Evelyn Gilley        6999      0     98     89     78     20
============================ STATISTICS =========================
     Highest Scores:      100      100      100       90       80
     Lowest Scores:        11        7       20       32       10
     Average Scores:       53       43       75       75       49
*** Finished! :) ***
*/