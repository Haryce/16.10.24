#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int n; // Высота ромба
    n = 61; 
    int sp = n / 2; 
    // Верхняя половина ромба
    for (int i = 1; i <= n / 2 + 1; i++) {
        // Вывод пробелов
        for (int j = 1; j <= sp; j++) {
            cout << " ";
        }
        sp--;
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    // Нижняя половина ромба
    sp = 1;
    for (int i = n / 2; i >= 1; i--) {
        // Вывод пробелов
        for (int j = 1; j <= sp; j++) {
            cout << " ";
        }
        sp++;
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

