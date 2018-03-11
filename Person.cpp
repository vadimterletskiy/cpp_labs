#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

//����������� ���� ������ ��������********************************************
string Person::NumberHospital = "Hospital�1";
//������������********************************************

Person::Person (): familia (""), name (""), otchestvo (""), age(0){}

Person::Person (string name_, string familia_, string otchestvo_, int age_):
	name (name_), familia (familia_), otchestvo (otchestvo_), age (age_){}

Person::Person (const Person&pers):
	familia (pers.familia), name (pers.name), otchestvo (pers.otchestvo), age (pers.age){}

//������ ����������� (��������)
Person::~Person (){}

//���������� �����************************************
//�������
string Person:: GetFamilia () const
{
	return familia;
}

//���
string Person:: GetName () const
{
	return name;
}

//��������
string Person:: GetOtchestvo() const
{	
	return otchestvo;
}

//�������
int Person:: GetAge () const
{
	return age;
}

//��������� �����********************************************

//��������� �������
bool Person:: SetFamilia (string familia_)
{	
	familia=familia_;
return true;}


//��������� �����
bool Person:: SetName (string name_)
{
	name=name_;
return true;}

//��������� ��������
bool Person:: SetOtchestvo(string otchestvo_)
{
	otchestvo=otchestvo_;
return true;}

//��������� ��������
int Person:: SetAge (int age_)
{
	age=age_;
return true;}


//������***********************************
void Person:: Print (ostream& out)const
{

	out<<name.c_str()<<" "<<familia.c_str()<<" "<<otchestvo.c_str()<<" "<<age<<endl;
}

void Person:: Change (istream& in)
{
	string temp = "";
	int a;	
	cout<<"������� �������"<<endl;
	while (temp == "")
	{
		getline(in, temp);
	}
	
	SetFamilia (temp);
	cout<<"������� ���"<<endl;
	getline (in, temp);
	SetName (temp);
	cout<<"������� ��������"<<endl;
	getline (in, temp);
	SetOtchestvo (temp);
	cout<<"������� �������"<<endl;
	in>>a;
	SetAge (a);
	cin. ignore ();	
	
}
//����������**********************************************************************

//��������� ����������
bool Person::operator== (const Person&right) const
{
	if (familia==right.familia && name==right.name && otchestvo==right.otchestvo && age==right.age)
		return -1;
	return 0;
}

bool Person::operator!= (const Person&right) const
{
	return !(*this==right);
}

Person&Person::operator=(const Person&right)
{
		familia=right.familia;
		name=right.name;
		otchestvo=right.otchestvo;
		age=right.age;

return *this;
}


ostream& operator<< (ostream& out, const Person&right)
{
	right.Print (out);
	return out;
}


istream& operator>> (istream& in, Person&right)
{
	right.Change(in);
	return in;
}