#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int array[], int arrayLen, int swapArr[])
{
	int i; 
	int j;
	int temp;

	for (i = 0; i < arrayLen - 1; i++)
	{
		for (j = 0; j < arrayLen - i - 1; j++)
		{
			if (array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;

                swapArr[j]++;
                swapArr[j+1]++;
			}
		}
	}
}

void printArray(int array[], int arrayLen)
{
    for(int i = 0; i < arrayLen; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int array[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arrayLen = sizeof(array) / sizeof(int);
    int swapArr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    printf("\nArray before: ");
    printArray(array, arrayLen);

    printf("\n\nIndex swaps before: ");
    printArray(swapArr, arrayLen);

    bubbleSort(array, arrayLen, swapArr);

    printf("\n\nArray after: ");
    printArray(array, arrayLen);

    printf("\n\nIndex swaps after: ");
    printArray(swapArr, arrayLen);

    printf("\n\n");

    return 0;
}