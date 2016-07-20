/* CS261- Assignment 1 - Q.2*/
/* Name:Alexander Laquitara
 * Date: 3/28/2016
 * Solution description: modifies int x,y,and z with function foo.  
 *  Demonstrates how functions use pointers to modify variables.
 */
 
#include <stdio.h>
#include <stdlib.h>
/*********************************************************************
 ** Function: foo
 ** Description: modifies int pointer values
 ** Parameters: 3 Pointers to ints
 ** Pre-Conditions:none
 ** Post-Conditions: changes the value of first two int parameters.
 *********************************************************************/
int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;
    /*Set b to half its original value*/
    *b = *b/2;
    /*Assign a+b to c*/
    c = *a+ *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5, y = 6, z =7;
    int zval;
    /*Print the values of x, y and z*/
    printf("Value of x: %d\n", x);
    printf("Value of y: %d\n", y);
    printf("Value of z: %d\n", z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    zval=foo(&x, &y, z);
    
    /*Print the value returned by foo*/
    printf("The value returned by foo is %d \n" ,zval);
    
    /*Print the values of x, y and z again*/
    printf("Value of x is now: %d\n", x);
    printf("Value of y is now: %d\n", y);
    printf("Value of z is now: %d\n", z);
 
    /*Is the return value different than the value of z?  Why?
     See end of file.*/
    return 0;
}
/*it is different because z was passed into foo as a value rather
 than as a pointer like x and y.*/


