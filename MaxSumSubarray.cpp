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

int main(int argc, char **argv) 
{
	int ar[] = {2, -5, 3, 8, -4, 1, 2, 9, -6};
	PrintIntArray(ar, sizeof(ar) / sizeof(int));
	std::cout << std::endl;

	int maxSum = MaxSumSubArray_Exhaustive(ar, sizeof(ar) / sizeof(int));
	std::cout << "MaxSumSubArray_Exhaustive returns: " << maxSum << std::endl << std::endl;

	maxSum = MaxSumSubArray_Dynamic(ar, sizeof(ar) / sizeof(int));
	std::cout << "MaxSumSubArray_Dynamic returns: " << maxSum << std::endl << std::endl;

  	return 0;
}