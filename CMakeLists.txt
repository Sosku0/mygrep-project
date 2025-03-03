cmake_minimum_required(VERSION 3.21)
project(mygrep_project)

# ISO C++17 asetukset
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Lähdekoodin tiedostojen lisäys
file(GLOB_RECURSE SOURCES cpp/*.cpp main.cpp)
add_executable(mygrep_project ${SOURCES})

# Asennuspolku
install(TARGETS mygrep_project DESTINATION bin)

# Build-konfiguraatioiden liput
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Esimerkki ulkoisesta kirjastosta (jos tarpeen)
# find_package(SomeLibrary REQUIRED)
# target_link_libraries(mygrep_project PRIVATE SomeLibrary::SomeLibrary)