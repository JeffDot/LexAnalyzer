#include <iostream>

using namespace std;


/*this is a explain*/
int main()
{
	int i = 0;
	float j = 1.2;
	while(i <= 99)
	{
		if(!(i%2))
		{
				cout << "outstring 1" << endl;/*explain*/
		}
		else
		{
				cout << "outstring 2" << endl;/*explain*/
		}
		i += j;
		j ++;
	}
	return 0;
}