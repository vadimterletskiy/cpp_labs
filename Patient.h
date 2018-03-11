#ifndef PATIENT_H
#define PATIENT_H


class Patient: public Person
{

public:
//*******************констукторы******************************
	
	Patient ();//конструктор по умолчанию
	Patient (std::string familia_, std::string name_, std::string otchestvo_, int age_, std::string day_,
		     std::string* simptoms_, int top, std::string lechdoc_);//конструктор инициализации 
	Patient (const Patient &pat);//констуктор копирования
	
	virtual ~Patient();//деструктор
	virtual void Print (std::ostream& out)const;//виртуальная печать
	virtual void Change(std::istream& in);//виртуальная функция
			
	std::string GetLechDoc () const;//лечащий врач
	bool SetLechDoc (std::string lechdoc_);

	std::string GetDay ()const;//день обращения (пн, вт, ср, чт, пт, сб, вс)
	bool SetDay (std::string day_);//изменение дня обращения

//******************работа с массивом симптомов****************
	
	std::string GetSimp (int simp_) const;//симптомы
	bool AddSimp (std::string simp_);//добавление симптомов
	bool DeleteSimp (std::string simp_);//удаление симптомов

	//**************перегрузка операторов**********************

	Patient& operator+ (std::string simp_);//перегрузка оператора сложения
	Patient& operator- (std::string simp_);//перегрузка оператора вычитания
	Patient& operator~();//перегрузка оператора тильда (удаление)
	Patient& operator= (const Patient& pat);//перегрузка оператора присваивания

private:

	std::string lechdoc, day;
	std::string* simptoms;
	int top, size;
};
std::ostream& operator<< (std::ostream & out, const Patient&right);//взятие из потока
std::istream& operator>> (std::istream & in, Patient&right);//поместить в поток
#endif