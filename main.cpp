/*Programmer : B. Sharmila
Date: 4 Jun 2019
Revision History: 
To do: Trying to get avoided energy crossing from optical+spin tomograms*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <fstream>
#include <armadillo>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
using namespace arma;


/****************Global data structure********************/
/*********************************************************/

/****************Function prototype********************/
int fact(double*,int);
int get_all_comb(long int *result, int N, int r, double *factorial);
/*********************************************************/
int main(void)
{
	double *factorial;
	long int *result;
	int N,r;

	N=32;
	r=16;

	/*Getting fatcorials*/
	factorial=new double [100]();
	assert(factorial);
	int out=fact(factorial,100);

	long int NCr=(long int)((factorial[N]/factorial[N-r])/factorial[r]);
	result=new long int [NCr]();
	assert(result);

	out=get_all_comb(result,N,r,factorial);

	for(int i=0;i<NCr;i++)
	{
		long int temp=result[i];
		for(int j=0;j<N;j++)
		{
			if((temp%2)==1)
			{
				cout<<j<<" ";
			}
			temp=temp/2;
		}
		cout<<"\n";
	}


	assert(factorial);
	delete[] factorial;
	assert(result);
	delete[] result;

	return(0);
}
