//9 вариант ИДЗ
//Уменьшить каждый чётной элемент на значение, введённое пользователем
//Каждый нечётный элемент умножить на случайную величину в диапазоне от 1 до 5
//Сравнить скорость работы динамического массива и двусвязного списка
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;
struct List {
	int data;
	List* prev;
	List* next;
};
struct Timer {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	duration<__int64, ratio<1, 1000000000>> duration;
} timerList, timerMass;
List* CreateList(int& length) {
	List* curr = NULL, * prev = NULL;
	if (length == 0) {
		return curr;
	}
	for (int i = 0; i < length; i++) {
		curr = new List;
		curr->data = (rand() % 100) + 1;
		curr->prev = prev;
		if (prev)
			prev->next = curr;
		prev = curr;
	}
	curr->next = NULL;
	while (curr->prev)
		curr = curr->prev;
	return curr;
}
void CreateMass(int* mass, int& length) {
	for (int i = 0; i < length; i++) {
		mass[i] = (rand() % 100) + 1;
	}
}
void ShowList(List* curr) {
	cout << "Список: ";
	while (curr) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << "\n";
}
void ShowMass(int* mass, int& length) {
	cout << "Массив: ";
	for (int i = 0; i < length; i++) {
		cout << mass[i] << " ";
	}
	cout << "\n";
}
void ChangeList(List* curr, int& length, int& minus) {
	timerList.start = steady_clock::now();
	for (int i = 0; i < length; i++) {
		if (i % 2 != 0)
			curr->data -= minus;
		else
			curr->data *= (rand() % 5) + 1;
		curr = curr->next;
	}
	timerList.end = steady_clock::now();
	timerList.duration = timerList.end - timerList.start;
}
void ChangeMass(int* mass, int& length, int& minus) {
	timerMass.start = steady_clock::now();
	for (int i = 0; i < length; i++) {
		if (i % 2 != 0)
			mass[i] -= minus;
		else
			mass[i] *= (rand() % 5) + 1;
	}
	timerMass.end = steady_clock::now();
	timerMass.duration = timerMass.end - timerMass.start;
}
int main()
{
	srand(time(NULL));
	setlocale(0, "");
	int length = 0, minus = 0;
	List* list = NULL;
	cout << "Будут созданы список и массив с произвольными числами от 1 до 100. \nВведите их длину: ";
	cin >> length;
	int* mass = new int[length];
	list = CreateList(length);
	CreateMass(mass, length);
	ShowList(list);
	ShowMass(mass, length);
	system("pause");
	cout << "\nКаждый чётный элемент будет уменьшен на введённое вами значение, а каждый нечётный умножен на произвольное число от 1 до 5. \nВведите значение: ";
	cin >> minus;
	ChangeList(list, length, minus);
	ChangeMass(mass, length, minus);
	ShowList(list);
	ShowMass(mass, length);
	cout << "Время изменения списка: " << timerList.duration.count() << " наносек.\n";
	cout << "Время изменения массива: " << timerMass.duration.count() << " наносек.\n";
	cout << "Изменение массива произошло быстрее на " << (timerList.duration.count() - timerMass.duration.count()) << " наносек.\n";
	system("pause");
}