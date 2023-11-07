#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "Time.h"

int main(int argc, char* argv[])
{
    //std::cout << Clock{}.fromString(":::").toString() << std::endl;
    return Catch::Session{}.run(argc, argv);
}
