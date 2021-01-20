#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void writeIniFile(QString content);
    QString readIniFile();

private slots:
    void on_btn_Chinese_clicked();

    void on_btn_English_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
