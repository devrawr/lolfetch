#include "config.h"

std::vector<OperatingSystem*> getOperatingSystems()
{
    return {
    new OperatingSystem("hey", "hey"),
    new LinuxOperatingSystem("arch", "Arch Linux")
};
}
