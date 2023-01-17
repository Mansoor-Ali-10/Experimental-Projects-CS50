#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Ensure only one command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

// Open memory card, name file
    char *infile = argv[1];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    // If infile fails to open, return error
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // Create buffer to read to
    BYTE buffer[512];

    // Count the numnber of images
    int image_count = 0;

    // Assign file name. 000.jpeg - 7 characters plus null character so we allocate 8 bytes
    char filename[8];

    // Assign file to open later to silence error
    FILE *imgptr = NULL;

    // Read files
    while (fread(&buffer, 1, 512, inptr) == 512)
    {
        // Check if it's a jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] ==0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If not first jpeg, close the previous one
            if (image_count != 0)
            {
                fclose(imgptr);
            }

            // Code for updating file name on each file
            sprintf(filename, "%03i.jpg", image_count);

            // Open new file to write to
            imgptr = fopen(filename, "w");

            // Update counter to reflect next jpeg
            image_count++;
        }

            // Write to file
        if (image_count != 0)
        {
            fwrite(&buffer, 512, 1, imgptr);
        }
    }

        fclose(inptr);
        fclose(imgptr);
}