#include <iostream>
#include <string>

//using namespace std;

#define SIZE 8
int gCount = 0;

// void PrintPositions()
// {
// 	for (int pos=0; true; pos++)
// 	{
// 		if ((pos >> 8) > 0)
// 			break;

// 		if ((pos & 0xF) % 3 == ((pos & 0xF0) >> 4) % 3
// 			&& (pos & 0xF) % 3 > 0)
// 			continue;

// 		if ((pos & 0xF) > 9 || ((pos & 0xF0) >> 4) > 9)
// 			continue;

// 		std::cout 	<< (pos & 0xF) / 3 << "," << (pos & 0xF) % 3 << ":"
// 					<< ((pos >> 4) & 0xF) / 3 << "," << ((pos >> 4) & 0xF) % 3 << std::endl;
// 	}
// }

void PrintQueens(int * queens, bool success = true)
{
	if (success)
	{
		std::cout << "Solution " << gCount++ << ": " << std::endl;
	}
	else
	{
		std::cout << "Failed solution " << ": " << std::endl;
	}

	for (int i = 0; i < SIZE; i ++)
	{
		std::cout << i << ", " << queens[i] << std::endl;
	}

	std::cout << std::endl;
}

bool CheckQueens(int * queens, int index)
{
	for (int i = 0; i < index; i ++)
	{
		for (int j = i + 1; j <= index; j++)
		{
			if (queens[i] == queens[j]
				|| (i + queens[i]) == (j + queens[j])
				|| (-i + queens[i]) == (-j + queens[j])
				// || (i - queens[i]) == (j - queens[j])
				)
			{
				return false;
			}
		}
	}

	return true;
}

void EightQueens(int * queens, int index)
{
	if (index >= SIZE)
	{
		PrintQueens(queens);
	}
	else
	{
		for (int i = 0; i < SIZE; i++)
		{
			queens[index] = i;
			if (CheckQueens(queens, index))
			{
				EightQueens(queens, index + 1);
			}
		}
	}
}

int main(int argc, char **argv) {

	// PrintPositions();

	int queens[SIZE] = {0};
	EightQueens(queens, 0);

  return 0;
}