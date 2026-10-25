#include "Buffer.hpp"

#include <iostream>
#include <utility>

int main()
{

    {
        Buffer a(4);
        a.set(0, 10);
        a.set(1, 20);
        std::cout << "a[0] = " << a.get(0) << ", a[1] = " << a.get(1)
                  << ", dimensiune = " << a.size() << '\n';
    }

    {
        Buffer original(3);
        original.set(0, 100);
        original.set(1, 200);
        original.set(2, 300);

        Buffer copie(original);

        copie.set(0, 999);

        std::cout << "original[0] = " << original.get(0) << '\n';
        std::cout << "copie[0]    = " << copie.get(0) << '\n';
    }

    {
        Buffer sursa(2);
        sursa.set(0, 42);
        Buffer destinatie(std::move(sursa));

        std::cout << "destinatie[0]   = " << destinatie.get(0) << '\n';
        std::cout << "sursa.size()    = " << sursa.size()<< '\n';
    }

    return 0;
}
