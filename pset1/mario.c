 #include <cs50.h>
#include <stdio.h>

int main(void)
{
    string x = "#";
    int height;
    
    //Prompt for height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height >8);
    
    //Code for height of pyramid
    for (int i = 0; i < height; i++)
    {
        
        //For right aligning
        for (int k = (height - 1); k > (i); k--)
        {
            printf(" ");
        }
        //Code for how many hashes to print per line
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }
        // Space between the two pyramids
        printf("  ");
        
        // For the left aligning pyramid
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }
        
        //next line
        printf("\n");
    }
    
    
}