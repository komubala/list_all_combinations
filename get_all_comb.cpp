/*Programmer : B. Sharmila
Date: 20 Nov 2018
Revision History: 
To do: Trying to get all combinations of indices where x1,x2,...xr is denoted by 2^{x1}+2^{x2}+....+2^{xr}*/

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
int get_all_comb(long int *result, int N, int r, double *factorial)
{
	int retval=0;
	if(r>N || r<0 || N<0)
	{
		cout<<"Error in input params\t"<<N<<"\t"<<r<<"\n";
		retval++;
	}

	long int *combinator=new long int [r]();
	assert(combinator);
	for(int i=0;i<r;i++)
	{
		combinator[i]=(long int) ((factorial[N-r+i+1]/factorial[N-r])/factorial[i+1]);
	}
	int *workspace=new int [combinator[r-1]]();
	assert(workspace);
	int *dup_workspace=new int [combinator[r-1]]();
	assert(dup_workspace);
	int flag=0;
	long int *pre_result=new long int [combinator[r-1]]();
	assert(pre_result);
	for(int i=0;i<r;i++)
	{
		if(flag==0)
		{
			for(int j=0;j<=(N-r);j++)
			{
				workspace[j]=j;
				dup_workspace[j]=j;
				pre_result[j]=(long int) pow(2,j);
				result[j]=(long int) pow(2,j);
			}
			flag++;
		}
		else
		{
			int count=0;
			for(int k=0;k<combinator[i-1];k++)
			{
				for(int j=dup_workspace[k]+1;j<=(N-r+i);j++)
				{
					workspace[count]=j;
					result[count]=pre_result[k]+((long int) pow(2,j));
					count++;
				}
			}
			for(count=0;count<combinator[i];count++)
			{
				dup_workspace[count]=workspace[count];
				pre_result[count]=result[count];
			}
		}
	}

	assert(pre_result);
	delete[] pre_result;
	assert(combinator);
	delete[] combinator;
	assert(dup_workspace);
	delete[] dup_workspace;
	assert(workspace);
	delete[] workspace;

	return(retval);
}
