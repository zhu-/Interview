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

	int *mediaResult = new int[target + 1];
	if (mediaResult == NULL)
		return -2;
	mediaResult[0] = 0;

	for (int i = 1; i < target + 1; i++)
	{
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
	}

	return mediaResult[target];
}

int main(int argc, char **argv) 
{
	int coins[] = {1, 2, 7, 9};
	int change = 14;

	int minCoins = MinCoins_Greedy(coins, sizeof(coins) / sizeof(int), change);
	std::cout << "MinCoins_Greedy for change " << change << " returns: " << minCoins << std::endl << std::endl;

	minCoins = MinCoins_Dynamic(coins, sizeof(coins) / sizeof(int), change);
	std::cout << "MinCoins_Dynamic for change " << change << " returns: " << minCoins << std::endl << std::endl;

  	return 0;
}