#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include "funcs.h"
double distance(std::vector<double> a, std::vector<double> b)
{
	double d = 0.0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a.at(i) > b.at(i))
			d += sqrt(pow(a.at(i), 2) - pow(b.at(i), 2));
		else
			d += sqrt(pow(b.at(i), 2) - pow(a.at(i), 2));
	}
	return d / 26.0;
}
std::string decryptCaesar(std::string e, int sh)
{
	std::string r = "";
	int index = -1;
	while (e[++index])
		r += shiftChar(e[index], -sh);
	return r;
}
int main()
{
	std::string text = "", s;
	while (getline(std::cin, s))
		text += s;
	std::vector<double> e = getLetterFreqs(text);
	std::string t = "Spending time at national parks can be an exciting adventure, but this wasn't the type of excitement she was hoping to experience. As she contemplated the situation she found herself in, she knew she'd gotten herself in a little more than she bargained for. It wasn't often that she found herself in a tree staring down at a pack of wolves that were looking to make her their next meal.";
	std::string encryption = encryptCaesar(t, 3);
	double min = 100000000, index;
	for (int i = 0; i < 26; i++)
	{
		std::vector<double> check;
		while (check.size() < 26)
			check.push_back(0.0);
		int letters = 0;
		for (int p = 0; p < encryption.length(); p++)
		{
			if (isalpha(encryption[p]))
			{
				int hold = charIndex(encryption[p]) + i;
				check.at(hold % 26)++;
				letters++;
			}
		}
		for (int p = 0; p < check.size(); p++)
			check.at(p) /= letters;
		double d = distance(check, e);
		std::cout << d << std::endl;
		if (d < min)
		{
			index = i;
			min = d;
		}
	}
	std::cout << index <<  " " << encryptCaesar(t, index) << std::endl;
	return 0;
}
