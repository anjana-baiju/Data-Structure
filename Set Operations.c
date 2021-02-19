#include <stdio.h>
void main()
{
 int U[5]={1,2,3,4,5},A[5]={1,0,0,1,1},B[5]={0,1,1,1,0},uni[5],ints[5],diffA[5],diffB[5], i,compA[5],compB[5];
 
 printf("The universal set : ");
 for(i=0;i<5;i++)
 printf("%d\t",U[i]);
 printf("\nThe Set A : ");
 for(i=0;i<5;i++)
 {
    if(A[i]==1)
    printf("%d\t",U[i]);
 }
 printf("\nThe Set B : ");
 for(i=0;i<5;i++)
 {
    if(B[i]==1)
    printf("%d\t",U[i]);
 }
 printf("\nBit representation of AUB : ");
 for(i=0;i<5;i++)
 {
    uni[i]=A[i]|B[i];
    printf("%d\t",uni[i]);
 }
 printf("\n AUB =\t");
 for(i=0;i<5;i++)
 {
    if(uni[i]==1)
    printf("%d\t",U[i]);
 }


 printf("\nBit representation of AnB : ");
 for(i=0;i<5;i++)
 {
    ints[i]=A[i]&B[i];
    printf("%d\t",ints[i]);
 }
 printf("\n AnB =\t");
 for(i=0;i<5;i++)
 {
    if(ints[i]==1)
    printf("%d\t",U[i]);
 }

 printf("\nComplement of A : ");
 for(i=0;i<5;i++)
 {
 compA[i]=1-A[i];
 printf("%d\t",compA[i]);
 }
 printf("\nA' =\t");
 for(i=0;i<5;i++)
 {
    if(compA[i]==1)
    printf("%d\t",U[i]);
 }

 printf("\nComplement of B : ");
 for(i=0;i<5;i++)
 {
    compB[i]=1-B[i];
    printf("%d\t",compB[i]);
 }
 printf("\nB' =\t");
 for(i=0;i<5;i++)
 {
 if(compB[i]==1)
 printf("%d\t",U[i]);
 }

 printf("\nDifference of A : ");
 for(i=0;i<5;i++)
 {
    diffA[i]=A[i]&compB[i];
    printf("%d\t",diffA[i]);
 }
 printf("\n A-B =\t");
 for(i=0;i<5;i++)
 {
    if(diffA[i]==1)
    printf("%d\t",U[i]);
 }

 printf("\nDifference of B : ");
 for(i=0;i<5;i++)
 {
    diffB[i]=B[i]&compA[i];
    printf("%d\t",diffB[i]);
 }
 printf("\n B-A =\t");
 for(i=0;i<5;i++)
 {
 if(diffB[i]==1)
 printf("%d\t",U[i]);
 }
 
}
