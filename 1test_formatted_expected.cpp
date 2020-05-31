#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int boxWithFruit = 15;    //количество ящиков на складе
    int amountBoxForSale = 0; // количество отгружаемых ящиков
    cout << "На складе сейчас" << boxWithFruit << " ящиков с фруктами.\n\n";
    for (int i = 1;; i++) //i - количество машин к погрузке
    {
        cout << "Сколько ящиков отгрузить в " << i << "-ю машину? ";
        cin >> amountBoxForSale;
        if (amountBoxForSale > boxWithFruit)
        {
            cout << "\nНа складе нет такого количества товара!";
            cout << "Осталось только " << boxWithFruit << " ящиков\n\n";
            i--; //уменьшить счетчик на 1
        }
        else
        {
            boxWithFruit -= amountBoxForSale; //перезаписываем значение
            cout << "Осталось " << boxWithFruit << " ящиков.\n";
        }
        if (boxWithFruit == 0) //если ящиков больше нет - выйти из цикла
        {
            cout << "Фрукты закончились! До свидания!\n";
            break;
        }
    }
    return 0;
}