#pragma once

#include <iostream>

template <class T>
class MySharedPtr
{
    T* m_ptr;
    size_t* m_counter;

    void Destruct();

public:
    MySharedPtr(T* ptr = nullptr): m_ptr{ptr}, m_counter{new size_t{1}}{}
    MySharedPtr(const MySharedPtr<T> &other_ptr);
    MySharedPtr(MySharedPtr<T>&&);

    MySharedPtr<T>& operator=(const MySharedPtr<T>&);
    MySharedPtr<T>& operator=(MySharedPtr<T>&&);

    operator bool() {return m_ptr != nullptr;}
    T* operator->() {return m_ptr;}
    T& operator*(){return *m_ptr;}
    T* get() {return m_ptr;}

    size_t use_counter();

    ~MySharedPtr() { Destruct(); }
};

#include "MySharedPtr.inl"
