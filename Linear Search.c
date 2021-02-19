#include <stdio.h>
void main()
{
  int array[100], key, n,i;

  printf("Enter number of elements in array(Max:100) ");
  scanf("%d", &n);

  printf("\nEnter the elements ");

  for (int i = 0; i < n; i++)
    scanf("%d", &array[i]);

  printf("\nEnter the number to search ");
  scanf("%d", &key);

  for ( i = 0; i < n; i++)
  {
    if (array[i] == key) 
    {
      printf("%d is present at location %d.\n", key, i+1);
      break;
    }
  }
  if ( i == n)
    printf("%d isn't present in the array.\n", key);

  
}
