#pragma once

#include <deque>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

// TODO:: Consider templatizing class to accept and create a chain of any data type 
// Input could be tokenized with a supllied delimiter ex " " or "," 
// No supplied delimiter would read in one (of data type T) at a time
// ex. one int at a time from a buffer of ints supplied

typedef std::deque<std::string> Prefix;


class MarkovChain
{
public:
	MarkovChain();
	MarkovChain(int prefixSize, int maxNumWordsGen);
	~MarkovChain();

	// Builds the data map of the markov chain from an input source
	void ConstructChain();

	// Generates an output from the constructed data map
	std::string GenerateOutput();

	// Sets the prefix size for Building the chain *Lower value will result in more random outputs, Higher results in more structured/strict.*
	void SetPrefixSize(int prefixSize);

	// Sets the maximum number of words the generator is allowed to create for the output
	void SetMaxNumWordsGen(int maxNumWordsGen);

	const int GetPrefixSize() const;
	const int GetMaxNumWordsGen() const;

protected:
	int prefixSize;
	int maxNumWordsGen;

	Prefix dqPrefix;
	std::map<Prefix, std::vector<std::string>> dataMap;
};

