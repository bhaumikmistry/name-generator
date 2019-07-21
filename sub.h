#ifndef SUB_H
#define SUB_H

#include <string>

/**
 * @brief The sub struct
 * holds information about a piece
 * or a section of name with
 * binary option to use this sub
 * section or not while generating
 * the final name.
 */
struct sub
{
    sub()
    {}
    sub(bool use,std::string value)
        :m_to_use(use),
          m_value(value)
    {}

    /*
     * Used to check if this sub is
     * active or not while generating
     * name
     */
    bool m_to_use;
    /*
     * Storage of the value to be
     * added in the name
     */
    std::string m_value;

    /*
     */

    /**
     * @brief operator =
     * @param use bool
     * Operator for the object of
     * sub to be assinged a bool
     * value directly
     */
    void operator=(bool use)
    {
        m_to_use = use;
    }

    /**
     * @brief operator +=
     * @param value
     * Operator for the object of
     * sub to add string value to
     * the internal storage value
     * directly
     */
    void operator+=(std::string value)
    {
        m_value += value;
    }

    /**
     * @brief operator =
     * @param value
     * Operator for the object of
     * sub to be assigned string
     * value directly
     */
    void operator=(std::string value)
    {
        m_value = value;
    }

    /**
     * @brief operator bool
     * Object of sub can be used
     * as a bool which should refect
     * same as if the bool value is
     * checked.
     *
     * e.g
     *
     * sub s;
     * if(s.to_use)
     * is same as
     * if(s)
     */
    explicit operator bool()
    {
        return m_to_use;
    }
};

#endif // SUB_H
