#include <iostream>
#include "helper.h"

#include "generator.h"

int main()
{
    log_debug(" main()");

    basicName bn;
    std::string name = bn.Get();

    bn.name= true;
    bn.name= "new_name";
    bn.time= false;

    std::string new_name = bn.Get(true);

    return 0;
}
