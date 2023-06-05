#include "Employee.h"
#include <iostream>

using namespace std;

namespace TSA
{
	Employee::Employee() {};

	Employee::Employee(string name, string lastName, int age, string login, string pass, string job)
	{
		this->name = name;
		this->lastName = lastName;
		this->age = age;
		this->login = login;
		this->pass = pass;
		this->job = job;
	}

	string Employee::getName()
	{
		return this->name;
	}

	string Employee::getLastName()
	{
		return this->lastName;
	}

	int Employee::getAge()
	{
		return this->age;
	}

	string Employee::getLogin()
	{
		return this->login;
	}

	string Employee::getPass()
	{
		return this->pass;
	}


	string Employee::getJob()
	{
		return this->job;
	}

	void Employee::setJob(string job)
	{
		this->job = job;
	}

	bool Employee::operator<(Employee& employee)
	{
		return this->lastName < employee.lastName;
	}

	bool Employee::operator>(Employee& employee)
	{
		return this->lastName > employee.lastName;
	}

	bool Employee::operator==(Employee& employee)
	{
		return this->lastName == employee.lastName;
	}

	bool Employee::operator!=(Employee& employee)
	{
		return this->lastName != employee.lastName;
	}

	ostream& operator<<(ostream& out, Employee& employee)
	{
		out << "Name: " << employee.name << endl;
		out << "Last name: " << employee.lastName << endl;
		out << "Age: " << employee.age << endl;
		out << "Login: " << employee.login << endl;
		out << "Job: " << employee.job << endl;

		return out;
	}

	istream& operator>>(istream& in, Employee& employee)
	{
		try
		{
			cout << "Name: ";
			in >> employee.name;
			if (employee.name.find_first_of("0123456789") != -1)
				throw runtime_error("Name must not contain numbers");
			cout << "Last name: ";
			in >> employee.lastName;
			if (employee.name.find_first_of("0123456789") != -1)
				throw runtime_error("Last name must not contain numbers");
			cout << "Age: ";
			if ((in >> employee.age).fail())
				throw runtime_error("Age must be a number");
			cout << "Login: ";
			in >> employee.login;
			cout << "Password: ";
			in >> employee.pass;
			cout << "Job: ";
			in >> employee.job;
		}
		catch (exception e)
		{
			cerr << e.what() << endl;
			in.clear();
			in.ignore(255, '\n');
		}

		return in;

	}
}
