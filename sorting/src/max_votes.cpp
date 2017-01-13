#include <iostream>
#include <string.h>
using namespace std;

void counting_sort(int arr[], int sorted[], int n, int k)
{
	int temp[k];
	memset(temp, 0, sizeof(temp));

	for(int i=0; i<n; i++)
		temp[arr[i]]++;

	for(int i=1; i<k; i++)
		temp[i] += temp[i-1];

	for(int i=0; i<n; i++)
		sorted[--temp[arr[i]]] = arr[i];
}

int max_votes(int votes[], int n)
{
	int curr_count, max_count;
	curr_count = max_count = 1;

	int curr_cand, max_cand;
	curr_cand = max_cand = votes[0];

	for(int i=1; i<n; i++)
	{
		if(curr_cand == votes[i])
			curr_count++;
		else
		{
			curr_cand = votes[i];
			curr_count = 1;
		}

		if(max_count < curr_count)
		{
			max_count = curr_count;
			max_cand = curr_cand;
		}
	}

	return max_cand;
}

int main()
{
	int votes[] = {4, 2, 1, 3, 1, 2, 1, 2, 3, 2};
	int n = sizeof(votes) / sizeof(votes[0]);
	int sorted[n];

	counting_sort(votes, sorted, n, 5);

	cout << max_votes(sorted, n) << endl;

	return 0;
}