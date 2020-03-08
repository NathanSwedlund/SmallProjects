#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;

// Returns ture/false if the two given strings are anagrams
bool isAnagram(string a, string b)
{
	// Sorting both string and checking if both are the same
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}

// Inserts all the individual words from the file into the given vector
void getFileContents(vector<string>& v, string fileName)
{
	ifstream fin;
	fin.open(fileName.c_str()); // Opening file

	// Getting contents if file exists
	if(fin.is_open())
	{
		string word;
		while(fin>>word)
		{
			// Lower-casing uppercase first characters
			if(word[0] >= 65 && word[0] <= 90)
				word[0] += 32;
			v.push_back(word);
		}
		fin.close();
	}
}

int main() 
{
	// Retrieving contents of file
	vector<string> fileWords(1000);
	getFileContents(fileWords, "words.txt");

	// Getting input
	string word;
	cout<<"Enter word: ";
	cin>>word;

	// Checking if "word" is a word
	if(find(fileWords.begin(), fileWords.end(), word) != fileWords.end())
		cout<<'\n'<<word<<" is a word\n";
	else
		cout<<'\n'<<word<<" is not a word:\n";

	// Finding anagrams
	vector<string> anagrams;
	for(auto i = fileWords.begin(); i != fileWords.end(); i++)
		if(isAnagram(*i, word) && *i != word)
			anagrams.push_back(*i);

	// finding words that contain "word"
	vector<string> containsWord;
	for(auto i = fileWords.begin(); i != fileWords.end(); i++)
	{
		string a = *i;
		if(a.find(word) != std::string::npos && a != word)
			containsWord.push_back(a);
	}

	// Outputting anagrams if any exist
	if(anagrams.size() != 0)
	{
		cout<<'\n'<<word<<" is an anagram of the following:\n";
		for(int i = 0; i != anagrams.size(); i++)
			cout<<setw(2)<<i+1<<") "<<anagrams[i]<<'\n';
	}	
	else
		cout<<'\n'<<word<<" has no anagrams.\n";

	// Outputting words that contain "word"
	if(containsWord.size() != 0)
	{
		cout<<'\n'<<word<<" is contained in the following:\n";
		for(int i = 0; i != containsWord.size(); i++)
			cout<<setw(3)<<i+1<<") "<<containsWord[i]<<'\n';
	}
	else
		cout<<'\n'<<"No words contain "<<word<<'\n';
}
