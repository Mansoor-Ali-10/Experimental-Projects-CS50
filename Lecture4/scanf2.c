#include <stdio.h>
#include <stdlib.h> // Gives malloc
int main(void)
{
// scaf also works for strings,

    // char *s;
    // Returning null because we need to assign it memory
    char *s = malloc(4);
    printf("s: ");
    scanf("%s", s);
    // Because a string is already a char *, no need to put "&" to tell the computer that it's an address
    printf("s: %s\n", s);

}