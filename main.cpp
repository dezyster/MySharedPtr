#include "SharedPtr.h"

#include <utility>
#include <memory>

int main()
{
    /*MySharedPtr<int> a(new int (5));
    MySharedPtr<int> b(a);
    MySharedPtr<int> c(b);
    MySharedPtr<int> d(std::move(b));*/

    MySharedPtr<int> a(new int{ 5 });
    MySharedPtr<int> b(a);

    {
        MySharedPtr<int> c(std::move(a));

        b = c;
    }

    std::cout << "----------" << std::endl;

    return 0;
}
