/* CS261- Assignment 1 - Q. 0*/
/* Name: Alexander Laquitara
 * Date: 3/28/2016
 * Solution description:  Pointer practice with integer x being modified by fooA function
 */
 
#include <stdio.h>
#include <stdlib.h>

/*********************************************************************
 ** Function: fooA
 ** Description: prints the value and address of a int pointer
 ** Parameters: Pointer to an int.
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void fooA(int* iptr){
    int **ptr= &iptr;
    
    /*Print the value pointed to by iptr*/
    printf("Printing the value pointed to by iptr: ");
    printf("%d \n\n",*iptr);
    
    /*Print the address pointed to by iptr*/
    printf("Printing the address pointed to by iptr: ");
    printf("%p \n\n", iptr);
    
    /*Print the address of iptr itself*/
    printf("Printing the address of iptr: ");
    printf("%p \n\n", ptr);
}

int main(){
    /*declare an integer x*/
    int x = 261;
    
    /*print the address of x*/
    printf("Printing the address of x: ");
    printf("%p \n\n", &x);
    
    /*Call fooA() with the address of x*/
    printf("Calling fooA() with the address of x:\n\n");
    fooA(&x);
    /*print the value of x*/
    printf("Printing the value of x: ");
    printf("%d \n\n",x);
    return 0;
    
}

