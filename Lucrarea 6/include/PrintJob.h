#ifndef PRINT_JOB_H
#define PRINT_JOB_H

#include <memory>
#include <string>

#include "PrinterResource.h"

inline std::unique_ptr<PrintJobHandle, decltype(&finishPrintJob)>
makeManagedPrintJob(const std::string& document) {
    return {startPrintJob(document), &finishPrintJob};
}

#endif
