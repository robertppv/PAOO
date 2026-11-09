#include "resource.h"

#include <iostream>
#include <string>

int main() {
    std::string newObject("object1");
    std::string oldObject("object2");
    NamedObject p(newObject, 2);
    NamedObject s(oldObject, 36);

    // p = s;

    // NamedObject c(p);

    std::cout << "NamedObjects created: " << NamedObject::created() << '\n';

    return 0;
}
