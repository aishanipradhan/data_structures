#include <stdio.h>
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void swap(int *a, int *b)
{
    int temp = *a;
      *a = *b;
      *b = temp;
}
 
void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
 
    if (left < n && arr[left] > arr[largest])
        largest = left;
 
    if (right < n && arr[right] > arr[largest])
        largest = right;
 
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
 
        heapify(arr, n, largest);
    }
}
 
void buildHeap(int arr[], int k)
{

    int startindex = (k / 2) - 1;
    int j;
 
    for (j = startindex; j >= 0; j--) {
        heapify(arr, k, j);
    }
}
 
void printHeap(int arr[], int m)
{
    printf("Array representation of Heap is:\n");
 
    for (int i = 0; i < m; ++i)
        printf("%d ",arr[i]);
    printf("\n");
}
 
int main()
{

    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
 
    int N = sizeof(arr) / sizeof(arr[0]);
 
    buildHeap(arr, N);
    printHeap(arr, N);

 
    return 0;
}
