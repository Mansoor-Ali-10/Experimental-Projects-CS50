#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    
    //Prompt for total value
    do
    {
        dollars = get_float("Dollars: ");
    }
    while (dollars < 0);
    
    //Round up for easier math
    int cents = round(dollars * 100);
    
    //Calculate quarters
    int quarters = (cents / 25);
    
    //Calculate dimes
    int dimes = ((cents - (quarters * 25)) / 10);
    
    //Calculate nickels
    int nickels = ((cents - (quarters * 25) - (dimes * 10)) / 5);
    
    //Calculate pennies
    int pennies = ((cents - (quarters * 25) - (dimes * 10) - (nickels * 5)));
    
    //Calculate total
    int total = (quarters + dimes + nickels + pennies);
    
    //Print total
    printf("%i \n", total);
    
}