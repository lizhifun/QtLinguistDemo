#include "mainwindow.h"

#include <QApplication>
#include <QSettings>
#include <QTranslator>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //多语言
    QTranslator *translator = new QTranslator();
    QSettings *settings = new QSettings("./SystemSettings.ini", QSettings::IniFormat);
    QString language = settings->value("language", "Chinese").toString();//读取文件中保存的语言设置
    qDebug() << "language>>> " << language;
    delete settings;
    if(language == "Chinese")
    {
        bool res = translator->load("./QtLinguist_zh_CN.qm");//加载中文语言文件
        qDebug() << "res>>> " << res;
        a.installTranslator(translator);//将翻译家应用到程序中
    }
    else
    {
        bool res = translator->load("./QtLinguist_zh_EN.qm");//加载英文语言文件
        qDebug() << "res>>> " << res;
        a.installTranslator(translator);//将翻译家应用到程序中
    }

    MainWindow w;
    w.show();
    return a.exec();
}
