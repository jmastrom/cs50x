/*ceasar.c is an implementaiton of a simple ceasar cypher
  it accepts 1 command line argument of 'secret key' of k
  as the number of 'characters' to shift during the 
  caesar cypher. 
  Author: Jimmy Mastrom
  CS50x
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    //check to ensure exactly 2 arguments are passed and <key> argument is not 
    //less than or equal to 0
    if (argc !=2 || atoi(argv[1]) <=0)
    { 
        printf("Usage: ./caesar <key>\n");
        return 1;    
    }   
    
    //initialize key as integer mod 26 using atoi function to pull integer from string argv[1]
    int key = (atoi(argv[1])) % 26; 
    string plaintext = GetString();
           
    //for loop to step through each character in plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
            //checks if i character in plaintext array is alphabetic
            if (isalpha(plaintext[i])) 
            {
                //initializes char p from plaintext array
                char p = plaintext[i];
                
                //converts char p into ASCII by setting variable c to p's integer value
                int c = p;
                
                //variable used to 
                //convert ASCII to alpha index
                int x = 0; 
                
                //if upper case, set x to 65 in oder to properly wrap around 
                //alphabet in ASCII table
                if (isupper(plaintext[i]))
                {
                    x = 65;
                }
                
                //if lower case, set x to 97 in order to properly wrap around 
                //alphabet in ASCII table
                if (islower(plaintext[i]))
                {       
                    x = 97;
                }
                
                c = (((c - x) + key) % 26) + x;
                //c = (c + key);
                printf("%c", c);
                
            } 
            else printf("%c", plaintext[i]);
        }

    printf("\n"); 
    return 0;
        
}
