#include "mergesort.h"
#include <stdlib.h>
#include <stdio.h>

void printArray(int size, int arr[], int depth);

void mergesort(int size, int values[]){
  int midPoint; // It's more efficient to initialize only if sorting is needed.
  int *merged;

  if(size<2){return;} //Doesn't need sorting
  
   midPoint = size / 2; //C rounds towards 0 when dividing two ints
   mergesort(midPoint,values);
   mergesort(size-midPoint,values+midPoint);
   //printf("Merging Arrays...%p, %d, %d\n", (void *) values, midPoint, size-midPoint);
   //printArray(midPoint,values,1);
   //printArray(size-midPoint,values+midPoint,1);
   merged=mergeRanges(midPoint,values,size-midPoint,values+midPoint);
   //printArray(size,merged,2);
   arrayCopy(values,merged,size); // overwrite original data with merged data
   free((void *) merged);
}

int *mergeRanges(int sizeA,int arrayA[],int sizeB,int arrayB[]){ //allocates 
   int n=sizeA+sizeB; // size of combined arrays
   int val=-1;       // storage variable
   int *mergedArray;
   int i=0,a=0,b=0;
   
   mergedArray=(int *) calloc(sizeof(int),n);
   if (!mergedArray) { //PCD doesn't matter if students don't include this bonus if they do
     fputs("mem failure, exiting \n", stderr);
     exit(EXIT_FAILURE);
   }
   for(i=0;i<n;i++){
     if(a==sizeA){ //Then a is 1 past the end of the 0indexed arrayA
       val=arrayB[b++]; // Now we start copying from arrayB
     } else if (b==sizeB){ //Same idea for b
       val=arrayA[a++]; // But we start copying from a
     } else {
       //printf("\t\t\tComparing %d to %d at positions %d and %d\n",arrayA[a],arrayB[b],a,b);
       val=(arrayA[a]<arrayB[b])?arrayA[a++]:arrayB[b++];
     }
     mergedArray[i]=val;
     //printf("\t\tSetting index %d to value %d\n",i,val);
   }
   return(mergedArray);
}

void arrayCopy(int *arrayA, int *arrayB,int n){ // sets values of a[] to values of b[] for first n
   int i=0;
   for(i=0;i<n;i++){
      arrayA[i]=arrayB[i];
   }
}
void printArray(int size, int* arr,int tab){
  int i;

  for(i=0;i<tab;i++){ // Print an indention if requested
    //printf("\t");
  }
  for(i=0; i<(size-1); i++){printf("%d, ",arr[i]);} // Print all but the last member
  printf("%d\n",arr[i]); //print the last member
}
/*int main(){
  //printf("hello mom!\n");
}*/
