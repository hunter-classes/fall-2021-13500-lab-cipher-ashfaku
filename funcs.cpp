#include <iostream>
#include "funcs.h"
#include <vector>
int charIndex(char o)
{
        int ascii = (int) o - (isupper(o) ? (int) 'A' : (int) 'a');
        return ascii % 26;
}
char shiftChar(char o, int sh)
{
        if (!isalpha(o) || sh == 0)
                return o;
        int index;
        if (sh > 0)
        {
                int a = isupper(o) ? (int) 'A' : (int) 'a';
                index = (((int) o + sh - a) % 26) + a;
        }
        else
        {
                int z = isupper(o) ? (int) 'Z' : (int) 'z';
                index = (((int) o + sh - z) % 26) + z;
        }
        return (char) index;
}
std::string encryptCaesar(std::string o, int shift)
{
	std::string s = "";
	int index = -1;
	while (o[++index])
		s += shiftChar(o[index], shift);
	return s;
}
std::vector<double> getLetterFreqs(std::string input)
{
	std::vector<double> ints;
	int letters = 0;
	while (ints.size() < 26)
		ints.push_back(0.0);
	for (int i = 0; i < input.length(); i++)
	{
		if (isalpha(input[i]))
		{
			ints.at(charIndex(input[i]))++;
			letters++;
		}
	}
	for (int j = 0; j < ints.size(); j++)
		ints.at(j) /= letters;
	return ints;
}
