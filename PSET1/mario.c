#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //initialize n as an integer    
    int n; 
    
    // do while loop to prompt user for height input between 1-23
    do {
        printf("Height: ");
        n = GetInt();
        
    if (n == 0)
        {
        return 0;
        }
    } while(n < 1 || n > 23);
    
    //for loop to count rows
    for (int i = 0; i < n; i++)
    
        {
        //for loop to print spaces
        for (int j = 0; j < n-i-1; j++)
        {    printf("%c", ' ');
        } 
            //for loop to print #s
            for (int k = 0; k < i+2; k++)
            {   printf("#");
            }
        
        printf("\n");
        }
}       
 

         //print spaces
         //print hashes
         //print new line

       


