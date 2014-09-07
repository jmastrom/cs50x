#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

{
    //initialize change variable
    float change_input;
    int change_dollar;
    int coin_count;
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
    
    //convert change_input to int, then covert to dollars by multiplying by 100
    //round()

    //Quarters
    do {
       change_dollar-quarter
       coin_count++;
       } while (change_dollar > 25);
        
    //Dimes
    do {
        change_dollar-dime
        coin_count++;
        } while (change_dollar > 10);
   
    //Nickels
    do {
        change_dollar-dime
        coin_count++;
        } while (change_dollar > 5);
        
    //Pennies
    do {
        change_dollar-penny
        coin_count++
        } while (change_dollar > 1);
        
    printf(coin_count);

}

