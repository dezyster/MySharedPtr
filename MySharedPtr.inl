template <typename T>
void MySharedPtr<T>::Destruct()
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
        --(*m_counter);
    }
    std::cout << "MySharedPtr deleted!\n";
}

template <typename T>
MySharedPtr<T>::MySharedPtr(const MySharedPtr<T> &other_ptr): m_ptr{other_ptr.m_ptr}, m_counter{other_ptr.m_counter}
{
    ++(*other_ptr.m_counter);
}

template <typename T>
MySharedPtr<T>::MySharedPtr(MySharedPtr<T> &&other_ptr): m_ptr{other_ptr.m_ptr}, m_counter{other_ptr.m_counter}
{
    other_ptr.m_ptr = nullptr;
    other_ptr.m_counter = new size_t(1);
}

template <typename T>
MySharedPtr<T>& MySharedPtr<T>::operator=(const MySharedPtr<T> &other_ptr)
{
    Destruct();

    m_ptr = other_ptr.m_ptr;
    m_counter = other_ptr.m_counter;
    ++(*m_counter);

    return *this;
}

template <typename T>
MySharedPtr<T>& MySharedPtr<T>::operator=(MySharedPtr<T> &&other_ptr)
{
    Destruct();

    m_ptr = other_ptr.m_ptr;
    m_counter = other_ptr.m_counter;

    other_ptr.m_ptr = nullptr;
    other_ptr.m_counter = new size_t {1};

    return *this;
}

template <typename T>
size_t MySharedPtr<T>::use_counter()
{
    return *m_counter;
}
