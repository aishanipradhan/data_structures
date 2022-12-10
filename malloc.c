#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    
    arr = (int*)malloc(10 * sizeof(int));

    if (arr == NULL)
    {
        printf("Error: memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < 10; i++)
        arr[i] = i + 1;

    printf("Array elements: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
  
    arr = (int*)realloc(arr, 15 * sizeof(int));

    if (arr == NULL)
    {
        printf("Error: memory allocation failed!\n");
        return 1;
    }

    for (int i = 10; i < 15; i++)
        arr[i] = i + 1;

    printf("Array elements: ");
    for (int i = 0; i < 15; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);

    return 0;
}
