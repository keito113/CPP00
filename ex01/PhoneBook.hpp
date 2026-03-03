#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"


class PhoneBook
{
private:
	Contact _contact[8];
	int _count;
	int _next;
	std::string formatCol(const std::string& str) const;
	int parseIndex(const std::string& input) const;

public:
	PhoneBook();

	void addContact(const Contact& contact);
	void displayTable() const;
	void searchContact() const;
};

#endif
