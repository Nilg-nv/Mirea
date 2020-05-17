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
		cout << "������� ������: ";
		cin >> Country;
		cout << "������� �����: ";
		cin >> City;	
		cout << "������� �����: ";
		cin >> Street;
		cout << "������� ������: ";
		cin >> Postal_Code;
	}
	void Output()
	{
		cout << "C�����: " << Country << endl;
		cout << "�����: " << City << endl;	
		cout << "�����: " << Street << endl;
		cout << "������: " << Postal_Code << endl;
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
		cout << "���: " << Name << endl;
		cout << "����� ��������: " << Phone_Number << endl;	
		cout << "Email: " << Email_Address << endl;
		cout << "�����: " << endl;
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
		cout << "������������ �����: " << Student_Number << endl;
		cout << "������� ����: " << Average_Mark << endl;
	}
	void Write()
	{
		cout << "��� ��������: ";
		cin >> Name;
		cout << "Email: ";
		cin >> Email_Address;
		cout << "����� ��������: ";
		cin >> Phone_Number;
		cout << "������������ �����: ";
		cin >> Student_Number;
		cout << "������� ����: ";
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
		cout << "����: " << Expirience << endl;
		cout << "��������� ������: " << Salary << endl;
		cout << Name << " ���������� " << Hours << " �����" << endl;
		cout << "��������: " << Pay << endl;
		cout << "������: " << Premy << endl;
		
	}
	void Write()
	{
		cout << "������� ��� ���������: ";
		cin >> Name;
		cout << "Email: ";
		cin >> Email_Address;
		cout << "����� ��������: ";
		cin >> Phone_Number;
		cout << "������� ���� " << Name << ": ";
		cin >> Expirience;
		cout << "������� ��������� ������ " << Name << ": ";
		cin >> Salary;
		cout << "������� ����� ����� ������ " << Name << ": ";
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
		fout << "����: " << Expirience << endl;
		fout << "��������� ������: " << Salary << endl;
		fout << Name << " ���������� " << Hours << " �����" << endl;
		fout << "��������: " << Pay << endl;
		fout << "������: " << Premy << endl;
		fout.close();
		cout << "���������� ���� ��������� � ���� Worked.txt" << endl;
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
		cout << "����� ���������: " << Students.size() << endl;
		cout << "����� ����������: " << Workeds.size() << endl;
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
