#include <iostream>
#include <memory>
#include <string>

int CountOfOne(int n)
{
	if (n < 0)
		return -1;

	int count = 0;

	while (n > 0)
	{
		count += (n & 1);
		n = n >> 1;
	}

	return count;
}

int GreatestCommonDivider(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;

	if (a > b)
		return GreatestCommonDivider(a - b, b);
	else if (b > a)
		return GreatestCommonDivider(a, b - a);
	else
		return a;
}

int FibonaqiLoop(int n)
{
	if (n < 0)
		return -1;
	if (n == 0 || n == 1)
		return n;

	int a = 0, b = 1;
	int fibo;
	for (int i = 2; i <= n; i ++)
	{
		fibo = a + b;
		a = b;
		b = fibo;
	}

	return fibo;
}

int FibonaqiRecurrence(int n)
{
	if (n < 0)
		return -1;
	if (n < 2)
		return n;

	return FibonaqiRecurrence(n - 1) + FibonaqiRecurrence(n - 2);
}

bool IfSubArraySumsN(int *ar, int len, int N)
{
	if (ar == NULL || len <= 0)
		return false;

	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum = 0;
		for (int j = i; j < len; j++)
		{
			sum += ar[j];
			if (sum == N)
				return true;
		}
	}

	return false;
}

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

int MaxSumSubArray_Exhaustive(int *ar, int len)
{
	if (ar == NULL || len <= 0)
		return -1;

	int maxSum = ar[0];
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			int temp = 0;
			for (int k = i; k <= j; k++)
			{
				temp += ar[k];
			}

			maxSum = maxSum > temp ? maxSum : temp;
		}
	}

	return maxSum;
}

int MaxSumSubArray_Dynamic(int *ar, int len)
{
	if (ar == NULL || len <= 0)
		return -1;

	int * mediaResult = new int[len];
	if (mediaResult == NULL)
		return -2;

	int maxSum = ar[0];
	int start = 0, end = 0;
	mediaResult[0] = ar[0];
	for (int i = 1; i < len; i++)
	{
		if (mediaResult[i - 1] > 0)
		{
			mediaResult[i] =  mediaResult[i - 1] + ar[i];
		}
		else
		{
			mediaResult[i] =  ar[i];
			start = i;
		}

		if (maxSum < mediaResult[i])
		{
			maxSum = mediaResult[i];
			end = i;
		}
	}

	std::cout << "start: " << start << " end: " << end << " sum: " << maxSum << std::endl;

	delete[] mediaResult;
	mediaResult = NULL;
	
	return maxSum;
}

int MinCoins_Greedy(int *coins, int len, int target)
{
	if (coins == NULL || len < 1)
		return -1;

	int *counts = new int[len];
	if (counts == NULL)
		return -2;

	memset(counts, 0, sizeof(int) * len);

	int ret = 0;
	int index = len - 1;
	int remains = target;

	while (index >= 0 && remains > 0)
	{
		while (remains >= coins[index])
		{
			ret++;
			remains -= coins[index];
			counts[index]++;
		}
		index--;
	}

	PrintIntArray(coins, len);
	PrintIntArray(counts, len);

	return ret;
}

int MinCoins_Dynamic(int *coins, int len, int target)
{
	if (coins == NULL || len < 1)
		return -1;

	int *counts = new int[len];
	if (counts == NULL)
		return -2;
	memset(counts, 0, sizeof(int) * len);

	int *mediaResult = new int[target + 1];
	if (mediaResult == NULL)
		return -2;
	mediaResult[0] = 0;

	for (int i = 1; i < target + 1; i++)
	{
		memset(counts, 0, sizeof(int) * len);

		int min = target;
		int currency = 0;
		for (int j = 0; j < len; j++)
		{
			int cand = mediaResult[i - coins[j]] + 1;
			if (cand < min)
			{
				min = cand;
				currency = j;
			}
		}
		mediaResult[i] = min;
		counts[currency]++;
	}

	PrintIntArray(coins, len);
	PrintIntArray(counts, len);

	return mediaResult[target];
}

int main(int argc, char **argv) 
{
	////////////////////////////////////////Count of 1
	// int n;
	// do
	// {
	// 	std::cout << "Input number n: ";
	// 	std::cin >> n;
	// 	std::cout << "Count of 1 for " << n << " is: " << CountOfOne(n) << std::endl;
	// } while(n > 0);

	////////////////////////////////////////GreatestCommonDivider
	// int a = 0, b = 0;
	// do
	// {
	// 	std::cout << "Input a: ";
	// 	std::cin >> a;
	// 	std::cout << std::endl;

	// 	std::cout << "Input b: ";
	// 	std::cin >> b;
	// 	std::cout << std::endl;

	// 	std::cout << GreatestCommonDivider(a, b) << std::endl;
	// }while (a != 0 && b != 0);

	////////////////////////////////////////fibo
	// int n = 0;
	// do 
	// {
	// 	std::cout << "Input n:(negative for exit)";
	// 	std::cin >> n;
	// 	std::cout << "Fibonaqi at the index " << n << " is: " << FibonaqiRecurrence(n) << std::endl;
	// } while (n > 0);

	////////////////////////////////////////fibo
	// int ar[] = {2, -5, 3, 8, -4, 1, 2, 9};
	// int N;
	// do 
	// {
	// 	PrintIntArray(ar, sizeof(ar) / sizeof(int));
	// 	std::cout << "Input sum N:(0 for exit)";
	// 	std::cin >> N;
	// 	std::cout << "IfSubArraySumsN is: " << IfSubArraySumsN(ar, sizeof(ar) / sizeof(int), N) << std::endl;
	// } while (N != 0);

	////////////////////////////////////////bubble sort
	// int ar[] = {2, -5, 3, 8, -4, 1, 2, 9, -6};
	// PrintIntArray(ar, sizeof(ar) / sizeof(int));
	// // BubbleSort(ar, sizeof(ar) / sizeof(int));
	// QuickSort(ar, sizeof(ar) / sizeof(int));
	// PrintIntArray(ar, sizeof(ar) / sizeof(int));

	////////////////////////////////////////MaxSumSubArray
	// int ar[] = {2, -5, 3, 8, -4, 1, 2, 9, -6};
	// PrintIntArray(ar, sizeof(ar) / sizeof(int));
	// std::cout << "MaxSumSubArray_Exhaustive returns: " << MaxSumSubArray_Exhaustive(ar, sizeof(ar) / sizeof(int)) << std::endl;
	// std::cout << "MaxSumSubArray_Dynamic returns: " << MaxSumSubArray_Dynamic(ar, sizeof(ar) / sizeof(int)) << std::endl;

	int coints[] = {1, 2, 7, 9};
	std::cout << "MinCoins_Greedy returns: " << MinCoins_Greedy(coints, sizeof(coints) / sizeof(int), 14) << std::endl;
	std::cout << "MinCoins_Dynamic returns: " << MinCoins_Dynamic(coints, sizeof(coints) / sizeof(int), 14) << std::endl;

  	return 0;
}