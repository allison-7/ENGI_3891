#include "average.h"

/*
 * Calculate the average of all values in an array.
 *
 * @param   data     the values to average
 * @param   length   the length of the array in `data`
 *
 * @return  the average value, or 0 if the array is empty
 */
double average(const double data[], int length)
{
	double sum =0;
	for (int i=0;i<length;i++)
	{
		sum+=data[i];
	}
	if (sum==0)
		return 0;
	else
		return sum/length;
}
