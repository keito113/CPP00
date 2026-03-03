#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string  _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;
	bool _isEmpty;

public:
	Contact();
	void setContact(const std::string& firstName,
		const std::string& lastName,
		const std::string& nickName,
		const std::string& PhoneNumber,
		const std::string& darkestSecret);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
	bool isEmpty() const;
	void displayFull() const;
};

#endif
