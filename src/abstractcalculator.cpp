#include "abstractcalculator.h"
#include "xmlparser.h"
#include "txtparser.h"

#include <QFileInfo>
#include <qfile.h>

AbstractCalculator::AbstractCalculator() {

}

AbstractCalculator::~AbstractCalculator() {

}

AbstractCalculator* AbstractCalculator::getConstructorByPath(const QString &filePath) {
    QFileInfo qfli(filePath);
    if(qfli.completeSuffix() == "xml") {
        XMLParser *xml = new XMLParser();
        return xml;

    }
    else if(qfli.completeSuffix() == "txt") {
        TXTParser *txt = new TXTParser();
        return txt;
    }
}

int AbstractCalculator::sum(int a, int b) {
    return a+b;
}

int AbstractCalculator::diff(int a, int b) {
    return a-b;
}

int AbstractCalculator::mult(int a, int b) {
    return a*b;
}

int AbstractCalculator::div(int a, int b) {
    return a/b;
}

