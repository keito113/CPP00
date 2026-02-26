#include <iostream>
#include <cctype>

char to_upper_char(char c)
{
	return(std::toupper(c));
}

int main (int ac, char **av)
{
	if(ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return(0);
	}
	for(int i = 1; i < ac; ++i)
	{
		for(int j = 0; av[i][j] != '\0'; ++j)
			std::cout << to_upper_char(av[i][j]);
	}
	std::cout << std::endl;
	return(0);
}
