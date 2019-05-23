#include "txtparser.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

TXTParser::TXTParser() {}

TXTParser::~TXTParser() {}

QVector<int> TXTParser::parse(const QString &filePath) {
    QVector<int> vector;

    QFile *file = new QFile(filePath);

    if(!file->open(QIODevice::ReadOnly | QIODevice::Text)) {}

    QTextStream qts(file);
    while(!qts.atEnd()) {
        int num0;
        qts >> num0;

        int num1;
        qDebug() << num0;

        vector.push_back(num0);

        char operat;
        qts >> operat;

        if(operat == ' ') {
            qts >> operat;
            qDebug() << operat;
        }
        if(operat == '+') {
            vector.push_back(0);
            qts >> num1;
            vector.push_back(num1);
            vector.push_back(sum(num0, num1));
        }
        else if(operat == '-') {
            vector.push_back(1);
            qts >> num1;
            vector.push_back(num1);
            vector.push_back(diff(num0, num1));
        }
        else if(operat == '*') {
            vector.push_back(2);
            qts >> num1;
            vector.push_back(num1);
            vector.push_back(mult(num0, num1));
        }
        else if(operat == '/') {
            vector.push_back(3);
            qts >> num1;
            vector.push_back(num1);
            vector.push_back(div(num0, num1));
        }
    }
    return vector;
}

void TXTParser::write(const QString &savePath, QVector<int> result) {
    QFile *file = new QFile(savePath);

    if(!file->open(QIODevice::WriteOnly | QIODevice::Text)) {};

    QTextStream qts(file);
    for(int i = 0; i < result.size()-2; i+=4) {
        qts << result[i];
        qts << " ";
        switch (result[i+1]) {
        case 0:
            qts << "+ ";
            break;
        case 1:
            qts << "- ";
            break;
        case 2:
            qts << "* ";
            break;
        case 3:
            qts << "/ ";
            break;
        }

        qts << result[i+2];
        qts << " = ";
        qts << result[i+3];
        qts << "\n";
    }
}
