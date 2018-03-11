#ifndef PATIENT_H
#define PATIENT_H


class Patient: public Person
{

public:
//*******************�����������******************************
	
	Patient ();//����������� �� ���������
	Patient (std::string familia_, std::string name_, std::string otchestvo_, int age_, std::string day_,
		     std::string* simptoms_, int top, std::string lechdoc_);//����������� ������������� 
	Patient (const Patient &pat);//���������� �����������
	
	virtual ~Patient();//����������
	virtual void Print (std::ostream& out)const;//����������� ������
	virtual void Change(std::istream& in);//����������� �������
			
	std::string GetLechDoc () const;//������� ����
	bool SetLechDoc (std::string lechdoc_);

	std::string GetDay ()const;//���� ��������� (��, ��, ��, ��, ��, ��, ��)
	bool SetDay (std::string day_);//��������� ��� ���������

//******************������ � �������� ���������****************
	
	std::string GetSimp (int simp_) const;//��������
	bool AddSimp (std::string simp_);//���������� ���������
	bool DeleteSimp (std::string simp_);//�������� ���������

	//**************���������� ����������**********************

	Patient& operator+ (std::string simp_);//���������� ��������� ��������
	Patient& operator- (std::string simp_);//���������� ��������� ���������
	Patient& operator~();//���������� ��������� ������ (��������)
	Patient& operator= (const Patient& pat);//���������� ��������� ������������

private:

	std::string lechdoc, day;
	std::string* simptoms;
	int top, size;
};
std::ostream& operator<< (std::ostream & out, const Patient&right);//������ �� ������
std::istream& operator>> (std::istream & in, Patient&right);//��������� � �����
#endif