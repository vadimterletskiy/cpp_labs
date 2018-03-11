#include <iostream>
#include <string>
#include "Person.h"
#include "Doctor.h"

using namespace std;

Doctor::Doctor ():Person(), patient(0), dezh(""){}
Doctor::Doctor(string familia, string name, string otchestvo, int age, int patient_, string dezh_):
	Person (familia, name, otchestvo, age), patient (patient_), dezh (dezh_){}
Doctor::Doctor (const Doctor&doc):Person (doc), patient (doc.patient), dezh (doc.dezh){}

//������
void Doctor:: Print(ostream& out) const
{
	Person::Print(out);
	out<<"���������� ���������: "<<patient<<""<<"���� ���������: "<<dezh.c_str()<<endl;
}
//
void Doctor:: Change(istream& in)
{
	Person:: Change (in);
	string temp;
	int a;
	cout<<"������� ���������� ���������: "<<endl;
	in>>a;
	SetPatient (a);
    cout<<"������� ���� ���������: "<<endl;
	getline (in, temp);
	SetDezh (temp);
	cin. ignore ();
	getline (in, temp);
}

//����������
Doctor::~Doctor (){}

//����� ������� � �����
int Doctor:: GetPatient ()const
{	
	return patient;
}

//��������� ����� ������� � �����
void Doctor:: SetPatient (int patient_)
{	
	patient=patient_;
}

//���� ���������
string Doctor:: GetDezh ()const
{	
	return dezh;
}

//��������� ��� ���������
bool Doctor:: SetDezh (string dezh_)
{	
	dezh=dezh_;
	return true;
}

//************************���������************************************
//���������� ����� ���������
Doctor&Doctor:: operator++ ()
{
	patient++;
	return *this;
}
Doctor Doctor:: operator++ (int)
{
	Doctor temp (*this);
	++(*this);
	return temp;
}

//���������� ����� ���������
Doctor&Doctor:: operator-- ()
{
	patient--;
	return *this;
}

Doctor Doctor:: operator-- (int)
{
	Doctor temp (*this);
	--(*this);
	return temp;
}

Doctor&Doctor::operator= (const Doctor&doc)
{
	(*this).Person::operator= (doc);
	patient=doc.patient;
	dezh=doc.dezh;
	return *this;
}

ostream& operator<< (ostream& out, const Doctor&right)
{
	right.Print (out);
	return out;
}


istream& operator>> (istream& in, Doctor&right)
{
	right.Change(in);
	return in;
}