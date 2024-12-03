# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MySQLConnectorCppExample VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find MySQL Connector/C++ library
set(MYSQL_CONNECTOR_CPP_DIR "D:/MySoft/mysql-connector-c++-8.0.33-winx64") # Replace with your actual path

# Include directories for MySQL Connector
include_directories(${MYSQL_CONNECTOR_CPP_DIR}/include/jdbc)

# Library directories for MySQL Connector
link_directories(${MYSQL_CONNECTOR_CPP_DIR}/lib64)
link_directories(${MYSQL_CONNECTOR_CPP_DIR}/lib64/vs14)

# Add the executable (source file)
add_executable(MySQLConnectorCppExample main.cpp)

# Link the MySQL Connector library
target_link_libraries(MySQLConnectorCppExample mysqlcppconn)
