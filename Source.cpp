#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
// C++ program to convert whole string to
// uppercase or lowercase using STL.
using namespace std;

string lower_string(string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	}
	return str;
}
void insertmessage(string message) {
	fstream myfile;
	myfile.open("message.txt", ios::out); // will write our input message in message.txt
	myfile << message;
	myfile.close();
}
void returncorrect(string word1) {
	int counter = 0;
	string word2;
	ifstream myfile2;
	string filename2 = "small.txt";
	myfile2.open(filename2.c_str());
	while (myfile2 >> word2)
	{
		if (word1 == word2)
		{
			counter = 1;
		}
	}
	if (counter == 1)
	{
		cout << word1<<"\n";
		counter = 0;
	}
	myfile2.close();
	
}
void permute(string a, int l)
{
	int r = a.size() - 1;
	// Base case
	if (l == r)
		returncorrect(a);
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(a[l], a[i]);
			permute(a, l + 1);
			swap(a[l], a[i]);
		}
	}
}
void check() {
	string word1;
	fstream myfile1;
	string filename1 = "message.txt";
	myfile1.open(filename1.c_str());
	while (myfile1 >> word1)
	{
		int counter = 0;
		string word2;
		ifstream myfile2;
		string filename2 = "small.txt";
		myfile2.open(filename2.c_str());
		while (myfile2 >> word2)
		{
			
	
			if (lower_string(word1)== word2)
			{
				counter = 1;
			}
		}
		myfile2.close();
		if (counter == 0)
		{
			cout << "This word is wrong:" << word1 << "\n";
			cout << "It's possible correct combinations are :";
			permute(word1, 0);
			cout << "Now type one word correctly: \n";
			string correctword;
			cin >> correctword;
			ofstream myfile3("correct.txt", std::ios_base::app);
			myfile3 << correctword << " ";
			myfile3.close();


		}
		else
		{
			ofstream myfile3("correct.txt",std::ios_base::app);
			myfile3 << word1<<" ";
			myfile3.close();
			
			

		}
	}
}
void clear_correct_file() {
	ofstream file("correct.txt"); // Without append
}

int main() {
	check();
	//clear_correct_file();
	//insertmessage("good baaad");
	//	while (myfile >> word)
		//{
			//chechk(word);
		//}
		//myfile.close();
		/*while (getline(myfile2, word2))
		{
		//	cout << word2;
			while (getline(myfile, word))
			{
				cout << word2 << "\n";
				cout << word << "\n";
				if (word == word2)
				{
					//cout << word;
				//	cout << word2;
				//	cout << "g";
					cout << word <<"  "<<word2;
					counter++;
				}
			}
			if (counter == 0)
			{
				cout << "This word spelling are wrong:" << word2<<"\n";
			}
			counter = 0;
		}
		myfile.close();
		myfile2.close();
	/*	if (myfile.is_open())
		{
			myfile << "we are good real";
			myfile.close();
		}

		myfile.open("fkassembly.txt", ios::app);
		if (myfile.is_open())
		{
			myfile << "we are good realt";
			myfile.close();
		}*/
}