#ifndef DOCTOR_H
#define DOCTOR_H
 

class Doctor: public Person
{

public:
//*******************констукторы******************************
	
	Doctor ();//конструктор по умолчанию
	Doctor (std::string familia_, std::string name_, std::string otchestvo_, int age_, int patient_,
		    std::string dezh_);//конструктор инициализации 
	Doctor (const Doctor &doc);//констуктор копирования
	
	virtual ~Doctor();//деструктор
	virtual void Print (std::ostream& out)const;//виртуальная печать
	virtual void Change(std::istream& in);//виртуальная функция
			
	int GetPatient ()const;//число пациентов
	void SetPatient (int patient_);//изменение числа пациентов

	std::string GetDezh ()const;//день дежурства (пн, вт, ср, чт, пт, сб, вс)
	bool SetDezh (std::string dezh_);//изменение дня дежурства

	//**************перегрузка операторов**********************
	
	Doctor& operator++ ();//перегрузка инкремента (префикс)
	Doctor operator++ (int);//перегрузка инкремента (постфикс)
	Doctor& operator-- ();//перегрузка дикремента (префикс)
	Doctor operator-- (int);//перегрузка дикремента (постфикс)
	Doctor& operator= (const Doctor& doc);//перегрузка оператора присваивания

private:

	std::string dezh;
	int patient;
};
std::ostream& operator<< (std::ostream & out, const Doctor&right);//взятие из потока
std::istream& operator>> (std::istream & in, Doctor&right);//поместить в поток
#endif