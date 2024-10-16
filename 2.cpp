#include <iostream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    const int num = 4;
    string products[num] = { "Елка", "Мешура", "елочные игрушки", "Гирлянда" };
    double prices[num] = { 2500.0, 240.0, 700.0, 1500.0 };
    int stock[num] = { 54, 220, 152, 87 }; // Количество товара в магазине
    double income = 0.0;
    double dis = 0.25; // 25% скидка
    char proceed = 'y';

    while (proceed == 'y' || proceed == 'Y') {
        double totalSum = 0.0;

        // Вывод списка товаров
        for (int i = 0; i < num; ++i) {
            cout << i + 1 << ". " << products[i] << " - " << prices[i] << " руб (в наличии " << stock[i] << ")" << endl;
        }

        while (true) {
            int choice, quantity;
            cout << "Выберите товар (1-" << num << ") или введите 0 для завершения покупки: ";
            cin >> choice;

            if (choice == 0) break;
            if (choice < 1 || choice > num) {
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
        //наличие скидки
        char discount;
        cout << "У вас есть скидка? (y/n): ";
        cin >> discount;
        if (discount == 'y' || discount == 'Y') {
            totalSum *= (1 - dis); // Применяем скидку
            cout << "Применена скидка 25%." << endl;
        }

        cout << "Итоговая сумма покупки: " << totalSum << " руб." << endl;

        income += totalSum;

        cout << "Обслужить следующего клиента? (y/n): ";
        cin >> proceed;
    }
    cout << "Общая выручка магазина: " << income << " руб." << endl;
    return 0;
}
