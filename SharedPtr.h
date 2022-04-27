#pragma once

#include <iostream>

template <class T>
class MySharedPtr
{
    T* m_ptr;
    int* m_counter;

    void Destruct()
    {
        if(*m_counter == 1)
        {
            if(m_ptr)
            {
                delete m_ptr;
                std::cout<<"m_ptr deleted! & ";
            }

            delete m_counter;
            std::cout<<"m_counter deleted! & ";
        }
        else
        {
            (*m_counter)--;
        }

        std::cout << "Shared pointer deleted!\n";
    }

public:
    MySharedPtr(T* ptr = nullptr)
        :m_ptr{ptr}, m_counter{new int(1)}
    {
    }

    MySharedPtr(const MySharedPtr<T> &temp_ptr)
        :m_ptr{temp_ptr.m_ptr}, m_counter{temp_ptr.m_counter}
    {
        (*temp_ptr.m_counter)++;
    }

    MySharedPtr(MySharedPtr<T> &&temp_ptr)
        :m_ptr{temp_ptr.m_ptr}, m_counter{temp_ptr.m_counter}
    {
        temp_ptr.m_ptr = nullptr;
        temp_ptr.m_counter = nullptr;
    }

    MySharedPtr<T>* operator=(const MySharedPtr<T> &temp_ptr)
    {
        Destruct();

        m_ptr = temp_ptr.m_ptr;
        (*(m_counter = temp_ptr.m_counter))++;

        return this;
    }

    MySharedPtr<T>* operator=(MySharedPtr<T> &&temp_ptr)
    {
        Destruct();

        m_ptr = temp_ptr.m_ptr;
        m_counter = temp_ptr.m_counter;

        temp_ptr.m_ptr = nullptr;
        temp_ptr.m_counter = new int(1);

        return this;
    }

    operator bool() {return m_ptr != nullptr;}
    T* operator->() {return m_ptr;}
    T& operator*(){return *m_ptr;}
    T* get() {return m_ptr;}

    ~MySharedPtr()
    {
        Destruct();
    }
};
