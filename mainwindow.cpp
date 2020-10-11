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
    QString u_eingabe = ui->ln_edt_ip->text();
    int u_netzanteil = ui->ln_edt_netzanteil->text().toInt();


    bestimmung A;
    A.set_ip_adresse(u_eingabe);
    A.set_netzanteil(u_netzanteil);
    A.output();

    ui->list_out->setHtml(A.get_bin_out(0)+" - "+QString::number(A.get_array(0))+"<br>"
                          +A.get_bin_out(1)+" - "+QString::number(A.get_array(1))+"<br>"
                          +A.get_bin_out(2)+" - "+QString::number(A.get_array(2))+"<br>"
                          +A.get_bin_out(3)+" - "+QString::number(A.get_array(3))+"<br>");

    ui->list_out_2->setHtml("IP Addresse Binär: <br>"+A.get_bin_out(0)+A.get_bin_out(1)+A.get_bin_out(2)+A.get_bin_out(3)
                            +"<br> Subnetzmaske Binär: <br>"+A.get_subnet_mask()+"<br> NET ID Binär: <br>"+A.get_net_ID()
                            /*+"<br>"+"<br>"+A.out_numbers()*/);

    ui->list_net_id->setHtml(A.get_dez_conv_net_id());

    ui->list_subnet_mask->setHtml(A.get_dez_conv_subnet_mark());
}

