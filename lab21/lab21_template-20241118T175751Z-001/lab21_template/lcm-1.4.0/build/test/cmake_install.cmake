# Install script for directory: /home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/test

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/rajat/.local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/test/gtest/cmake_install.cmake")
  include("/home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/test/types/cmake_install.cmake")
  include("/home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/test/c/cmake_install.cmake")
  include("/home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/test/cpp/cmake_install.cmake")
  include("/home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/test/python/cmake_install.cmake")
  include("/home/rajat/502_lab/lab21/lab21_template-20241118T175751Z-001/lab21_template/lcm-1.4.0/build/test/lua/cmake_install.cmake")

endif()

