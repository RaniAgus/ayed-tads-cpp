#include "criteriosDeBusqueda.h"

int criterioAZ(std::string e1, std::string e2) {
    return e1 > e2 ? 1 : e1 < e2 ? -1 : 0;
}

int criterioZA(std::string e1, std::string e2) {
    return e2 > e1 ? 1 : e2 < e1 ? -1 : 0;
}

int criterio09(int e1, int e2) {
    return e1 - e2;
}

int criterio90(int e1, int e2) {
    return e2 - e1;
}
