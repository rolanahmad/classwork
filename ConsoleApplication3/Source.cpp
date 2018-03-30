#include <iostream>
#include <time.h>

using namespace std;

/*
—формировать массив структур, каждый элемент которого содержит следующие три пол€:

фамили€, им€ отчество студента (вводим);

массив оценок в дес€тибалльной системе (вводим);

признак



ƒл€ каждого студента получить одно из следующих значений признака: 
5 Ц отличник (только 9 и (или) 10),
4 Ц хорошист (нет оценок, меньше 6, но не все 9 или 10, а есть 6 и (или) 7 и (или) 8),
3 Ц троечник (нет оценок, меньше 4, но есть 4 и (или) 5),
2 Ц неуспевающий (есть 1 и (или) 2 и (или) 3). 
–ассортировать массив структур по убыванию полученного признака.
*/

struct fio {
	char *surname;
	char *name;
	char *patronymic;
};

struct student {
	fio *fio;
	int *assessments;
	int attribute;
	int sum;
};

void generate_name(fio *fio);
void calculate_assessments(student *student);
void chek_assessments(student *student);

void main() {
	srand(time(0));
	rand();
	system("chcp 1251");
	system("cls");
	int students_colvo;
	cout << "ѕожалуйста введите количество студентов: ";
	cin >> students_colvo;
	student *students = new student[students_colvo];
	if (students == NULL) {
		cout << "ѕам€ть не выделенна" << endl;
	}
	else {
		for (int i = 0; i < students_colvo; i++)
		{
			students->fio = new fio[1];
			generate_name(students->fio);
			students->assessments = new int[10];
			for (int j = 0; j < 10; j++)
				students->assessments[j] = 1 + rand() % 9;
				
			students++;
		}
		students -= students_colvo;

		for (int i = 0; i < students_colvo; i++)
		{
			calculate_assessments(students+i);
			chek_assessments(students+i);

		}

		for (int i = 0; i < students_colvo; i++)
		{
			cout << "#" << i + 1 << ". " <<
				(students + i)->fio->name << " " <<
				(students + i)->fio->surname[0] << "." <<
				(students + i)->fio->patronymic[0] << "." << " " <<
				(students + i)->attribute << endl;

		}

	}
}
/*
5 Ц отличник(только 9 и(или) 10),
4 Ц хорошист(нет оценок, меньше 6, но не все 9 или 10, а есть 6 и(или) 7 и(или) 8),
3 Ц троечник(нет оценок, меньше 4, но есть 4 и(или) 5),
2 Ц неуспевающий(есть 1 и(или) 2 и(или) 3).
*/
void chek_assessments(student *student) {
	if (student->sum > 8) {
		student->attribute = 5;
	}
	else if (student->sum > 6 && student->sum < 9) {
		student->attribute = 4;
	}
	else if (student->sum > 4 && student->sum < 8) {
		student->attribute = 3;
	}
	else {
		student->attribute = 2;
	}
}

void calculate_assessments(student *student) {
	for (int i = 0; i < 10; i++) 
		student->sum += student->assessments[i];
	
	student->sum = student->sum / 10;
}

void generate_name(fio *fio) {
	fio->name = new char[3];
	fio->patronymic = new char[3];
	fio->surname = new char[3];
	for (int i = 0; i < 3; i++)
	{
		fio->name[i] = (char)97 + rand() % 25;
		fio->patronymic[i] = (char)97 + rand() % 25;
		fio->surname[i] = (char)97 + rand() % 25;
	}
	fio->name[3] = '\0';
	fio->patronymic[3] = '\0';
	fio->surname[3] = '\0';

}