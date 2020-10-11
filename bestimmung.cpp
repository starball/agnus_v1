#include "bestimmung.h"

void bestimmung::set_ip_adresse(QString adresse)
{
    this->ip_adresse = adresse;
}

QString bestimmung::get_ip_adresse()
{
    return this->ip_adresse;
}

void bestimmung::splitter()
{
    QString speicher = get_ip_adresse();
    QString out = "";
    int array_index = 0;

    for(int i = 0, l = speicher.size(); i <= l; i++)
    {
        if(speicher[i] == "." || i == l)
        {
            to_array(out.toInt(), array_index);
            array_index++;
            out.clear();
        }
        else
        {
           out.append(speicher[i]);
        }
    }

    this->array_size = array_index;
}

void bestimmung::to_array(int block, int array_index)
{
    this->array[array_index] = block;
}

int bestimmung::get_array(int index)
{
    return this->array[index];
}

int bestimmung::get_array_size()
{
    return this->array_size;
}

QString bestimmung::to_bin(int part_array)
{
    int speicher = part_array;
    QString bin = "";
    QString out = "";

    for(int i = 0; speicher > 0; i++) // Dezimal zu Binär
    {
        if(speicher % 2 == 0)
        {
            bin.append("0");
        }
        else
        {
            bin.append("1");
        }
        speicher = speicher / 2;
    }

    for(int i = bin.size(); i < 8; i++) // Nullen auffüllen
    {
        out.append("0");
    }

    for(int i = 0, l = bin.size() -1; i <= l; i++)
    {
        out.append(bin[l - i]);
        qInfo() << "l-i: " << l-i << "out " << out << "bin{l-i]" << bin[l - i];
    }

    qInfo() << "\n";

    return out;
}

void bestimmung::set_bin_out(QString bin_out_index, int index)
{
    this->bin_out[index] = bin_out_index;
}

QString bestimmung::get_bin_out(int index)
{
    return bin_out[index];
}

void bestimmung::output()
{
    splitter();

    set_bin_out(to_bin(array[0]),0);
    set_bin_out(to_bin(array[1]),1);
    set_bin_out(to_bin(array[2]),2);
    set_bin_out(to_bin(array[3]),3);

    fill_subnet_mask();

    fill_total_bin_complete();

    set_net_ID();
}

void bestimmung::set_netzanteil(int anteil)
{
    this->netzanteil = anteil;
}

int bestimmung::get_netzanteil()
{
    return this->netzanteil;
}

void bestimmung::set_total_bin()
{
    int index = 0;
    for(int i = 0; i < 4; i++)
    {
        QString test = this->bin_out[i];

        for(int i = 1, l = test.size(); i < l; i++)
        {
            this->total_bin[index] = test[i];
            index++;
        }
    }
}

QString bestimmung::get_total_bin(int index)
{
    return this->total_bin[index];
}

void bestimmung::fill_subnet_mask()
{
    int anteil = get_netzanteil();

    for(int i = 0; i < anteil; i++)
    {
        this->subnetz_maske.append("1");
    }

    set_total_bin();

    for(int i = anteil;i < 32; i++)
    {
        this->subnetz_maske.append("0");
    }
}

QString bestimmung::get_subnet_mask()
{
    return this->subnetz_maske;
}

void bestimmung::fill_total_bin_complete()
{
    for(int i = 0; i < 4; i++)
    {
        this->total_bin_complete.append(get_bin_out(i));
    }
}

QString bestimmung::get_total_bin_complete()
{
    return this->total_bin_complete;
}

void bestimmung::set_net_ID()
{
    QString mask = get_subnet_mask();

    QString bin = get_total_bin_complete();

    for(int i = 0; i < this->netzanteil; i++)
    {
        if(mask[i] == bin[i])
        {
            this->net_ID.append("1");
            qInfo() << "I: "<< i << "mask " << mask[i] << " | bin " << bin[i] << "-> 1";
        }
        else
        {
            this->net_ID.append("0");
            qInfo() << "I: "<< i << "mask " << mask[i] << " | bin " << bin[i] << "-> 0";
        }
    }

    for(int i = this->netzanteil; i < 32; i++)
    {
        this->net_ID.append("0");
    }
}

QString bestimmung::get_net_ID()
{
    return this->net_ID;
}



void bestimmung::to_dez(QString bin_dez)
{
    QString umwandeln = bin_dez;

    int index = 0;

    for(int i = 0; i < 4; i++)
    {
        QString part_string = "";
        int part_dez = 0;

        for(int potenz = 7; potenz >= 0; potenz--)
        {
            part_string = umwandeln[index];
            qInfo() << "Bin: "<< part_string;
            if(part_string != '0')
            {
                part_dez += pow(2,potenz);
                qInfo() << "Potenz :"<< pow(2,potenz);
            }
            index++;
        }
        this->dez_conv.append(QString::number(part_dez));

        qInfo() << "\n";

        if(i < 3)
        {
            this->dez_conv.append(".");
        }
    }
}

QString bestimmung::get_dez_conv_net_id()
{
    this->dez_conv = "";
    to_dez(net_ID);
    return this->dez_conv;
}

QString bestimmung::get_dez_conv_subnet_mark()
{
    this->dez_conv = "";
    to_dez(subnetz_maske);
    return this->dez_conv;
}
