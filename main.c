#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "worstzip/worstzip.h"

int main(int argc, char *argv[]) {
    
    srand(time(0));
    int randRange = rand() % 10 + 1;

    // check if valid args are given
    if (argc != 2) {
        fprintf(stderr, "incorrect number of arguments");
        getchar();
        return EXIT_FAILURE;
    }

    // get file path from arg
    const char* filepath = argv[1];

    // Check if the file exists
    if (access(filepath, F_OK) == -1) {
        fprintf(stderr, "Error: File '%s' does not exist.\n", filepath);
        return EXIT_FAILURE;
    }

    // Open the file in read-write mode
    FILE* file = fopen(filepath, "r+");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // seek to end of file to get size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    long bytesToRemove = lround( (fileSize /randRange) );
    float kbRemoved = bytesToRemove / 1000;

    // Remove half of data from the file
    if (removeDataFromFile(file, bytesToRemove) != 0) {
        fprintf(stderr, "Error removing data from the file.\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    //fclose(file);
    printf("Successfully compressed ;) the file.\n");
    printf("Saved %.2f kb of data \n", kbRemoved);

    return EXIT_SUCCESS;
}