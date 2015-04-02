/*

Author:  Jimmy Mastrom
Date:    2/28/2015
Class:   CS50 edx 2015
Section: PSET2

*/


#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>


int main(void)
{
   
    
    //prompt user for name
    //printf("What is your name?: \n");
    
    //initialize a string variable called name
    //use the CS50 GetString function to pass user input to name variable as a string
    string name = GetString();
    

    //print first letter of first name
    printf("%c", toupper(name[0]));
    
    //for loop to cycle through remaining letters until a space and then prints next letter
    for(int i = 0, n = strlen(name); i < n; i++)
    {    
        if (name[i] == ' ' && name[i +1] != '\0')
        {
         
            printf("%c", toupper(name[i + 1]));
            i++;
            
        }
        
    }   
    //finish by printing a new line
    printf("\n");  
}


