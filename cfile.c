/*
    Campos, Annika Dominique S.
    Tiu, Lance Wilem
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
    Correctness Check: Validate if the computation if the same
*/
void checkCorrectness(unsigned char *input, float *output, int width, int height) {
    int size = width * height;
    int correct = 1;
    float expected; 

    for (int i = 0; i < size; i++) {
        expected = input[i] / 255.0;
        if (output[i] != expected) { 
            printf("Error Mismatch Values: Expected %.2f but got %.2f\n", expected, output[i]);
            correct = 0; 
        }
    }

    if (correct) 
        printf("Success: All values match the expected output!\n");
    else 
        printf("Error: Correctness Check Failed\n");
}

extern void imgCvtGrayInttoFloat(int height, int width, unsigned char *input, float *output);

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
        printf("Error: Memory Allocation Failed.\n");
        return 1;
    }

    srand(time(NULL));

    // Different Random Pixel Values (0-256)
    printf("\nRandomly Generated Pixel Values:\n");
    int pixel_limit = (height > 10 || width > 10) ? 10 : height; 

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            input[i * width + j] = rand() % 256;
            if (i < pixel_limit && j < pixel_limit) {
                printf("%3d ", input[i * width + j]);
            }
        }
        if (i < pixel_limit) {
            if (width > pixel_limit) {
                printf("...");
            }
            printf("\n");
        }
    }

    // Truncate for Large Images
    if (height > 10 || width > 10) {
        printf("(Pixel Values Truncated. See intPixels.txt.)\n");
    }

    // For reference, pixel values displayed in .txt file
    FILE *file1 = fopen("intPixels.txt", "w");
    if (file1) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fprintf(file1, "%3d ", input[i * width + j]);
            }
            fprintf(file1, "\n");
        }
        fclose(file1);
    } else {
        printf("Error: Unable to write output to file.\n");
    }

    // Measure execution time over 30 runs
    double total = 0.0; 
    int executions = 30; 

    for (int i = 0; i < executions; i++) {
        clock_t start_time = clock(); 
        imgCvtGrayInttoFloat(height, width, input, output);
        clock_t end_time = clock();  

        total += (double)(end_time - start_time) / CLOCKS_PER_SEC;
    }

    // Average execution time (Total / Executions)
    double average = total / executions;

    // Converted Float Pixel Values
    printf("\nSingle Float Pixel Values:\n");
    if (height <= 10 && width <= 10) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                printf("%.2f ", output[i * width + j]);
            }
            printf("\n");
        }
    } else {
        int float_limit = 10;
        for (int i = 0; i < float_limit; i++) {
            for (int j = 0; j < float_limit; j++) {
                printf("%.2f ", output[i * width + j]);
            }
            printf("...\n");
        }
        printf("(Output truncated for larger images. See cvtFloat.txt.)\n");
    }

    // For reference, full output for the converted pixel values
    FILE *file2 = fopen("cvtFloat.txt", "w");
    if (file2) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fprintf(file2, "%.2f ", output[i * width + j]);
            }
            fprintf(file2, "\n");
        }
        fclose(file2);
    } else {
        printf("Error: Unable to write output to file.\n");
    }

    printf("\nAverage execution time over %d runs: %.9f seconds\n", executions, average);
    checkCorrectness(input, output, width, height);


    // Free allocated memory
    free(input);
    free(output);

    return 0;
}
