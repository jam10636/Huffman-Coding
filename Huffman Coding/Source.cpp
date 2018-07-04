#include<map>
#include<iostream>
#include<string>
#include<map>
#include<fstream>
using namespace std;
void readmessage()
{
	ifstream infile;
	string filename;
	cout << "please enter file name";
	cin >> filename;
	infile.open(filename);
	string q;
	getline(infile, q);
	cout << q.size() << endl;
	map<char, int>list;
	char y;
	int count = 0;
	int check = 0;
	for (int i = 0; i < q.size(); i++)
	{
		y = q[i];
		for (int x = i - 1; x > 0; x--)
		{
			if (y == q[x])
			{
				check++;
			}
		}
		if (check == 0)
		{
			for (int i = 0; i < q.size(); i++)
			{
				if (q[i] == y)
				{
					count++;
				}
			}
			list[y] = count;
		}
		count = 0;
		check = 0;
	}
}
int main()
{
	system("pause");
	return 0;
}