cmake_minimum_required(VERSION 3.29)
project(BankingApp)

set(CMAKE_CXX_STANDARD 20)

add_executable(BankingApp main.cpp
        InvestmentCalculator.cpp
        InvestmentCalculator.h)
