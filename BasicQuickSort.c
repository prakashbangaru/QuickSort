#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARRAY_SIZE 1000
#define LOOP_COUNT 10

int compareCount=0;
int swappingCount=0;

int partitionSort (int array[], int low, int high);    
void sort(int array[],int low,int high);

int partition (int array[], int low, int high){    
    int pivot = array[high];
    int i=0;
    int j=0;	
    int temp=0;
    i = (low - 1);  // Index of smaller element

    for (j = low; j <= high- 1; j++){
        // If current element is smaller than or equal to pivot
        compareCount++;
        if (array[j] <= pivot){
            i++;    // increment index of smaller element
	    temp = array[i];  
            array[i]=array[j];
	    array[j]=temp;
            swappingCount++; 
        }
    }
    swappingCount++;
    temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp; 	
    return (i + 1);
}

int getRand(){
    int d = rand() % 1000; /*Generate Value from 1 to 1000*/
    return (d+1); 
}

int basicSort(int array[],int low, int high){
  	int pi=0; /* pi is partitioning index*/
    if (low < high){
        pi = partition(array, low, high);
        basicSort(array, low, pi - 1);
        basicSort(array, pi + 1, high);
    }
}

void getRandomInput(int *array){
     int index=0;
     srand(time(NULL));
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
	
	/*Generate a random list of 1000  */
	getRandomInput(array);
	
	memcpy(sortedArray, array, arraySizeByte);
	/*Generate a sorted version of the list */
        sort(sortedArray,0,ARRAY_SIZE-1);

	memcpy(reverseSortedArray,sortedArray, arraySizeByte);
	/*Generate reverse-sorted (i.e. high to low) version of the list */
	reverseList(reverseSortedArray);

        #if 0	
	/*Test to BE removed*/
	printList(array);
	printList(sortedArray);
	printList(reverseSortedArray);
        #endif
       /*BAsic Sort Operation on randomized Array*/
       for(index=0;index<LOOP_COUNT;index++){
          basicSort(array,0,ARRAY_SIZE-1);
       }
       printf("Avg Number OF Comparison required for Basic Quick Sort on Randomized Array = %d\n",(compareCount/LOOP_COUNT));
       printf("Avg Number OF Swapping required for  Basic Quick Sort on Randomized Array = %d\n",(swappingCount/LOOP_COUNT));
       compareCount=0;
       swappingCount=0;
       /*BAsic Sort Operation on sortedArray Array*/
       for(index=0;index<LOOP_COUNT;index++){
             basicSort(sortedArray,0,ARRAY_SIZE-1);
       }
       printf("Avg Number OF Comparison required for Basic Quick Sort on Sorted Array = %d\n",(compareCount/LOOP_COUNT));
       printf("Avg Number OF Swapping required for  Basic Quick Sort on Sorted Array = %d\n",(swappingCount/LOOP_COUNT));
       compareCount=0;
       swappingCount=0;
       /*BAsic Sort Operation on reverseSortedArray Array*/
       for(index=0;index<LOOP_COUNT;index++){
             basicSort(reverseSortedArray,0,ARRAY_SIZE-1);
       }
       printf("Avg Number OF Comparison required for Basic Quick Sort on reverse Sorted Array = %d\n",(compareCount/LOOP_COUNT));
       printf("Avg Number OF Swapping required for  Basic Quick Sort on reverse Sorted Array = %d\n",(swappingCount/LOOP_COUNT));
	
	return 0;
}

int partitionSort (int array[], int low, int high){    
    int pivot = array[high];
    int i=0;
    int j=0;	
    int temp=0;
    i = (low - 1);  // Index of smaller element

    for (j = low; j <= high- 1; j++){
        if (array[j] <= pivot){
            i++;    // increment index of smaller element
	    temp = array[i];  
            array[i]=array[j];
	    array[j]=temp;
        }
    }
    temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp; 	
    return (i + 1);
}


void sort(int array[],int low, int high){
    int pi=0; /* pi is partitioning index*/
    if (low < high){
        pi = partitionSort(array, low, high);
        sort(array, low, pi - 1);
        sort(array, pi + 1, high);
    }
}

