#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//valgrind checked

void mergeSort(int *array, int left, int right);
void merge(int *array, int left, int mid, int right);

int main (int argc, char **argv)
{
    //correct user input
    if (argc != 3)
    {
        printf("Usage: ./mergesort <input file name>.txt <output file name>.txt\n");
        return 1;
    }

    //opening files
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 2;
    }

    //get file size
    fseek(input, 0, SEEK_END);
    long size = ftell(input);

    rewind(input);
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 2;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open output file.\n");
        return 3;
    }

    //copy numbers in file into array of file size
    int numofNum = 0;
    int buffer;
    int *copy = malloc(size);

    while (fscanf(input, "%d, ", &buffer) == 1)
    {
        copy[numofNum] = buffer;
        numofNum++;
    }

    //sort
    mergeSort(copy, 0, numofNum - 1);

    for (int i = 0; i < numofNum; i++)
    {
        fprintf(output, "%d", copy[i]);
        if (i < numofNum - 1)
        {
            fprintf(output, "\n");
        }
    }

    printf("%s (merge)sorted in %s", argv[1], argv[2]);

    //close files
    free(copy);
    fclose(input);
    fclose(output);
}

//sorter
void mergeSort(int *array, int left, int right)
{
    if (left == right)
    {
        return;
    }

    int mid = left + (right - left)/2;

    //recursion
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);

    merge(array, left, mid, right);
}

void merge(int *array, int left, int mid, int right)
{
    int i, j, k;

    //temporary arrays
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int *leftArray = malloc(sizeof(int) * leftSize);
    int *rightArray = malloc(sizeof(int) * rightSize);

    //copy into temp array
    for (i = 0; i < leftSize; i++)
    {
        leftArray[i] = array[left + i];
    }
    for (j = 0; j < rightSize; j++)
    {
        rightArray[j] = array[mid + 1 + j];
    }

    //sorting while merge
    i = 0;
    j = 0;
    k = left;

    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i] < rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    //add rest of elements
    while (i < leftSize)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (right < rightSize)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    free(leftArray);
    free(rightArray);
}