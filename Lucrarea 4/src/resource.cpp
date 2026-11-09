#include "resource.h"

std::size_t& NamedObject::registry() {
    static std::size_t count = 0;
    return count;
}

NamedObject::NamedObject(std::string& name, int value)
    : nameValue(name), objectValue(value) {
    ++registry();
}

std::size_t NamedObject::created() {
    return registry();
}
