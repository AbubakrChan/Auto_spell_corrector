#include <iostream>
#include <fstream>
#include <string>
// C++ program to convert whole string to
// uppercase or lowercase using STL.


using namespace std;
int counter = 0;

void alternates(string wrong_word) {
	swap(wrong_word[0], wrong_word[2]);
	cout << wrong_word;
}


void chechk(string word) {
	fstream correct;
	correct.open("correct.txt", ios::app);
	ifstream myfile2;
	string word2;
	string small = "small.txt";
	myfile2.open(small);
	while (myfile2 >> word2)
	{
		if (word == word2)
		{
			if (correct.is_open())
			{
				correct << word<<" ";
				correct.close();
			}		
			counter = 1;

		}
	}
//	cout << counter;
	if (counter == 0)
	{
		cout << "This word is wrong :" << word<<"\n";
	}
	counter = 0;
	myfile2.close();
	correct.close();

}
int main() {
	string word;
	ifstream myfile;
	string message = "message.txt";
	myfile.open(message);
	alternates("1234");
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
