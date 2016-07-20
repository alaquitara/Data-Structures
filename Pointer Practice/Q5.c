/* CS261- Assignment 1 - Q.5*/
/* Name: Alexander Laquitara
 * Date: 3/28/2016
 * Solution description: Converts the letters of a string to sticky caps.  Odd 
 *                       string indexes are upper case and even are lower case.
 */

//reference http://stackoverflow.com/questions/15648531/pointer-and-array-in-c

#include <stdio.h>
#include <stdlib.h>
/*********************************************************************
 ** Function:toUpperCase
 ** Description: turns a lower case char into an uppercase char
 ** Parameters: char ch
 ** Pre-Conditions: none
 ** Post-Conditions: cha is made uppercase
 *********************************************************************/
/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*********************************************************************
 ** Function:toLowerCase
 ** Description: turns a uppercase char into a lower case char
 ** Parameters: char ch
 ** Pre-Conditions: none
 ** Post-Conditions: cha is made lowercase
 *********************************************************************/
/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

/*********************************************************************
 ** Function:sticky
 ** Description: Turns a "word" into sticky caps
 ** Parameters: pointer to char word.
 ** Pre-Conditions: *word is made in main
 ** Post-Conditions: turns char* word into StIcKyCaPs.
 *********************************************************************/
void sticky(char* word){
     /*Convert to sticky caps*/
    int i;
    
    /*referenced http://www.c4learn.com/c-programs/check-whether-character-is-uppercase-or.html*/
    
    for(i=0;word[i]!='\0';i++)
    {
        
        if(i%2 !=0)
        {
            if(word[i] >='A' && word[i] <='Z')
            {
                word[i] = toLowerCase(word[i]);
            }
        }
        
        else
        {
            if(word[i] >= 'a' && word[i] <='z')
            {
                word[i] = toUpperCase(word[i]);
            }
        }
    }
}

int main(){
    //char* word = malloc(50*sizeof(char));
    char word[100];
    
    printf("Enter a word up to 100 characters:");
   
    /*Read word from the keyboard using scanf*/
    //no need to deference word becasuse an array is a pointer?
     scanf("%99s", word);
    
    /*Call sticky*/
    sticky(word);
    
    /*Print the new word*/
    printf("Sticky: %s\n", word);
    
    return 0;
}
