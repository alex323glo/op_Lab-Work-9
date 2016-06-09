#include "stdafx.h"
#include "Factory.h"

FILE *fw, *fs;
void input(){
	FILE* fw,*fs;
	/*if (fw != NULL)
		//remove("workers.dat");
		fclose(fw);
	else*/
	{
		fopen_s(&fw,"workers.dat", "wb");

		worker person1;
		int wk = 0; //кількість робітників
		char answer_workers;
		cout << "Enter workers? y/n" << endl;
		answer_workers = _getch();
		while (answer_workers != 'n')
		{
			wk++;

			cout << "Enter Surname\n";
			cin >> person1.surname;
			cout << "Enter Sex (m/f)\n";
			cin >> person1.sex;
			cout << "Enter Education level\nNo\nMiddle\nFull_middle\nHigh\n"; //getch();
			cin >> person1.education;//gets_s(person1.education);
			cout << "Enter Experience\n";
			cin >> person1.workExp;
			cout << "Enter Salary\n";
			cin >> person1.salary;
			cout << "Enter Profession\n";
			cin >> person1.profession;
			cout << "Enter Level(rozrjad)\n";
			cin >> person1.category;
			//person1.flag = true;

			fwrite(&person1, sizeof(worker), 1, fw);

			cout << "One more worker? (y/n)" << endl;
			answer_workers = _getch();
		}
		fclose(fw);
	}

	/*if (fs != NULL)
		fclose(fs);
		//remove("staffs.dat");
	else*/
	{
		fopen_s(&fs,"staffs.dat", "wb");
		staff person2;
		int st = 0; //кількість перстоналу
		char answer_staff;
		cout << "Enter stuff? y/n" << endl;
		answer_staff = _getch();
		while (answer_staff != 'n')
		{
			st++;

			cout << "Enter Surname\n";
			cin >> person2.surname;
			cout << "Enter Sex (m/f)\n";
			cin >> person2.sex;
			cout << "Enter Education level\nNo\nMiddle\nFull middle\nHigh\n";
			cin >> person2.education;
			cout << "Enter Experience\n";
			cin >> person2.workExp;
			cout << "Enter Salary\n";
			cin >> person2.salary;
			cout << "Enter fakh\n";
			cin >> person2.speciality;
			cout << "Enter Level\n";
			cin >> person2.level;

			fwrite(&person2, sizeof(staff), 1, fs);

			cout << "One more stuff? (y/n)" << endl;
			answer_staff = _getch();
		}
		fclose(fs);
	}
	//_getch();
}

void read_from_file_w() //читання з файлу з робітниками та виведення на екран
{
	FILE *fw;
	worker person;
	if (fopen_s(&fw,"workers.dat", "rb")) cerr << "File can`t be found";
	else
	{
		cout << endl << setw(20) << "Workers:" << endl;

		fread(&person, sizeof(worker), 1, fw);

		printf("%-10s | %-3s | %-15s | %-5s | %-6s | %-15s | %-8s\n", "Surname", "Sex", "Education", "Exp", "Salary", "Profession", "Category");
		printf("----------------------------------------------------------------\n");

		while (!feof(fw))
		{
			
			//cout << "surname____sex___educatinon__workExp___salary____profession__category" << endl;

			//cout.setf(ios::left); //вирівнювання даних на екрані зліва

			//виведення робітника
			/*cout << setw(12) << person.surname
				<< setw(6) << person.sex
				<< setw(12) << person.education
				<< setw(10) << person.workExp
				<< setw(10) << person.salary
				<< setw(12) << person.profession
				<< setw(12) << person.category << endl;
			*/
			printf("%-10s | %-3c | %-15s | %-5d | %-6d | %-15s | %-8c\n\n", person.surname, person.sex, person.education, person.workExp, person.salary, person.profession, person.category);
			fread(&person, sizeof(worker), 1, fw);
		}
		fclose(fw);
	}
	_getch();
}

void read_from_file_s() //читання з файлу з персоналом та виведення на екран
{
	FILE *fs;
	staff person;
	if (fopen_s(&fs,"staffs.dat", "rb")) cerr << "File can`t be found";
	else
	{
		cout << endl << setw(20) << "Stuff:" << endl;

		fread(&person, sizeof(staff), 1, fs);

		printf("%-10s | %-3s | %-15s | %-5s | %-6s | %-15s | %-8s\n", "Surname", "Sex", "Education", "Exp", "Salary", "Speciality", "Level");
		printf("----------------------------------------------------------------\n");

		while (!feof(fs))
		{

			//cout << "surname____sex___educatinon__workExp___salary____speciality__level" << endl;

			

			//cout.setf(ios::left);				//вирівнювання даних на екрані зліва

			//виведення ІТП
			/*cout << setw(12) << person.surname
				<< setw(6) << person.sex
				<< setw(12) << person.education
				<< setw(10) << person.workExp
				<< setw(10) << person.salary
				<< setw(12) << person.speciality
				<< setw(12) << person.level << endl;
			*/
			printf("%-10s | %-3c | %-15s | %-5d | %-6d | %-15s | %-8d\n\n", person.surname, person.sex, person.education, person.workExp, person.salary, person.speciality, person.level);
			fread(&person, sizeof(staff), 1, fs);
		}
		fclose(fs);
	}
	_getch();
}

int Task2(char* str) {
	FILE *fs;
	staff person;
	int counter = 0;
	if (fopen_s(&fs,"staffs.dat", "rb")) cerr << "File can`t be found";
	else
	{
		fread(&person, sizeof(staff), 1, fs);

		while (!feof(fs))
		{

			if (!strcmp(str, person.speciality) && (person.level == 1))
				counter++;

			fread(&person, sizeof(staff), 1, fs);
		}
		fclose(fs);
	}
	return counter;

}

void Task3()
{
	FILE *fw, *jam;
	worker person;
	if (fopen_s(&fw,"workers.dat", "rb")) cerr << "File can`t be found";
	else
	{
		FILE* jam;
		fopen_s(&jam, "workers2.dat", "wb");

		fread(&person, sizeof(worker), 1, fw);
		printf("%-15s%-15s%-8s%-15s%\n", "Surname", "Education", "Rozrjad", "Profession");

		while (!feof(fw))
		{
			if ((!strcmp("Full_middle", person.education)) && (person.category == '1'))
			{
				fwrite(&person, sizeof(worker), 1, jam);
				printf("%-15s%-15s%-8c%-15s\n%", person.surname, person.education, person.category, person.profession);
			}

			fread(&person, sizeof(worker), 1, fw);
		}
		fclose(fw);
		fclose(jam);
		system("pause");
	}
}


void Add()
{
	FILE *fw, *fs;
	fopen_s(&fw,"workers.dat", "ab+");

	worker person1;
	int wk = 0; //кількість робітників
	char answer_workers;
	cout << "Enter workers? y/n" << endl;
	answer_workers = _getch();
	while (answer_workers != 'n')
	{
		wk++;

		cout << "Enter Surname\n";
		cin >> person1.surname;
		cout << "Enter Sex (m/f)\n";
		cin >> person1.sex;
		cout << "Enter Education level\nNo\nMiddle\nFull_middle\nHigh\n";
		cin >> person1.education;
		cout << "Enter Experience\n";
		cin >> person1.workExp;
		cout << "Enter Salary\n";
		cin >> person1.salary;
		cout << "Enter Profession\n";
		cin >> person1.profession;
		cout << "Enter Level(rozrjad)\n";
		cin >> person1.category;

		fwrite(&person1, sizeof(worker), 1, fw);

		cout << "One more worker? (y/n)" << endl;
		answer_workers = _getch();
	}
	fclose(fw);


	fopen_s(&fs,"staffs.dat", "ab+");
	staff person2;
	int st = 0; //кількість перстоналу
	char answer_staff;
	cout << "Enter stuff? y/n" << endl;
	answer_staff = _getch();
	while (answer_staff != 'n')
	{
		st++;

		cout << "Enter Surname\n";
		cin >> person2.surname;
		cout << "Enter Sex (m/f)\n";
		cin >> person2.sex;
		cout << "Enter Education level\nNo\nMiddle\nFull_middle\nHigh\n";
		cin >> person2.education;
		cout << "Enter Experience\n";
		cin >> person2.workExp;
		cout << "Enter Salary\n";
		cin >> person2.salary;
		cout << "Enter Fakh\n";
		cin >> person2.speciality;
		cout << "Enter Level\n";
		cin >> person2.level;

		fwrite(&person2, sizeof(staff), 1, fs);

		cout << "One more stuff? (y/n)" << endl;
		answer_staff = _getch();
		fclose(fs);
	}
	//_getch();
}

void Task1(double sal)
{
	FILE *fw;
	worker person;
	worker mas[100];
	if (fopen_s(&fw,"workers.dat", "rb")) cerr << "File can`t be found";
	else
	{
		fread(&person, sizeof(worker), 1, fw);
		int i = 0;
		while (!feof(fw))
		{

			if ((person.workExp > 3) && (person.salary < sal) && (person.sex=='m'))
			{
				mas[i] = person;
			}
			fread(&person, sizeof(worker), 1, fw);
			i++;
		}
		int n = i;
		char *max;
		worker sort;
		int k = 0;
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (strcmp(mas[j].surname, mas[j + 1].surname)>0)
			{
				sort = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = sort;
				k++;
			}
		}
		//cout << "surname____sex___educatinon__workExp___salary____profession__category" << endl;
		printf("%-10s | %-3s | %-15s | %-5s | %-6s | %-15s | %-8s\n","Surname","Sex","Education","Exp","Salary","Profession","Category");
		printf("----------------------------------------------------------------\n");
		//if (k != 0){
			for (int i = 0; i < n; i++)
			{	
				/*cout << setw(12) << mas[i].surname
					<< setw(6) << mas[i].sex
					<< setw(12) << mas[i].education
					<< setw(10) << mas[i].workExp
					<< setw(10) << mas[i].salary
					<< setw(12) << mas[i].profession
					<< setw(12) << mas[i].category << endl;
				*/
				printf("%-10s | %-3c | %-15s | %-5d | %-6d | %-15s | %-8c\n\n", mas[i].surname, mas[i].sex, mas[i].education, mas[i].workExp, mas[i].salary, mas[i].profession, mas[i].category);
			}
	}
	fclose(fw);
}


void Changed()
{
	FILE *fw, *fs;
	int key;
	cout << "Whome do you want to change?\n1. Worker\n2. Stuff\n";
	cin >> key;
	if (key == 1) 
	{
		int num = 0;
		fopen_s(&fw, "workers.dat", "rb+");
		fseek(fw, 0, SEEK_SET);
		cout << "Enter # of person\n";
		cin >> num;
		fseek(fw, (num - 1)*sizeof(worker), SEEK_SET);
		worker person1;
		cout << "Enter Surname\n";
		cin >> person1.surname;
		cout << "Enter Sex (m/f)\n";
		cin >> person1.sex;
		cout << "Enter Education level\nNo\nMiddle\nFull_middle\nHigh\n";
		cin >> person1.education;
		cout << "Enter Experience\n";
		cin >> person1.workExp;
		cout << "Enter Salary\n";
		cin >> person1.salary;
		cout << "Enter Profession\n";
		cin >> person1.profession;
		cout << "Enter Level(rozrjad)\n";
		cin >> person1.category;
		fwrite(&person1, sizeof(worker), 1, fw);
		person1.flag = false;
		fclose(fw);
	}
	else
	{
		fopen_s(&fs, "staffs.dat", "rb+");
		fseek(fs, 0, SEEK_SET);
		int num;
		cout << "Enter # of person\n";
		cin >> num;
		fseek(fs, (num - 1)*sizeof(staff), SEEK_SET);
		staff person1;
		cout << "Enter Surname\n";
		cin >> person1.surname;
		cout << "Enter Sex (m/f)\n";
		cin >> person1.sex;
		cout << "Enter Education level\nNo\nMiddle\nFull_middle\nHigh\n";
		cin >> person1.education;
		cout << "Enter Experience\n";
		cin >> person1.workExp;
		cout << "Enter Salary\n";
		cin >> person1.salary;
		cout << "Enter Fakh\n";
		cin >> person1.speciality;
		cout << "Enter Level\n";
		cin >> person1.level;
		fwrite(&person1, sizeof(staff), 1, fs);
		person1.flag = false;
		fclose(fs);
	}
}
