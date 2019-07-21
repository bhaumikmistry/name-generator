#ifndef GENERATOR_H
#define GENERATOR_H

#include "sub.h"
#include <vector>
#include <memory>

class generator
{
private:
    bool NAME_GENERATED = true;

    std::vector<std::shared_ptr<sub>> m_name_sequence;
    sub m_name;

public:
    generator(){}
    virtual ~generator(){}
protected:
    void AddToSequence( std::shared_ptr<sub> item)
    {
        this->m_name_sequence.push_back(item);
    }
    void ClearSequence()
    {
        this->m_name_sequence.clear();
    }
    std::vector<std::shared_ptr<sub>> GetNameSequence()
    {
        return m_name_sequence;
    }
    virtual void UpdateSequence(){}
public:
    std::string Get(bool force=false)
    {

        if(!this->m_name || force)
        {
            Generate();
        }
        return this->m_name.m_value;
    }
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

