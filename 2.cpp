#include <iostream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    const int numProducts = 4;
    string products[numProducts] = { "Елка", "Мешура", "елочные игрушки", "Гирлянда" };
    double prices[numProducts] = { 2500.0, 120.0, 600.0, 990.0 };
    int stock[numProducts] = { 24, 120, 52, 41 }; // Количество товара в магазине
    double income = 0.0;
    double discount = 0.25; // 25% скидка
    char proceed = 'y';
    while (proceed == 'y' || proceed == 'Y') {
        double totalSum = 0.0;
        for (int i = 0; i < numProducts; ++i) {
            cout << i + 1 << ". " << products[i] << " - " << prices[i] << " руб (в наличии " << stock[i] << ")" << endl;
        }
        while (true) {
            int choice, quantity;
            cout << "Выберите товар (1-" << numProducts << ") или введите 0 для завершения покупки: ";
            cin >> choice;

            if (choice == 0) break;
            if (choice < 1 || choice > numProducts) {
                cout << "Неверный ввод, попробуйте снова." << endl;
                continue;
            }
            cout << "Введите количество товара: ";
            cin >> quantity;

            if (quantity < 0 || quantity > stock[choice - 1]) {
                cout << "Неверное количество, попробуйте снова." << endl;
                continue;
            }

            totalSum += prices[choice - 1] * quantity;
            stock[choice - 1] -= quantity;
        }
        if (totalSum > 100.0) {
            totalSum *= (1 - discount); // Применяем скидку
            cout << "Применена скидка 10%." << endl;
        }
        cout << "Итоговая сумма покупки: " << totalSum << " руб." << endl;
        income += totalSum;

        cout << "Обслужить следующего клиента? (y/n): ";
        cin >> proceed;
    }
    cout << "Общая выручка магазина: " << income << " руб." << endl;

    return 0;
}