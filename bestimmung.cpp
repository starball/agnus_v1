#include "bestimmung.h"


/**
 * Set IP-address
 * 
 * some more detailed explanation of the Function
 * @param adresse This is a dot-separated string incomming as xxx.xxx.xxx.xxx
 */
// Setzt IP-Adresse
void bestimmung::set_ip_adresse(QString adresse)
{
    this->ip_adresse = adresse;
}

// Gibt IP-Adresse zurück
QString bestimmung::get_ip_adresse()
{
    return this->ip_adresse;    // for general understanding, why just take the ip_adresse from the Class, why this wrapper?
}

// Teilt IP-Adresse in Vier Blöcke anhand der Punkte "."
void bestimmung::splitter()
{
    QString speicher = get_ip_adresse();  // ok, now explain this?!?, why uise the getter?
    QString out = "";  // better name
    int array_index = 0;

    for(int i = 0, l = speicher.size(); i <= l; i++)  // you might wnat to call it "buffer"?
    {
        if(speicher[i] == "." || i == l)    // Wird True wenn "." gefunden wird oder Ende der IP-Adresse
        {
            // here is happening some poor? magic I don't understand.^^
            to_array(out.toInt(), array_index);
            array_index++;
            out.clear();
            // ok, got it, hmmm... there must be a more easy way to do this.
            // there might be already a function out there, splitting a string by a special character.
            // buuuut I think I like your version.
        }
        else
        {
           out.append(speicher[i]);         // Gibt Block der Adresse zurück <-- This comment I don't like.
        }
    }

    //this->array_size = array_index;
}

// Setzt IP-Adress Block in Array
void bestimmung::to_array(int block, int array_index)
{
    // So tell me, how do you make sure, that you keep track of the index and the content of the array?
    // Still the question, why the wrapper?
    this->array[array_index] = block;  // great idea to call a array, 'array'!
}

// Gibt IP-Adress Block zurück
int bestimmung::get_array(int index)  // the name is misguiding
{
    return this->array[index];
}

// Kann weg  ... so discard it?
int bestimmung::get_array_size()
{
    return this->array_size;
}

// Wandelt Adress Block (Dez) in Bin um
// Wird Automatisiert, um direkt alle Blöcke umzuwandeln
QString bestimmung::to_bin(int part_array) // why use int, if you only expect values up to 255?
{
    int speicher = part_array;
    QString bin = "";
    QString out = "";

    for(int i = 0; speicher > 0; i++) // Dezimal zu Binär
    {
        // you got modulo right!!!
        if(speicher % 2 == 0)       // Wenn durch zwei Teilbar dann "0"
        {
            bin.append("0");
        }
        else                        // Wenn Rest dann "1"
        {
            bin.append("1");
        }
        // Angenommen es gibt einen Operator, der den Inhalt einer
        // Variable um n Bytes nach rechts verschiebt,
        // wie würdest du ihn benutzen, wenn er so ausschaut: variable >> n 
        speicher = speicher / 2;  // why does this work, why there is no 0.5?
    }

    for(int i = bin.size(); i < 8; i++) // Nullen auffüllen
    {
        // add leading zeros to new array... now I got it. 
        out.append("0");
    }

    for(int i = 0, l = bin.size() -1; i <= l; i++) // Dreht den String um
    {
        // please make it more complicated =)^^ just al little bit^^
        // DEs war echt nen harter brocken für die zu schrieben und du hast guuuut gekämpft!
        out.append(bin[l - i]);
    }
    return out;         // Gibt Block als Binär-String zurück

    // challenge, there is a way to do this with binary operators and in one loop in nine lines with only a output buffer.
    // solution = [0x73, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x20, 0x62, 0x69, 0x6e, 0x61, 0x72, 0x69, 0x73, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x28, 0x75, 0x6e, 0x73, 0x69, 0x67, 0x6e, 0x65, 0x64, 0x20, 0x63, 0x68, 0x61, 0x72, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x67, 0x65, 0x72, 0x5f, 0x74, 0x6f, 0x5f, 0x63, 0x6f, 0x6e, 0x76, 0x65, 0x72, 0x74, 0x29, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x73, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x20, 0x6f, 0x75, 0x74, 0x20, 0x3d, 0x20, 0x22, 0x22, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6f, 0x72, 0x28, 0x69, 0x6e, 0x74, 0x20, 0x69, 0x20, 0x3d, 0x20, 0x38, 0x3b, 0x20, 0x69, 0x3e, 0x30, 0x3b, 0x20, 0x69, 0x2d, 0x2d, 0x29, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x69, 0x66, 0x28, 0x31, 0x3c, 0x3c, 0x69, 0x20, 0x26, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x67, 0x65, 0x72, 0x5f, 0x74, 0x6f, 0x5f, 0x63, 0x6f, 0x6e, 0x76, 0x65, 0x72, 0x74, 0x29, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x6f, 0x75, 0x74, 0x2e, 0x61, 0x70, 0x70, 0x65, 0x6e, 0x64, 0x28, 0x22, 0x31, 0x22, 0x29, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7d, 0x65, 0x6c, 0x73, 0x65, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x6f, 0x75, 0x74, 0x2e, 0x61, 0x70, 0x70, 0x65, 0x6e, 0x64, 0x28, 0x22, 0x30, 0x22, 0x29, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x7d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6e, 0x20, 0x6f, 0x75, 0x74, 0x0a, 0x7d]
}

// Setz Adress Block (Bin) in Array  
void bestimmung::set_bin_out(QString bin_out_index, int index)  // there is no schem of naming getter and setter, compared to the arry get/set
{
    this->bin_out[index] = bin_out_index;
}

// Gibt Adress Block (Bin) zurück
QString bestimmung::get_bin_out(int index)
{
    return bin_out[index];
}

// From context, shodn't this function be at the very top or button, cause it's kind of the main function?
// "Main Function" Gibt Reihenfolge der Funktionen an
void bestimmung::output()   // are you certain that this name matches the usage of the function?
{
    splitter(); // 1. Teilt IP-Adresse in 4 Blöcke (Array)

    set_bin_out(to_bin(array[0]),0);        //2. Setzt und wandelt Block für Block Binär (Array)
    set_bin_out(to_bin(array[1]),1);        // 4 lines, one loop, now!
    set_bin_out(to_bin(array[2]),2);
    set_bin_out(to_bin(array[3]),3);

    count_hosts();

    set_total_bin();                        // Macht aus den 4 Binär Blöcken ein String (Array to String)
    fill_total_bin_complete();              // Macht aus den den vier Blöcken ein String (Array -> String)

    fill_subnet_mask();                     // Füllt Subnetz Maske mit "0" / "1" anhand von Netzanteil

    set_net_ID();                           // Setz Net ID anhand von Subnetzmaske und Total Bin

    fill_inv_subnet_mask();                 // und hier verließen sie ihn...

    set_broadcast();                        // I still think it is kind of confusing, how yopu handle the stuff.
                                            // So nen bissel fehlt mir der rote Faden.
}

// two moe useless set/get?
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
// You know, one function can call an other one?
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
// wes? woher wozu?
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
    // ok, you have learned about binary operators. USE THEM. Working with strings instead of bytes is a waste of time and memory
    // you have demonstrated, that you have a logical imagination and are able to solve problems =)! good job.
    // now use strings only for presenting the result and not for calculation.
    QString mask = get_subnet_mask();

    QString bin = get_total_bin_complete();

    int anteil = get_netzanteil();

    for(int i = 0; i < anteil; i++)         // Solange i kleiner ist als netzanteil wird verglichen
    {
        /**
         * Ich kanne mich mit netzmasken nicht aus, aber ich habe das dumpfe gefühl,
         * dass du dich hier vertan hast. der Kommentar sagt etwas anderes aus, als die Zeile
         * tut!!!
         */
        if(mask[i] == bin[i])               // Wenn char von Maske und Bin "1" sind wird 1 angehängt
        {
            this->net_ID.append("1");
            this->first_host.append(("1"));
            // Debug: qInfo() << "I: "<< i << "mask " << mask[i] << " | bin " << bin[i] << "-> 1";
        }
        else
        {
            this->net_ID.append("0");
            this->first_host.append(("0"));// Wenn nicht dann "0"
            // Debug: qInfo() << "I: "<< i << "mask " << mask[i] << " | bin " << bin[i] << "-> 0";
        }
    }

    for(int i = this->netzanteil; i < 32; i++) // Der Rest wird mit "0" aufgefüllt
    {
        // Without looking at it, don't use a additional loop to fix the first imperfect loop...
        // changing the first one, requires changing the second one too.
        this->net_ID.append("0");
        if(i < 31) {
            this->first_host.append(("0"));
        }
        else
        {
            this->first_host.append(("1"));
        }
    }
}

// Gibt net_ID zurück
// would you mind, to write all getter and setter at one place?
// write functions in logical context, where they bekolong. Nix da Kraut und Rüben.
QString bestimmung::get_net_ID()
{
    return this->net_ID;
}

// Wandelt binär in dezimal um
// Wird für GUI benötigt umd Subnetzmaske & Net ID in Dez darzustellen
// Wie potenziere ich durch bitshiften?
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
            if(part_string != '0')
            {
                part_dez += pow(2,potenz);
            }
            index++;
        }
        this->dez_conv.append(QString::number(part_dez));   // Convertierte Zahlen werden an Variable übergeben

        if(i < 3)                                           // Fügt "." hinzu
        {
            this->dez_conv.append(".");
        }
    }
}

// Gibt Convertierte net_ID zurück
// Die funktion tut weh, was machst du da?
QString bestimmung::get_dez_conv_net_id()
{
    // lokale variable zuzrücksetzen, nicht dass das nicht auch die aufgerufene funktion machen könnte, oder?
    this->dez_conv = ""; 
    // jetzt machen wir das, was eigentlich diese funktion machen soll
    to_dez(net_ID);
    // und jetzt geben wir noch das zurück, was vermutlich von der überliegenden funktion gesetzt wurde.
    // das sind irgendwie drei komplett unabhängige sachen, die logisch gekoppelt sind.
    // wenn deine Programme komplexer werden, dann blickt da keiner mehr durch.
    return this->dez_conv;
}

// Gibt Convertierte Subnetz Maske zurück
QString bestimmung::get_dez_conv_subnet_mark()
{
    //s.o.
    this->dez_conv = "";
    to_dez(subnetz_maske);
    return this->dez_conv;
}


/**
 * Das folgende nur grob überflogen, kann das sein, dass sie der Code wiederholt?
 * vll findest du geminsamkeiten und kannst abstraktere funktionen ßdafür schreiben?
 * Lass das mit dem String geschubse und guck die mal binäre operatoren und Bit-operationen in c++ an.
 * Was ist ein Integer, was ein unsigned character, was bedeutet unsigned? Was bedeutet es, wenn werte maskiert werden?
 * Wie vergleiche ich das n'te bit zweier variablen miteinander? (...)
 */

// Füllt Invertiert Subnetz Maskse mit 0 / 1 nach dem Netzanteil
void bestimmung::fill_inv_subnet_mask()
{
    int anteil = get_netzanteil();

    for(int i = 0; i < anteil; i++)         // Alles bis angebenem Netzanteil wird "0" gesetzt
    {
        this->inv_subnetz_maske.append("0");
    }

    for(int i = anteil;i < 32; i++)         // Alles danach wird "1" gesetzt
    {
        this->inv_subnetz_maske.append("1");
    }
}

// Gibt invertierte Subnetz Maske zurpck
QString bestimmung::get_inv_subnet_mask()
{
    return this->inv_subnetz_maske;
}

// Gibt deziaml convertierte invertierte Subentz Maske zurück
QString bestimmung::get_dez_conv_inv_subnet_mask()
{
    this->dez_conv = "";
    to_dez(inv_subnetz_maske);
    return this->dez_conv;
}

// Setz Broadcast
void bestimmung::set_broadcast()
{
    QString mask = get_inv_subnet_mask();

    QString bin = get_total_bin_complete();

    int anteil = get_netzanteil();

    for(int i = 0; i < anteil; i++)         // Was vor dem dem netzteil "1" ist wird "1"
    {
        if(bin[i] == "1")
        {
            this->broadcast.append("1");
            this->last_host.append(("1"));
        }
        else {
            this->broadcast.append("0");
            this->last_host.append(("0"));
        }
    }

    for(int i = anteil; i < 32; i++)         // Alles nachdem Netzanteil wird "1"
    {
        this->broadcast.append("1");
        if(i < 31)
        {
            this->last_host.append(("1"));
        }
        else {
            this->last_host.append(("0"));
        }
    }
}

// Gibt Broadcast zurück
QString bestimmung::get_broadcast()
{
    return this->broadcast;
}

// Gibt deziaml convertierten Broadcast zurück
QString bestimmung::get_dez_conv_braodcast()
{
    this->dez_conv = "";
    to_dez(broadcast);
    return this->dez_conv;
}

// Bestimmt mögliche Hosts im Netz
void bestimmung::count_hosts()
{
    int potenz = 32 - get_netzanteil();

    this->counted_hosts = pow(2,potenz) - 2;
}

// Gibt Mögliche Hosts zurück
int bestimmung::get_counted_hosts()
{
    return this->counted_hosts;
}

QString bestimmung::get_dez_conv_first_host()
{
    this->dez_conv = "";
    to_dez(first_host);
    return this->dez_conv;
}

QString bestimmung::get_dez_conv_last_host()
{
    this->dez_conv = "";
    to_dez(last_host);
    return this->dez_conv;
}
