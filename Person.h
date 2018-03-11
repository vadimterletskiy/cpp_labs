#ifndef PERSON_H
#define  PERSON_H 

class Person
{
public:

	//**********************конструкторы*********************************
	Person ();//конструктор по умолчанию
	Person (std::string familia_, std::string name_, std::string otchestvo_, int age_);//конструктор инициализации
	Person (const Person&pers);//конструктор копировани€
	virtual ~Person();//деструктор

	//*************************функции***********************************
	std::string GetFamilia () const;//им€
	std::string GetName () const;//фамили€
	std::string GetOtchestvo () const;//отчество
	int GetAge () const;//возраст


	bool SetName (std::string name_);//измененние имени
	bool SetFamilia (std::string familia_);//изменение фамилии
	bool SetOtchestvo (std::string otchestvo_);//изменение отчества
	int SetAge (int age_);//изменение возраста
	
	//********************************************************************

	virtual void Print(std::ostream& out)const;//виртуальна€ функци€ печати
	virtual void Change(std::istream& in);//виртуальна€ функци€
	//********************************************************************

	static std::string GetNumberHospital();//статическое поле Ќомер больницы
	static void SetNumberHospital(std::string hospital_);//изменение статического пол€ Ќомер больницы

	//************************перегруженные операторы*********************
	
	bool operator == (const Person&right) const;//перегрузка оператора сравнени€
	bool operator!= (const Person&right) const;//перегрузка оператора Ќ≈ равно
	Person&operator= (const Person&right);//перегрузка оператора равно

private:
	std::string name, familia, otchestvo;
	int age;
	static std::string NumberHospital; 
};

std::ostream& operator<< (std::ostream & out, const Person&right);//вз€тие из потока
std::istream& operator>> (std::istream & in, Person&right);//поместить в поток

#endif