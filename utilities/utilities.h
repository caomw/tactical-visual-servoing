
#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <sstream>
#include <string>

#include <QString>

using namespace std;

class Utilities
{
    public:

        Utilities();
        ~Utilities();

        string itos(int i);
        QString itoqs(int i);

    private:
};

#endif
