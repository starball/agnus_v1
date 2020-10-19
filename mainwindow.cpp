#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bestimmung.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lbl_counted_hosts->setToolTip("<p style='color: #111;'>Ohne Net ID / Broadcast</p>");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ln_edt_netzanteil_returnPressed()
{
    // Input GUI IP-Adresse / Netzanteil
    QString u_eingabe = ui->ln_edt_ip->text();
    int u_netzanteil = ui->ln_edt_netzanteil->text().toInt();

    bestimmung A;
    A.set_ip_adresse(u_eingabe);
    A.set_netzanteil(u_netzanteil);
    A.output();

    // Would you like to stay at one language in your comments???

    // Output GUI Net ID:
    ui->list_net_id->setHtml(A.get_dez_conv_net_id());

    // Output GUI Subnetz Maske
    ui->list_subnet_mask->setHtml(A.get_dez_conv_subnet_mark());

    // Output GUI Inv Subnetz Maske
    ui->list_inv_subnetz_maske->setHtml(A.get_dez_conv_inv_subnet_mask());

    // Output GUI Broadcast
    ui->list_braodcast->setHtml(A.get_dez_conv_braodcast());

    // Output GUI Mögliche Hosts
    ui->list_counted_hosts->setHtml(QString::number(A.get_counted_hosts()));


    // Output GUI First Host "Von:"
    ui->list_von->setHtml(A.get_dez_conv_first_host());

    // Output GUI Last Host "Bis:"
    ui->list_bis->setHtml(A.get_dez_conv_last_host());
}
