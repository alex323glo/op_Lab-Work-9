
#include <iostream>
#include <conio.h>
#include <string.h>
#include <iomanip> 
//#pragma warning(disable : 4996)
using namespace std;

struct worker				//робітник
{
	char surname[15];		//прізвище 
	char sex;				// стать (m/f)
	char education[15];		//освіта
	int workExp;				//стаж роботи
	int salary;				//оклад
	char profession[15];		//професія
	char category;			//розряд
	bool flag = true;	
};


struct staff					//інженерно-технічний персонал
{
	char surname[15];		//прізвище 
	char sex;				// стать (m/f)
	char education[15];		//освіта
	int workExp;				//стаж роботи
	int salary;				//оклад
	char speciality[15];		//фах
	int level;
	bool flag = true;//рівень доступу до секретної інформації
};



void input();
void read_from_file_w();
void read_from_file_s();
void Task1(double);
int Task2(char* str);
void Task3(void);
void Add(void);
void Changed(void);
