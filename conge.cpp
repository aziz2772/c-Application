#include "conge.h"
#include "ui_contrat.h"

conge::conge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::conge)
{
    ui->setupUi(this);
    ui->tabcontrat->setModel(tmpconge.afficher());
    ui->comboBox->setModel(tmpconge.afficher_employer());
    ui->comboBox_2->setModel(tmpconge.afficher_id());
    QPixmap pix("C:/Users/Aziz/Desktop/pic.jpg");
    ui->label_pic->setPixmap(pix);
}

conge::~conge()
{
    delete ui;
}


void conge::on_comboBox_activated(const QString &arg1)
{
    tmpconge.set_idemployer(arg1.toInt());
}

void conge::on_dateEdit_userDateChanged(const QDate &date)
{
    tmpconge.set_datec(date);
}


void conge::on_dateEdit_2_userDateChanged(const QDate &date)
{
    tmpconge.set_datee(date);
}

void conge::on_pushButton_clicked()
{
    int id=ui->lineEdit->text().toInt();
    tmpconge.set_id(id);
    bool test=tmpconge.ajouter();
    if(test)
  {ui->tabcontrat->setModel(tmpconge.afficher());//refresh
        ui->comboBox_2->setModel(tmpconge.afficher_id());
  QMessageBox::information(nullptr, QObject::tr("Ajouter un abonée"),
                    QObject::tr("Abonée ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonée"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void conge::on_pushButton_2_clicked()
{
    QString id = ui->lineEdit->text();

    cong a;
    if(a.rech(id)){
        bool test = a.modifier(id,tmpconge.get_datec(),tmpconge.get_datee());
        if(test){
            ui->tabcontrat->setModel(tmpconge.afficher());//refresh
            QMessageBox::information(nullptr,QObject::tr("Personnel modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }
}

void conge::on_comboBox_2_activated(const QString &arg1)
{
    tmpconge.set_id(arg1.toInt());

}

void conge::on_pb_supprimer_clicked()
{
    int id = tmpconge.get_id();


    bool test=tmpconge.supprimer(id);

    if(test)
    {
        ui->tabcontrat->setModel(tmpconge.afficher());//refresh
        ui->comboBox_2->setModel(tmpconge.afficher_id());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un conge"),
                    QObject::tr("conge supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un conge"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void conge::on_pushButton_4_clicked()
{
    QString id = ui->lineEdit_r->text();
    ui->tabcontrat->setModel(tmpconge.recherche(id));
}

void conge::on_pushButton_3_clicked()
{
     ui->tabcontrat->setModel(tmpconge.afficher());
}
