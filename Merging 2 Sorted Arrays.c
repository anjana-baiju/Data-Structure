#include <stdio.h>
void main() {
    int array1[100], array2[100], final[200],m,n;
    printf("Enter the size of First Array ");
    scanf("%d",&m);
    printf("\nEnter the Elements for First Array (In Sorted Order) ");
    for(int i=0;i<m;i++)
        scanf("%d",&array1[i]);
    printf("Enter the size of Second Array ");
    scanf("%d",&n);
    printf("\nEnter the Elements for Second Array (In Sorted Order) ");
    for(int i=0;i<n;i++)
        scanf("%d",&array2[i]);
    int k=0,i=0,j=0;
    while (i<m && j <n) {
        if (array1[i] < array2[j]) 
            final[k++] = array1[i++]; 
        else
            final[k++] = array2[j++]; 
    }
    while (i < m) 
        final[k++] = array1[i++]; 
    while (j < n) 
        final[k++] = array2[j++]; 
        
    printf("\nFirst Array is :");
    for(int i=0;i<m;i++){
        printf("\t%d",array1[i]);
    }
    printf("\nSecond Array is :");
    for(int i=0;i<n;i++){
        printf("\t%d",array2[i]);
    }
    printf("\nMerged Array is :");
    for(int i=0;i<n+m;i++){
        printf("\t%d",final[i]);
    }
    
}

