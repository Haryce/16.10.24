#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int d1, d2, num;
    cout << "Введите первую границу диапазона: ";
    cin >> d1;
    cout << "Введите вторую границу диапазона: ";
    cin >> d2;
    if (d1 > d2) {
        cout << "Первая граница должна быть меньше Второй. Попробуйте снова." << endl;
        return 1; 
    }
    do {
        cout << "Введите число в диапазоне [" << d1 << ", " << d2 << "]: ";
        cin >> num;

        if (num < d1 || num > d2) {
            cout << "Число не входит в диапазон. Попробуйте снова." << endl;
        }
    } while (num < d1 || num > d2);
    cout << "Вы ввели корректное число: " << num << endl;
    return 0;
}
