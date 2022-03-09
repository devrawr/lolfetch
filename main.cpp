#include <iostream>
#include "config.h"

int main()
{
    for (OperatingSystem* system : getOperatingSystems())
    {
        if (system->matchesCurrentOs())
        {
            system->printData();
            break;
        }
    }

    return 0;
}
