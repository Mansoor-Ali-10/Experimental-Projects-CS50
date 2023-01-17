#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Only one key allowed, no spaces\n");
        return 1;
    }
    
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
            
        return 1;
    }

    for (int j = 0; j < strlen(argv[1] - 1); j++)
    {
        for (int k = 1; k < strlen(argv[1] - 1); k++)
        {
            if (argv[1][j] == argv[1][k])
            {
            printf("No duplicate characters allowed\n");
            
            return 1;
            }
        }
    }


    for (int h = 0; h < strlen(argv[1]); h++)
    {
        if (ispunct(argv[1][h]))
        {
        printf("Alphanumeric characters only\n");
        return 1;
        }
    }
        
    
    // Get plain text from person
        string plaintext = get_string("plaintext: ");
        
        // Get length of string for the for loop   
        int text_length = strlen(plaintext);
        
        // For loop that iterates through string and replaces for lower case
        
        printf("ciphertext: ");
        
        for (int i = 0; i < text_length; i++)
        {    // For lower case letters
            if (islower(plaintext[i]))
            {
                char cipher = argv[1][plaintext[i] - 'a'];
                
                printf("%c", tolower(cipher));
            }
            
            // For upper case letters
            else if (isupper(plaintext[i]))
            {
                char cipher = argv[1][plaintext[i] - 'A'];
                
                printf("%c", toupper(cipher));
            }
            
            else if (isdigit(plaintext[i]))
            {
                printf("%c", plaintext[i]);
            }
            
            // For punctuation
            else if (ispunct(plaintext[i]))
            {
                printf("%c", plaintext[i]);
            }
            
            // For spaces
            else if (isspace(plaintext[i]))
            {
                printf("%c", plaintext[i]);
            }
            
        }
    printf("\n");
    return 0;
}

