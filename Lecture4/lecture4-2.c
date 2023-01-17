#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h> // Contains malloc, freelib

int main(void)
{

// Since assining s to t doesn't make a copy, we must use a for loop to copy it in there
// malloc assigns new memory where s will be copied into t.
// Bytes of memory stored by mentioning the type (strlen)

    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);

    if (t == NULL)
    {
        return 1;
    }
    // This is in case the computer runs out of memory, the program won't continue and crash the system

    for (int i = 0; i < strlen(s) + 1; i++)

// or for (int i = 0; n = strlen(s) + 1; i < n; i++)
// The +1 is for the null character at the end of whatever is put into the string

    {
        t[i] = s[i];
    }
    // This for loop will copy every character in s into t individually

    // Alternative to for loop: strcpy(t, s);
    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);

}