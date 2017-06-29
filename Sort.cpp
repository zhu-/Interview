#include <iostream>
#include <memory>
#include <string>


void PrintIntArray(int *ar, int len)
{
	if (ar == NULL || len < 1)
		return ;

	std::cout << "array: ";
	for (int i = 0; i < len; i++)
	{
		std::cout << ar[i] << ", "; 
	}

	std::cout << std::endl;
}

bool BubbleSort(int *ar, int len)
{
	if (ar == NULL)
		return false;
	if (len <= 1)
		return true;

	bool ifFinished;
	for (int i = 0; i < len - 1; i++)
	{
		ifFinished = true;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (ar[j] > ar[j + 1])
			{
				int temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;

				ifFinished = false;
			}
		}

		if (ifFinished)
			return true;
	}

	return true;
}

bool QuickSort(int *ar, int len)
{
	if (ar == NULL)
		return false;
	if (len <= 1)
		return true;

	int target = ar[0];
	int i = 0, j = len - 1;
	while (i < j)
	{
		while (ar[j] > target && j > i)
			j--;

		if (j > i)
		{
			ar[i] = ar[j];
			i++;
		}

		while (ar[i] <= target && i < j)
			i++;

		if (i < j)
		{
			ar[j] = ar[i];
			j--;
		}
	}
	ar[i] = target;
	PrintIntArray(ar, len);

	QuickSort(ar, i);
	QuickSort(ar + i + 2, len - (i + 2));

	return true;
}

int main(int argc, char **argv) 
{
	int ar[] = {2, -5, 3, 8, -4, 1, 2, 9, -6};
	PrintIntArray(ar, sizeof(ar) / sizeof(int));
	BubbleSort(ar, sizeof(ar) / sizeof(int));
	PrintIntArray(ar, sizeof(ar) / sizeof(int));

	int br[] = {2, -5, 3, 8, -4, 1, 2, 9, -6};
	PrintIntArray(br, sizeof(br) / sizeof(int));
	QuickSort(br, sizeof(br) / sizeof(int));
	PrintIntArray(br, sizeof(br) / sizeof(int));

  	return 0;
}