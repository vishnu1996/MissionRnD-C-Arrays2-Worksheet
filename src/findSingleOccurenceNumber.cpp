/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

int findSingleOccurenceNumber(int *A, int len) //This function works well for given spec in order of n i.e., O(n)
{
	int i, sum = 0, temp;
	if (A == nullptr)
		return -1;
	for (i = 0; i < len; i++)
		sum += A[i];
	for (i = 0; i < len; i++)
	{
		if ((sum - A[i]) % 3 == 0)
		{
			temp = A[i];
			for (i; i < len - 1; i++)
			{
				if (A[i + 1] == temp)
				{
					for (i; i < len - 2; i++)
					{
						if (A[i + 2] != temp && ((sum - A[i + 2]) % 3 == 0))
							return A[i + 2];
					}
				}
			}
			return temp;
		}
	}
}


//if the above function doesn't work for any other case apart from spec, then the logic would be to sort and check i-1,i,i+1 elements to find unique element.