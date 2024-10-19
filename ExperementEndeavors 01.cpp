
//Instegration space 

#include <iostream>
//#include <cmath>
#include <string.h>
#include <stdlib.h>

//=========-------==========

//-= -= -= -= -= -= -= -= -= -= -
using namespace std;
//-= -= -= -= -= -= -= -= -= -= -

//Инкапсуляция

//Инкапсуляция - это упаковка данных и функций в один компонент(например, класс) и последующий контроль
//доступа к этому компоненту, создавая
//тем самым "чёрный ящик" из объекта12.Принцип инкапсуляции является одним из основных
//принципов объектно - ориентированного программирования...


//Void

//void — это ключевое слово в C++ (и других языках программирования, таких как C и Java), которое
//используется для обозначения функций, которые не возвращают значение.Вот, что это значит :
//Функции без возвращаемого значения : Когда функция объявлена
//с типом void, это означает, что она выполняет свои действия, но не возвращает никаких данных.



//Class

//Класс в C++ и других объектно - ориентированных языках программирования — это шаблон или "чертеж" для создания объектов.
//Он объединяет данные(переменные) и методы(функции), которые работают с этими данными,
//в одну структуру.По сути, класс определяет свойства и поведение объектов, которые создаются на его основе.


// Класс book для представления книги
class book {
private:          
    char* author, * title, * publisher; // Поля для хранения информации о книге
    float* price; // Указатель на цену книги
    int* stock; // Указатель на количество книг на складе
public:
    book() { // Конструктор класса
        author = new char[20];
        title = new char[20];
        publisher = new char[20];
        price = new float;
        stock = new int;
    }
    void feeddata(); // Метод для ввода данных о книге
    void editdata(); // Метод для редактирования данных книги
    void showdata(); // Метод для отображения данных книги
    int search(char[], char[]); // Метод для поиска книги
    void buybook(); // Метод для покупки книги
};

// Метод для ввода данных о книге
void book::feeddata() {
    cin.ignore(); // Игнорируем оставшийся символ новой строки в потоке ввода
    cout << "\nEnter Author Name: ";      cin.getline(author, 20);
    cout << "Enter Title Name: ";         cin.getline(title, 20);
    cout << "Enter Publisher Name: ";     cin.getline(publisher, 20);
    cout << "Enter Price: ";              cin >> *price;
    cout << "Enter Stock Position: ";     cin >> *stock;
}

// Метод для редактирования данных книги
void book::editdata() {
    cin.ignore(); // Игнорируем оставшийся символ новой строки в потоке ввода
    cout << "\nEnter Author Name: ";      cin.getline(author, 20);
    cout << "Enter Title Name: ";         cin.getline(title, 20);
    cout << "Enter Publisher Name: ";     cin.getline(publisher, 20);
    cout << "Enter Price: ";              cin >> *price;
    cout << "Enter Stock Position: ";     cin >> *stock;
}

// Метод для отображения данных книги
void book::showdata() {
    cout << "\nAuthor Name: " << author;
    cout << "\nTitle Name: " << title;
    cout << "\nPublisher Name: " << publisher;
    cout << "\nPrice: " << *price;
    cout << "\nStock Position: " << *stock;
}

// Метод для поиска книги по названию и автору
int book::search(char tbuy[20], char abuy[20]) {
    if (strcmp(tbuy, title) == 0 && strcmp(abuy, author) == 0)
        return 1; // Книга найдена
    else
        return 0; // Книга не найдена
}

// Метод для покупки книги
void book::buybook() {
    int count;
    cout << "\nEnter Number Of Books to buy: ";
    cin >> count;
    if (count <= *stock) {
        *stock = *stock - count;
        cout << "\nBooks Bought Successfully";
        cout << "\nAmount: Rs. " << (*price) * count;
    }
    else {
        cout << "\nRequired Copies not in Stock";
    }
}

int main() {
    book* B[20]; // Массив указателей на объекты класса book
    int i = 0, t, choice;
    char titlebuy[20], authorbuy[20];

    while (1) {
        // Отображение меню
        cout << "\n\n\t\tMENU"
            << "\n1. Entry of New Book"
            << "\n2. Buy Book"
            << "\n3. Search For Book"
            << "\n4. Edit Details Of Book"
            << "\n5. Exit"
            << "\n\nEnter your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            B[i] = new book; // Создание нового объекта класса book
            B[i]->feeddata(); // Ввод данных о книге
            i++;
            break;
        case 2:
            cin.ignore();
            cout << "\nEnter Title Of Book: "; cin.getline(titlebuy, 20);
            cout << "Enter Author Of Book: ";  cin.getline(authorbuy, 20);
            for (t = 0; t < i; t++) {
                if (B[t]->search(titlebuy, authorbuy)) {
                    B[t]->buybook(); // Покупка книги
                    break;
                }
            }
            if (t == i)
                cout << "\nThis Book is Not in Stock";
            break;
        case 3:
            cin.ignore();
            cout << "\nEnter Title Of Book: "; cin.getline(titlebuy, 20);
            cout << "Enter Author Of Book: ";  cin.getline(authorbuy, 20);
            for (t = 0; t < i; t++) {
                if (B[t]->search(titlebuy, authorbuy)) {
                    cout << "\nBook Found Successfully";
                    B[t]->showdata(); // Отображение данных о книге
                    break;
                }
            }
            if (t == i)
                cout << "\nThis Book is Not in Stock";
            break;
        case 4:
            cin.ignore();
            cout << "\nEnter Title Of Book: "; cin.getline(titlebuy, 20);
            cout << "Enter Author Of Book: ";  cin.getline(authorbuy, 20);
            for (t = 0; t < i; t++) {
                if (B[t]->search(titlebuy, authorbuy)) {
                    cout << "\nBook Found Successfully";
                    B[t]->editdata(); // Редактирование данных книги
                    break;
                }
            }
            if (t == i)
                cout << "\nThis Book is Not in Stock";
            break;
        case 5:
            exit(0); // Выход из программы
        default:
            cout << "\nInvalid Choice Entered";
        }
    }
    return 0;
}

