#include <stdexcept>
#include <iostream>

template<class T>
class DynamicArray {
private:
    T *array;
    int length;
    int capacity;

    void resize() {
        this->capacity *= 2;
        T *newArray = new T[this->capacity];
        for (int i = 0; i < this->length; i++) {
            newArray[i] = this->array[i];
        }
        delete[] this->array;
        this->array = newArray;
    }

public:
    DynamicArray() : length(0), capacity(10) {
        this->array = new T[this->capacity];
    }

    DynamicArray(T* items, int count) : length(count), capacity(count) {
        this->array = new T[this->capacity];
        for (int i = 0; i < count; i++) {
            this->array[i] = items[i];
        }
    }

    DynamicArray(const DynamicArray<T> &dynamicArray) : length(dynamicArray.length), capacity(dynamicArray.capacity) {
        this->array = new T[this->capacity];
        for (int i = 0; i < this->length; i++) {
            this->array[i] = dynamicArray.array[i];
        }
    }

    T& get(int index) const {
        if (index < 0 || index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        return this->array[index];
    }

    int getLength() const {
        return this->length;
    }

    void append(T value) {
        if (this->length == this->capacity) {
            this->resize();
        }
        this->array[this->length] = value;
        this->length++;
    }

    void prepend(T value) {
        if (this->length == this->capacity) {
            this->resize();
        }
        for (int i = this->length; i > 0; i--) {
            this->array[i] = this->array[i - 1];
        }
        this->array[0] = value;
        this->length++;
    }

    void insertAt(T value, int index) {
        if (index < 0 || index > this->length) {
            throw std::out_of_range("Index out of range");
        }
        if (this->length == this->capacity) {
            this->resize();
        }
        for (int i = this->length; i > index; i--) {
            this->array[i] = this->array[i - 1];
        }
        this->array[index] = value;
        this->length++;
    }

    void set(int index, T value) {
        if (index < 0 || index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        this->array[index] = value;
    }

    void clear() {
        this->length = 0;
        this->capacity = 10;
        delete[] this->array;
        this->array = new T[this->capacity];
    }

    T removeAt(int index) {
        if (index < 0 || index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        T value = this->array[index];
        for (int i = index; i < this->length - 1; i++) {
            this->array[i] = this->array[i + 1];
        }
        this->length--;
        return value;
    }

    ~DynamicArray() {
        delete[] this->array;
    }
};

int main() {
    DynamicArray<int> dynamicArray;
    dynamicArray.append(1);
    dynamicArray.append(2);
    dynamicArray.append(3);
    dynamicArray.prepend(0);
    dynamicArray.insertAt(4, 4);
    dynamicArray.set(4, 5);
    dynamicArray.removeAt(4);
    for(int i = 0; i < dynamicArray.getLength(); i++) {
        std::cout << dynamicArray.get(i) << " ";
    }
    return 0;
}