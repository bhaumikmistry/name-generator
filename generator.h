#ifndef GENERATOR_H
#define GENERATOR_H

#include "sub.h"
#include <vector>
#include <memory>

/**
 * @brief The generator class
 * Generator class that holds all the basic and
 * virtual methods that needs to be derived.
 */
class generator
{
private:
    /* used to set the sub name generator when the
     * name is generated.
     */
    bool NAME_GENERATED = true;

    /* holds all the sub pointers to be used while
     * generating the final file name
     */
    std::vector<std::shared_ptr<sub>> m_name_sequence;

    /* generated file name holder
     */
    sub m_name;

public:
    generator(){}
    virtual ~generator(){}

protected:
    /**
     * @brief AddToSequence
     * @param item std::shared_ptr<sub>
     * used to update the sequence vector for
     * name generator
     */
    void AddToSequence(std::shared_ptr<sub> item)
    {
        this->m_name_sequence.push_back(item);
    }

    /**
     * @brief ClearSequence
     * To empty sub sequence vector
     */
    void ClearSequence()
    {
        this->m_name_sequence.clear();
    }

    /**
     * @brief UpdateSequence
     * To be used to update sequence, this
     * method is being called by the Generate()
     * which needs to implemented in derived
     * class
     */
    virtual void UpdateSequence(){}

public:
    /**
     * @brief Get
     * interface to get the generated name
     * @param force
     * @return std::string name
     */
    std::string Get(bool force=false)
    {

        if(!this->m_name || force)
        {
            Generate();
        }
        return this->m_name.m_value;
    }
    /**
     * @brief Generate
     * Implements of the generating name on
     * demand if the name has not been generated.
     */
    void Generate()
    {
        this->UpdateSequence();
        this->m_name = NAME_GENERATED;
        this->m_name = std::string("");
        for(auto string_to_add : m_name_sequence)
        {
            if(string_to_add->m_to_use)
                this->m_name+=string_to_add->m_value;
        }
    }

};

class basicName : public generator
{
public:
    sub name={true,"basicName"};
    sub time={true,"1970"};

    basicName(){}
    ~basicName() override
    {}

    void UpdateSequence() override
    {
        this->ClearSequence();
        this->AddToSequence(std::make_shared<sub>(name));
        this->AddToSequence(std::make_shared<sub>(time));
    }


};

#endif // GENERATOR_H

