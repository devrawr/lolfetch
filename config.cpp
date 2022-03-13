#include "config.h"

const std::string WHITESPACE = " \n\r\t\f\v";

// didn't make this myself! found on github, https://gist.github.com/meritozh/f0351894a2a4aa92871746bf45879157.
std::string exec(const char* cmd) {
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);

    if (!pipe)
    {
      return "ERROR";
    }

    char buffer[128];
    std::string result = "";

    while (!feof(pipe.get())) {
        if (fgets(buffer, 128, pipe.get()) != NULL)
        {
            result += buffer;
        }
    }

    return result;
}

std::string trimRight(std::string str)
{
    return str.erase(str.find_last_not_of(WHITESPACE) + 1);
}

std::vector<OperatingSystem*> getOperatingSystems()
{
    return {
    new LinuxOperatingSystem(
        "arch",
        "Arch Linux",
        [=]() -> std::string {
            return trimRight(exec("pacman -Qq | wc -l")) + " (pacman)";
        }
    ),

    new LinuxOperatingSystem(
        "gentoo",
        "Gentoo Linux",
        [=]() -> std::string {
            return trimRight(exec("ls -d /var/db/pkg/*/* | wc -l"));
        }
    )
};
}
