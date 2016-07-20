/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
//reference: http://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
//reference: Chapter 6 page 5-6.
{
    //referenced chapter 6 page 5.
	/* FIXME: You will write this function */
    // interate through, is the element in the inverse index.
    
        int cap = 10;
        char c;
        
        /*checks to see if s pointer is not null*/
        if(s == 0)
        {
            printf("Error. the pointer is null");
            return 0;
        }
        
        DynArr* stack = newDynArr(cap);
        
        
        do
        {
            c = nextChar(s);
            /*Push if c is a starting bracket*/
            if((c =='{')||(c =='(')||(c =='['))
            {
                pushDynArr(stack,c);
            }
            
            /*if c is a closing bracket, it is poped and tested for a match*/
            if((c =='}')||(c ==')')||(c ==']'))
            {
                //if there exists an ending bracket without a pair.
                if(!sizeDynArr(stack))
                {
                    return 0;
                }
                
                //check for matching pair.
                else
                {
                    if (c == '}')
                    {
                        if (topDynArr(stack) == '{')
                        {
                            popDynArr(stack);
                        }
                    }
                    if (c == ')')
                    { 
                        if (topDynArr(stack) == '(')
                        {
                            popDynArr(stack);
                        }
                    }
                    
                    if (c == ']')
                    { 
                        if (topDynArr(stack) == '[')
                        {
                            popDynArr(stack);
                        }
                    }
                }
            }
        }while(c !='\0');			
        
        /*If the stack is empty the all left brackets balance*/
        if(sizeDynArr(stack) == 0)
        { 
            return 1; // balanced
        }
        else;
        
        return 0; //not balanced
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
     return 0;
    
    /* THIS Code was used to test if isBalanced worked properly)
    char *tmp[10];
    int res;
    printf("Plese enter a string:\n");
    scanf("%s", &tmp);
    res = isBalanced(tmp);
    if (res)
        printf("The string %s is balanced\n",tmp);
    else
        printf("The string %s is not balanced\n",tmp);
	
	return 0;	
     */
}

