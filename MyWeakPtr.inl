template <typename T>
MyWeakPtr<T>::MyWeakPtr(MyWeakPtr<T> &&weakPtr): m_sharedPtr{ weakPtr.m_sharedPtr }
{
    weakPtr.m_sharedPtr = new MySharedPtr<T>{};
}

template <typename T>
MyWeakPtr<T>& MyWeakPtr<T>::operator=(MySharedPtr<T> &sharedPtr)
{
     m_sharedPtr = &sharedPtr;
}

template <typename T>
MyWeakPtr<T>& MyWeakPtr<T>::operator=(const MyWeakPtr<T> &weakPtr)
{
    m_sharedPtr = weakPtr.m_sharedPtr;
}

template <typename T>
MyWeakPtr<T>& MyWeakPtr<T>::operator=(MyWeakPtr<T> &&weakPtr)
{
    m_sharedPtr = weakPtr.m_sharedPtr;
    weakPtr.m_sharedPtr = new MySharedPtr<T>{};
}

template <typename T>
MySharedPtr<T>& MyWeakPtr<T>::lock()
{
    return *m_sharedPtr;
}

template <typename T>
size_t MyWeakPtr<T>::use_counter()
{
    return m_sharedPtr->use_counter();
}
