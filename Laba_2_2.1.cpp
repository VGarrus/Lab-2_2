#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;

    class Node { //Отвечает за каждый обьект элемент в программе
    public:
        double data;
        Node* prev, * next; //указатели на предыдущий и следуйщий элемент 

    public: //конструкт класса
        Node(double data) {
            this->data = data;
            this->prev = this->next = NULL; //изначально принемают значения NULL
        }
    };


class LinkedList { // работа со всем списком
public:
    Node* head, * tail; // ссылаются на элементы двухсвязного списка

public: //конструкт класса
    LinkedList() {
        this->head = this->tail = NULL; //изначально принемают значения NULL пока нет обьектов
    }
    ~LinkedList() { //диструктор всего списка дабы избежать утечки памяти
        while (head != NULL)
            pop_front();
    }
    
    Node* push_front(double data) { //добавление нового элемента в НАЧАЛО двухсвязного списка
        Node* ptr = new Node(data); //ptr временный указатель 

        ptr->next = head; //ptr обращается к указатею next и приравнивается к указателю head следующего элемента 
        if (head != NULL) //Проверка(тоесть если head будет указывать на сущ. элемент то next тоже будет вести на сущ обьект.если нет то оба будут null)
            head->prev = ptr;
        if (tail == NULL) // если добавляем самый первый элемент в двусвязный список
            tail = ptr;
        head = ptr;

        return ptr;
    }
                                // то есть оглавлю если обьект единственный то на него ведут и tail и head

    Node* push_back(double data) { //добавление нового элемента в КОНЕЦ
        Node* ptr = new Node(data);

        ptr->prev = tail;
        if (tail != NULL)
            tail->next = ptr;
        if (head == NULL) // добовляем первый обьект
            head = ptr;
        tail = ptr;

        return ptr;
    }

    
    void pop_front() { //функция удаления элемента с начало 
        if (head == NULL) return; // если нет обьектов то и удалаять нечего

        Node* ptr = head->next;
        if (ptr != NULL) 
            ptr->prev = NULL; // присваевание следующего элемента (его становица prev = Null)
        else
            tail = NULL; // если обьект остается единственным

        delete head;
        head = ptr;
    }


    void pop_back() { //функция удаления элемента с конца 
        if (tail == NULL) return; // если нет обьектов то и удалаять нечего

        Node* ptr = tail->prev;
        if (ptr != NULL)
            ptr->next = NULL;
        else
            head = NULL;

        delete tail;
        tail = ptr;
    }
    
    Node* getAt(int index) {// произвольный доступ к элементу двусвязного списка:
        Node* ptr = head; //сыллается на самый первый указатель 
        int n = 0;

        while (n != index) {
            if (ptr == NULL)//если нет возращяемся 
                return ptr;
            ptr = ptr->next;
            n++;
        }

        return ptr;
    }




    Node* operator [] (int index) { //оператор который возращяет элемент по определленному индексу
        return getAt(index);
    }
    
    Node* insert(int index, double data) {
        Node* right = getAt(index); //(будем добавлять новый элемент между указателем left и right)
        if (right == NULL)//если даного элемента с таким индексом нет добовляем КОНЕЦ списка
            return push_back(data);

        Node* left = right->prev;
        if (left == NULL)//если даного элемента с таким индексом нет добовляем НАЧАЛО списка
            return push_front(data);

        Node* ptr = new Node(data);

        ptr->prev = left;
        ptr->next = right; //связи для вставки 
        left->next = ptr;
        right->prev = ptr;

        return ptr;
    }
    
    void erase(int index) { //удаление промежуточного элемента
        Node* ptr = getAt(index);
        if (ptr == NULL)//нет элемента которого надо удалить
            return;

        if (ptr->prev == NULL) {//хотим удалить самый первый
            pop_front();
            return;
        }

        if (ptr->next == NULL) {//хотим удалить самый послейдний
            pop_back();
            return;
        } // если прошли все проверки то нам нужны сылки на правый и левый элемент 

        Node* left = ptr->prev;
        Node* right = ptr->next;
        left->next = right;
        right->prev = left;

        delete ptr; // освободаем память элемента ptr
    }

};


int main()
{
    
    LinkedList lst;
    int n = 0 , notification = 0;
    

    setlocale(0, "");
    setlocale(LC_ALL, "Rus"); // Подключение русского языка
    {
        while (true) {

            system("cls");

            cout << "____________________________________________________________________________________" << "\n";
            cout << "|                                 Меню :                                           |" << "\n";
            cout << "|   1) 1 Создание двухсвязного списка .                                            |" << "\n";
            cout << "|   2) 2 Получить элемент списка.                                                  |" << "\n";
            cout << "|   3) 3 Вставка элемента.                                                         |" << "\n";
            cout << "|   4) 4 Удаление элемента                                                         |" << "\n";
            cout << "|   5) 5 Обмен местами                                                             |" << "\n";
            cout << "|   0) 0 Выход из программы                                                        |" << "\n";
            cout << "|__________________________________________________________________________________|" << "\n";
            if (notification == 0) {
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!Лист пуст создайте его!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << "\n";
            cout << "            _______ .______      .______        ______   .______                    " << "\n";
            cout << "           |   ____||   _        |   _         /  __     |   _                      " << "\n";
            cout << "           |  |__   |  |_)  |    |  |_)  |    |  |  |  | |  |_)  |                  " << "\n";
            cout << "           |   __|  |      /     |      /     |  |  |  | |      /                   " << "\n";
            cout << "           |  |____ |  |    ----.|  |    ----.| `- - ' | |  |    ----.            " << "\n";
            cout << "           |_______|| _| `._____|| _| `._____|  ______/  | _| `._____|              " << "\n";
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!Лист пуст создайте его!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << "\n";
            

            }
            cout << "Выберите пункт : " ;
            
            int choice;
            cin >> choice;
            switch (choice) {
            case 0:
                system("cls");
                

                cout << "___________________________________________$$$$$$$$$$$$" << "\n";
                cout << "________________________________________$$$$$$$$$_ __$$$" << "\n";
                cout << "____________________________________$$$$$$$$_____( &)_$$$$" << "\n";
                cout << "________________________________$$$$$$$$$$________ ____$$$$" << "\n";
                cout << "_____________________________$$$$$$$$$$$$$$$____§ §§§_____$" << "\n";
                cout << "___________________________$$$$$$$$$$$$$$$$$$§§ ?§_§§§_____$" << "\n";
                cout << "_________________________$$$$$$$$$$$$$$$$$$$$$§§ §§§_§____" << "\n";
                cout << "______________________$$$$$$$$$$$$$$$$$$_$$$$___§ §§__§_$" << "\n";
                cout << "____________________$$$$$$$$$$$$$_$$$$$$$$_$______ __§" << "\n";
                cout << "___________________$$$$$$$$$$$$$$$$$$$$$$$$_$" << "        Спасибо за просмотр" <<"\n";
                cout << "_________________$$$$$$$$$_$$$$$$$$$$$$$$$$_$" << "          попугай вторник"<<"\n";
                cout << "_______________$$$$$$$$_§$$$$$$$$$§$$$$$$$$_$" << "\n";
                cout << "_____________$$$$$$$_$$§§§$$$§$$§§$$$$§§$_ $$$" << "\n";
                cout << "____________$$$$$$_§§§$$§§$$§§§$$§§$$§ ?$_$$$" << "\n";
                cout << "___________$$$$$_$§§§$$$$§§§$$$§§§§§$$_ $$$$$" << "\n";
                cout << "__________$$$$$_§§§§§§$$§§§$$§§§§§§ §_$$$$$$" << "\n";
                cout << "_________$$$$_§§0§§§§§§§§§§§§§§§ ?_$$$$$$$" << "\n";
                cout << "________$$$_000§§§00§§§§§000§00§_$$$$$$" << "\n";
                cout << "________$$_0000§§0000§§§00§0§_$$$$$$" << "\n";
                cout << "_______$_0000§§00000§0000_$$$$$$$" << "\n";
                cout << "_____§§00000§000§0000_$$$$$$$$" << "\n";
                cout << "___§00000§0000000_$$$$$$$$$$" << "\n";
                cout << "___000§00000§_§§§§$$$$$$$$$$$$$___......" << "\n";
                cout << "___000§00000§_§§§§$$$$$$$$$$$$$___......" << "\n";
                cout << "_000§0_§§§§§§$$$$$$$_§000_$$$§§§_000000 0000000000000" << "\n";
                cout << "00____§§§§§$$$$$$$_§§00000_$§§§_00000000 000000000000" << "\n";
                cout << "______§§§§$$$$$$$_§§§_’’______§§§__???’" << "\n";
               
                return 0;
            case 1:
                system("cls");
                cout << "Создание нового двусвязного списока удалит старый \n";
                cout << "     Вы готовы к этому ? 1- да 0 - нет \n";
                char deleteoldlist;
                cin >> deleteoldlist;
                system("cls");

                srand(time(NULL));

                if (deleteoldlist == '1') {
                    notification = 1;
                    lst.~LinkedList();

                    cout << "1 - Создать двусвязный список со случайными числами от 0 до 99 .\n";
                    cout << "2 - Самому заполнить двусвязный список \n";
                    cout << "Введите значение: ";
                    char opt;
                    cin >> opt;
                    system("cls");

                    if (opt == '1') {
                        cout << "Введите размерность списка : ";
                        cin >> n;
                        auto start = chrono::steady_clock::now();
                        for (int i = 0; i < n; ++i) {
                            lst.push_back(rand() % 100); // рандомное заполнение от 0 до 99

                        }
                        auto end = chrono::steady_clock::now();
                        cout << "Размерность списка : " << n << "\n";
                        cout << "Время создания: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносекунды" << endl;
                        cout << "Вывод списка в одном напрвлении:\n";
                        for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)//выводим на экаран в одном направлнии
                            std::cout << ptr->data << " ";
                        std::cout << std::endl;
                        cout << "Вывод списка в другом напрвлении:\n";
                        for (Node* ptr = lst.tail; ptr != NULL; ptr = ptr->prev) // и в другом чтобы проверить на двухсвящность 
                            std::cout << ptr->data << " ";

                        cout << "\n";
                    }


                    if (opt == '2') {
                        cout << "Для выхода нажмите 000 " << "\n";
                        int a;
                        auto start = chrono::steady_clock::now();
                        while (true) {

                            cin >> a;
                            if (a != 000) {
                                lst.push_back(a); // ручное заполнение
                                n++;
                            }
                            else {
                                break;
                            }
                        }
                        auto end = chrono::steady_clock::now();
                        system("cls");
                        cout << "Размерность списка : " << n << "\n";
                        cout << "Время создания: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносекунды" << endl;
                        cout << "Вывод списка в одном напрвлении:\n";
                        for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)//выводим на экаран в одном направлнии
                            std::cout << ptr->data << " ";
                        std::cout << std::endl;
                        cout << "Вывод списка в другом напрвлении:\n";
                        for (Node* ptr = lst.tail; ptr != NULL; ptr = ptr->prev) // и в другом чтобы проверить на двухсвящность 
                            std::cout << ptr->data << " ";
                        std::cout << std::endl;

                        cout << "\n";

                    }
                    if (opt != '1' and '2') {
                        cout << "Введено неправильное значение\n";
                        system("pause");
                        break;

                    }
                }
                if (deleteoldlist == '0') {
                    cout << "Изменения не были применены\n";
                    system("pause");
                    break;
                }
                system("pause");
                break;
            case 2:
            
                system("cls");
                {
                    cout << "1 - Получить значения по нумерации от 1 до N - го члена \n";
                    cout << "2 - Получить значения равными определенному числу \n";
                    char opt;
                    cin >> opt;
                    system("cls");
                    if (opt == '1') {
                        int a;
                        cout << "Введите индекс : ";
                        cin >> a;
                        a = a - 1;
                        cout << "Значение по индексу : " << lst[a]->data << "\n";

                        cout << "Вывод списка :\n";
                        for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)//выводим на экаран в одном направлнии
                            std::cout << ptr->data << " ";
                        std::cout << std::endl;
                        cout << "\n";
                        system("pause");
                    }

                    if (opt == '2') {
                        cout << "Введите значение : ";
                        int a, opredel = 0;
                        cin >> a;
                        for (int i = 0; i < n; i++) {
                            if (lst[i]->data == a) {
                                cout << "Число -> " << lst[i]->data << " Найдено под индексом :" << i + 1 << '\n';
                                opredel = 1;
                            }


                        }
                        if (opredel == 0) {
                            cout << "Числа не существует";
                        }
                        for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)//выводим на экаран в одном направлнии
                            std::cout << ptr->data << " ";
                        std::cout << std::endl;
                    }
                    if (opt != '1' and '2') {
                        cout << "Введено неправильное значение\n";
                        system("pause");
                        break;
                    }
                }
                    system("pause");
                    break;
            case 3:
                system("cls");
                cout << "Ваш список выгледит так : \n";
                for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)//выводим на экаран в одном направлении
                    std::cout << ptr->data << " ";
                std::cout << std::endl;
                std::cout << std::endl;
                cout << "Под каким индексом должно создаться новое число (1 - N): ";
                int id,numb;
                cin >> id;
                id = id - 1;
                cout << "Значение нового числа : ";
                cin >> numb;
                lst.insert(id, numb);
                cout << "Ваш список выгледит так : \n";
                for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)//выводим на экаран в одном направлнии
                    std::cout << ptr->data << " ";
                std::cout << std::endl;
                system("pause");
                break;
            case 4:
                system("cls");
                {
                    

                    
                        cout << "Ваш список выгледит так : \n";
                        for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)//выводим на экаран в одном направлнии
                            std::cout << ptr->data << " ";
                        std::cout << std::endl;
                        int a ,b;
                        cout << "Введите индекс(1 до N): ";
                        cin >> a;
                        b = a;
                        a = a - 1;
                        cout << "Значение по индексу  удалено: " << b << " Значение числа: " << lst[a]->data << "\n";
                       
                        lst.erase(a);
                        cout << "Ваш список выгледит так : \n";
                        for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)//выводим на экаран в одном направлнии
                            std::cout << ptr->data << " ";
                        std::cout << std::endl;
                      
                    
                    
                }
                system("pause");
                break;
            case 5:
                system("cls");
                system("cls");
                cout << "Ваш список выгледит так : \n";
                for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)//выводим на экаран в одном направлнии
                    std::cout << ptr->data << " ";
                std::cout << std::endl;
                
                cout << "Индексы каких чисел должны поменятся местами (1 - N): \n";
                int numb1, numb2,a,b;
                
                cout << "Число 1: ";
                cin >> numb1;
                numb1 = numb1 - 1;
                
                cout << "Число 2: ";
                cin >> numb2;
                numb2 = numb2 - 1;

                a = lst[numb1]->data ;
                b = lst[numb2]->data ;
                
               
                lst[numb1]->data = b;
                lst[numb2]->data = a;
               


                cout << "Ваш список выгледит так : \n";
                for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)//выводим на экаран в одном направлнии
                    std::cout << ptr->data << " ";
                std::cout << std::endl;
                system("pause");
                break;

                system("pause");
                break;
            
               
            default:
                cout << "\n не найден данный символ " << choice << " d" << endl;
                system("pause");
                break;
                }
            }
        }

        return 0;
    }







