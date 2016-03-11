#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void reverseWord(const string & sentence)
{
	vector<string> vectorOfWord;
	string word;
	istringstream stringStream(sentence);
	while(getline(stringStream, word, ' '))
	    vectorOfWord.push_back(word);

	while(!vectorOfWord.empty())
	{
		cout<<vectorOfWord.back()<<" " ;
		vectorOfWord.pop_back();
	}
    cout<<endl;
}
int main()
{

    int counter = 0;
	string sentence;
	ifstream streamIn;
	streamIn.open("test.txt");

	int cases;
	streamIn >> cases;


	while(!streamIn.eof())
	{
	    counter++;
        cout <<"Case #" << counter << ": ";
		getline(streamIn,sentence);
        reverseWord(sentence);
	}
	streamIn.close();
	return 0;
}
