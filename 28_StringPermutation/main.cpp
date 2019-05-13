#include<iostream>
using namespace std;

void StringPermutation(char* string)
{
	if(string == nullptr)return;

}



void Test(char* string)
{
	if(string == nullptr)return;
	else
	{
		StringPermutation(string);
	}
	cout << endl;
}

int main(void)
{
	char string1[] = "";
	Test(string1);


	char string2[] = "a";
	Test(string2);


	char string3[] = "ab";
	Test(string3);


	char string4[] = "abc";
	Test(string4);

	return 0;
}
