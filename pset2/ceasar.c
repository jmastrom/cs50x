/*ceasar.c is an implementaiton of a simple ceasar cypher
  it accepts 1 command line argument of 'secret key' of k
  as the number of 'characters' to shift during the 
  cypher. 
  Author: Jimmy Mastrom
  CS50x
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, string argv[])
{

    //int k = atoi(argv[1]); 
    
    if (argc >= 3 || argc < 2)
    { 
        printf("Incorrecte command line arguments, enter value for K");
        return 1;    
    }   
    else
        {
            printf("Input your plaintext: ");
            char plaintext[60] = GetString();
            printf ("thanks! I got %c", plaintext);
        }
   
   
   
   
    return 0;
        
}
