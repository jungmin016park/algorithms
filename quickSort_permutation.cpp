// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

int T, N, M, K;

int arr[MAX_N] = { 5, 2, 9, 4 };
int cnt = 0;

int swap(int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
	return 0;
}

int permutation(int totalN, int N)
{
	if (N == 1) {
		for (int i = 0; i < totalN; i++) {
			printf("%d ", arr[i]);
		}

		cnt++;
		printf("\n");
		return 0;
	}


	for (int i = 0; i < N; i++) {
		swap(i, N - 1);
		permutation(totalN, N - 1);
		swap(i, N - 1);
	}
}

int partition(int left, int right)
{
	int pivot = left;
	left++;

	while (left <= right) {
		while (left < right && arr[left] < arr[pivot]) left++;
		while (left <= right && arr[pivot] <= arr[right]) right--;

		if (left < right) {
			swap(left, right);
		}
		else
			break;
	}

	swap(pivot, right);
	return right;
}

int quick_sort(int left, int right)
{
	if (left < right) {
		int mid = partition(left, right);

		quick_sort(mid+1, right);
		quick_sort(left, mid -1);
	}

	return 0;
}

int main()
{
	//permutation(4, 4);
	quick_sort(0, 3);
}

