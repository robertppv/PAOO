#include "PrintJob.h"
#include "PrinterLock.h"

int main() {
    {
        auto job = makeManagedPrintJob("report.pdf");
        (void)job;
    }

    {
        Printer p{"office-laser"};
        PrinterLock guard(&p);
        (void)guard;
    }

    {
        Printer p{"label-printer"};
        SharedPrinterLock a(&p);
        {
            SharedPrinterLock b(a);
            (void)b;
        }
        (void)a;
    }

    return 0;
}
