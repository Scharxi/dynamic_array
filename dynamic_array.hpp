#include <algorithm>

namespace collections {
    template<typename T>
    class dynamic_array {
    private:
        int capacity;
        int length;
        T *buffer;

    private:
        void GrowArray();

        void ShrinkArray();


    public:
        dynamic_array() : capacity(2), length(0), buffer(new T[capacity]) {}

        explicit dynamic_array(int cap) : capacity(cap), length(0), buffer(new T[capacity]) {}

        ~dynamic_array() {
            Clear();
            delete[] buffer;
        }

        inline int GetLength() const { return length; };

        inline int GetCapacity() const { return capacity; };

        void PushBack(T value);

        T PopBack();

        T Pop();

        T *get(int index);

        void Clear();
    };

    template<typename T>
    void dynamic_array<T>::Clear() {
        for (auto i = 0; i < length; i++) {
            buffer[i].~T();
        }
        length = 0;
    }

    template<typename T>
    T dynamic_array<T>::Pop() {
        T element = buffer[0];
        buffer[0] = 0;
        length--;

        if (length == (capacity / 2)) {
            ShrinkArray();
        }

        return element;
    }

    template<typename T>
    T *dynamic_array<T>::get(int index) {
        if (index > length) return nullptr;
        return &buffer[index];
    }

    template<typename T>
    T dynamic_array<T>::PopBack() {
        int lastElement = buffer[length - 1];

        // delete last element
        buffer[length - 1] = 0;

        length--;

        if (length == (capacity / 2)) {
            ShrinkArray();
        }

        return lastElement;
    }


    template<typename T>
    void collections::dynamic_array<T>::PushBack(T value) {
        if (dynamic_array::GetCapacity() == dynamic_array::GetLength()) {
            GrowArray();
        }

        buffer[length] = value;

        length++;
    }

    template<typename T>
    void collections::dynamic_array<T>::ShrinkArray() {
        // shrink the capacity
        capacity = length;

        // create the new buffer with the capacity
        T *new_buff = new T[capacity];

        // copy elements
        std::copy(buffer, buffer + capacity, new_buff);

        // clean up memory of old buffer
        delete[] buffer;

        // assign new buffer to buffer
        buffer = new_buff;
    }

    template<typename T>
    void collections::dynamic_array<T>::GrowArray() {
        // creates a new buffer with twice the size of the old one
        T *new_buff = new T[capacity * 2];

        // double the capacity
        capacity *= 2;

        // copy element to the new buffer
        std::copy(buffer, buffer + capacity, new_buff);

        // delete the old buffer
        delete[] buffer;

        // set buffer to new buffer
        buffer = new_buff;
    }


} // collections