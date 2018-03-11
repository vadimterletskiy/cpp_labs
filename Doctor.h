#ifndef DOCTOR_H
#define DOCTOR_H
 

class Doctor: public Person
{

public:
//*******************�����������******************************
	
	Doctor ();//����������� �� ���������
	Doctor (std::string familia_, std::string name_, std::string otchestvo_, int age_, int patient_,
		    std::string dezh_);//����������� ������������� 
	Doctor (const Doctor &doc);//���������� �����������
	
	virtual ~Doctor();//����������
	virtual void Print (std::ostream& out)const;//����������� ������
	virtual void Change(std::istream& in);//����������� �������
			
	int GetPatient ()const;//����� ���������
	void SetPatient (int patient_);//��������� ����� ���������

	std::string GetDezh ()const;//���� ��������� (��, ��, ��, ��, ��, ��, ��)
	bool SetDezh (std::string dezh_);//��������� ��� ���������

	//**************���������� ����������**********************
	
	Doctor& operator++ ();//���������� ���������� (�������)
	Doctor operator++ (int);//���������� ���������� (��������)
	Doctor& operator-- ();//���������� ���������� (�������)
	Doctor operator-- (int);//���������� ���������� (��������)
	Doctor& operator= (const Doctor& doc);//���������� ��������� ������������

private:

	std::string dezh;
	int patient;
};
std::ostream& operator<< (std::ostream & out, const Doctor&right);//������ �� ������
std::istream& operator>> (std::istream & in, Doctor&right);//��������� � �����
#endif