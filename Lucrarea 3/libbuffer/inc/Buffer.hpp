#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <cstddef> 

class Buffer {
public:

    explicit Buffer(std::size_t size);

    ~Buffer();

    Buffer(const Buffer& other);

    Buffer(Buffer&& other) noexcept;

    void        set(std::size_t index, int value);
    int         get(std::size_t index) const;
    std::size_t size() const;
    void        fill(int value);

private:

    int*        m_data;
    std::size_t m_size;
};

#endif
