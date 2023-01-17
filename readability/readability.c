#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get Text
    string text = get_string("Text: ");

    // Calculate everything
    float num_letters = count_letters(text);

    float num_words = count_words(text);

    float num_sentences = count_sentences(text);
    
    // letters per word
    float L = (num_letters / num_words) * 100;
    
    // Sentences per word
    float S = (num_sentences / num_words) * 100;
    
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    
    // Print results with parameters
    if (index < 1)
    {
        printf ("Before Grade 1\n");
    }
    
    else if (index >= 16)
    {
        printf ("Grade 16+\n");
    }
    else
    {
        printf ("Grade %0.0f\n", round(index));
    }

}

int count_letters(string text)
{
    int i;
    int letters = 0;
    int len = strlen(text);

    for (i = 0; i < len; i++)
    {
        if (ispunct(text[i]))
        {
            continue;
        }

        if (isspace(text[i]))
        {
            continue;
        }

        else
        {
            letters++;
        }

    }

    return letters;
}


int count_words(string text)
{
    int i;
    int words = 0;
    int len = strlen(text);

    for (i = 0; i < len; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }

    }
    return (words + 1);

}

int count_sentences(string text)
{
    int i;
    int sentences = 0;
    int len = strlen(text);

    for (i = 0; i < len; i++)
    {
        
        if (text[i] == '.')
        {
            sentences++;
        }
        
        else if (text[i] == '!')
        {
            sentences++;
        }
        
        else if (text[i] == '?')
        {
            sentences++;
        }

    }
    return sentences;

}