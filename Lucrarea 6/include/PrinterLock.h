#ifndef PRINTER_LOCK_H
#define PRINTER_LOCK_H

#include <iostream>
#include <memory>

#include "Printer.h"

class PrinterLock {
public:
    explicit PrinterLock(Printer* p) : printerPtr_(p) { acquirePrinter(printerPtr_); }
    ~PrinterLock() { releasePrinter(printerPtr_); }

    PrinterLock(const PrinterLock&) = delete;
    PrinterLock& operator=(const PrinterLock&) = delete;

private:
    Printer* printerPtr_;
};

class SharedPrinterLock {
public:
    explicit SharedPrinterLock(Printer* p) : printerPtr_(p, releasePrinter) {
        acquirePrinter(p);
        std::cout << "acquire : " << p->name
                  << " (owners: " << printerPtr_.use_count() << ")\n";
    }

    SharedPrinterLock(const SharedPrinterLock& other) : printerPtr_(other.printerPtr_) {
        std::cout << "copy    : " << printerPtr_->name
                  << " (owners: " << printerPtr_.use_count() << ")\n";
    }

    ~SharedPrinterLock() {
        std::cout << "destroy : " << printerPtr_->name
                  << " (owners before: " << printerPtr_.use_count() << ")\n";
    }

    long owners() const { return printerPtr_.use_count(); }

private:
    std::shared_ptr<Printer> printerPtr_;
};

#endif
