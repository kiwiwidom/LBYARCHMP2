/*
    Campos, Annika Dominique S.
    Tiu, Lance Wilem
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
    Correctness Check: Validate if the computation if the same
*/
void expectedOutput(unsigned char *input, float *output, int width, int height) {
    int size = width * height;

    printf("\nExpected Output Values:\n");
    for (int i = 0; i < size; i++) {
        float expected = input[i] / 255.0; 
        printf("%.2f ", expected); 
        if ((i + 1) % width == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

extern void imgCvtGrayInttoFloat(int height, int width, unsigned char *input, float *output);

int main() {
    int height, width;

    // User input Height and Width
    // Get the execution time only for 10 * 10, 100 * 100, and 1000 * 1000
    printf("\nEnter height and width of the image: ");
    scanf("%d %d", &height, &width);

    // Allocate memory for the input and output arrays
    unsigned char *input = (unsigned char *)malloc(height * width * sizeof(unsigned char));
    float *output = (float *)malloc(height * width * sizeof(float));

    if (!input || !output) {
        printf("Error, memory allocation failed.\n");
        return 1;
    }

    srand(time(NULL));

    // Different Random Pixel Values (0-256)
    printf("\nRandomly generated pixel values:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            input[i * width + j] = rand() % 256;
            printf("%3d ", input[i * width + j]); 
        }
        
    printf("\n");
    }

    // Measure execution time over 30 runs
    double total = 0.0; 
    int executions = 30; 


    imgCvtGrayInttoFloat(height, width, input, output);


    // Converted Float Pixel Values
    printf("\nConverted float pixel values:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", output[i * width + j]);
        }
        printf("\n");
    }

    expectedOutput(input, output, width, height);


    // Free allocated memory
    free(input);
    free(output);

    return 0;
}
