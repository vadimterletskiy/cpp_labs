#include <iostream>
#include <string>
#include "Person.h"
#include "Doctor.h"

using namespace std;

Doctor::Doctor ():Person(), patient(0), dezh(""){}
Doctor::Doctor(string familia, string name, string otchestvo, int age, int patient_, string dezh_):
	Person (familia, name, otchestvo, age), patient (patient_), dezh (dezh_){}
Doctor::Doctor (const Doctor&doc):Person (doc), patient (doc.patient), dezh (doc.dezh){}

//печать
void Doctor:: Print(ostream& out) const
{
	Person::Print(out);
	out<<"Количество пациентов: "<<patient<<""<<"День дежурства: "<<dezh.c_str()<<endl;
}
//
void Doctor:: Change(istream& in)
{
	Person:: Change (in);
	string temp;
	int a;
	cout<<"Введите количество пациентов: "<<endl;
	in>>a;
	SetPatient (a);
    cout<<"Введите день дежурства: "<<endl;
	getline (in, temp);
	SetDezh (temp);
	cin. ignore ();
	getline (in, temp);
}

//деструктор
Doctor::~Doctor (){}

//число больных у врача
int Doctor:: GetPatient ()const
{	
	return patient;
}

//изменение числа больных у врача
void Doctor:: SetPatient (int patient_)
{	
	patient=patient_;
}

//день дежурства
string Doctor:: GetDezh ()const
{	
	return dezh;
}

//изменение дня дежурства
bool Doctor:: SetDezh (string dezh_)
{	
	dezh=dezh_;
	return true;
}

//************************пергрузка************************************
//увеличение числа пациентов
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

//уменьшение числа пациентов
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