#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeIniFile(QString content)
{
    QSettings *settings = new QSettings("./SystemSettings.ini",QSettings::IniFormat);
    settings->setValue("language",content);//将当前选择的语言写入ini文件中
    delete settings;
}

QString MainWindow::readIniFile()
{
    QSettings *settings = new QSettings("./SystemSettings.ini",QSettings::IniFormat);
    QString lang = settings->value("language","Chinese").toString();//读出ini文件中保存的语言
    delete settings;
    return  lang;
}

void MainWindow::on_btn_Chinese_clicked()
{
    writeIniFile("Chinese");//将当前选择的中文设置写入ini文件中
    QMessageBox::information(this,tr("infomation"),tr("Restart the software for the settings to take effect"));
}

void MainWindow::on_btn_English_clicked()
{
    writeIniFile("English");//将当前选择的英文设置写入ini文件中
    QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("语言设置在重启系统后生效"));
}
