#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
}

//Write definition of randData(), showData() and findColSum()
void randData(double *x,int y,int z)
{
	for(int i = 0;i < z;i++)
	{
		for(int j = 0;j < y;j++)
		{
			*x = (rand()%101)/100.00;
			*x++;
		}
	}
}

void showData(double *x,int y,int z)
{
	for(int i = 0;i < y;i++)
	{
		for(int j = 0;j < z;j++)
		{
			cout << *x << " ";
			*x++;
		}
		cout << "\n";
	}
}

void findColSum(double const *dPtr,double *result,int z,int y)
{
	double sum=0;
	for(int i=0;i<49;i++)
	{
		sum += *dPtr ;
		if((i+1)%7 == 0)
		{
			*result = sum;
			result++;
			sum=0;
			dPtr -= 41 ;
		}else {
			dPtr += 7 ;
		}
	}
}
