#ifndef TXTPARSER_H
#define TXTPARSER_H

#include "abstractcalculator.h"

class TXTParser : public AbstractCalculator
{
public:
    TXTParser();
    ~TXTParser() override;

    QVector<int> parse(const QString &filePath) override;
    void write(const QString &savePath, QVector<int> result) override;
};

#endif // TXTPARSER_H
