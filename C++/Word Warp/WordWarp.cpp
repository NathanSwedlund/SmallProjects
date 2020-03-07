#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include "Timer.h"
using namespace std;

struct size {
    bool operator()(const string& first, const string& second) 
    {
        return first.size() < second.size();
    }
};

int main()
{ 
	vector<string> allWords;
	cout<<"getting allWords...\n";
	ifstream fin;
	fin.open("words.txt");
	if(fin.is_open())
	{
		string a;
		while(fin>>a)
		{
			a[0] = tolower(a[0]);
			allWords.push_back(a);
			//allWords.push_back(a+'s');
		}
	}

	// Putting input characters into a set
	string input;
	cout<<"Done.\n\nEnter word/characters: ";
	cin>>input;

	Timer t;
	t.start();

	multiset<char> chars;
	for (int i = 0; i < input.size(); i++)
		chars.insert(input[i]);

	vector<string> subWords;
	// checking allWords that match
	for (int i = 0; i < allWords.size(); i++)
	{
		multiset<char> tempChars = chars;
		bool isSub = true;
		for(int x = 0; x < allWords[i].size() && isSub; x++)
		{
			auto itr = tempChars.find(allWords[i][x]);
			if(itr == tempChars.end())
				isSub = false;
			else
				tempChars.erase(itr);
		}

		if(isSub && allWords[i].size() > 2)
			subWords.push_back(allWords[i]);
	}


	size s;
	sort(subWords.begin(), subWords.end());
	sort(subWords.begin(), subWords.end(), s);

	for (int i = 0; i < subWords.size(); ++i)
	{
		cout<<subWords[i]<<"\n";
	}



	cout<<"program completed in "<<t.getTime()<<" seconds\n";
	cin.ignore();
	cin.get();
}




