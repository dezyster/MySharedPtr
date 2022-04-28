#include "MySharedPtr.h"
#include "MyWeakPtr.h"

#include <utility>

void testMySharedPtr()
{
    MySharedPtr<int> a(new int (5));

    MySharedPtr<int> d;

    d = std::move(a);

    std::cout << *d << std::endl;
    std::cout << std::boolalpha << a << std::endl;

    MySharedPtr<int> b;

    b = MySharedPtr<int>{new int {10}};

    a = b;

    std::cout << *a << std::endl;

    MySharedPtr<int> c(std::move(b));

    *c = 55;

    std::cout << *a << std::endl;
}

void testMyWeakPtr()
{
    MySharedPtr<int> shared_a{new int {5}};

    MyWeakPtr<int> weak_a{shared_a};

    std::cout << *weak_a.lock() << std::endl;

    MyWeakPtr<int> weak_b;

    std::cout << std::boolalpha << weak_b.lock() << std::endl;

    weak_b = weak_a;

    std::cout << std::boolalpha << weak_b.lock() << std::endl;
    std::cout << *weak_b.lock() << std::endl;
}

class Item
{
public:
    int m_numb;

    MyWeakPtr<Item> m_Item_ptr;

    Item(): m_numb{5}, m_Item_ptr{} {}

    friend std::ostream& operator<<(std::ostream &out, const Item &item)
    {
        out << item.m_numb;
        return out;
    }
};

void checkPointerToItself()
{
    MySharedPtr<Item> ptr(new Item);

    ptr->m_Item_ptr = ptr;

    std::cout << *ptr << *(ptr->m_Item_ptr.lock()) << "\n";
}

int main()
{
    testMySharedPtr();

    std::cout << "----------------------" << std::endl;

    testMyWeakPtr();

    std::cout << "----------------------" << std::endl;

    checkPointerToItself();

    std::cout << "----------------------" << std::endl;

    return 0;
}
