#include"Huffman.h"
void Huffman::clear(node*x)
{
	if (x != NULL)
	{
		if (x->left != NULL)
		{
			clear(x->left);
		}
		if (x->right != NULL)
		{
			clear(x->right);
		}
		delete x;
	}
}
bool Huffman::createTree(string filename)
{
	clear(root);
	root = NULL;
	ifstream infile;
	infile.open(filename);
	char q;
	string line;
	line = "";
	while (infile.get(q))
	{
		int check = 0;
		check = 0;
		for (int i = 0; i < list1.size(); i++)
		{
			if (list1[i]->char1 == q)
			{
				check++;
				list1[i]->freq++;
			}
		}
		if (check == 0)
		{
			node*x = new node;
			x->char1 = q;
			x->freq = 1;
			list1.push_back(x);
		}
	}
	/*while (getline(infile, line))
	{
		q += line;
	}
	cout << q.size() << endl;
	char y;
	int count = 0;
	int check = 0;
	for (int i = 0; i < q.size(); i++)
	{
	
		y = q[i];
		for (int x = i; x > 0; x--)
		{
			if (y == q[x-1])
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
			node*x = new node;
			x->char1 = y;
			x->freq = count;
			list1.push_back(x);
		}
		count = 0;
		check = 0;
		cout << y << endl;
	}*/
	sort(list1.begin(), list1.end(), sorter);
	while (list1.size() > 1)
	{
		node*left = list1[0];
		node*right = list1[1];
		list1.erase(list1.begin(), list1.begin() + 2);
		double sum = left->freq + right->freq;
		node* x = new node;
		x->freq = sum;
		x->left = left;
		x->right = right;
		list1.push_back(x);
		sort(list1.begin(), list1.end(), sorter);
	}
	root = list1[0];
	list1.clear();
	tree* x = new tree(root);
	head = x;
	name = "";
	return true;
}
string Huffman::decodeMessage(string toDecode)
{
	string result;
	node* cur = root;
	for (int i = 0; i < toDecode.size(); i++)
	{
		if (toDecode[i] == '1')
		{
			cur = cur->right;
		}
		else
		{
			cur = cur->left;
		}
		if (cur->right == NULL&&cur->left == NULL)
		{
			result += cur->char1;
			cur = root;
		}
	}
	return result;
}
map<char, string> Huffman::getEncodings()
{
	list.clear();
	string mess;
	code(mess, root);
	return list;
}
string Huffman::encodeMessage(string toEncode)//fix this part;
{
	string x;
	string u;
	map<char, string>o = getEncodings();
	for (int i = 0; i < toEncode.size(); i++)
	{
		char y = toEncode[i];
		x = o[y];
		u += x;
	}
	return u;
}
void Huffman::code(string mess,node*x)
{
	char data = x->char1;
	if (data != 0)
	{
		list[data] = mess;
	}
	else
	{
		code(mess + "0", x->left);
		code(mess + "1", x->right);
	}
}
TreeInterface* Huffman::getTree()
{
	return head;
}

