cmake_minimum_required(VERSION 3.30)
project(IoT_Spring_2025 C)

set(CMAKE_C_STANDARD 11)

add_executable(IoT_Spring_2025 main.c
        "Assignments/Assignment 1.c"
        cmake-build-debug/main.c
        Notes/Basics/datatypes.c
        Notes/Basics/formatspecifiers.c
        Notes/Basics/helloworld.c
        Notes/Basics/variables.c
        Notes/Functions/functions.c
        Notes/Inputs/roomtempconv.c
        Notes/Inputs/userinput.c
        Notes/Math/arithmeticoperators.c
        Notes/Math/augmentedarioperators.c
        Notes/Math/calculatorprogram.c
        Notes/Math/circlecircum.c
        Notes/Math/constants.c
        Notes/Math/hypotenusecalc.c
        Notes/Math/mathfunctions.c
        Notes/Statements/ifstatements.c
        Notes/Statements/logicaloperators.c
        Notes/Statements/switchstatements.c
        "Assignments/Assignment 2.c"
        "Assignments/Assignment 3.c"
        "Assignments/Assignment 4.c"
        Notes/Pointers/pointers.c
        "Assignments/Assignment 7.c"
        "Assignments/Assignment 8.c"
        "Assignments/Assignment 9.c")
