#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: _count(0),
	  _next(0)
{
}

void PhoneBook::addContact(const Contact& contact)
{
	_contact[_next] = contact;
	_next = (_next + 1) % 8;
	if(_count < 8)
		_count++;
}

std::string PhoneBook::formatCol(const std::string& str) const
{
	if(str.length() > 10)
		return(str.substr(0, 9) + ".");
	return(str);
}

int PhoneBook::parseIndex(const std::string& input) const
{
	if(input.length() != 1)
		return(-1);
	if(input[0] < '0' || input[0] > '7')
		return(-1);
	return(input[0] - '0');
}

void PhoneBook::displayTable() const
{
	int i;
	i = 0;
	while(i < _count)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formatCol(_contact[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formatCol(_contact[i].getLastName()) << "|";
		std::cout << std::setw(10) << formatCol(_contact[i].getNickName()) << std::endl;
		i++;
	}
}

void PhoneBook::searchContact() const
{
	std::string input;
	int index;

	if(_count == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}
	displayTable();
	std::cout << "Enter index: ";
	if(!std::getline(std::cin, input))
		return;
	index = parseIndex(input);
	if(index < 0 || index >= _count)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	_contact[index].displayFull();
}
