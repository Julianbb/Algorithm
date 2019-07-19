#include <iostream>
#include <math.h>
using namespace std;
#define g_maxValue 6

void Probability(int original, int current, int sum, int* pProbabilities)
{
    if(current == 1)
	pProbabilities[sum-original]++;
    else
    {
	for(int i =1; i<=g_maxValue; i++)
	{
	    Probability(original, current-1, i+sum, pProbabilities);
	}
    }
}

void Probability(int number, int* pProbabilities)
{
    for(int i=1; i<=g_maxValue; i++)
    {
	Probability(number, number, i, pProbabilities);
    }
}


void PrintProbability_Solution1(int number)
{
    if(number <= 0) return;
    int maxSum = number*g_maxValue;
    int* pProbabilities = new int[maxSum-number+1];
    for(int i=number; i<=maxSum; ++i)
	pProbabilities[i-number] = 0;

    Probability(number, pProbabilities);
    // int total = pow((double)g_maxValue, number);
    // for(int i=number; i<=maxSum; i++)
    // {
    //     double ratio = (double)pProbabilities[i-number] /total;
    // }
    for(int i=0; i<maxSum-number+1; i++)
	cout << pProbabilities[i] << " ";
    delete [] pProbabilities;
    

}


void PrintProbability_Solution2(int number)
{
    if(number <=0)return;
    int* pProbabilities;
    int maxSum = number*g_maxValue;
    int minSum = number;

    int lengthArray = maxSum+1;
    pProbabilities = new int [lengthArray];

    for(int i=0; i<lengthArray; i++)
    {
	pProbabilities[i] = 0;
    }


    for(int i=1; i<=number; i++)
    {
	for(int j=1; j<=g_maxValue; j++)
	{
	    for(int k=i+j-1; k<=(i-1)*g_maxValue+j; k++)
	    {
		pProbabilities[k]++;
	    }
	}
    }
    
    for(int i=minSum; i<=maxSum; i++)
    {
	cout << pProbabilities[i] << " ";
    }
    delete[] pProbabilities;
    
}


// ====================测试代码====================
void Test(int n)
{

    cout << "Test for " << n << endl;

    cout << "Solution1" << " ";
    PrintProbability_Solution1(n);

    cout << endl;

    cout << "Solution2" << " ";
    PrintProbability_Solution2(n);

    cout << endl;
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(4);

    Test(11);

    Test(0);

    return 0;
}

