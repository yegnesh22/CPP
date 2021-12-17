#include "person.h"

Person::Person()
{
	m_age = 0;
	m_name = "";
}


Person::Person(string name, int age)
{
	m_name = name;
	m_age = age;
}

Person::Person(const Person &other)
{
	m_name = other.m_name;
	m_age = other.m_age;
}

void Person::print() const
{
	cout << m_name << ":" << m_age << flush;
}

bool Person::operator<(const Person &other) const
{
	if (m_name == other.m_name)
		return m_age < other.m_age;
	return m_name < other.m_name;
}

