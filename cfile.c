/*
    Campos, Annika Dominique S.
    Tiu, Lance Wilem
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void imgCvtGrayIntoFloat(int height, int width, unsigned char *input, float *output);

int main() {
    int height, width;

    // User input Height and Width
    // Get the execution time for 10 * 10, 100 * 100, and 1000 * 1000
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
int pixel_limit = (height > 10 || width > 10) ? 5 : height; 

for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
        input[i * width + j] = rand() % 256;

        // Print values with float_limit
        if (i < pixel_limit && j < pixel_limit) {
            printf("%3d ", input[i * width + j]);
        }
    }

    // Print ellipsis for truncated rows
    if (i < pixel_limit) {
        if (width > pixel_limit) {
            printf("...");
        }
        printf("\n");
    }
}

// Indicate truncation if necessary
if (height > 10 || width > 10) {
    printf("... (Remaining rows truncated for display)\n");
}

    // Measure execution time over 30 runs
    double total = 0.0; 
    int executions = 30; 

    for (int i = 0; i < executions; i++) {
        clock_t start_time = clock(); 
        imgCvtGrayIntoFloat(height, width, input, output);
        clock_t end_time = clock();  

        // Accumulate the elapsed time
        total += (double)(end_time - start_time) / CLOCKS_PER_SEC;
    }

    // Average execution time (Total / Executions)
    double average = total / executions;

    // Converted Float Pixel Values
    printf("\nConverted float pixel values:\n");
    if (height <= 10 && width <= 10) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                printf("%.2f ", output[i * width + j]);
            }
            printf("\n");
        }
    } else {
        // Print a sample of the first 5 rows and columns for larger images
        int float_limit = 5;
        for (int i = 0; i < float_limit; i++) {
            for (int j = 0; j < float_limit; j++) {
                printf("%.2f ", output[i * width + j]);
            }
            printf("...\n");
        }
        printf("(Output truncated for larger images. Full output written to file.)\n");
    }

    // Write full output to file for larger images
    FILE *file = fopen("cvtFloat.txt", "w");
    if (file) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fprintf(file, "%.2f ", output[i * width + j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
        printf("\nFull output written to 'cvtFloat.txt'.\n");
    } else {
        printf("Error: Unable to write output to file.\n");
    }

    printf("\nAverage execution time over %d runs: %.6f seconds\n", executions, average);


    // Free allocated memory
    free(input);
    free(output);

    return 0;
}
