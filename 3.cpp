#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0)); //генератор случайных чисел
    int lvl;
    cout << "Выберите уровень сложности (1, 2 или 3):" << endl;
    cout << "1 - Легкий (умножение на числа от 1 до 10)" << endl;
    cout << "2 - Средний (умножение на числа от 1 до 100)" << endl;
    cout << "3 - Сложный (умножение на числа от 1 до 1000)" << endl;
    cin >> lvl;
    int maxnum;
    switch (lvl) {
    case 1: maxnum = 10; break;
    case 2: maxnum = 100; break;
    case 3: maxnum = 1000; break;
    default:
        cout << "Неверный уровень. Завершение программы." << endl;
        return 1;
    }
    int coranswer = 0;
    for (int i = 0; i < 5; i++) {
        int a = rand() % maxnum + 1; //Случайное число от 1 до maxnum
        int b = rand() % maxnum + 1; //Случайное число от 1 до maxnum
        cout << "Вопрос " << (i + 1) << ": Сколько будет " << a << " * " << b << "?" << endl;
        int ans;
        cin >> ans;

        if (ans == a * b) {
            cout << "Правильно!" << endl;
            coranswer++;
        }
        else {
            cout << "Неправильно. Правильный ответ: " << a * b << endl;
        }
    }
    cout << "Вы ответили правильно на " << coranswer << " из 5 вопросов." << endl;
    return 0;
}
