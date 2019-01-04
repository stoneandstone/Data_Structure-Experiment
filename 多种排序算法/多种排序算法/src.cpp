#include <iostream>
#include <random>
#include <vector>
#include "sort.h"

using namespace std;

vector<int>createRandomVector(int ivecSize)
{
	default_random_engine random(time(NULL));
	uniform_int_distribution<int> dis1(0, INT_MAX);
	vector<int>ivec(ivecSize);
	for (auto& i : ivec)
	{
		i = dis1(random);
	}
	return ivec;
}

int main()
{
	
	int ivecSize;
	cout << "请输入数组的容量: ";
	cin >> ivecSize;

	vector<int>ivec=createRandomVector(ivecSize);

	BubbleSort<int> bubbleSort(ivec);
	bubbleSort.outputMess();
	cout << endl;

	SelectionSort<int> selectioSort(ivec);
	selectioSort.outputMess();
	cout << endl;

	DirectlyInsertSort<int> directlySort(ivec);
	directlySort.outputMess();
	cout << endl;

	ShellSort<int> shellSort(ivec);
	shellSort.outputMess();
	cout << endl;

	QuickSort<int> quickSort(ivec);
	quickSort.outputMess();
	cout << endl;

	HeapSort<int> heapSort(ivec);
	heapSort.outputMess();
	cout << endl;

	MergeSort<int> mergeSort(ivec);
	mergeSort.outputMess();
	cout << endl;

	RadixSort<int> radixSort(ivec, 10);
	radixSort.outputMess();

	system("pause");
	return 0;

}