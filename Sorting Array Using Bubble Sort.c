#include <stdio.h>

void main()
{
  int array[100], n, swap;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter the elements : ");

  for (int i = 0; i < n; i++)
    scanf("%d", &array[i]);

  for (int i = 0 ; i < n - 1; i++)
  {
    for (int j = 0 ; j < n - i - 1; j++)
    {
      if (array[j] > array[j+1]) 
      {
        swap       = array[j];
        array[j]   = array[j+1];
        array[j+1] = swap;
      }
    }
  }

  printf("Sorted list in ascending order:\n");

  for (int i = 0; i < n; i++)
     printf("%d\n", array[i]);

  
}
