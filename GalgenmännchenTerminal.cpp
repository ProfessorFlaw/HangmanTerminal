#include <algorithm>
#include <cmath>
#include <iostream>
//#include <iterator>
#include <string>
#include <cctype>

using namespace std;

int main() {
    system("clear");
    cout << "Willcommen bei Hangman, viel Spaß!" << endl << endl;
    int Versuche;
    int Regelauswahl;
    cout << "Willst du eigene Regeln festlegen (1) oder den Standart nutzen (2)?" << endl;
    cin >> Regelauswahl;
    if (Regelauswahl == 2) {
        Versuche = 10;
    }
    else {
        cout << "Wie viele Leben soll der Spieler haben?" << endl;
        cin >> Versuche;
        system("clear");
        cout << "Der Spieler wird " << Versuche << " Leben bekommen." << endl;
    }
    string Wort;
    cout << "Gebe dein Wort ein:" << endl;
    cin >> Wort;
    transform(Wort.begin(), Wort.end(), Wort.begin(), ::tolower);
    int Länge = Wort.length();
    system("clear");
    string Felder = "";
    for (int i = 0; i < Länge; i++) {
        Felder += "=";
    }

    string versuchteBuchstaben;
    while (Versuche > 0) {
        if (versuchteBuchstaben.length() < 1) {
            cout << "Gebe deinen ersten Buchstaben ein:" << endl;
        } else {
            cout << "Du hast bereits die Buchstaben " << versuchteBuchstaben << " ausprobiert." << endl;
            cout << "Gebe einen Buchstaben ein:" << endl;
        }
        cout << Felder << endl;

        string Eingabe;
        cin >> Eingabe;

        if (Eingabe.length() != 1) {
            cout << "Deine Eingabe darf nur 1 Zeichen lang sein, gebe diesmal den Buchstaben richtig ein:" << endl;
            continue;
        }

        char Buchstabe = tolower(Eingabe[0]);

        // Prüfe, ob der Buchstabe bereits ausprobiert wurde
        if (versuchteBuchstaben.find(Buchstabe) != string::npos) {
            cout << "Du hast diesen Buchstaben bereits ausprobiert. Bitte wähle einen anderen." << endl;
            continue;
        }

        versuchteBuchstaben += Buchstabe;
        int Position = Wort.find(Buchstabe);
        system("clear");

        if (Position < 0) {
            Versuche -= 1;
            cout << "Das war leider Falsch" << endl;
            cout << "Du hast noch " << Versuche << " Leben übrig." << endl;
        } else {
            cout << "Das war richtig!" << endl;
            // Aktualisiere alle Stellen im Wort, an denen der Buchstabe vorkommt
            for (int i = 0; i < Länge; ++i) {
                if (Wort[i] == Buchstabe) {
                    Felder[i] = Buchstabe;
                }
            }
        }

        if (Felder == Wort) {
            cout << "Du hast das Wort erraten, es war: " << Wort << " und du hattest noch " << Versuche << " Leben übrig!" << endl;
            return 0;
        }
    }

    cout << "Leider hattest du keine Leben übrig :O, viel Glück beim nächsten Mal!" << endl;
    cout << "Das Wort war " << Wort << "." << endl;
    return 0;
}
