#include <iostream>
#include <fstream>
#include <queue>
#include <map>

#include "Timer.h"

using namespace std;
	
void reset(int& count, queue<string>& q)
{
	count = 0;
	while(!q.empty())
		q.pop(); 
}

string toString(queue<string> q)
{
	string ret = q.front();
	q.pop();
	while(!q.empty())
	{
		ret += " "+q.front();
		q.pop();
	}
	return ret;
}

void removeWord(int& sylCount, queue<string>& q, map<string, int> m)
{
	sylCount -= m.find(q.front())->second;
	q.pop();
}

int main()
{ 
	int haikuCount = 0;
	cout<<"mapping syllables...\n\n";
	// Mapping words and corresponding syllables
	map<string, int> wordSyl;
	ifstream fin("wordSyl.txt");
	if(fin.is_open())
	{
		int sylCount;	
		string word;
		while(fin>>word>>sylCount) 
			wordSyl[word] = sylCount;
	}
	fin.close();

	cout<<"Mapping complete. Seaching for haiku...\n\n";

	Timer timer;
	timer.start();

	// Input
	fin.open("big2.txt");
	if(fin.is_open())
	{
		queue<string> lastWords;
		string word;
		int sylCount = 0;
		char punc[] = {'.',',','?','-','!',';',':','\"','\'',};
		while(fin>>word)
		{
			// Sanitizing word
			word[0] = tolower(word[0]);

			for (int i = 0; i < 9; ++i)
				if(*(word.begin()-1) == punc[i])
					word.erase(word.begin()-1);

			while(sylCount >= 17)
				removeWord(sylCount, lastWords, wordSyl);

			// If word has a mapped syllable count add the count to the runnning total
			if(wordSyl.find(word) != wordSyl.end())
			{
				sylCount += wordSyl.find(word)->second;
				lastWords.push(word);
			}
			else // else reset
				reset(sylCount, lastWords);

			// If a string of words have a combined syllable count of 17
			if(sylCount == 17)
			{
				// Checking syllables don't stretch across single words
				int tempCount = 0;
				bool firstFive, seven, lastFive, fail;
				firstFive = seven = lastFive = fail = false;

				queue<string> first;
				queue<string> second;
				queue<string> third;

				for(int i = 0; i < lastWords.size(); i++)
				{
					// Subtracting count
					lastWords.push(lastWords.front());
					tempCount += wordSyl.find(lastWords.front())->second;

					if(!firstFive)
						first.push(lastWords.front());
					else if(!seven)
						second.push(lastWords.front());
					else
						third.push(lastWords.front());

					if(!firstFive && tempCount == 5)
						firstFive = true;
					else if(firstFive && !seven && tempCount == 12)
						seven = true;
					else if(tempCount == 17)
						lastFive = true;

					lastWords.pop();
				}


				// Print if no paragraphs stretch across multiple words
				if(firstFive && seven && lastFive)
				{
					// haikuCount++;
					// for(int i = 0; i < lastWords.size(); i++)
					// {
					// 	lastWords.push(lastWords.front());
					// 	cout<<lastWords.front()<<wordSyl.find(lastWords.front())->second<<' ';
					// 	lastWords.pop();
					// }
					cout<<"Haiku #"<<++haikuCount<<'\n';
					cout<<"5:"<<toString(first)<<",\n";
					cout<<"7:"<<toString(second)<<",\n";
					cout<<"5:"<<toString(third)<<".\n\n";

					removeWord(sylCount, lastWords, wordSyl);
				}
			}
		}
	}
	cout<<"\nDone.\nFound "<<haikuCount<<" haiku in "<<timer.getTime()<<" seconds.";
	cin.ignore();
	cin.get();
}




