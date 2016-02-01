/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction
{
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int iter1, iter2;
	for (iter1 = 0; iter1 < len; iter1++)									//iterating to check dates of each transaction
	{
		for (iter2 = 0; iter2 < 10; iter2++)								//iterating to check each digit of the date
		{
			if (Arr[iter1].date[iter2] == date[iter2])
			{
				if (date[iter2 + 1] == '\0')								//cond for all digits to match with the given date
				{
					for (iter1; iter1 < len; iter1++)		//after matching, iterating to check if there are any transactions with same date
					{
						for (iter2 = 0; iter2 < 11; iter2++)
						{
							if (Arr[iter1].date[iter2] != date[iter2])  //if the above condition fails returning length
								return len - iter1;
						}
					}
				}

			}
			else
				break;
		}
	}
	return 0;
}

/*

int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int iter1, iter2, iter3, found;
	for (iter1 = 0; iter1 < len; iter1++)
	{
		found = 1;
		for (iter2 = 0; iter2 < 11; iter2++)
		{
			if (Arr[iter1].date[iter2] != date[iter2])
			{
				found = 0;		break;
			}
		}

		if (found == 1)
		{
			for (iter3 = iter1; iter3 < len; iter3++)
			{
				for (iter2 = 0; iter2 < 11; iter2++)
				{
					if (Arr[iter3].date[iter2] != date[iter2])
						return len - iter3;
				}
			}
		}
	}
	return 0;
}

*/