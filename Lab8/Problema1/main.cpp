#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <string>
using namespace std;

class Compare
{
public:
	bool operator()(pair<string, int> p1, pair<string, int> p2)
	{
		if (p1.second < p2.second)
			return true;
		if (p1.second > p2.second)
			return false;
		if (p1.first > p2.first)
			return true;
		return false;
	}
};

int main()
{
	string phrase;
	ifstream myFile("input.txt");
	if (!myFile)
	{
		cout << "Eroare la deschiderea fisierului \"input.txt\".\n";
		return 1;
	}
	if (!getline(myFile, phrase))
	{
		cout << "Eroare la functia getline.\n";
		return 1;
	}

	map<string, int> freq;
	while (true)
	{
		const size_t found = phrase.find_first_of(" ,.?!");
		if (found == -1) break;

		string word = phrase.substr(0, found);
		transform(word.begin(), word.end(), word.begin(), tolower);
		phrase.erase(phrase.begin(), phrase.begin() + found + 1);

		if (!word.empty()) {
			cout << "Added the word \"" << word << "\" to the map\n";
			freq[word]++;
		}
	}

	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pqueue;
	for (const auto& i : freq)
	{
		pqueue.emplace(i);
	}

	cout << "\nThe words frequency sorted lexycographic are: \n";
	while (!pqueue.empty())
	{
		cout << pqueue.top().second << " => " << pqueue.top().first << '\n';
		pqueue.pop();
	}
	return 0;
}