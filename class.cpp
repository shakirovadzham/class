#include <iostream>
#include <algorithm>
using namespace std;

class DynamicArray {
private:
    int *data;
    int size;

public:
    DynamicArray(int arrSize) {
        if (arrSize < 0) {
            cout << "Error: Size cannot be negative" << endl;
            size = 0;
            data = nullptr;
            return;
        }
        size = arrSize;
        data = new int[size]();
    }

    DynamicArray(const DynamicArray& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + other.size, data);
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + other.size, data);
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] data;
    }

    void setValue(int index, int value) {
        if (0 <= index && index < size) {
            if (-100 <= value && value <= 100) {
                data[index] = value;
            } else {
                cout << "Error: meaning " << value << " vykhodit za predely [-100, 100] " << endl;
            }
        } else {
            cout << "Error: index " << index << " vykhodit za predely" << endl;
        }
    }

    int getValue(int index) const {
        if (0 <= index && index < size) {
            return data[index];
        } else {
            cout << "Error: index " << index << " vykhodit za predely" << endl;
            return 0;
        }
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void addValue(int value) {
        if (-100 <= value && value <= 100) {
            int* newData = new int[size + 1];
            std::copy(data, data + size, newData);
            newData[size] = value;
            delete[] data;
            data = newData;
            size += 1;
        } else {
            cout << "Error: meaning " << value << "vykhodit za predely [-100, 100]" << endl;
        }
    }

    DynamicArray add(const DynamicArray& other) const {
        int maxSize = (size > other.size) ? size : other.size;
        DynamicArray result(maxSize);
        
        for (int i = 0; i < maxSize; i++) {
            int val1 = (i < size) ? data[i] : 0;
            int val2 = (i < other.size) ? other.data[i] : 0;
            result.data[i] = val1 + val2;
        }
        
        return result;
    }

    int getSize() const {
        return size;
    }
};