#include <iostream>

using namespace std;

int swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int count = 0;
	float ftest = 1.56789;
	string str_test = "bilibilibi~~~~~~!";
	while(count <= 9999)
	{
		if(count % 2)
		{
			count += 3;
		}
		else
		{
			count += 2;
		}
		if(ftest != 0)
		{
			fteset *= 10;
		}
		else if(ftest >= 156789)
		{
			break;
		}
		else
		{
			cout << str_test << endl;
			cout << "end test \n";
		}
	}
	return 0;
}