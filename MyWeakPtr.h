#pragma once

#include "MySharedPtr.h"

template <class T>
class MyWeakPtr
{
    MySharedPtr<T> *m_sharedPtr;

public:
    MyWeakPtr(): m_sharedPtr{ new MySharedPtr<T>{}}{}
    MyWeakPtr(MySharedPtr<T> &sharedPtr): m_sharedPtr{ &sharedPtr }{}
    MyWeakPtr(const MyWeakPtr<T> &weakPtr): m_sharedPtr{ weakPtr.m_sharedPtr }{}
    MyWeakPtr(MyWeakPtr<T>&&);

    MyWeakPtr<T>& operator=(MySharedPtr<T>&);
    MyWeakPtr<T>& operator=(const MyWeakPtr<T>&);
    MyWeakPtr<T>& operator=(MyWeakPtr<T>&&);

    MySharedPtr<T>& lock();

    size_t use_counter();
};

#include "MyWeakPtr.inl"
