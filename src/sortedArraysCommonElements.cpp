/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

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


struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	struct transaction *result;
	int iter1 = 0, iter2 = 0, iter3 = 0, found = 1, count = 0;
	if (A == NULL || B == NULL)
		return NULL;
	result = (struct transaction*)malloc(ALen*(sizeof(struct transaction)));
	while (iter1 < ALen && iter2 < BLen)
	{
		while (iter2 < BLen)
		{
			found = 1;
			for (iter3 = 0; iter3 < 11; iter3++)
			{
				if (A[iter1].date[iter3] != B[iter2].date[iter3])
				{
					found = 0;		break;
				}
			}
			if (found == 1)
			{
				result[count] = B[iter2];
				count += 1;
			}
			else
				break;
			iter2++;

		}
		iter1++;
	}
	if (count == 0)
		return NULL;
	else
		return result;
}


/*

struct transaction *result;
int iter1 = 0, iter2 = 0, iter3 = 0, found = 1, count = 0;
if (A == NULL || B == NULL)
return NULL;
result = (struct transaction*)malloc(ALen*(sizeof(struct transaction)));
while (iter1 < ALen || iter2 < BLen)
{
	while (iter2 < BLen)
	{
		found = 1;
		for (iter3 = 0; iter3 < 11; iter3++)
		{
			if (A[iter1].date[iter3] != B[iter2].date[iter3])
			{
				found = 0;		break;
			}
		}
		if (found == 1)
		{
			result[count] = B[iter2];
			count += 1;

		}
		else
			break;
		iter2++;
	}
	iter1++;
}
if (count == 0)
return NULL;
else
return result;

*/