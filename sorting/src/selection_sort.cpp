#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}

void selection_sort(int arr[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		int min = i;

		for(int j=i+1; j<n; j++)
			if(arr[j] < arr[min])
				min = j;
		
		swap(arr[min], arr[i]);
	}

	for(int i=0; i<n ;i++)
		cout << arr[i] << " " << flush;
	cout << endl;
}

int main()
{
	int arr[] = {1, 4, 3, 6, 7 ,2 , 8, 5, 9};
	int n = sizeof(arr) / sizeof(arr[0]);

	selection_sort(arr, n);

	return 0;
}