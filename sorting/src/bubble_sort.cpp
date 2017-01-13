#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}

void bubble_sort(int arr[], int n)
{
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(arr[i] > arr[j])
				swap(arr[i], arr[j]);

	for(int i=0; i<n; i++)
		cout << arr[i] << " " << flush;
	cout << endl;
}

int main()
{
	int arr[] = {1, 4, 3, 2, 6, 5, 9, 8};
	int n = sizeof(arr) / sizeof(arr[0]);

	bubble_sort(arr, n);

	return 0;
}