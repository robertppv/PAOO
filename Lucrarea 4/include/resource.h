#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <cstddef>

class NamedObject {
public:
    NamedObject(std::string& name, int value);

    NamedObject(const NamedObject&) = delete;

    const std::string& name() const { return nameValue; }
    int value() const { return objectValue; }

    static std::size_t created();

private:
    std::string& nameValue;
    const int    objectValue;

    static std::size_t& registry();
};

#endif
