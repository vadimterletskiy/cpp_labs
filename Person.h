#ifndef PERSON_H
#define  PERSON_H 

class Person
{
public:

	//**********************������������*********************************
	Person ();//����������� �� ���������
	Person (std::string familia_, std::string name_, std::string otchestvo_, int age_);//����������� �������������
	Person (const Person&pers);//����������� �����������
	virtual ~Person();//����������

	//*************************�������***********************************
	std::string GetFamilia () const;//���
	std::string GetName () const;//�������
	std::string GetOtchestvo () const;//��������
	int GetAge () const;//�������


	bool SetName (std::string name_);//���������� �����
	bool SetFamilia (std::string familia_);//��������� �������
	bool SetOtchestvo (std::string otchestvo_);//��������� ��������
	int SetAge (int age_);//��������� ��������
	
	//********************************************************************

	virtual void Print(std::ostream& out)const;//����������� ������� ������
	virtual void Change(std::istream& in);//����������� �������
	//********************************************************************

	static std::string GetNumberHospital();//����������� ���� ����� ��������
	static void SetNumberHospital(std::string hospital_);//��������� ������������ ���� ����� ��������

	//************************������������� ���������*********************
	
	bool operator == (const Person&right) const;//���������� ��������� ���������
	bool operator!= (const Person&right) const;//���������� ��������� �� �����
	Person&operator= (const Person&right);//���������� ��������� �����

private:
	std::string name, familia, otchestvo;
	int age;
	static std::string NumberHospital; 
};

std::ostream& operator<< (std::ostream & out, const Person&right);//������ �� ������
std::istream& operator>> (std::istream & in, Person&right);//��������� � �����

#endif