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

int main() {
    // Создаём список List1
    LinkedList<int> List1;
    List1.add(10);
    List1.add(20);
    List1.add(15);
    List1.add(20); // Дублируем максимальный элемент
    List1.add(5);

    std::cout << "List1: ";
    List1.print();

    // Создаём список List2 с индексами максимальных элементов из List1
    LinkedList<int> List2 = List1.findMaxIndices();

    std::cout << "List2 (индексы максимальных элементов): ";
    List2.print();

    return 0;
}