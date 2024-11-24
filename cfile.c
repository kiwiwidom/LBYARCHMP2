#include <stdio.h>
#include <stdlib.h>

/*
    TODO: Pixel values should be randomly generated to test the execution time of bigger sizes 1000 * 1000
*/
// Extern function from SASM
extern void imgCvtGrayIntoFloat(int height, int width, unsigned char *input, float *output);

int main() {
    int height, width;

    // Input height and width
    printf("Enter height and width of the image: ");
    scanf("%d %d", &height, &width);

    // Allocate memory for the input and output arrays
    // NOTES (delete when done)
    // Unsigned char(1 byte) is 8-bit integer(0-255) ex.(3 * 4 * size0f(float) = 12 bytes)
    // Float (4 bytes) ex.(3 * 4 * size0f(float) = 48 bytes)
    unsigned char *input = (unsigned char *)malloc(height * width * sizeof(unsigned char));
    float *output = (float *)malloc(height * width * sizeof(float));

    if (!input || !output) {
        printf("Error, Try again.\n");
        return 1;
    }

    // Input integer pixel values
    // NOTES (delete when done)
    // input matrix here
    // input could be in a line ex.(1 2 3 4 5 6 7 8 9 10 11 12) or matrix style
    // (1 2 3 4)
    // (5 6 7 8)
    // (9 10 11 12)
    printf("Enter the pixel values (space-separated):\n");
    for (int i = 0; i < height * width; i++) {
        scanf("%hhu", &input[i]); // Read unsigned char (uint8)
    }

    // Convert integer pixels to float using SASM (not done)
    imgCvtGrayIntoFloat(height, width, input, output);

    // Output the result
    printf("Converted float pixel values:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", output[i * width + j]);
        }
        printf("\n");
    }

    // Free allocated memory (apparently stops memory leaks)
    free(input);
    free(output);

    return 0;
}
