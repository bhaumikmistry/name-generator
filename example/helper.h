#ifndef HELPER_H
#define HELPER_H
#include <iostream>

/**
 * @brief log
 * used for basic logs with file and line name.
 * @param data
 * @param level
 * @param file
 * @param line
 */
void log(char * data,char * level,const char * file,int line)
{
    std::cout << "[" << level << "] ";
    std::cout << data << " (" <<file << ":" << line << ")" << std::endl;
}

#define log_debug(message) log(message,"debug",__FILE__,__LINE__)
#define log_error(message) log(message,"error",__FILE__,__LINE__)
#define log_warning(message) log(message,"warning",__FILE__,__LINE__)
#define log_notify(message) log(message,"notify",__FILE__,__LINE__)
#define log_fatal(message) log(message,"fatal",__FILE__,__LINE__)

#endif // HELPER_H
