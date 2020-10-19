#ifndef BESTIMMUNG_H
#define BESTIMMUNG_H

#include <qstring.h>
#include <QDebug>
#include <math.h>

class bestimmung
{
public:
// there is a refactor->renaming support in every IDE, use it wisely ;)
    void set_ip_adresse(QString adresse);
    QString get_ip_adresse();

    void splitter();  // of what?
    void to_array(int block, int array_index);

    int get_array(int index);
    int get_array_size();

    QString to_bin(int part_array); // wandelt dez in bin

    void set_bin_out(QString bin_out_index, int index);
    QString get_bin_out(int index);
    void output();

    void set_netzanteil(int anteil);
    int get_netzanteil();

    void fill_subnet_mask();
    QString get_subnet_mask();

    void set_total_bin();
    QString get_total_bin(int index);

    void fill_total_bin_complete();
    QString get_total_bin_complete();

    void set_net_ID();
    QString get_net_ID();

    void to_dez(QString bin_dez); // wandelt bin in dez

    QString get_dez_conv_net_id();
    QString get_dez_conv_subnet_mark();
    QString get_dez_conv_inv_subnet_mask();
    QString get_dez_conv_braodcast();
    QString get_dez_conv_first_host();
    QString get_dez_conv_last_host();

    void fill_inv_subnet_mask();
    QString get_inv_subnet_mask();

    void set_broadcast();
    QString get_broadcast();

    void count_hosts();
    int get_counted_hosts();

private:  // can you explain, why you have chosen "private" for this?
    QString ip_adresse;
    QString bin_out[4];
    QString total_bin[32];
    QString total_bin_complete;

    QString subnetz_maske;
    QString inv_subnetz_maske;

    QString net_ID;
    QString broadcast;

    QString dez_conv;

    QString first_host;
    QString last_host;

    int array[4];
    int array_size;

    int netzanteil;

    int counted_hosts;

};

#endif // BESTIMMUNG_H
