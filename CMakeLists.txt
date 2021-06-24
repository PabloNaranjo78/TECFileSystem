cmake_minimum_required(VERSION 3.19)
project(Proyecto_III)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/home/rewieer/Libraries/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib")
set(SFML_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)


add_executable(Proyecto_III main.cpp Display/Display.cpp Display/Display.h Display/Button.cpp Display/Button.h Display/fileSprite.cpp Display/fileSprite.h Display/TextBox.cpp Display/TextBox.h ceRobot/ceRobot.cpp ceRobot/ceRobot.h ceSearch/ceSearch.cpp ceSearch/ceSearch.h HuffmanCode/CharacterCounter/CharacterCounter.cpp HuffmanCode/CharacterCounter/CharacterCounter.h HuffmanCode/HCBinaryTree/HCBinaryTree.cpp HuffmanCode/HCBinaryTree/HCBinaryTree.h HuffmanCode/CharacterCounter/CharacterList/CharacterList.cpp HuffmanCode/CharacterCounter/CharacterList/CharacterList.h HuffmanCode/CharacterCounter/CharacterListNode/CharacterListNode.cpp HuffmanCode/CharacterCounter/CharacterListNode/CharacterListNode.h RAID/Books/Converter.cpp RAID/Books/Converter.h RAID/Books/XOR.cpp RAID/Books/XOR.h RAID/DiskNode.cpp RAID/DiskNode.h RAID/ControllerNode.cpp RAID/ControllerNode.h RAID/File.cpp RAID/File.h RAID/TinyXml/tinyxml2.cpp RAID/TinyXml/tinyxml2.h)


find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()


target_link_libraries (Proyecto_III sfml-graphics sfml-window sfml-system sfml-network)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})