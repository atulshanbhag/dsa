// A and B are 2 arrays of length n. Given K, 
// find a in A and b in B such that a + b = K

#include <iostream>
using namespace std;

void print_array(int arr[], int n)
{
	for(int i=0; i<n; i++)
		cout << i << " " << flush;
	cout << endl;
}

void swap(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}

int partition(int arr[], int low, int high)
{
	int left = low, right = high;
	int pivot = arr[low];

	while(left < right) 
	{
		while(arr[left] <= pivot)
			left++;

		while(arr[right] > pivot)
			right--;

		if(left < right)
			swap(arr[left], arr[right]);
	}

	arr[low] = arr[right];
	arr[right] = pivot;

	return right;
}

void quick_sort(int arr[], int low, int high)
{
	if(low < high)
	{
		int pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot-1);
		quick_sort(arr, pivot+1, high);
	}
}

bool binary_search(int arr[], int low, int high, int val)
{
	if(low <= high)
	{
		int mid = (low + high) / 2;

		if(arr[mid] == val)
			return true;

		else if(val < arr[mid])
			return binary_search(arr, low, mid-1, val);

		else
			return binary_search(arr, mid+1, high, val);
	}

	return false;
}

bool find(int A[], int B[], int n, int K)
{
	quick_sort(A, 0, n-1);

	for(int i=0; i<n; i++)
	{
		int val = K - B[i];
		if(binary_search(A, 0, n-1, val))
			return true;
	}

	return false;
}

int main()
{
	int A[] = {3, 4, 5, 2, 1, 3, 2, 6};
	int B[] = {5, 4, 2, 1, 4, 5, 3, 2};
	int n = sizeof(A) / sizeof(A[0]);

	int K = 10;

	cout << find(A, B, n, K) << endl;

	return 0;
}