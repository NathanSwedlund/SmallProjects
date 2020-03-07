// Author: Nathan Swedlund
// Date:   07-03-2020

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include "Timer.h"
using namespace std;

struct SizeFunctor {
    bool operator()(const string& first, const string& second)
    {
        return first.size() < second.size();
    }
};

int main()
{
    // Reading in words from the "words.txt" file
	vector<string> allWords;
	cout<<"Reading in words...\n";
	ifstream fin;
	fin.open("words.txt");
	if(fin.is_open()) // If file exists
	{
        // Store all words from in "allWords"
		string word;
		while(fin>>word)
		{
            // Making sure the first character is lower case
			word[0] = tolower(word[0]);
			allWords.push_back(word);
		}
        cout<<"Done.\n";
	}
    else // If file does not exist
    {
        cout<<"\"words.txt\" not found.";
        return 0;
    }

	// Putting input characters into a set
	string input;
    cout<<"-----------------------------------\n";
    cout<<"Enter characters: ";
	cin>>input;

    // Starting timer
	Timer t;
	t.start();

    // Inserting input characters into set
	multiset<char> chars;
	for (int i = 0; i < input.size(); i++)
		chars.insert(input[i]);

	// Putting all words that can be created from input's characters into subWords
    vector<string> subWords;
	for (int i = 0; i < allWords.size(); i++)
	{
		multiset<char> tempChars = chars;
		bool isSub = true;
		for(int x = 0; x < allWords[i].size() && isSub; x++)
		{
			auto itr = tempChars.find(allWords[i][x]);

            // If set contains the character, remove it (to avoid duplicates), else, it is not a subword.
			if(itr != tempChars.end())
                tempChars.erase(itr);
			else
                isSub = false;
		}

        // Only getting subwords with a length of 3+
		if(isSub && allWords[i].size() > 2)
			subWords.push_back(allWords[i]);
	}

    // Sorting alphabetically, then by size (using size functor)
	sort(subWords.begin(), subWords.end());

    SizeFunctor s;
	sort(subWords.begin(), subWords.end(), s);

    // Printing subwords in segments of size
    int size = -1;
	for (int i = 0; i < subWords.size(); ++i)
	{
        if(size != subWords[i].size())
        {
            size = subWords[i].size();
            cout<<"\n"<<size<<" letter words: \n";

        }
		cout<<subWords[i]<<"\n";
	}

    // Final output
    cout<<"Found "<<subWords.size()<<" Words in "<<t.getTime()<<" seconds\n";
    cout<<"-----------------------------------";
}
