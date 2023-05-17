#include <iostream>
#include<vector>
#include<fstream>
#include <sstream>
using namespace std;


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

string TreeTraversal(Node* letter);

Node* makeTree(vector<Node*> v);

void delete_elements(int a[], int n);

void insert1(int b, int* a, int n);

void selectionsort(int arr[], int n);


void decoder(string &s, vector<string> &v)
{
	ofstream op2;
	op2.open("decoded.txt");
	int i = 1;
	int a = 0;
	while(i<s.size())
	{
		for (int j = 0; j < v.size() ; j++)
		{
			if (s.substr(a, i) == v[j])
			{
				op2 << char(j + 97);
				a = a + i;
				i = 0;
				break;
			}
		}
		i++;
	}

}


int main()
{
	vector<Node*> v1(26, nullptr);
	//v1.reserve(27);

	
	
	ifstream myfile;
	stringstream buffer;

	myfile.open("text1.txt");
	string s;
	buffer << myfile.rdbuf();
	s = buffer.str();
	myfile.close();
	


	 
	for (int i = 0; i < s.size(); i++)
	{

		Node* a = new Node();

		v1[int(s[i])-97] = a;
		v1[int(s[i]) - 97]->c = s[i];

	}


	for (int i = 0; i < s.size(); i++)
	{
		 
		v1[int(s[i])-97]->freq++;
	}



	
	Node* n = new Node();
	vector<string> vct(26, " ");
	n = makeTree(v1);
	//cout << (n->right)->c;
	string st;
	for (auto& i : v1)
	{
		if (i != nullptr)
		{
			st = TreeTraversal(i);

			reverse(st.begin(), st.end());
			vct[int(i->c) - 97] = st;
			cout << st << endl;
		}
	}

	ofstream op1("encoded.txt");
	string s1;	
	for (auto& i : s)
	{
		op1 << vct[int(i) - 97];
		//cout << vct[int(i) - 97];
		s1.append(vct[int(i) - 97]);
	}
	cout << endl;
	//ifstream m;

	
	

	//cout << s1 << endl;

	decoder(s1, vct); 



}


