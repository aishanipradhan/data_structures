#include <stdio.h>
void quicksort(int array[100],int first_index,int last_index){
   int i, j, pivot, temp;
   if(first_index<last_index){
      pivot=first_index;
      i=first_index;
      j=last_index;
      while(i<j){
         while(array[i]<=array[pivot]&&i<last_index)
         i++;
         while(array[j]>array[pivot])
         j--;
         if(i<j){
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
         }
      }
      temp=array[pivot];
      array[pivot]=array[j];
      array[j]=temp;
      quicksort(array,first_index,j-1);
      quicksort(array,j+1,last_index);
   }
}

int main ()
{   int x;
    int new_array[6] = {12,1298,218,1208,8347,239};
    
    printf("Original list = ");
    for (x = 0; x < 5; x++) 
        printf("%d ", new_array[x]);
        
    quicksort(new_array,0,5);
    printf("\nSorted list = ");
    for (x = 0; x < 5; x++) 
        printf("%d ", new_array[x]);    
}
