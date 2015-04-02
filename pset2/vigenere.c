/*vigenere.c is an implementaiton of a vigenere cypher
  it accepts 1 command line argument of 'secret key' of k
  as the number of 'characters' to shift during the 
  vigenere cypher. Each letter in k (ki) is used to encypher
  the plain text cyclically.
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
    //check to ensure exactly 2 arguments are passed to the program
    if (argc !=2)
    { 
        printf("You used too many arguments!\n ~Usage: ./vigenere <keyword>\n");
        return 1;    
    }   
    
    //initialize string keyword from argv[1]
    string keyword = argv[1];
   
    //for loop that steps through each character in keyword to verify it has letters only
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {    
        if (isalpha(keyword[i])) 
            {
            
            }
        else 
            {
                printf("Your keyword must contain alpha characters only!\n ~Usage: ./vigenere <keyword>\n");
                return 1; 
            }    
                       
    }
    
    
    //initialize integer cypherlength as the lenght of characters in keyword
    int cypherlength = strlen(keyword);  
    
    //initialize integer cypher as an array with size of cypherlength
    int cypher[cypherlength]; 
    
   
    //converts keyword characters into integer values and stores them in a single dimensional array cypher
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {
        
        //converts each character in the cypher array to its ascii shift value, upper case and lower case
        if (isupper(keyword[i]))
        {
            cypher[i] = keyword[i] - 65;
        }
        else
        {
            cypher[i] = keyword[i] - 97;
        }
    }
    
    //prompt user for plaintext
    string plaintext = GetString();
    
    //counter to keep track of characters during loop (so spaces don't screw things up)
    int counter = 0;
           
    //for loop to step through each character in plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
            //checks if i character in plaintext array is alphabetic
            if (isalpha(plaintext[i]) == 0) 
            {
                printf("%c", plaintext[i]);
                counter++;
            }
            else
            {   
                //initializes integer value of i'th keyword char from plaintext array
                int k = plaintext[i];
             
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
                
                k = (((k - x) + cypher[(i - counter) % cypherlength]) % 26) + x;
                
                //c = (c + key);
                printf("%c", k);
            } 
        }
    printf("\n"); 
    return 0;
}
