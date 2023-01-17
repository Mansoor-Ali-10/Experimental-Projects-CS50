#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
    int start;
    int end;
    int years_passed;
    
    // TODO: Prompt for start size
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    
    // TODO: Prompt for end size
    do
    {
        end = get_int("End size: ");
    }
    while (end <= start);

    // TODO: Calculate number of years until we reach threshold
    
    years_passed = 0;
    
    while (start < end)
    {
        years_passed++;
        start += (start / 3) - (start / 4);
    }
    
    // TODO: Print number of years
    printf("Years: %i\n", years_passed);
}