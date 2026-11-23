#ifndef PRINTER_H
#define PRINTER_H

#include <string>

struct Printer {
    std::string name;
};

inline void acquirePrinter(Printer* p) {
    (void)p;
}

inline void releasePrinter(Printer* p) {
    (void)p;
}

#endif
