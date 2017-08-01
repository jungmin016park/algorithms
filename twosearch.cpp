// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
const int MAXN = 100;
const int MAXM = 100;

int card[MAXN];
int search[MAXM];

void swap(int *list, int left, int right)
{
	int tmp = list[left];
	list[left] = list[right];
	list[right] = tmp;
}

int partition(int *list, int left, int right)
{
	// left ++
	// right --
	// swap
	int pilot = left;
	left++;

	while (left <= right) {
		while (left < right && list[left] < list[pilot]) left++;
		while (left <= right && list[pilot] <= list[right]) right--;
		
		if (left < right)
			swap(list, left, right);
	}
	
	swap(list, pilot, right);
	return right;
}

void quick_sort(int *list, int left, int right)
{

	if (left < right) {
		int mid = partition(list, left, right);
		// divide
		quick_sort(list, left, mid-1);
		quick_sort(list, mid+1, right);
	}
}

int twosearch(int left, int right, int count, int search_num)
{
	int mid = (left + right) / 2;
	int ret = 0;
	
	if (left > right)
		return count;
	else {
		if (card[mid] > search_num) {
			ret += twosearch(left, mid-1, count, search_num);
		}
		else if (card[mid] < search_num) {
			ret += twosearch(mid+1, right, count, search_num);
		}
		else {
			ret += twosearch(left, mid - 1, count, search_num);
			ret += twosearch(mid + 1, right, count, search_num);
			ret++;
		}
	}
	
	return ret;
}

int main(void) {
	int T;
	
	int N, M;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &card[i]);

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
		scanf("%d", &search[i]);

	quick_sort(card, 0, N-1);

	for (int i = 0; i < M; i++) {
		int searchNum = search[i];
		int left = 0, right = N - 1;
		int mid;
		int count = 0;

		printf("%d ", twosearch(left, right, 0, searchNum));
	}
	printf("\n");

	return 0;
}
