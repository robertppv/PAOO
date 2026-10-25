#include "Buffer.hpp"

#include <iostream>
#include <stdexcept>

Buffer::Buffer(std::size_t size)
    : m_data(new int[size]),
      m_size(size)
{
    for (std::size_t i = 0; i < m_size; ++i) {
        m_data[i] = 0;
    }
    std::cout << "[Constructor]      Buffer de " << m_size
              << " elemente, alocat la adresa " << m_data << '\n';
}

Buffer::~Buffer()
{
    std::cout << "[Destructor]       Eliberez adresa " << m_data
              << " (" << m_size << " elemente)\n";
    delete[] m_data;
}

Buffer::Buffer(const Buffer& other)
    : m_data(new int[other.m_size]),
      m_size(other.m_size)
{
    for (std::size_t i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
    std::cout << "[Copy constructor] Copiez " << m_size
              << " elemente de la " << other.m_data
              << " in blocul nou " << m_data << '\n';
}

Buffer::Buffer(Buffer&& other) noexcept
    : m_data(other.m_data),
      m_size(other.m_size)
{
    other.m_data = nullptr;
    other.m_size = 0;
    std::cout << "[Move constructor] Mut resursa " << m_data
              << " (" << m_size << " elemente), fara copiere\n";
}

void Buffer::set(std::size_t index, int value)
{
    if (index >= m_size) {
        throw std::out_of_range("Buffer::set - index in afara limitelor");
    }
    m_data[index] = value;
}

int Buffer::get(std::size_t index) const
{
    if (index >= m_size) {
        throw std::out_of_range("Buffer::get - index in afara limitelor");
    }
    return m_data[index];
}

std::size_t Buffer::size() const
{
    return m_size;
}

void Buffer::fill(int value)
{
    for (std::size_t i = 0; i < m_size; ++i) {
        m_data[i] = value;
    }
}
