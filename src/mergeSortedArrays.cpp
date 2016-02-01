/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction
{
	int amount;
	char date[11];
	char description[20];
};

int datecheck(char *date1, char *date2)
{
	long int dt1, dt2;
	dt1 = (date1[0] - '0') + 10 * (date1[1] - '0') + 100 * (date1[3] - '0') + 1000 * (date1[4] - '0') + 10000 * (date1[6] - '0') + 100000 * (date1[7] - '0') + 1000000 * (date1[8] - '0') + 10000000 * (date1[9] - '0');
	dt2 = (date2[0] - '0') + 10 * (date2[1] - '0') + 100 * (date2[3] - '0') + 1000 * (date2[4] - '0') + 10000 * (date2[6] - '0') + 100000 * (date2[7] - '0') + 1000000 * (date2[8] - '0') + 10000000 * (date2[9] - '0');
	if (dt1 == dt2)
		return 0;
	else if (dt1 > dt2)
		return 1;
	else
		return 2;
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	struct transaction *result;
	int iter1 = 0, iter2 = 0, grt, count = 0;
	if (A == NULL || B == NULL)
		return NULL;
	result = (struct transaction *)malloc((ALen + BLen)*(sizeof(struct transaction)));
	while (iter1 < ALen || iter2 < BLen)
	{
		grt = datecheck(A[iter1].date, B[iter2].date);
		if (grt == 0)
		{
			result[count] = A[iter1];
			count++;
			iter1++;
			result[count] = B[iter2];
			count++;
			iter2++;
			if (iter2 >= BLen)
				goto execute1;
			if (iter1 >= ALen)
				goto execute2;

		}
		else if (grt == 1)
		{
			result[count] = B[iter2];
			count++;
			iter2++;
			if (iter2 >= BLen)
				goto execute1;
		}
		else
		{
			result[count] = A[iter1];
			count++;
			iter1++;
			if (iter1 >= ALen)
				goto execute2;
		}
	}
execute1:
	for (; iter1 < ALen; iter1++)
	{
		result[count] = A[iter1];
		count++;
	}
	return result;
execute2:
	for (; iter2 < BLen; iter2++)
	{
		result[count] = B[iter2];
		count++;
	}
	return result;
}

