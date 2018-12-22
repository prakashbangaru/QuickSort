all:
	gcc -g BasicQuickSort.c -o BasicQuickSort.out
	gcc -g RandomizedQuickSort.c -o RandomizedQuickSort.out
	gcc -g MedianQuickSort.c -o MedianQuickSort.out

part_BasicQuickSort:
	gcc -g BasicQuickSort.c -o BasicQuickSort.out
part_RandomizedQuickSort:
	gcc -g RandomizedQuickSort.c -o RandomizedQuickSort.out
part_MedianQuickSort:
	gcc -g MedianQuickSort.c -o MedianQuickSort.out

clean:
	rm ./*.out

