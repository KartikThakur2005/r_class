#include <stdio.h>
#include <stdlib.h>

void swp(int i, int j, int *arr)
{
     int temp = arr[i];
     arr[i] = arr[j];
     arr[j] = temp;
}

int partition(int l, int h, int *arr)
{
    int pivot = arr[l]; // Pivot is chosen as the first element
    int i = l; 
    int j = h;
    
    while (i < j)
    {
         // Move 'i' forward until an element larger than the pivot is found
         while (i <= h && arr[i] <= pivot)
         {
             i++;
         }
         
         // Move 'j' backward until an element smaller than the pivot is found
         while (j >= l && arr[j] > pivot)
         {
             j--;
         }
         
         if (i < j)
         {
             swp(i, j, arr);
         }
    }
    // Swap the pivot with the correct position
    swp(l, j, arr);
    
    return j; // Return pivot's new position
}

void quick_sort(int *arr, int l, int h)
{
    if (l < h)
    {
        int part = partition(l, h, arr); // Get partition index
        quick_sort(arr, l, part - 1);    // Sort left subarray
        quick_sort(arr, part + 1, h);    // Sort right subarray
    }
}

int main()
{
     int n;
     scanf("%d", &n);

     int *arr = (int*) malloc(n * sizeof(int));

     for(int i = 0; i < n; i++)
     {
         scanf("%d", &arr[i]);
     }

     quick_sort(arr, 0, n - 1);

     for (int i = 0; i < n; i++)
     {
        printf("%d ", arr[i]);
     }

     free(arr);  // Free allocated memory
     return 0;
}
