#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstring>

static int front_space_tab(const std::string &s)
{
	int i;
	i = 0;
	while(s[i] == ' ' || s[i] == '\t')
	{
		if(s[i] == '\0')
			return(-1);
		i++;
	}
	return(i);
}

static int back_space_tab(const std::string &s)
{
	std::size_t len = s.size();
	len--;
	while(s[len] == ' ' || s[len] == '\t')
		len--;
	return(len);
}

static int trim_space_tab(const std::string &s){
	int start = front_space_tab(s);
	if(start == -1)
		return(-1);
	int end = back_space_tab(s);
	int i = start;
	while(i < end){
		
	}

}

static std::string promptNonEmpty(const std::string &fieldName)
{
	std::string input;
	while (true)
	{
		std::cout << fieldName;
		if (!std::getline(std::cin, input))
			return ("");
		if (!input.empty())
			return (input);
		std::cout << "Field cannot be empty." << std::endl;
	}
}

int	main(void)
{
	PhoneBook	phonebook;
	Contact		contact;

	std::string command;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
		{
			std::string firstName;
			std::string lastName;
			std::string nickName;
			std::string phoneNumber;
			std::string darkestSecret;
			firstName = promptNonEmpty("First name: ");
			if (firstName.empty())
				break ;
			lastName = promptNonEmpty("Last name: ");
			if (lastName.empty())
				break ;
			nickName = promptNonEmpty("Nick name: ");
			if (nickName.empty())
				break ;
			phoneNumber = promptNonEmpty("Phone number: ");
			if (phoneNumber.empty())
				break ;
			darkestSecret = promptNonEmpty("Darkest secret: ");
			if (darkestSecret.empty())
				break ;
			contact.setContact(firstName, lastName, nickName, phoneNumber,darkestSecret);
				phonebook.addContact(contact);
		}
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break ;
	}
	return (0);
}
