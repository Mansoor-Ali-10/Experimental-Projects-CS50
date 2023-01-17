#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through each column
    for (int i = 0; i < height; i++)
    {
        // Iterate through each row
        for (int j = 0; j < width; j++)
        {
            int blue = image[i][j].rgbtBlue;
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;

            //Average it using float, otherwise the rounding will be off
            float convert = (red + green + blue)/3.0;

            // Convert to integer
            int average = lround(convert);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through each column
    for (int i = 0; i < height; i++)
    {
        // Iterate through each row
        for (int j = 0; j < width; j++)
        {
            // Get the original values
            int blue = image[i][j].rgbtBlue;
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;

            // Create new colour for each pixel

            float sepiaRed = .393 * red + .769 * green + .189 * blue;
            float sepiaGreen = .349 * red + .686 * green + .168 * blue;
            float sepiaBlue = .272 * red + .534 * green + .131 * blue;

            // Convert back to integer
            int newGreen = lround(sepiaGreen);
            int newRed = lround(sepiaRed);
            int newBlue = lround(sepiaBlue);

            if (newRed > 255)
            {
                newRed = 255;
            }

            if (newGreen > 255)
            {
                newGreen = 255;
            }

            if (newBlue > 255)
            {
                newBlue = 255;
            }

            // reassign to pixels
            image[i][j].rgbtGreen = newGreen;
            image[i][j].rgbtRed = newRed;
            image[i][j].rgbtBlue = newBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{    // Iterate through each column
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE copy[height][width];
        // Iterate through each row
        for (int j = 0; j < width; j++)
        { // Make a copy of the far right pixel and put it into the first pixel on the left
            copy[i][j] = image[i][(width - 1) - j];
        }

        for (int c = 0; c < width; c++)
        {// Put the flipped pixel back into image
            image[i][c] = copy[i][c];
        }
    }
        return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    // Iterate through columns
    for (int i = 0; i < height; i++)
    {
        // Iterate through rows
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
        // On each loop, set values to zero
        int sum_blue = 0;
        int sum_red = 0;
        int sum_green = 0;
        float counter = 0;
        // Iterate surrounding pixels for each pixel
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Check if pixel exists outside column
                    if (k + i < 0 || k + i > height - 1)
                    {
                        continue;
                    }
                    // Check if pixel exists outside row
                    if (l + j < 0 || l + j > width - 1)
                    {
                        continue;
                    }
                    // Otherwise, continue operation
                    sum_red += copy[k + i][l + j].rgbtRed;
                    sum_blue += copy[k + i][l + j].rgbtBlue;
                    sum_green += copy[k + i][l + j].rgbtGreen;
                    counter++;
                }
            }
            // Get average and write to image
            image[i][j].rgbtRed = lround(sum_red / counter);
            image[i][j].rgbtBlue = lround(sum_blue / counter);
            image[i][j].rgbtGreen = lround(sum_green / counter);
        }
    }
    return;
}
