#include <iostream>
using namespace std;

void print_array(int arr[], int n)
{
	for(int i=0; i<n; i++)
		cout << arr[i] << " " << flush;
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
	int left, right, pivot = arr[low];
	left = low, right = high;

	while(left < right)
	{
		while(arr[left] <= pivot)
			left++;

		while(pivot < arr[right])
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

int main()
{
	int arr[] = {4, 2, 3, 1, 5, 9, 12, 14, 8, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	quick_sort(arr, 0, n-1);

	print_array(arr, n);

	return 0;
}