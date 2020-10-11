#include "bestimmung.h"

// Setzt IP-Adresse
void bestimmung::set_ip_adresse(QString adresse)
{
    this->ip_adresse = adresse;
}

// Gibt IP-Adresse zurück
QString bestimmung::get_ip_adresse()
{
    return this->ip_adresse;
}

// Teilt IP-Adresse in Vier Blöcke anhand der Punkte "."
void bestimmung::splitter()
{
    QString speicher = get_ip_adresse();
    QString out = "";
    int array_index = 0;

    for(int i = 0, l = speicher.size(); i <= l; i++)
    {
        if(speicher[i] == "." || i == l)    // Wird True wenn "." gefunden wird oder Ende der IP-Adresse
        {
            to_array(out.toInt(), array_index);
            array_index++;
            out.clear();
        }
        else
        {
           out.append(speicher[i]);         // Gibt Block der Adresse zurück
        }
    }

    //this->array_size = array_index;
}

// Setzt IP-Adress Block in Array
void bestimmung::to_array(int block, int array_index)
{
    this->array[array_index] = block;
}

// Gibt IP-Adress Block zurück
int bestimmung::get_array(int index)
{
    return this->array[index];
}

// Kann weg
int bestimmung::get_array_size()
{
    return this->array_size;
}

// Wandelt Adress Block (Dez) in Bin um
// Wird Automatisiert, um direkt alle Blöcke um zuwandeln
QString bestimmung::to_bin(int part_array)
{
    int speicher = part_array;
    QString bin = "";
    QString out = "";

    for(int i = 0; speicher > 0; i++) // Dezimal zu Binär
    {
        if(speicher % 2 == 0)       // Wenn durch zwei Teilbar dann "0"
        {
            bin.append("0");
        }
        else                        // Wenn Rest dann "1"
        {
            bin.append("1");
        }
        speicher = speicher / 2;
    }

    for(int i = bin.size(); i < 8; i++) // Nullen auffüllen
    {
        out.append("0");
    }

    for(int i = 0, l = bin.size() -1; i <= l; i++) // Dreht den String um
    {
        out.append(bin[l - i]);
    }
    return out;         // Gibt Block als Binär zurück
}

// Setz Adress Block (Bin) in Array
void bestimmung::set_bin_out(QString bin_out_index, int index)
{
    this->bin_out[index] = bin_out_index;
}

// Gibt Adress Block (Bin) zurück
QString bestimmung::get_bin_out(int index)
{
    return bin_out[index];
}

// "Main Function" Gibt Reihenfolge der Funktionen an
void bestimmung::output()
{
    splitter(); // 1. Teilt IP-Adresse in 4 Blöcke (Array)

    set_bin_out(to_bin(array[0]),0);        //2. Setzt und wandelt Block für Block Binär (Array)
    set_bin_out(to_bin(array[1]),1);
    set_bin_out(to_bin(array[2]),2);
    set_bin_out(to_bin(array[3]),3);

    set_total_bin();                        // Macht aus den 4 Binär Blöcken ein String (Array to String)
    fill_total_bin_complete();              // Macht aus den den vier Blöcken ein String (Array -> String)

    fill_subnet_mask();                     // Füllt Subnetz Maske mit "0" / "1" anhand von Netzanteil

    set_net_ID();                           // Setz Net ID anhand von Subnetzmaske und Total Bin
}

// Setz Netzanteil
void bestimmung::set_netzanteil(int anteil)
{
    this->netzanteil = anteil;
}

// Gibt Netzanteil zurück
int bestimmung::get_netzanteil()
{
    return this->netzanteil;
}

// Macht aus den 4 Binär Blöcken ein String (Array to String)
// Wird für Net Id Benötigt
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

// Gibt total bin zurück
QString bestimmung::get_total_bin(int index)
{
    return this->total_bin[index];
}

// Füllt Subnetzmaske
void bestimmung::fill_subnet_mask()
{
    int anteil = get_netzanteil();

    for(int i = 0; i < anteil; i++)         // Alles bis angebenem Netzanteil wird "1" gesetzt
    {
        this->subnetz_maske.append("1");
    }

    for(int i = anteil;i < 32; i++)         // Alles danach wird "0" gesetzt
    {
        this->subnetz_maske.append("0");
    }
}

// Gibt Subnetz Maske zurück
QString bestimmung::get_subnet_mask()
{
    return this->subnetz_maske;
}

// Füllt String mit 4 Bin Adress Blöcken
void bestimmung::fill_total_bin_complete()
{
    for(int i = 0; i < 4; i++)
    {
        this->total_bin_complete.append(get_bin_out(i));
    }
}

// gibt total_bin_complete zurück
QString bestimmung::get_total_bin_complete()
{
    return this->total_bin_complete;
}

// Setz net_ID
void bestimmung::set_net_ID()
{
    QString mask = get_subnet_mask();

    QString bin = get_total_bin_complete();

    int anteil = get_netzanteil();

    for(int i = 0; i < anteil; i++)         // Solange i kleiner ist als netzanteil wird verglichen
    {
        if(mask[i] == bin[i])               // Wenn char von Maske und Bin "1" sind wird 1 angehängt
        {
            this->net_ID.append("1");
            // Debug: qInfo() << "I: "<< i << "mask " << mask[i] << " | bin " << bin[i] << "-> 1";
        }
        else
        {
            this->net_ID.append("0");       // Wenn nicht dann "0"
            // Debug: qInfo() << "I: "<< i << "mask " << mask[i] << " | bin " << bin[i] << "-> 0";
        }
    }

    for(int i = this->netzanteil; i < 32; i++) // Der Rest wird mit "0" aufgefüllt
    {
        this->net_ID.append("0");
    }
}

// Gibt net_ID zurück
QString bestimmung::get_net_ID()
{
    return this->net_ID;
}

// Wandelt binär in dezimal um
// Wird für GUI benötigt umd Subnetzmaske & Net ID in Dez darzustellen
void bestimmung::to_dez(QString bin_dez)
{
    QString umwandeln = bin_dez;

    int index = 0;

    for(int i = 0; i < 4; i++)                              // 4 mal da 4 Blöcke
    {
        QString part_string = "";
        int part_dez = 0;

        for(int potenz = 7; potenz >= 0; potenz--)          // Fängt bei 2^7 an und geht herunter
        {                                                   // da 128 / 64 / 32 / 16 / 8 / 4 / 2 / 1
            part_string = umwandeln[index];                 // Multipliziert dann char für char mit x Potenz von 2
            qInfo() << "Bin: "<< part_string;
            if(part_string != '0')
            {
                part_dez += pow(2,potenz);
                qInfo() << "Potenz :"<< pow(2,potenz);
            }
            index++;
        }
        this->dez_conv.append(QString::number(part_dez));   // Convertierte Zahlen werden an Variable übergeben

        // Debug: qInfo() << "\n";

        if(i < 3)                                           // Fügt "." hinzu
        {
            this->dez_conv.append(".");
        }
    }
}

// Gibt Convertierte net_ID zurück
QString bestimmung::get_dez_conv_net_id()
{
    this->dez_conv = "";
    to_dez(net_ID);
    return this->dez_conv;
}

// Gibt Convertierte Subnetz Maske zurück
QString bestimmung::get_dez_conv_subnet_mark()
{
    this->dez_conv = "";
    to_dez(subnetz_maske);
    return this->dez_conv;
}
