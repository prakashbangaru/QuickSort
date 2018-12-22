#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define ARRAY_SIZE 1000
#define LOOP_COUNT 10

int compareCount=0;
int swappingCount=0;

int getRandWithInRange(int,int);
bool flag=false;

void swap(int *x, int*y){
   int z = *x; 
    *x = *y; 
    *y = z;
	if(flag){
	  swappingCount++;
    }
}

int median(int array[],int small,int high){
	  int middle = (small+high)/2;

       if(flag){
         compareCount++; /*Comparison Count*/
       }
 
      if(array[middle] >= array[small] && array[middle] <= array[high]){
        return middle;
      }   
      else if(array[middle] <= array[small] && array[middle] >= array[high]){
        return middle;
      }   
      else if(array[small] >= array[middle] && array[small] <= array[high]){
        return small;
      }
      else if(array[small] <= array[middle] && array[small] >= array[high]){
        return small;
      }
      else if(array[high] <= array[middle] && array[high] >= array[small]){
        return high;
      }
      else if(array[high] >= array[middle] && array[high] <= array[small]){
        return high;
      }

}

int partition(int array[], int low, int high){    
    int pivot = array[high];
    int i=0;
    int j=0;	
    i = (low - 1);  // Index of smaller element

    for (j = low; j <= high- 1; j++){
     	if(flag){
          compareCount++; /*Comparison Count*/
		}
		// If current element is smaller than or equal to pivot 
        if (array[j] <= pivot){
            i++;    // increment index of smaller element
			swap(&array[i],&array[j]); 
        }
    }
	swap(&array[i+1],&array[high]);
    return (i + 1);
}

int medianPartition(int array[],int low,int high){
    int i=0;
    int medianIndex=0;
    int small = array[low];
    medianIndex = median(array,high,low); /*Get the Median Index*/
    swap(&array[medianIndex],&array[high]); /*Swap the High Index Value and Median Index Value to make Median index Value as Pivot*/
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

void medianQuickSort(int array[],int low, int high){
  	int pi=0; /* pi is partitioning index*/
    if (low < high){
        pi = medianPartition(array, low, high);
        medianQuickSort(array, low, pi - 1);
        medianQuickSort(array, pi + 1, high);
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
	  swap(&array[i],&array[j]);
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
        medianQuickSort(sortedArray,0,ARRAY_SIZE-1);

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
          medianQuickSort(array,0,ARRAY_SIZE-1);
       }
       printf("Avg Number OF Comparison required for Median Quick Sort on Randomized Array = %d\n",(compareCount/LOOP_COUNT));
       printf("Avg Number OF Swapping required for Median Quick Sort on Randomized Array = %d\n",(swappingCount/LOOP_COUNT));
       compareCount=0;
       swappingCount=0;
       /*BAsic Sort Operation on sortedArray Array*/
       for(index=0;index<LOOP_COUNT;index++){
             medianQuickSort(sortedArray,0,ARRAY_SIZE-1);
       }
       printf("Avg Number OF Comparison required for Median Quick Sort on Sorted Array = %d\n",(compareCount/LOOP_COUNT));
       printf("Avg Number OF Swapping required for Median Quick Sort on Sorted Array = %d\n",(swappingCount/LOOP_COUNT));
       compareCount=0;
       swappingCount=0;
       /*BAsic Sort Operation on reverseSortedArray Array*/
       for(index=0;index<LOOP_COUNT;index++){
             medianQuickSort(reverseSortedArray,0,ARRAY_SIZE-1);
       }
       printf("Avg Number OF Comparison required for Median Quick Sort on reverse Sorted Array = %d\n",(compareCount/LOOP_COUNT));
       printf("Avg Number OF Swapping required for  Median Quick Sort on reverse Sorted Array = %d\n",(swappingCount/LOOP_COUNT));
	
	return 0;
}
