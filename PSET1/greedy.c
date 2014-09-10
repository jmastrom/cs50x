/* Greedy.c
   CS50x PSET1
   Author: Jimmy Mastrom
   
*/


#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

{
    //initialize change variable
    float change_input;
    int change_dollar;
    int coin_count = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    
    //prompt user for amount of change
    do {
        printf("How much change is owed?: ");
        change_input = GetFloat();
        
    if (change_input == 0)
        {
        return 0;
        }
    } while(change_input < 0);
    
    change_dollar = (int)round(change_input * 100);
    
    
    //convert change_input to int, then covert to dollars by multiplying by 100
    //round()
    do 
    {
            //Quarters
            while (change_dollar >= 25)
            { change_dollar = (change_dollar - quarter);
              coin_count += 1; 
            }
            
            //Dimes
            while (change_dollar >= 10)
            { change_dollar = (change_dollar - dime);
              coin_count += 1;
            } 
   
            //Nickels
            while (change_dollar >= 5)
            { change_dollar = (change_dollar - nickel);
              coin_count += 1;
            } 
        
            //Pennies
            while (change_dollar >= 1)
            { change_dollar = (change_dollar - penny);
              coin_count += 1;
            }
      } 
      while (change_dollar > 0);
        
    printf("%d\n", coin_count); 
    
    return 0;

}

