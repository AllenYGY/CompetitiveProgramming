#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<assert.h>

//* Structure to hold the start and end indices of subarrays
typedef struct {
    int start;
    int end;
} Subarray;

//* A function to compute the maximum continuous subarray
int MCS(int S[],int n);
//* A function to read the numbers from the file
int *readNumbers(const char *filename, int *size);
//* A function to print the array
void print_array(int S[], int n);
//* A function to output the maximum continuous subarray
void outputMaxSubarrays(const char *filename, int fmax, Subarray *maxSubarrays, int count);
//* A function to print the maximum subarrays
void printMaxSubarrays(Subarray *maxSubarrays, int count);
//* A function to find maximum subarray sum and print all subarrays with maximum sum
int findMCS(int S[], int n, Subarray **maxSubarrays, int *count);
