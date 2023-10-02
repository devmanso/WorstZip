#ifndef WORSTZIP_H
#define WORSTZIP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


size_t byteToKb(size_t bytes) {
    return bytes * 1000;
}

size_t kbToMb(size_t kbytes) {
    return kbytes * 1000;
}

size_t mbToGb(size_t mbytes) {
    return mbytes * 1000;
}

long generateRandomLong(long min, long max) {
    return min + rand() % (max - min + 1);
}

int removeDataFromFile(FILE* file, size_t bytes) {
     
    if (bytes <=0) {
        printf("invalid parameter bytes, cannot be less than 0");
        return 1;
    }
    
    // seek to end of file to get size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);

    if(fileSize <= bytes) {
        printf("You are trying to remove too much data!");
        fclose(file);
        return 1;
    }

    // Seek back from the end by the specified amount of data to remove
    fseek(file, -bytes, SEEK_END);

    // Truncate the file at the current position
    if (ftruncate(fileno(file), ftell(file)) != 0) {
        printf("Error truncating file");
        fclose(file);
        return 1;
    }

    fclose(file);

    return 0;
}

int compressFile(const char* filepath) {
    // Check if the file exists
    if (access(filepath, F_OK) == -1) {
        fprintf(stderr, "Error: File '%s' does not exist.\n", filepath);
        return 1;
    }

    // Open the file in read-write mode
    FILE* file = fopen(filepath, "r+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // seek to end of file to get size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);

    long bytesToRemove = lround( (fileSize /2) );

    // Remove half of data from the file
    if (removeDataFromFile(file, bytesToRemove) != 0) {
        fprintf(stderr, "Error removing data from the file.\n");
        fclose(file);
        return 1;
    }
    
    return 0;
}

#endif