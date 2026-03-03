#include "Contact.hpp"
#include "PhoneBook.hpp"

static std::string promptNonEmpty(const std::string& fieldName)
{
	std::string input;

	while(true)
	{
		std::cout << fieldName;
		if(!std::getline(std::cin, input))
			return("");
		if(!input.empty())
			return(input);
		std::cout << "Field cannot be empty." << std::endl;
	}
}

int main()
{
	PhoneBook phonebook;
	std::string command;

	while(true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if(!std::getline(std::cin, command))
			break;
		if(command == "ADD")
		{
			Contact contact;
			std::string firstName;
			std::string lastName;
			std::string nickName;
			std::string phoneNumber;
			std::string darkestSecret;

			firstName = promptNonEmpty("First name: ");
			if(firstName.empty())
				break;
			lastName = promptNonEmpty("Last name: ");
			if(lastName.empty())
				break;
			nickName = promptNonEmpty("Nick name: ");
			if(nickName.empty())
				break;
			phoneNumber = promptNonEmpty("Phone number: ");
			if(phoneNumber.empty())
				break;
			darkestSecret = promptNonEmpty("Darkest secret: ");
			if(darkestSecret.empty())
				break;
			contact.setContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
			phonebook.addContact(contact);
		}
		else if(command == "SEARCH")
			phonebook.searchContact();
		else if(command == "EXIT")
			break;
	}
	return(0);
}
