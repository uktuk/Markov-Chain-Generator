#include "MarkovChain.h"
#include <assert.h>


MarkovChain::MarkovChain()
	: prefixSize(2)
	, maxNumWordsGen(100)
{
}

MarkovChain::MarkovChain(int InPrefixSize, int InMaxNumWordsGen)
{
	assert((InPrefixSize > 0) && (InMaxNumWordsGen > 0));
	prefixSize = InPrefixSize;
	maxNumWordsGen = InMaxNumWordsGen;
}

MarkovChain::~MarkovChain()
{
}

void MarkovChain::ConstructChain()
{
	dqPrefix.clear();

	// Initialize the Prefix
	for (int i = 0; i < prefixSize; ++i)
	{
		dqPrefix.push_back("");
	}

	// TODO:: abstract this input text to a templatized input
	std::string wordBuf;
	std::ifstream inFile;
	inFile.open("example.txt");

	if (inFile)
	{
		while (inFile >> wordBuf)
		{
			std::vector<std::string> tempBuf;

			auto iter = dataMap.find(dqPrefix);
			if (iter != dataMap.end())
			{
				// See if the Prefix has already been mapped, get its suffix if so
				tempBuf = iter->second;
			}
			// Append the wordBuf to the suffix
			tempBuf.push_back(wordBuf);

			// Map current state of Prefix along with the suffix
			dataMap.insert_or_assign(dqPrefix, tempBuf);

			// Update the Prefix
			dqPrefix.push_back(wordBuf);
			dqPrefix.pop_front();
		}
	}
}

std::string MarkovChain::GenerateOutput()
{
	dqPrefix.clear();

	// Initialize the Prefix
	for (int i = 0; i < prefixSize; ++i)
	{
		dqPrefix.push_back("");
	}

	srand(time(NULL));
	std::vector<std::string> tempBuf;
	std::string totalOutput = "";

	int randWord = 0;
	int numWordsGenerated = 0;

	while (numWordsGenerated <= maxNumWordsGen)
	{
		auto iter = dataMap.find(dqPrefix);
		if (iter != dataMap.end())
		{
			randWord = rand() % iter->second.size();
			totalOutput += iter->second[randWord] + " ";

			// Udate Prefix
			dqPrefix.push_back(iter->second[randWord]);
			dqPrefix.pop_front();
			++numWordsGenerated;
		}
		else
		{
			break;
		}
	}
	return totalOutput;
}

const int MarkovChain::GetPrefixSize() const
{
	return prefixSize;
}

const int MarkovChain::GetMaxNumWordsGen() const
{
	return maxNumWordsGen;
}

void MarkovChain::SetPrefixSize(int InPrefixSize)
{
	assert(prefixSize > 0);
	prefixSize = InPrefixSize;
}

void MarkovChain::SetMaxNumWordsGen(int InMaxNumWordsGen)
{
	assert(maxNumWordsGen > 0);
	maxNumWordsGen = InMaxNumWordsGen;
}