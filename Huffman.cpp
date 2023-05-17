#include <iostream>
#include <vector>
#include<map>
using namespace std;

// given the frequencies of characters, create a huffman encoding tree and then print out the codes assigned to each character

struct Node
{
	char c;
	int freq;
	//Node* parent;
	Node* left;
	Node* right;
	Node* parent;

	Node()
	{
		c = ' ';
		freq = 0;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		
	}

};

void selectionsort(int arr[],int n);

void insert1(int b, int* a, int n)
{
	a[n - 2] = b;
	selectionsort(a,n-1);
}
void delete_elements(int a[], int n)
{
	
		for (int i = 0; i < n-2; i++)
		{
			a[i] = a[i + 2];

		}
	
	a[n - 1] = 0;
	a[n - 2] = 0;
} 

multimap<int,Node*> map1;

//multimap<int, Node*>::iterator it;


Node* makeTree(vector<Node*> v)
{

	//map<int, Node*> map1;


	vector<int> arr;
	for (auto& i : v)
	{
		if (i != nullptr)
		{
			arr.push_back(i->freq);
			map1.insert({ i->freq, i });
		}
		
	}

	int* a = &arr[0];

	selectionsort(a, arr.size());

	int i = arr.size();
	

	while (i > 0)
	{
		Node* z = new Node();
		//z->c = 'z';

		int z_freq = a[0] + a[1];
		z->c = ' ';
		z->freq = z_freq;
		
		(z->left) = map1.find(a[0])->second;
		(map1.find(a[0])->second)->parent = z;

		map1.erase(map1.find(a[0]));

		(z->right) = map1.find(a[1])->second; 
		(map1.find(a[1])->second)->parent = z;
		map1.erase(map1.find(a[1]));
		
		
		delete_elements(a, i);


		insert1(z_freq, a, i);
		map1.insert({ z_freq, z });
		
		i--;
		//cout << z->c;
		if (i == 1)
		{
			return z;
		}

	}

}



string TreeTraversal(Node* letter)
{
	string str;
	cout << letter->c << " : ";
	while (letter->parent != nullptr)
	{
		if ((letter->parent)->left == letter)
		{
			str.append("0");
			letter = letter->parent;
		}

		else
		{
			str.append("1");
			letter = letter->parent;
		}

	}
	return str;
	
}


