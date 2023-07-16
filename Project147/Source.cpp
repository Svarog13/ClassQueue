#include <iostream>
#include <cstdlib>
#include <conio.h>

template<typename T>
class Queue
{
private:
    T* data;
    int maxSize;
    int size;
public:
    Queue() = default;
    Queue(int maxS) : maxSize(maxS), data(new int[maxSize]), size(0) {}
    ~Queue()
    {
        if (data != nullptr)
        {
            delete[]data;
        }
    }
    bool IsEmpty() const
    {
        return size == 0;
    }
    bool IsFull()
    {
        return size == maxSize;
    }
    void Enqueue(int elem)
    {
        if (!IsFull())
        {
            data[size++] = elem;
        }
    }
    int Dequeue()
    {
        if (!IsEmpty())
        {
            int first = data[0];
            for (size_t i = 1; i < size; i++)
            {
                data[i - 1] = data[i];
            }
            size--;
            return first;
        }
        return -1; 
    }
    int GetCount() const
    {
        return size;
    }
    void Clear()
    {
        size = 0;
    }
    void Show() const
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Queue<int> q(10);
    for (size_t i = 0; i < 7; i++)
    {
        q.Enqueue(rand() % 30);
    }
    q.Show();
    std::cout << q.Dequeue() << std::endl;
    while (!q.IsEmpty())
    {
        std::cout << "Element : " << q.Dequeue() << std::endl;
        _getch();
    }
    return 0;
}