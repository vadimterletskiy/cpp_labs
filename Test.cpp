#include <iostream>
#include <fstream>
#include <string>
#include "Person.h" 
#include "Patient.h"
#include "Doctor.h"

using namespace std;

int menu_main ();
int menu_add ();
int add();
int menu_change ();
void change(int index);
int print_all();
int menu_select();
int new_patient ();
int new_doctor ();
void read_file(const char *fileName);
void write_file(const char *fileName);
void add_person(Person *person);
void change_simpt(Person *person);
int menu_change_simpt();

const int num = 100;
Person* arr[num] = { 0 };
const string doctor = "doctor";
const string patient = "patient";
//todo not used hospital
ifstream hospital;

int main()
{
	setlocale(LC_ALL, "Rus");
	read_file("C:\\Person.txt");
	print_all();	
	int choice;
	int choice1 = -1;
	int choice3 = -1;
	int patient_index = -1;

	while (1)
	{
		choice=menu_main();//получаем команду, выбранную пользователем

		switch (choice)
		{
		case 0: // 0. Выход из программы
			write_file("C:\\Person.txt");	
			cout<<"Goodbay"<<endl; 
			return 0;		
		case 1: // 1. Добавить человека
			patient_index = add();
			change(patient_index);
			break;
		case 2:  // 2. Распечатать всю информацию о приёмном покое
			print_all();			
			break;
		case 3: // 3. Изменить информацию
			patient_index = menu_select();
			change(patient_index);
			break;
		case 4: // 4. Изменить номер больницы
			break;
			//case 4: Person.SetNumberHospital (); break;
		default: cout<<"Пропробуйте ещё раз!!\n\n";
		}	
	}
}

//исходное меню
int menu_main()
{
	int choice;
	cout<<"0. Выход из программы\n";
	cout<<"1. Добавить человека\n";
	cout<<"2. Распечатать всю информацию о приёмном покое\n";
	cout<<"3. Изменить информацию\n";
	cout<<"4. Изменить номер больницы\n";
	cout<<"Введите команду: ";
	cin>>choice;

	return choice;
}

int add() {
	int choice1 = menu_add();
	while (true)
	{
		switch (choice1)
		{
		case 1: // 1. Добавить пациента
			return new_patient();
		case 2: // 2. Добавить врача
			return new_doctor();
		default: cout << "Попробуйте ещё раз!!\n\n";
		}
	}	
}
//первое меню выбора
int menu_add ()
{
	int choice1;
	cout<<"1. Добавить пациента\n";
	cout<<"2. Добавить врача\n";
	cin>>choice1;
	return choice1;
}

int menu_select() 
{
	int capacity = print_all();
	int index;
	cout << "Enter index:\n";
	cin >> index;
	//todo check index
	return index;
}

int print_all() {
	cout << "**************** print_all ****************" << endl;
	int count = 0;
	for (size_t i = 0; i < num; i++)
	{
		if (arr[i] != NULL)
		{
			cout << "Index "<<i << ": " << *arr[i];
			count++;
			cout << "-------------------------------------------" << endl;
		}
	}
	cout << "Всего: " << count << endl;
	cout << "*******************************************" << endl;
	return count;
}

int menu_change_simpt()
{
	int choice3;
	cout << "0. to main menu\n";
	cout << "1. add new\n";
	cout << "2. delete\n";
	cout << "3. ...\n\n";
	cout << "Введите команду: ";
	cin >> choice3;
	return choice3;
}

void change_simpt(Person *pers) 
{
	if (Patient* person = dynamic_cast<Patient*>(pers)) {
		while (1)
		{
			int choice3 = menu_change_simpt();
			cout << "0. Enter simpt\n";
			string s;
			cin >> s;
			switch (choice3)
			{
			case 0: // 0. to main menu
				return;
			case 1: // 1. add			
				person->AddSimp(s);
				break;
			case 2: // 2. delete
				person->DeleteSimp(s);
				//todo
				break;
			case 3: // 3. Изменить информацию о докторе (день дежурства и количество пациентов)			
					//todo
				break;
			default:
				cout << "Попробуйте ещё раз!!\n\n";
			}
		}
	}
	else
	{
		cout << "It is not patient!!!\n\n";
	}
}

void change(int index)
{
	while (1)
	{
		int choice3 = menu_change();

		switch (choice3)
		{
		case 0: // 0. to main menu
			return;
		case 1: // 1. Изменить основную информацию о пациенте (ФИО и возраст)
			arr[index]->Change(cin);
			break;
		case 2: // 2. Изменить больничную информацию (симптомы, день обращения)
			change_simpt(arr[index]);
				//todo
			break;
		case 3: // 3. Изменить информацию о докторе (день дежурства и количество пациентов)			
				//todo
			break;
		default: 
			cout << "Попробуйте ещё раз!!\n\n";
		}
	}
}

//третье поле выбора
int menu_change ()
{
	int choice3;
	cout << "0. to main menu\n";
	cout<<"1. Изменить основную информацию о пациенте (ФИО и возраст)\n";
	cout<<"2. Изменить больничную информацию (симптомы, день обращения)\n";
	cout<<"3. Изменить информацию о докторе (день дежурства и количество пациентов)\n\n";
	cout<<"Введите команду: ";
	cin>>choice3;
	return choice3;
}

//введение нового пациента
int new_patient()
{	
	for (size_t i = 0; i < num; i++)
	{
		if (arr[i] == NULL)
		{
			arr[i] = new Patient();
			return i;
			//todo change arr[i]
		}
	}
	//todo list is full.
	//new patient can not be added.	
}

//введение нового доктора
int new_doctor()
{
	for (size_t i = 0; i < num; i++)
	{
		if (arr[i] == NULL)
		{
			arr[i] = new Doctor();
			return i;
			//todo change arr[i]
		}
	}
	//todo list is full.
	//new doctor can not be added.
}

void write_file(const char *fileName)
{
	ofstream hospital0(fileName);	
	
	for (size_t i = 0; i < num; i++)
	{
		if (arr[i] == NULL)
		{
			break;
		}			
		if (Doctor* d = dynamic_cast<Doctor*>(arr[i])) {				
			hospital0 << doctor << endl;
		}
		else if (Patient* p = dynamic_cast<Patient*>(arr[i])) {
			hospital0 << patient << endl;
		}
		hospital0 << arr[i]->GetName() << endl;
		hospital0 << arr[i]->GetFamilia() << endl;
		hospital0 << arr[i]->GetOtchestvo() << endl;
		hospital0 << arr[i]->GetAge() << endl;
		if (Doctor* d = dynamic_cast<Doctor*>(arr[i])) {
			//todo
		}
		else if (Patient* p = dynamic_cast<Patient*>(arr[i])) {
			int index = 0;
			string s;
			while ((s = p->GetSimp(index++)) != string(""))
			{					
				hospital0 << s << endl;
			}				
		}
		
	}
	hospital.close();	
}

void read_file(const char *fileName)
{
	hospital.open(fileName);
	if (hospital.good()) 
	{
		string rool;
		string temp;
		hospital >> rool;
		while (hospital.good())
		{			
			string Familia;
			string Name;
			string Otchestvo;
			int Age;
			hospital >> Familia;
			hospital >> Name;
			hospital >> Otchestvo;
			hospital >> Age;
			Person* person;
			
			if (rool == doctor)
			{
				person = new Doctor(Familia, Name, Otchestvo, Age, -1, "dezh");
				hospital >> rool; //next person
			}
			else if (rool == patient)
			{
				string lechDoc;
				hospital >> lechDoc;
				string* simptoms = new string[10];
				int i = 0;
				do {
					getline(hospital, temp);
					if (temp == "") 
					{
						continue;
					}
					if (temp == doctor || temp == patient)
					{
						break;
					}
					simptoms[i++] = temp;
				} while (hospital.good());

				person = new Patient(Familia, Name, Otchestvo, Age, "day", simptoms, i, lechDoc);
				rool == temp;
			}
			add_person(person);			
		}
	}
	hospital.close();	
}

void add_person(Person *person) 
{
	if (person == NULL)
	{
		return;
	}
	for (size_t i = 0; i < num; i++)
	{
		if (arr[i] == NULL)
		{
			arr[i] = person;
			return;
		}
	}
}


