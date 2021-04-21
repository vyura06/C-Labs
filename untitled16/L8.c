#include <sys/io.h>
#include "pci_c_header.h"
#include <stdio.h>
#include <stdbool.h>

void print(unsigned int regRes) {
    unsigned short int venID;
    unsigned short int devID;
    bool venIsFound, DevIsFound;

    venID = regRes;
    devID = regRes >> 16;
    int i;
    venIsFound = false;
    for (
            i = 0;
            ((!venIsFound) && (i < PCI_VENTABLE_LEN)); i++) {
        if (venID == PciVenTable[i].VenId) {
            printf("Vendor ID: %04x %s;\n", venID, PciVenTable[i].VenFull);
            venIsFound = true;
        }
    }
    if (venIsFound) {
        DevIsFound = false;
        for (
                i = 0;
                ((!DevIsFound) && (i < PCI_DEVTABLE_LEN)); i++) {
            if (devID == PciDevTable[i].DevId) {
                printf("Device ID: %04x %s;\n", devID, PciDevTable[i].ChipDesc);
                DevIsFound = true;
            }
        }
        if (!DevIsFound) printf("Device ID: %04x Device not found;\n", devID);
    } else printf("Vendor ID: %04x Vendor not found\n", venID);
}

bool isBridge(unsigned int mainAdr) {
    unsigned int regAdr;
    unsigned char regRes;
    regAdr = mainAdr + 0x0C;
    outl(regAdr, 0xCF8);
    regRes = (char) (inl(0xCFC) >> 16);
    return regRes != 0;
}

void seven(unsigned int mainAdr) {
    if (!isBridge(mainAdr)) {
        unsigned int regAdr, regRes;
        regAdr = mainAdr + 0x3C;
        outl(regAdr, 0x0CF8);
        regRes = inl(0xCFC);
        unsigned char intLine;
        intLine = regRes;
        printf("Interrupt Line : %02x\n", intLine);
    }
}

void six(unsigned int mainAdr) {
    if (!isBridge(mainAdr)) {
        unsigned int regAdr, regRes;
        regAdr = mainAdr + 0x3C;
        outl(regAdr, 0x0CF8);

        regRes = inl(0xCFC);
        unsigned char intPin;
        intPin = regRes >> 8;
        printf("Interrupt Pin : %02x\n", intPin);
    }
}

void two(unsigned int mainAdr) {
    if (!isBridge(mainAdr)) {
        unsigned int regAdr = mainAdr + 0x20;
        outl(regAdr, 0xCF8);
        unsigned int regRes = inl(0xCFC);
        unsigned char memoryBase = regRes;
        printf("Memory base: %04x\n", memoryBase);
        regAdr = mainAdr + 0x24;
        outl(regAdr, 0xCF8);
        regRes = inl(0xCFC);
        memoryBase = regRes;
        printf("Prefetchable memory base: %04x\n", memoryBase);
    }
}

int main() {
    if (iopl(3)) {
        printf("Error. Try running under ROOT user\n");
        return 1;
    }
    unsigned int regAdr, mainAdr, regRes;
    int busNum, deviceNum, funcNum;
    for (busNum = 0; busNum < 256; busNum++) {
        for (deviceNum = 0; deviceNum < 32; deviceNum++) {
            for (funcNum = 0; funcNum < 8; funcNum++) {
                mainAdr = (1 << 31) + (busNum << 16) + (deviceNum << 11) + (funcNum << 8);
                regAdr = mainAdr;
                outl(regAdr, 0xCF8);
                regRes = inl(0xCFC);
                if (((regRes >> 16) != 0xFFFF) && (regRes != 0)) {
                    printf("%d : %0d : %d\n", busNum, deviceNum, funcNum);
                    print(regRes);
                    two(mainAdr);
                    six(mainAdr);
                    seven(mainAdr);
                    printf("-------------------------------------------------------------------------\n");
                }
            }
        }
    }