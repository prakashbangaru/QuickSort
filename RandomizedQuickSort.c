#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define ARRAY_SIZE 1000
#define LOOP_COUNT 10

int compareCount=0;
int swappingCount=0;
bool flag=false;

int getRandWithInRange(int,int);

void swap(int *x, int*y){
   int z = *x; 
    *x = *y; 
    *y = z;
    if(flag)
    swappingCount++;
}

int partition(int array[], int low, int high){    
    int pivot = array[high];
    int i=0;
    int j=0;	
    i = (low - 1);  // Index of smaller element

    for (j = low; j <= high- 1; j++){
        if(flag)
           compareCount++;
        // If current element is smaller than or equal to pivot
        if (array[j] <= pivot){
            i++;    // increment index of smaller element
            swap(&array[i],&array[j]);
        }
    }

    swap(&array[i+1],&array[high]);
    return (i + 1);
}

int randomizedPartition(int array[],int low,int high){
    int i=0;
    i = getRandWithInRange(low,high);
    swap(&array[i],&array[high]);
    return partition(array,low,high);
}


void sort(int array[],int low, int high){
	int pi=0; /* pi is partitioning index*/
    if (low < high){
        pi = partition(array, low, high);
        sort(array, low, pi - 1);
        sort(array, pi + 1, high);
    }
}

int getRand(){
    int d = rand() % ARRAY_SIZE; /*Generate Value from 1 to 1000*/
    return (d+1); 
}

int getRandWithInRange(int lower, int upper){
    int num=0;
    num = (rand() % (upper - lower + 1)) + lower; 
    return num;   
}

int randomizedQuickSort(int array[],int low, int high){
    int pi=0; /* pi is partitioning index*/
    if (low < high){
        pi = randomizedPartition(array, low, high);
        randomizedQuickSort(array, low, pi - 1);
        randomizedQuickSort(array, pi + 1, high);
    }
}

void getRandomInput(int *array){
     int index=0;
     for(index=0; index < ARRAY_SIZE; index++){
		 array[index] = getRand();
     }		 
}

void reverseList(int *array){
   int i=0;
   int j=ARRAY_SIZE-1;
   int temp=0;
   
     while (i < j) {
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      i++;             
      j--;         
   }   
}

void printList(int *array){
	int i=0;
	for(i=0;i<ARRAY_SIZE;i++){
		printf("%d\n",array[i]);
	}
}

int main(){
	int array[ARRAY_SIZE];
	int sortedArray[ARRAY_SIZE];
	int reverseSortedArray[ARRAY_SIZE];
	int arraySizeByte = sizeof(int)*ARRAY_SIZE; 
        int index=0;
	
	memset(array,0,arraySizeByte);
	memset(sortedArray,0,arraySizeByte);
	memset(reverseSortedArray,0,arraySizeByte);
	
         srand(time(NULL));
	/*Generate a random list of 1000  */
	getRandomInput(array);
	
	memcpy(sortedArray, array, arraySizeByte);
	/*Generate a sorted version of the list */
        randomizedQuickSort(sortedArray,0,ARRAY_SIZE-1);

	memcpy(reverseSortedArray,sortedArray, arraySizeByte);
	/*Generate reverse-sorted (i.e. high to low) version of the list */
	reverseList(reverseSortedArray);
        #if 0
	/*Test to BE removed*/
	printList(array);
	printList(sortedArray);
	printList(reverseSortedArray);
        #endif
        flag=true;
       /*BAsic Sort Operation on randomized Array*/
       for(index=0;index<LOOP_COUNT;index++){
          randomizedQuickSort(array,0,ARRAY_SIZE-1);
       }
       printf("Avg Number OF Comparison required for Randomized Quick Sort on Randomized Array = %d\n",(compareCount/LOOP_COUNT));
       printf("Avg Number OF Swapping required for  Randomized Quick Sort on Randomized Array = %d\n",(swappingCount/LOOP_COUNT));
       compareCount=0;
       swappingCount=0;
       /*BAsic Sort Operation on sortedArray Array*/
       for(index=0;index<LOOP_COUNT;index++){
             randomizedQuickSort(sortedArray,0,ARRAY_SIZE-1);
       }
       printf("Avg Number OF Comparison required for Randomized Quick Sort on Sorted Array = %d\n",(compareCount/LOOP_COUNT));
       printf("Avg Number OF Swapping required for  Randomized Quick Sort on Sorted Array = %d\n",(swappingCount/LOOP_COUNT));
       compareCount=0;
       swappingCount=0;
       /*BAsic Sort Operation on reverseSortedArray Array*/
       for(index=0;index<LOOP_COUNT;index++){
             randomizedQuickSort(reverseSortedArray,0,ARRAY_SIZE-1);
       }
       printf("Avg Number OF Comparison required for Randomized Quick Sort on reverse Sorted Array = %d\n",(compareCount/LOOP_COUNT));
       printf("Avg Number OF Swapping required for  Randomized Quick Sort on reverse Sorted Array = %d\n",(swappingCount/LOOP_COUNT));
	
	return 0;
}
