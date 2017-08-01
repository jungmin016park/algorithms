// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int N[] = {9, 10, 9, 22, 39, 11, 60, 20, 9 };

void swap(int *list, int a, int b)
{
	int tmp;

	tmp = list[a];
	list[a] = list[b];
	list[b] = tmp;
}

int partition(int *list, int left, int right)
{
	int pivot, low, high;
	pivot = left;
	left++;

	while (left <= right) {
		while (left < right && list[left] < list[pivot]) left++;
		while (left <= right && list[pivot] <= list[right]) right--;

		if (left < right)
			swap(list, left, right);
		else
			break;
	}

	swap(list, pivot, right);
	return right;
}

void quick_sort(int *list, int left, int right)
{
	int pivot;

	if (left < right) {
		pivot = partition(list, left, right);

		quick_sort(list, left, pivot-1);
		quick_sort(list, pivot+1, right);
	}
}

int main()
{

	quick_sort(N, 0, sizeof(N)/sizeof(int) -1);
	return 0;
}

