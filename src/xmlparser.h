#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <abstractcalculator.h>
#include <QString>
#include <QVector>

class XMLParser : public AbstractCalculator {

public:
    XMLParser();
    ~XMLParser();

    QVector<int> parse(const QString &filePath) override;
    void write(const QString &savePath, QVector<int> result) override;

};

#endif // XMLPARSER_H
