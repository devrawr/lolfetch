#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <memory>

class OperatingSystem
{
    public:
        std::string id;
        std::string display;

        OperatingSystem() {}
        OperatingSystem(std::string id, std::string display)
        {
            this->id = id;
            this->display = display;
        }

        void printData()
        {
            std::vector<std::string> details = this->getDetails();
            std::vector<std::string> ascii = this->getAsciiArt();

            // loop through ascii, considering the ascii should always be on the left.
            for (int i = 0; i < ascii.size(); i++)
            {
                std::string ascii_line = ascii[i];

                // if there are less details than lines of ascii,
                // simply print the current ascii line. we're out of
                // details
                if (details.size() < i + 1)
                {
                    std::cout << ascii_line << std::endl;
                }
                else
                {
                    std::string line = ascii_line;

                    line += " ";
                    line += details[i];

                    // print now so we don't have to loop through the vector again
                    std::cout << line << std::endl;
                }
            }
        }

        virtual bool matchesCurrentOs() {
            return false;
        }

        virtual std::vector<std::string> getAsciiArt();
        virtual std::vector<std::string> getDetails();
};

class LinuxOperatingSystem : public OperatingSystem
{
    public:
        LinuxOperatingSystem(std::string id, std::string display)
        {
            this->id = id;
            this->display = display;
        }

        std::vector<std::string> getDetails() override
        {
            // todo: implement methods to fetch these details
            return {
            "id: " + this->id,
            "shell: loksh",
            "wm: gnome-shell",
            "packages: 73"
        };
        }

        // epic penguin tux ascii art! made by Przemek Borys
        std::vector<std::string> getAsciiArt() override
        {
            return {
            "   .--.      ",
            "   |o_o |    ",
            "   |:_/ |    ",
            "  //   \\ \\   ",
            " (|     | )  ",
            "/'\\_   _/`\\  ",
            "\\___)=(___/  ",
        };
        }

        bool matchesCurrentOs() override
        {
            FILE* file = fopen("/etc/os-release", "r");

            if (file == nullptr)
            {
                return false;
            }

            fseek(file, 0, SEEK_END);

            size_t size = ftell(file);
            char* where = new char[size];

            rewind(file);
            fread(where, sizeof(char), size, file);

            return std::string(where).find(this->id) != 0;
        }
};

std::vector<OperatingSystem*> getOperatingSystems();
