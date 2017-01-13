#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{
	for(int i=1; i<n; i++)
	{
		int temp = arr[i];
		int j = i;
		
		while(j >= 1 && arr[j-1] > temp)
		{
			arr[j] = arr[j-1];
			j--;
		}

		arr[j] = temp;
	}

	for(int i=0; i<n; i++)
		cout << arr[i] << " " << flush;
	cout << endl;
}

int main()
{
	int arr[] = {4, 13, 2, 5, 20, 1, 45, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	insertion_sort(arr, n);

	return 0;
}