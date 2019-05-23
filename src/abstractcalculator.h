#ifndef INTERFACECALCULATOR_H
#define INTERFACECALCULATOR_H

#include <QString>
#include <QVector>


class AbstractCalculator {
public:
    static AbstractCalculator* getConstructorByPath(const QString &filePath);

    virtual ~AbstractCalculator();

    virtual void write(const QString &savePath, QVector<int> result) = 0;
    virtual QVector<int> parse(const QString &filePath) = 0;
protected:
    AbstractCalculator();

    virtual int sum(int a, int b);
    virtual int div(int a, int b);
    virtual int mult(int a, int b);
    virtual int diff(int a, int b);
};

#endif // INTERFACECALCULATOR_H
