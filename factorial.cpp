/*Programmer : B. Sharmila
Date: 2 Mar 2016
Revision History: 
To do: Trying to get factorials from 0! to max! and store in array*//*Alert!! Function name: fact*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <fstream>
#include <armadillo>
#include <time.h>
#include <stdlib.h>
using namespace std;
using namespace arma;

int fact(double *array, int max)
{
	int z;
	array[0]=1.;
	for(z=1;z<max;z++)
	{
		array[z]=array[z-1]*z;
	}
	return(0);
}
