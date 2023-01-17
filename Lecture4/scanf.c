#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x);
    printf("x: %i\n", x);


// scaf also works for strings,

    char *s;
    printf("s: ");
    scanf("%s", s); // This is a replacement for get_int without training wheels
    // Because a string is already a char *, no need to put "&" to tell the computer that it's an address
    printf("s: %s\n", s);

}