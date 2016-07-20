/* CS261- Assignment 1 - Q.3*/
/* Name:
 * Date:
 * Solution description: Randomly fills in contents of an array int size 20.
 *  Displays the contents of the array sorted and unsorted.
 */
 // referenced http://stackoverflow.com/questions/15955458/sort-an-array-in-a-c-function
//referencedhttp://www.dailyfreecode.com/code/sorting-array-elements-function-2605.aspx
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
/*********************************************************************
 ** Function:sort
 ** Description: bubble sort for pointer to int number
 ** Parameters: pointer to int number and int n
 ** Pre-Conditions: the number is array is filled in by main.  int n
    is determined by main also
 ** Post-Conditions: values in number are sorted.
 *********************************************************************/
void sort(int* number, int n)
{
     /*Sort the given array number , of length n*/
    int i, j;
    int temp;
    
    for (i = 0; i < n; i++)
    {
        for (j =0; j <n; j++)
        {
            if (number[i] > number[j])
                {
                    temp = number[i];
                    number[i] = number[j];
                    number[j] = temp;
                }
        }
        
    }
    
}

int main(){
    
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *ptr = malloc(n * sizeof *ptr);
    
    /*Fill this array with random numbers, using rand().*/
    int i = 0;
    while (i< n)
    {
        ptr[i]=(rand()%100 + 1);
        i++;
    }
    
    /*Print the contents of the array.*/
    printf("Contents of the array unsorted: \n");
    int j  = 0;
    while(j <n)
    {
        printf("%d, ",ptr[j]);
        j++;
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort (ptr , n);
    printf("\n\n");
    
    /*Print the contents of the array.*/
    printf("Contents of the array after sorting: \n");
    int k = 0;
    while(k < n)
    {
        printf("%d, ",ptr[k]);
        k++;
    }
    
    return 0;
}
