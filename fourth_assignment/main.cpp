/// @file Main.cpp
/// @brief - Runs the Program.
/// @author Ryan Jewik - jewik@chapman.edu

#include <string>
#include <iostream>
using namespace std;

#include "ServiceCenter.h"

int main(int argc, char** argv)
{

    ServiceCenter sc(argv[1]);
    return 0;
}
