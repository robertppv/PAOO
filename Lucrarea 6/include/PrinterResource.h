#ifndef PRINTER_RESOURCE_H
#define PRINTER_RESOURCE_H

#include <iostream>
#include <string>

struct PrintJobHandle {
    std::string document;
};

inline PrintJobHandle* startPrintJob(const std::string& document) {
    std::cout << "construct : " << document << '\n';
    return new PrintJobHandle{document};
}

inline void finishPrintJob(PrintJobHandle* j) {
    if (j) {
        std::cout << "destruct  : " << j->document << '\n';
        delete j;
    }
}

#endif
