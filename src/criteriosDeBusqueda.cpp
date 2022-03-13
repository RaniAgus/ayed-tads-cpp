#include <iostream>

using namespace std;

int criterioAZ(string e1, string e2) {
    return e1 > e2 ? 1 : e1 < e2 ? -1 : 0;
}

int criterioZA(string e1, string e2) {
    return e2 > e1 ? 1 : e2 < e1 ? -1 : 0;
}

int criterio09(int e1, int e2) {
    return e1 - e2;
}

int criterio90(int e1, int e2) {
    return e2 - e1;
}
