#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(void)
{
// A single "&" is the "address of" operator
// e.g. &n

// You can store the address of that variable in a variable, you have to let the comp.
// know ahead of time with "*"

int n = 50;
int *s = &n;

// s is now holding not the int 'n' itself, but the address of that int. This is a pointer variable.

// The following will print the location address, using the pointer printer "p"
printf("%p\n", s);

// The following will print what is at the location, which is n. Also called dereferencing
printf("%i\n", *s);
printf("\n");
// The following creates a copy, it doesn't point at the original int n. *s is untouched.

int c = n;

// [string i = "n"] is equivalent to ["char *i = "n" ]. The *s contains the address of the first character in "n"

char *i = "n";
printf("%s\n", i);
printf("\n");

// Poking around with pointer arithmetic
char *j = "HI!";
printf("%c\n", j[0]);
printf("%c\n", *j);
printf("%c\n", *(j+1));
printf("%s\n", j);
printf("\n");

int numbers[] = {4, 6, 8, 2, 7, 5, 0};

// Don't need to indicate in numbers[] how many numbers there are, computer/compiler figures it out

printf("%i\n", *(numbers));
printf("%i\n", *(numbers + 1));
printf("%i\n", *(numbers + 2));
printf("%i\n", *(numbers + 3));
printf("%i\n", *(numbers + 4));
printf("%i\n", *(numbers + 5));
printf("%i\n", *(numbers + 6));
printf("\n");

// The name of the array itself is a pointer.
// The array can be treated as the address of the first element in that array.

string mo = get_string("mo: ");
string no = mo;
no[0] = toupper(no[0]);
printf("mo: %s\n", no);
printf("no: %s\n", mo);

// The reason 'mo' is also capitalized instead of just 'no' is because they're representing the same address
// So, the change is made to the one address, both of which are being pointed at by 'no' and 'mo'
// Only the pointer was copied, not the contents. If s points to 0x123, t is also points to 0x123

printf("\n");


}