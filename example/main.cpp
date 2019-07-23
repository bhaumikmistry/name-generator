#include <iostream>
#include "helper.h"

#include "../generator.h"
class testName : public generator
{
public:
    sub name = {true,"name"};
    sub time = {true,"time"};
    sub good = {true,"good"};

    testName(){}
    ~testName(){}

    void UpdateSequence() override
    {
        this->ClearSequence();
        this->AddToSequence(std::make_shared<sub>(name));
        this->AddToSequence(std::make_shared<sub>(time));
        this->AddToSequence(std::make_shared<sub>(good));
    }
};

int main()
{
   log_debug(" main()");

   testName tn;
   std::string name = tn.Get();

    return 0;
}
