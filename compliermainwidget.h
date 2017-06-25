#ifndef COMPLIERMAINWIDGET_H
#define COMPLIERMAINWIDGET_H

#include <QWidget>
#include "parser.h"
#include <QDebug>
#include <QQueue>
#include <QFile>
#include <QtAlgorithms>
#include <QMessageBox>
#include <QDir>
#include <QRegExp>
#include <QMap>
#include <QMapIterator>


#include <exception>
#include <sstream>


using namespace std;


namespace Ui {
class ComplierMainWidget;
}

class ComplierMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ComplierMainWidget(QWidget *parent = 0);
    ~ComplierMainWidget();
public:
    QString TokenizeString( QQueue<QString> &Tokens, QString LineToParse);
private:
    Ui::ComplierMainWidget *ui;

private:
    Parser mParser;
    QQueue<QString> Tokens;
    QString Commands;
    QMap <QString,QString>BiteCode;
};

#endif // COMPLIERMAINWIDGET_H
