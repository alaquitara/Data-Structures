/* CS261- Assignment 1 - Q.4*/
/* Name: Alexander Laquitara
 * Date: 3/28/2016
 * Solution description: Fills an array of struct students with random ID
    numbers and scores.  It then prints the values, sorts the score values, and 
    prints again.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

/*********************************************************************
 ** Function:sort
 ** Description: Sorts students based on their scores
 ** Parameters: pointer to struct student and int n
 ** Pre-Conditions: the values students holds is initilized in main
 ** Post-Conditions: scores of students are sorted.
 *********************************************************************/
void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    int i,j, tempScore, tempID;
    for(i=0;i<n; i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(students[j].score>students[j+1].score)
            {
                tempScore = students[j].score;
                tempID = students[j].id;
                
                students[j].score = students[j+1].score;
                students[j].id = students[j+1].id;
                
                students[j+1].score = tempScore;
                students[j+1].id = tempID;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 5;
    
    /*Allocate memory for n students using malloc.*/
    struct student* group = malloc(n*sizeof(struct student));

    /*Generate random IDs and scores for the n students, using rand().*/
    int g, k, scores;
    int duplicate = 0; //using as a bool
    
    
    for (g = 0; g< n; g++)
    {
        do
        {
            duplicate = 0;
            group[g].id = (rand()% n+1);
            if(g !=0)
            {
                for(k = 0; k<g; k++)
                {
                    if (group[g].id == group[k].id)
                    {
                        duplicate = 1;
                    }
                }
            }
        }
        while(duplicate == 1);
        
        
        scores = (rand()%100 + 0);
        group[g].score = scores;
    }


    /*Print the contents of the array of n students.*/
    int i;
    printf("Unsorted List:\n");
    for(i = 0; i<n; i++)
    {
        printf("Student id: %d  Scores: %d\n", group[i].id, group[i].score);
    }

    /*Pass this array along with n to the sort() function*/
    sort(group, n);
    
    /*Print the contents of the array of n students.*/
    int j;
    printf("Sorted List: \n");
    for(j = 0;  j<n; j++)
    {
        printf("Student id: %d  Scores: %d\n", group[j].id, group[j].score);
    }
    return 0;
}
