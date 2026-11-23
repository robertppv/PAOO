#include <iostream>

#include "Employee.h"

int main() {
    {
        Employee a("A");
        Employee b("B");
        Employee c("C");

        a = b = c;

        std::cout << "  a = " << a.recordContent() << '\n';
        std::cout << "  b = " << b.recordContent() << '\n';
        std::cout << "  c = " << c.recordContent() << '\n';
    }

    {
        Employee e("E");
    
        e = e;
        std::cout << "e = " << e.recordContent() << '\n';
    }

    {
        Employee original("Orig");
        Employee copied(original);
        Employee assigned("Tmp");
        assigned = original;

        std::cout << "original : name=\"" << original.name()
                  << "\", record=" << original.recordContent() << '\n';
        std::cout << "copied   : name=\"" << copied.name()
                  << "\", record=" << copied.recordContent() << '\n';
        std::cout << "assigned : name=\"" << assigned.name()
                  << "\", record=" << assigned.recordContent() << '\n';
    }

    return 0;
}
