#include <iostream>
#include <fstream>
#include <map>

using namespace std;
	
char vowels[] = {'a','e','i','o','u','y'};

bool isVowel(char a)
{
	for(int x = 0; x < 6; x++)
		if(a == vowels[x])
			return true;
	return false;
}

int roughSyllableCount(string a)
{
	if(a.size() == 1)
		return 1;

	int vowelCount = isVowel(a[0]);

	for(int x = 1; a[x] != 0; x++)
		if(isVowel(a[x]) && !(isVowel(a[x-1])))
			vowelCount++;

	if(a[a.size()-1] == 'e' && vowelCount > 1)
		vowelCount--;
	
	return vowelCount;
}

int main()
{ 
	string word;
	int sylCount;

	ifstream fin("words.txt");
	ofstream fout("wordSyl.txt");
	if(fin.is_open())
	{
		while(fin>>word)
		{
			word[0] = tolower(word[0]);
			sylCount = roughSyllableCount(word);
			fout<<word<<' '<<sylCount<<'\n';
		}
	}
	fin.close();
	fout.close();


}




