
#include "utilities.h"

Utilities::Utilities(){}
Utilities::~Utilities(){}

// convert int to string
string Utilities::itos(int i)
{
    stringstream s;
    s << i;
    return s.str();
}

QString Utilities::itoqs(int i)
{
    stringstream s;
    s << i;
    string temp = s.str();
    QString ret = temp.c_str();
    return ret;
}
