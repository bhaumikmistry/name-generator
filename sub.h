#ifndef SUB_H
#define SUB_H

#include <string>

struct sub
{
    sub()
    {}
    sub(bool use,std::string value)
        :m_to_use(use),
          m_value(value)
    {}

    bool m_to_use;
    std::string m_value;

    void operator=(bool use)
    {
        m_to_use = use;
    }

    void operator+=(std::string value)
    {
        m_value += value;
    }

    void operator=(std::string value)
    {
        m_value = value;
    }

    explicit operator bool()
    {
        return m_to_use;
    }
};

#endif // SUB_H
