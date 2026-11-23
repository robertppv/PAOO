#ifndef RECORD_H
#define RECORD_H

#include <string>

class Record {
public:
    explicit Record(std::string content = "empty")
        : content_(std::move(content)) {}

    Record(const Record& other)
        : content_(other.content_ + "_copy") {}

    ~Record() = default;

    const std::string& content() const { return content_; }

private:
    std::string content_;
};

#endif
