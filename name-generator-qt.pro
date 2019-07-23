TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11
HEADERS += generator.h\
        sub.h
DESTDIR += $$PWD/Lib/
Release:TARGET = generator
Debug:TARGET = generator_d
