/* CS261- Assignment 1 - Q.1*/
/* Name: Alexander Laquitara
 * Date: 3/28/2016
 * Solution description: Assigns random and unique IDs to a group of students.
 *  Also gives the students random scores and finds the Highest, Lowest, and
 *  average scores
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


struct student{
	int id;
	int score;
};
/*********************************************************************
 ** Function: allocate
 ** Description: allocates memory for 10 struct students
 ** Parameters: none
 ** Pre-Conditions: struct student exists
 ** Post-Conditions: Memory is allocated for 10 structs students
 *********************************************************************/
struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student* group = malloc(10*sizeof(struct student));
     /*return the pointer*/
    return group;
}

/*********************************************************************
 ** Function:generate
 ** Description: Generates ID numbers and Scores for students
 ** Parameters: Pointer to a struct student.
 ** Pre-Conditions:struct student exists
 ** Post-Conditions: Values for ID and scores are set for the student
 *********************************************************************/
void generate(struct student* students)
{
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    int i, j, scores;
    int duplicate = 0; //using as a bool
    
    
    for (i = 0; i< 10; i++)
    {
        do
        {
            duplicate = 0;
            students[i].id = (rand()% 10+1);
            if(i !=0)
            {
                for(j = 0; j<i; j++)
                {
                    if (students[i].id == students[j].id)
                    {
                        duplicate = 1;
                    }
                }
            }
        }
        while(duplicate == 1);
        
        
        scores = (rand()%100 + 0);
        students[i].score = scores;
    }
}
/*********************************************************************
 ** Function:Output
 ** Description: prints the ID and Scores for struct student
 ** Parameters: Pointer to a struct student
 ** Pre-Conditions: Struct Student exists
 ** Post-Conditions: none
 *********************************************************************/
void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int i;
    for(i=0; i < 10; i++)
    {
        printf("ID%d Score%d\n",students[i].id,students[i].score);
    }
}

/*********************************************************************
 ** Function:Summary
 ** Description: Displays Max, Min and averge student scores
 ** Parameters: Pointer to a struct student.
 ** Pre-Conditions: Struct Student exists
 ** Post-Conditions: average tests scores are calculated.
 *********************************************************************/
void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int scores[10];
    int i, j, k, temp;
    int total = 0;
    double avg = 0;
    
    for(i=0;i<10;i++)
    {
        scores[i] = students[i].score;
    }
    
    //sort the scores to find min and max.  Using bubble sort
    for(i=0;i<10;i++)
    {
        for(j=0;j<10-1;j++)
        {
            if(scores[j]>scores[j+1])
            {
                temp = scores[j];
                scores[j] = scores[j+1];
                scores[j+1] = temp;
            }
        }
    }
    //average
    for (k =0; k<10; k++)
    {
        total += scores[k];
    }
    avg = total / 10;
    
    //first element in sorted array
    printf("Minimum is: %d \n", scores[0]);
    //last element in sorted array
    printf("Maximum is: %d \n", scores[9]);
    printf("Average is: %g \n", avg);
}

/*********************************************************************
 ** Function:deallocate
 ** Description: Frees up memory of a struct student
 ** Parameters: Pointer to a struct student
 ** Pre-Conditions: struct student exists
 ** Post-Conditions: Memory formerly occupied is now available.
 *********************************************************************/
void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    if (stud != NULL)
    {
        free(stud);
    }
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
