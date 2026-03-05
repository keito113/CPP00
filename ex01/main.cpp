
#include "PhoneBook.hpp"

static std::string::size_type front_space_tab(const std::string &s)
{
	std::string::size_type i;
	i = 0;
	if(s.size() == 0)
		return(std::string::npos);
	while(i < s.size() && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if(i == s.size())
		return(std::string::npos);
	return(i);
}

static std::string::size_type back_space_tab(const std::string &s, const std::string::size_type start)
{
	if(s.size() == 0)
		return(std::string::npos);
	std::string::size_type len = s.size();
	len--;
	while(len > start && (s[len] == ' ' || s[len] == '\t'))
		len--;
	return(len);
}

static std::string trim_space_tab(const std::string &s)
{
	std::string::size_type start = front_space_tab(s);
	if(start == std::string::npos)
		return("");
	std::string::size_type end = back_space_tab(s, start);
	std::string::size_type pos = start;
	std::string::size_type count = end - start + 1;
	return(s.substr(pos, count));
}

static std::string promptNonEmpty(const std::string &fieldName)
{
	std::string input;
	std::string trim_input;
	while (true)
	{
		std::cout << fieldName;
		if (!std::getline(std::cin, input))
			return ("");
		trim_input = trim_space_tab(input);
		if(trim_input == "")
		{
			std::cout << "Field cannot be empty." << std::endl;
			continue;
		}
		if (!trim_input.empty())
			return (trim_input);
	}
}

int	main(void)
{
	PhoneBook	phonebook;
	Contact		contact;
	std::string command;
	std::string trim_cmd;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break ;
		trim_cmd = trim_space_tab(command);
		if(trim_cmd == "")
		{
			std::cout << "Invalid command" << std::endl;
			continue;
		}
		if (trim_cmd == "ADD")
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
		else if (trim_cmd == "SEARCH")
			phonebook.searchContact();
		else if (trim_cmd == "EXIT")
			break ;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
