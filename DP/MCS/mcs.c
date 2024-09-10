#include "lib.h"

int main(int argc, char *argv[])
{
	// *read input file name from the argument
	if (argc != 2)
		printf("Usage: %s <filename>\n", argv[0]);
	int size, i, fmax = 0, count = 0;
	Subarray *maxSubarrays; //* Array to store the subarrays with maximum sum
	int *numbers = readNumbers(argv[1], &size); //* Read numbers from the file
	char out[100]; //* Outputfile name
	strcpy(out, argv[1]); strcat(out, "_out"); //* concate argv[1] with "_out" and store in out
	if (numbers != NULL)
	{
		print_array(numbers, size); //* Print the array from the file
		fmax=findMCS(numbers, size, &maxSubarrays, &count); //* Find the maximum subarray sum and the subarrays with maximum sum
		printf("%d\n\n", fmax); //* Print the maximum subarray sum
		printMaxSubarrays(maxSubarrays, count); //* Print the subarrays with maximum sum
		outputMaxSubarrays(out, fmax, maxSubarrays, count); //* Output the maximum subarray sum and the subarrays to the file
		free(numbers); //* Free the memory allocated for the array
		free(maxSubarrays); //* Free the memory allocated for the subarrays
	}
	return 0;
}
