#include <LoremIpsum/LoremIpsum.hpp>

#include <iostream>

int main(/*int argc, char** argv*/) {
    std::cout << "main called" << std::endl;
    loremipsum::Lorem lorem;
    std::cout << lorem.ipsum() << std::endl;
    return 0;
}
