#pragma once
#include <iostream>

using namespace std;

namespace TSA
{
	class Employee
	{
	private:
		string job;
		string name;
		string lastName;
		int age;
		string login;
		string pass;

	public:
		Employee();
		Employee(string, string, int, string, string, string);

		string getName();
		string getLastName();
		int getAge();
		string getLogin();
		string getPass();

		void setJob(string job);
		string getJob();

		bool operator<(Employee& employee);
		bool operator>(Employee& employee);
		bool operator==(Employee& employee);
		bool operator!=(Employee& employee);

		friend ostream& operator<<(ostream& out, Employee& employee);
		friend istream& operator>>(istream& in, Employee& employee);
	};

}