# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MySQLConnectorCExample VERSION 1.0)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Find MySQL C library
set(MYSQL_C_DIR "C:/Program Files/MySQL/MySQL Server 8.0") # Replace with your actual path

# Include directories for MySQL C API
include_directories(${MYSQL_C_DIR}/include)

# Library directories for MySQL C API
link_directories(${MYSQL_C_DIR}/lib)

# Add the executable (source file)
add_executable(MySQLConnectorCExample main.c) # Assuming your source file is main.c for C language

# Link the MySQL C library
target_link_libraries(MySQLConnectorCExample mysqlclient.lib)