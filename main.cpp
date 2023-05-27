#include <iostream>

template<typename T>
class Stack {
private:
    unsigned int m_ElementsCountMax;
    unsigned int m_ElementsCount = 0;
    T* container;
public:
    Stack(unsigned int size) {
        m_ElementsCountMax = size;

        try {
            container = new T[size];
        }
        catch (const std::bad_alloc& e) {
            std::cout << "ERROR! A very big size!";
        }
    }

    ~Stack() {
        delete[] container;
    }

    int size() {
        return m_ElementsCount;
    }

    bool empty() {
        return m_ElementsCount == 0;
    }

    bool push(T element) {
        if (m_ElementsCount < m_ElementsCountMax) {
            container[m_ElementsCount] = element;
            m_ElementsCount++;
        }
        else
            throw std::overflow_error("EXCEPTION! Stack is full!");
    }

    T pop() {
        if (m_ElementsCount == 0) {
            throw std::out_of_range("EXCEPTION! Stack is empty!");
        }
        else {
            T element = container[0];
            for (int i = 0; i < m_ElementsCountMax - 1; i++) {
                container[i] = container[i + 1];
            }
            m_ElementsCount--;

            return element;
        }
    }

    void top() {
        if (m_ElementsCount == 0) {
            throw std::logic_error("EXCEPTION! Stack is empty!");
        }
        else
            std::cout << container[m_ElementsCount - 1] << std::endl;
    }
};


int main() {
    Stack<int> stack(50);

    std::cout << "Stack is empty: " << stack.empty() << std::endl;

    for (int i = 13; i <= 31; i++)
        stack.push(i);

    std::cout << "Stack is empty: " << stack.empty() << std::endl;
    std::cout << "Stack size: " << stack.size() << std::endl;

    stack.top();

    std::cout << "First element from stack: " << stack.pop() << std::endl;
}