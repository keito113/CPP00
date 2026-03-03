#include "Contact.hpp"

Contact::Contact()
	: _firstName(""),
	  _lastName(""),
	  _nickName(""),
	  _phoneNumber(""),
	  _darkestSecret(""),
	  _isEmpty(true)
{
}

void Contact::setContact(const std::string& firstName,
			const std::string& lastName,
			const std::string& nickName,
			const std::string& PhoneNumber,
			const std::string& darkestSecret)
{
		_firstName = firstName;
		_lastName = lastName;
		_nickName = nickName;
		_phoneNumber = PhoneNumber;
		_darkestSecret = darkestSecret;
		_isEmpty = false;
}

std::string Contact::getFirstName() const
{
	return(_firstName);
}

std::string Contact::getLastName() const
{
	return(_lastName);
}

std::string Contact::getNickName() const
{
	return(_nickName);
}

std::string Contact::getPhoneNumber() const
{
	return(_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return(_darkestSecret);
}

bool Contact::isEmpty() const
{
	return(_isEmpty);
}

void Contact::displayFull() const
{
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nick name: " << _nickName << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}
