cmake_minimum_required(VERSION 3.25)
project(cpp2mlir)

set(CMAKE_CXX_STANDARD 23)

add_executable(cpp2mlir main.cpp
        mlir/Operator.h
        mlir/model.h
        mlir/ValueId.h
        mlir/Block.h
        mlir/Attribute.h
        mlir/ValueId.cpp)
