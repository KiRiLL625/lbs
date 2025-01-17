#include <iostream>
#include <limits>
#include <vector>

// Шаблонный класс узла списка
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

// Шаблонный класс односвязного списка
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    // Конструктор
    LinkedList() : head(nullptr), size(0) {}

    // Деструктор
    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Добавление элемента в конец списка
    void add(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    // Получение элемента по индексу
    T get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Получение размера списка
    int getSize() const {
        return size;
    }

    // Поиск индексов максимальных элементов
    LinkedList<int> findMaxIndices() const {
        LinkedList<int> indices;
        if (head == nullptr) return indices; // Пустой список

        T maxElement = std::numeric_limits<T>::lowest(); // Минимальное значение типа T
        Node<T>* current = head;
        int index = 0;

        // Первый проход: находим максимум
        while (current != nullptr) {
            if (current->data > maxElement) {
                maxElement = current->data;
            }
            current = current->next;
        }

        // Второй проход: находим индексы максимума
        current = head;
        index = 0;
        while (current != nullptr) {
            if (current->data == maxElement) {
                indices.add(index);
            }
            current = current->next;
            index++;
        }

        return indices;
    }

    // Вывод элементов списка
    void print() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

bool menu(LinkedList<int>& ll) {
    std::cout << "1. Добавить слово в конец" << std::endl;
    std::cout << "2. Получить индексы максимального элемента" << std::endl;
    std::cout << "3. Получить слово по индексу" << std::endl;
    std::cout << "4. Вывести список" << std::endl;
    std::cout << "5. Выход" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            std::cout << "Введите число: ";
            int word;
            std::cin >> word;
            if (std::cin.peek() != '\n') {
                std::cerr << "Ошибка: Вводите только одно слово." << std::endl;
                std::cin.ignore(10000, '\n');
                return true;
            }
            ll.add(word);
            return true;
        }
        case 2: {
            LinkedList<int> indices = ll.findMaxIndices();
            std::cout << "Индексы максимальных элементов: ";
            indices.print();
            return true;
        }
        case 3: {
            std::cout << "Введите индекс: ";
            int index;
            std::cin >> index;
            if (index < 0 || index >= ll.getSize()) {
                std::cerr << "Ошибка: Неверный индекс." << std::endl;
                return true;
            }
            std::cout << "Слово: " << ll.get(index) << std::endl;
            return true;
        }
        case 4: {
            ll.print();
            return true;
        }
        case 5: {
            return false;
        }
        default:
            std::cerr << "Ошибка: Неверный выбор." << std::endl;
            return true;
    }
}

int main() {
    // Создаём список List1
    LinkedList<int> List1;
    while(menu(List1));

    return 0;
}
