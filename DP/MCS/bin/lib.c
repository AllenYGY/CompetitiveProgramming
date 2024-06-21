#include "lib.h"

// Helper function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b; // Return a if a is greater than b, otherwise return b
}

void print_array(int S[], int n) // Print the array
{ 
    for (int i = 0; i < n; i++)
    {
        printf("%d ", S[i]);
    }
    printf("\n");
}

void printMaxSubarrays(Subarray *maxSubarrays, int count) // Print the maximum subarrays
{
    for (int i = 0; i < count; i++)
    {
        printf("%d %d\n", maxSubarrays[i].start, maxSubarrays[i].end);
    }
}

int MCS(int S[], int n) // Function to compute the maximum continuous subarray
{
    int F[n];
    F[0] = S[0];
    int Fmax = F[0];
    for (int i = 1; i < n; i++)
    {
        F[i] = max(F[i - 1] + S[i], S[i]);
        Fmax = max(Fmax, F[i]);
    }
    return Fmax;
}

// Function to find maximum subarray sum and print all subarrays with maximum sum
int findMCS(int S[], int size, Subarray **maxSubarrays, int *count)
{
    if (size == 0)
    {
        *count = 0;
        return 0;
    }
    *maxSubarrays = (Subarray *)malloc(size * sizeof(Subarray)); // Allocate memory for the maximum subarrays
    int *F = (int *)malloc(size * sizeof(int));
    F[0] = S[0];
    int maxCount = 0, currentStart = 0, Fmax = F[0];
    for (int i = 1; i < size; i++)
    {
        if (F[i - 1] + S[i] > S[i])
        { // Extend the current subarray
            F[i] = F[i - 1] + S[i];
        }
        else
        { // Start a new subarray
            F[i] = S[i];
            currentStart = i;
        }
        if (F[i] > Fmax)
        {
            Fmax = F[i];
            maxCount = 0; // Reset count when a new maximum is found
            (*maxSubarrays)[maxCount].start = currentStart;
            (*maxSubarrays)[maxCount].end = i;
        }
        else if (F[i] == Fmax)
        {
            maxCount++; // Increment count when a subarray with maximum sum is found
            if (maxCount < size)
            {
                (*maxSubarrays)[maxCount].start = currentStart;
                (*maxSubarrays)[maxCount].end = i;
            }
            else
            { // Reallocate memory if the number of subarrays exceeds the initial size
                *maxSubarrays = (Subarray *)realloc(*maxSubarrays, 2 * size * sizeof(Subarray));
                (*maxSubarrays)[maxCount].start = currentStart;
                (*maxSubarrays)[maxCount].end = i;
            }
        }
    }
    *count = maxCount + 1;                                                           // Number of subarrays with maximum sum
    *maxSubarrays = (Subarray *)realloc(*maxSubarrays, (*count) * sizeof(Subarray)); // Adjust memory to fit the actual number of subarrays
    free(F);
    return Fmax;
}

int *readNumbers(const char *filename, int *size)
{
    FILE *file;
    int *numbers = NULL;
    int temp;
    int capacity = 10; 
    *size = 0;         
    file = fopen(filename, "r"); // Open the file for reading
    if (file == NULL)
    {
        perror("Error opening file");
        return NULL;
    }
    // Allocate memory for the array
    numbers = (int *)malloc(capacity * sizeof(int));
    if (numbers == NULL)
    {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }
    // Read the numbers from the file
    while (fscanf(file, "%d", &temp) == 1)
    {
        if (*size >= capacity)
        {
            capacity *= 2; // Double the capacity
            numbers = (int *)realloc(numbers, capacity * sizeof(int));
            if (numbers == NULL)
            {
                perror("Failed to reallocate memory");
                fclose(file);
                return NULL;
            }
        }
        numbers[*size] = temp;
        (*size)++;
    }
    // Close the file
    fclose(file);
    // Adjust the memory to fit the actual number of elements
    numbers = (int *)realloc(numbers, (*size) * sizeof(int));
    return numbers;
}

// Output a file with the maximum subarray sum and the subarrays with maximum sum
void outputMaxSubarrays(const char *filename, int fmax, Subarray *maxSubarrays, int count)
{
    FILE *file;
    file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%d\n", fmax);
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d %d\n", maxSubarrays[i].start, maxSubarrays[i].end);
    }   
    fclose(file);
}