#ifndef __GENERIC_EXCEPTION_HPP__
#define __GENERIC_EXCEPTION_HPP__
#include <exception>
#include <string>

class GenericException : public std::exception {
public:
    inline GenericException(const std::string& message) : m_message(message) {}

    inline const char* what() const noexcept override {
        return m_message.c_str();
    }

private:
    std::string m_message;
};
#endif