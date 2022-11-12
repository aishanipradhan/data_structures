#include <math.h> 
#include <stdio.h> 
   
int main()
{   int array[10] = {4, 5, 72, 823, 3, 230, 38, 238, 487, 78};
    int n = 10;
    int x, y, z; 
    for (x = 1; x < n; x++) 
    {z = array[x]; 
    y = x - 1; 
    while (y >= 0 && array[y] > z) { 
            array[y + 1] = array[y]; 
            y = y - 1; 
        } 
        array[y + 1] = z; 
    } 
    
    printf("Sorted list = ");
    for (x = 0; x < n; x++) 
        printf("%d ", array[x]); 
} 
