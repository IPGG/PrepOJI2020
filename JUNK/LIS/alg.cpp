#include <bits/stdc++.h>
using namespace std;
int arr[100];
int n;

int lis()
{
	int lis[n + 1], i, j, max = 0;
	for (i = 1; i <= n; i++)
		lis[i] = 1;

	for (i = 2; i <= n; i++)
		for (j = 1; j < i; j++)
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;

	int maxIndex = -1;
	for (i = 1; i <= n; i++)
		if (max < lis[i])
		{
			max = lis[i];
			maxIndex = i;
		}
    cout << '\n';
    cout << "LIS it's: ";
    int LIS_sequence[max];
    int currentLength = max;
    for (int i = maxIndex; i >= 1; i--)
    {
        if (lis[i] == currentLength)
        {
            LIS_sequence[currentLength] = arr[i];
            currentLength--;
        }
    }
    for (int i = 1; i <= max; i++)
        cout << LIS_sequence[i] << ' ';
	return max;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> arr[i];
	cout << "lungimea maxima a secventei crescatoare : " << lis();
	return 0;
}
