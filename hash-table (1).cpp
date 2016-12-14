// hash-table.cpp: определяет точку входа для консольного приложения.
//

#include<iostream>
#include<vector>
#include<string>

using namespace std;


struct node
{
	double number;
	string key;
	node(double num, string k)
	{
		number = num;
		key = k;
	}
};

const int multiplier = 256;
vector<node*> table;

void init_table(vector<node*>& table)
{
	int size;
	cin >> size;
	table.resize(size, NULL);
}

int hash_function(string str)
{
	int res = 0;
	int temp = res;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		res = (temp * multiplier + (int)str[i]) % table.size();
		temp = res;
	}
	return res;
}

int additional_hash_function(string str, int index)
{
	int temp_index = index;
	int sum = 0;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		sum += (int)(str[i]);
	}
	int res_1 = (sum % (table.size() - 1)) + 1;
	const int res_2 = res_1;
	while (table[res_1] != NULL && table[index]->key != "DEL")
	{
		res_1 = (temp_index + res_2) % table.size();
		temp_index = res_1;
	}
	return res_1;
}

void add(string key, double value)
{
	int index = hash_function(key);
	if (table[index] == NULL || table[index]->key == "DEL")
	{
		table[index] = new node(value, key);
	}
	else
	{
		int res = additional_hash_function(key, index);
		table[res] = new node(value, key);
	}
}

bool find(string key)
{
	int index = hash_function(key);
	if (table[index] != NULL && table[index]->key != "DEL")
	{
		return true;
	}
	return false;
}

void remove(string key)
{
	if (find(key))
	{
		int index = hash_function(key);
		table[index]->key = "DEL";
	}
	return;
}

int main()
{

	setlocale(LC_CTYPE, "rus");
	init_table(table);
	string key;
	int value;
	string command;
	while (cin >> command)
	{
		if (command == "add")
		{
			cin >> key >> value;
			add(key, value);
		}
		else if (command == "find")
		{
			cin >> key;
			if (find(key))
				cout << "YES";
			else
				cout << "NO";
		}
		else if (command == "remove")
		{
			cin >> key;
			remove(key);
		}
	}
	system("pause");
	return 0;
}
