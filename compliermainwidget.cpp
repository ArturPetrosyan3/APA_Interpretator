#include "compliermainwidget.h"
#include "ui_compliermainwidget.h"

ComplierMainWidget::ComplierMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComplierMainWidget)
{
    ui->setupUi(this);
    QString PathToInput = QDir::currentPath();
    PathToInput.append("/Source.apa");
    qDebug() << PathToInput;
    QString PathToOutput = QDir::currentPath();
    PathToOutput.append("/variable.obj");
    qDebug() << PathToOutput;

    QFile Input(PathToInput);
    QFile Output(PathToOutput);
    if (!Input.open(QIODevice::ReadOnly | QIODevice::Text))
         return;
    if (!Output.open(QIODevice::ReadWrite | QIODevice::Text))
         return;

    QTextStream in(&Input);
    QTextStream out(&Output);
    out << "//  The BiteCode Code "<< "\n";

    while (!in.atEnd()) {
        QString Line = in.readLine();
        int v_latin;
        QChar c;
        if (Line != "") {
            c = Line.at(0);
            v_latin = c.toLatin1();
        } else {
            continue;
        }
        if (v_latin == 9) {
              //Line.erase(0,1);
              Line.remove(0,1);
        }
        if (Line != "") {
            c = Line.at(0);
            v_latin = c.toLatin1();
        } else {
            continue;
        }
        switch (v_latin) {
        case 0:
            break;
        case 9:
            break;
        default:
            QString VariableKeyAndValue;
            Commands = TokenizeString(Tokens, Line);
            BiteCode = mParser.ParseToken(Tokens);
            //out
            QMap<QString, QString>::iterator i;
            for (i = BiteCode.begin(); i != BiteCode.end(); ++i) {
                VariableKeyAndValue.append(i.key());
                VariableKeyAndValue.append("=");
                VariableKeyAndValue.append(i.value());
            }
            out << VariableKeyAndValue << " //" << Commands << "\n";
            break;
        }
    }

}

QString ComplierMainWidget::TokenizeString( QQueue<QString> &Tokens, QString LineToParse) {
    LineToParse.remove(QRegExp("[\t]"));
    LineToParse.remove(QRegExp("[,]"));
    LineToParse.remove(QRegExp("[$]"));
    QChar CommentCharacter = '#';
    int CommentIndex = LineToParse.indexOf('#');
    if (CommentIndex != -1) {
        LineToParse.remove(CommentIndex,LineToParse.size());
    }
    QStringList list = LineToParse.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    foreach (QString item, list) {
        Tokens.push_back(item);
    }
    return LineToParse;
}

ComplierMainWidget::~ComplierMainWidget()
{
    delete ui;
}
