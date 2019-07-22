TEMPLATE = lib
CONFIG += c++11
HEADERS += generator.h\
        sub.h
DESTDIR += $$PWD/Lib/
Release:TARGET = libgenerator
Debug:TARGET = libgenerator_d
