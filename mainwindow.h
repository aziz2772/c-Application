#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employer.h"
#include <QMainWindow>
#include <QString>
#include"QPropertyAnimation"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void sendMail();
    void mailSent(QString);
    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_dateEdit_2_userDateChanged(const QDate &date);

    void on_pushButton_20_clicked();

    void on_pushButton_2_clicked();



    void on_pushButton_3_clicked();

  //  void on_pushButton_4_clicked();



    void on_pushButton_clicked();




    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_comboBox_activated(int index);

    void on_sendBtn_clicked();

    void on_lineEdit_id_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
    employer tmpemployer;
    QPropertyAnimation *animation;
};

#endif // MAINWINDOW_H
