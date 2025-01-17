#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Конструктор по умолчанию
    Date() : day(1), month(1), year(2000) {}

    // Пользовательский конструктор
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        if (!isValidDate()) {
            throw std::invalid_argument("Invalid date");
        }
    }

    // Метод для установки даты
    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
        if (!isValidDate()) {
            throw std::invalid_argument("Invalid date");
        }
    }

    // Метод для вывода даты
    void printDate() const {
        std::cout << (day < 10 ? "0" : "") << day << "."
                  << (month < 10 ? "0" : "") << month << "."
                  << year << std::endl;
    }

    // Метод для определения времени года
    std::string getSeason() const {
        switch (month) {
            case 12:
            case 1:
            case 2:
                return "Winter";
            case 3:
            case 4:
            case 5:
                return "Spring";
            case 6:
            case 7:
            case 8:
                return "Summer";
            case 9:
            case 10:
            case 11:
                return "Autumn";
            default:
                return "Unknown season";
        }
    }

private:
    // Проверка корректности даты
    bool isValidDate() const {
        if (month < 1 || month > 12 || day < 1) return false;

        int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Учитываем високосный год
        if (month == 2 && isLeapYear()) {
            return day <= 29;
        }
        return day <= daysInMonth[month - 1];
    }

    // Проверка на високосный год
    bool isLeapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

int main() {
    try {
        // Создание объекта Date
        Date date1(15, 3, 2025); // Весна
        Date date2(1, 12, 2023); // Зима

        // Вывод даты и времени года
        std::cout << "Date 1: ";
        date1.printDate();
        std::cout << "Season: " << date1.getSeason() << std::endl;

        std::cout << "Date 2: ";
        date2.printDate();
        std::cout << "Season: " << date2.getSeason() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}