#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

#include "Record.h"

class Person {
public:
    explicit Person(std::string name = "") : name_(std::move(name)) {}
    const std::string& name() const { return name_; }
protected:
    std::string name_;
};

class Employee : public Person {
public:
    explicit Employee(const std::string& name = "employee")
        : Person(name), pRecord_(new Record(name)) {}

    Employee(const Employee& rhs)
        : Person(rhs),
          pRecord_(new Record(*rhs.pRecord_)) {}

    ~Employee() { delete pRecord_; }

    Employee& operator=(const Employee& rhs) {
        Person::operator=(rhs);

        Record* pOrig = pRecord_;
        pRecord_ = new Record(*rhs.pRecord_);
        delete pOrig;

        return *this;
    }

    const std::string& recordContent() const { return pRecord_->content(); }

private:
    Record* pRecord_;
};

#endif
