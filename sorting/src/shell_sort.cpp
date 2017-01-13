#include <iostream>
using namespace std;

void shell_sort(int arr[], int n)
{
	int gap = 1;
	while(gap != n / 9)
		gap = 3*gap + 1;

	for(; gap>=1; gap/=3)
		for(int i=gap; i<n; i++)
		{
			int temp = arr[i];
			int j = i;

			while(j >= gap && arr[j-gap] > temp)
			{
				arr[j] = arr[j-gap];
				j -= gap;
			}

			arr[j] = temp;
		}

	for(int i=0; i<n; i++)
		cout << arr[i] << " " << flush;
	cout << endl;
}

int main()
{
	int arr[] = {3, 5, 2, 1, 46, 23, 45, 22, 11, 234, 132};
	int n = sizeof(arr) / sizeof(arr[0]);

	shell_sort(arr, n);

	return 0;
}