#include <iostream>
#include <string>
#include "Person.h"
#include "Patient.h"

using namespace std;

//*******������������*************************
Patient::Patient ():Person(), day(""), simptoms(0), top(0), size(0), lechdoc(""){}
Patient::Patient(string familia, string name, string otchestvo, int age, string day_, string* simptoms_, int top_, string lechdoc_):
	Person (familia, name, otchestvo, age), day (day_), top (top_), lechdoc (lechdoc_)
{
	simptoms= new string [size=top];
	for (int i=0; i<top; i++)
		simptoms[i] = simptoms_[i];
}
Patient::Patient (const Patient&pat):Person (pat), day (pat.day), top (pat.top), lechdoc (pat.lechdoc)
{ 
	simptoms= new string [size=pat.size];
	for (int i=0; i<top; i++)
		simptoms[i]=pat.simptoms[i];
}
//**********************************************************
//���� �����������
string Patient:: GetDay () const
{	
	return day;
}

//��������� ��� �����������
bool Patient:: SetDay (string day_)
{	
	day=day_;
    return true;
}

//������� ����
string Patient::GetLechDoc () const
{
	cout<<"������� �������� �����:"<<endl;
	return lechdoc;
}

bool Patient:: SetLechDoc (string lechdoc_)
{	
	lechdoc=lechdoc_;
return true;
}
//***********************������*************************
void Patient::Print(ostream& out) const
{
	Person::Print(out);
	for (int i=0; i<top; i++)
		cout<<simptoms[i].c_str()<<endl;
	out<<"���� �����������: "<<day.c_str()<<", ������� ����: "<<lechdoc.c_str()<<endl;
}

void Patient:: Change (istream& in)
{
	Person:: Change (in);
	string temp;
	
	cout<<"������� ���� �����������"<<endl;
	getline (in, temp);
	SetDay (temp);
	cout<<"������� �������� �����"<<endl;
	getline (in, temp);
	SetLechDoc (temp);
	cin. ignore ();
	getline (in, temp);
}
//*********************����������***********************
Patient::~Patient (){}

//�������� ���������
string Patient::GetSimp (int simp_) const
{
	if (simp_<0 || simp_>=top)
		return "";
	return simptoms[simp_];
}

//���������� ���������
bool Patient::AddSimp (string simp_)
{
	if (top==size)
	{
		cout<<"������� ��������: "<<endl;;
		string* temp= new string [size+=10];
		for (int i=0; i<top; i++)
			temp[i]=simptoms[i];
		delete [] simptoms;
		simptoms=temp;
	}
	simptoms[top++]=simp_;
	return true;
}

//�������� ���������
bool Patient::DeleteSimp (string simp_)
{
	for (int i=0; i<top; i++)
	{
		if (simptoms [i]==simp_)
		{
			simptoms[i]=simptoms[--top];
			return true;
		}
	}
	return false;
}

//***********************����������*******************************

//�������� �������
Patient&Patient::operator+ (string simp_)
{
	AddSimp (simp_);
	return *this;
}

//������� �������
Patient&Patient::operator- (string simp_)
{
	DeleteSimp (simp_);
	return *this;
}

Patient&Patient:: operator~ ()
{
	top=0;
	return *this;
}

Patient&Patient::operator= (const Patient&pat)
{
	if (simptoms)
		delete [] simptoms;
	simptoms=new string[size=pat.size];
	top=pat.top;

	for (int i=0; i<top; i++)
		simptoms[i]=pat.simptoms[i];
	(*this).Person::operator= (pat);
	day=pat.day;
	lechdoc=pat.lechdoc;
	return *this;
}

ostream& operator<< (ostream& out, const Patient&right)
{
	right.Print (out);
	return out;
}


istream& operator>> (istream& in, Patient&right)
{
	right.Change(in);
	return in;
}