#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bestimmung.h"

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

void MainWindow::on_btn_submit_clicked()
{
    // Input GUI IP-Adresse / Netzanteil
    QString u_eingabe = ui->ln_edt_ip->text();
    int u_netzanteil = ui->ln_edt_netzanteil->text().toInt();


    bestimmung A;
    A.set_ip_adresse(u_eingabe);
    A.set_netzanteil(u_netzanteil);
    A.output();


    // Output GUI unten Links
    ui->list_out->setHtml(A.get_bin_out(0)+" - "+QString::number(A.get_array(0))+"<br>"
                          +A.get_bin_out(1)+" - "+QString::number(A.get_array(1))+"<br>"
                          +A.get_bin_out(2)+" - "+QString::number(A.get_array(2))+"<br>"
                          +A.get_bin_out(3)+" - "+QString::number(A.get_array(3))+"<br>");


    // Output GUI unte Rechts
    ui->list_out_2->setHtml("IP Addresse Binär: <br>"+A.get_total_bin_complete()
                            +"<br> Subnetzmaske Binär: <br>"+A.get_subnet_mask()+"<br> NET ID Binär: <br>"+A.get_net_ID()
                            +"<br> Inv Subnetzmaske Binär: <br>"+ A.get_inv_subnet_mask()+"<br> Broadcast Binär: <br>"+A.get_broadcast()
                            /*+"<br>"+"<br>"+A.out_numbers()*/);

    // Output GUI Net ID:
    ui->list_net_id->setHtml(A.get_dez_conv_net_id());

    // Output GUI Subnetz Maske
    ui->list_subnet_mask->setHtml(A.get_dez_conv_subnet_mark());

    // Output GUI Inv Subnetz Maske
    ui->list_inv_subnetz_maske->setHtml(A.get_dez_conv_inv_subnet_mask());

    // Output GUI Broadcast
    ui->list_braodcast->setHtml(A.get_dez_conv_braodcast());
}

