#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heapArray;
    int capacity;
    int size;

    void maxHeapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heapArray[left] > heapArray[largest])
            largest = left;

        if (right < size && heapArray[right] > heapArray[largest])
            largest = right;

        if (largest != index) {
            swap(heapArray[index], heapArray[largest]);
            maxHeapify(largest);
        }
    }

public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heapArray = new int[capacity];
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap penuh!\n";
            return;
        }

        int i = size;
        heapArray[size++] = value;

        while (i != 0 && heapArray[(i - 1) / 2] < heapArray[i]) {
            swap(heapArray[i], heapArray[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapify() {
        for (int i = (size / 2) - 1; i >= 0; i--)
            maxHeapify(i);
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << heapArray[i] << " ";
        cout << endl;
    }

    ~MaxHeap() {
        delete[] heapArray;
    }
};

int main() {
    MaxHeap heap(10);

    heap.insert(11);
    heap.insert(10);
    heap.insert(5);
    heap.insert(1);
    heap.insert(7);
    heap.insert(6);
    heap.insert(20);

    cout << "Heap setelah insert: ";
    heap.printHeap();

    heap.heapify();

    cout << "Heap setelah heapify: ";
    heap.printHeap();

    return 0;
}
