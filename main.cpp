#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

class Address
{
protected:
		string Street,
		City,
		Country,
		Postal_Code;
public:
	void Validate()
	{
		cout << "Введите страну: ";
		cin >> Country;
		cout << "Введите город: ";
		cin >> City;	
		cout << "Введите улицу: ";
		cin >> Street;
		cout << "Введите индекс: ";
		cin >> Postal_Code;
	}
	void Output()
	{
		cout << "Cтрана: " << Country << endl;
		cout << "Город: " << City << endl;	
		cout << "Улица: " << Street << endl;
		cout << "Индекс: " << Postal_Code << endl;
	}
};
class Person : public Address
{
protected:
		string Name,
		Email_Address,
		Phone_Number;	
public:
	void Print()
	{
		cout << "Имя: " << Name << endl;
		cout << "Номер телефона: " << Phone_Number << endl;	
		cout << "Email: " << Email_Address << endl;
		cout << "Адрес: " << endl;
		Output();		
	}
};

class Student : public Person
{
private:
		string Student_Number,
		Average_Mark;
public:
	void Massage()
	{
		Print();
		cout << "Студенческий номер: " << Student_Number << endl;
		cout << "Средний балл: " << Average_Mark << endl;
	}
	void Write()
	{
		cout << "Имя студента: ";
		cin >> Name;
		cout << "Email: ";
		cin >> Email_Address;
		cout << "Номер телефона: ";
		cin >> Phone_Number;
		cout << "Студенческий номер: ";
		cin >> Student_Number;
		cout << "Средний балл: ";
		cin >> Average_Mark;
		Validate();		
	}		
};

class Worked : public Person
{
private:
		int Expirience,
		Salary,
		Hours, 
		Pay,
		Premy;
				
public:
	void Massage()
	{
		Print();
		cout << "Стаж: " << Expirience << endl;
		cout << "Почасовая оплата: " << Salary << endl;
		cout << Name << " проработал " << Hours << " часов" << endl;
		cout << "Зарплата: " << Pay << endl;
		cout << "Премия: " << Premy << endl;
		
	}
	void Write()
	{
		cout << "Введите имя работника: ";
		cin >> Name;
		cout << "Email: ";
		cin >> Email_Address;
		cout << "Номер телефона: ";
		cin >> Phone_Number;
		cout << "Введите стаж " << Name << ": ";
		cin >> Expirience;
		cout << "Введите почасовую оплату " << Name << ": ";
		cin >> Salary;
		cout << "Введите общее время работы " << Name << ": ";
		cin >> Hours;
		
		Pay = Hours * Salary;
		if (Expirience < 1) Premy = 0;
		else if ((Expirience >= 1) && (Expirience < 3)) Premy = Pay * 0.05;
		else if ((Expirience >= 3) && (Expirience < 5)) Premy = Pay * 0.08;
		else if ((Expirience >= 5)) Premy = Pay * 0.15;
		
		Validate();
	}
	void WriteTXT()
	{
		ofstream fout("Worked.txt");
		fout << Name << endl;
		fout << "Стаж: " << Expirience << endl;
		fout << "Почасовая оплата: " << Salary << endl;
		fout << Name << " проработал " << Hours << " часов" << endl;
		fout << "Зарплата: " << Pay << endl;
		fout << "Премия: " << Premy << endl;
		fout.close();
		cout << "Информация была записанна в файл Worked.txt" << endl;
	}
};

class Mirea
{
private:
	vector <Student> Students;
	vector <Worked> Workeds;
public:
	void printInfo()
	{
		cout << "Число студентов: " << Students.size() << endl;
		cout << "Число работников: " << Workeds.size() << endl;
	}
	void printWorkeds()
	{
		for (int i = 0; i < Workeds.size(); i++)
		{
			Workeds[i].Massage(); 
			cout << endl;
		}
	}
	void printStudents()
	{
		for (int i = 0; i < Students.size(); i++)
		{
			Students[i].Massage(); 
			cout << endl;
		}
	}		
	void addWorked()
	{
		Worked objWorked;
		objWorked.Write();
		Workeds.push_back(objWorked);
	}	
	void addStudent()
	{
		Student objStudent;
		objStudent.Write();
		Students.push_back(objStudent);
	}
};

int main(int argc, char* argv[])
{
	setlocale(0,"");

	Mirea objMirea;
	objMirea.addWorked();
	objMirea.addStudent();
	objMirea.printWorkeds();
	objMirea.printStudents();
	objMirea.printInfo();

	system("pause");
	return 0;
}
