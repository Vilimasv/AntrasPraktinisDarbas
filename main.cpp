#include <iostream>
using namespace std;

int main() {
    bool programIsRunning = true;

    string vardai[100];
    int pazymiai[100][10];
    int pazymiuKiekis[100];

    int mokiniuKiekis = 0;

    while (programIsRunning) {

        int pasirinkimas;

        cout << "\n--- MENIU ---\n";
        cout << "1 - Prideti mokini\n";
        cout << "2 - Rodyti visus mokinius\n";
        cout << "3 - Rodyti konkretu mokini\n";
        cout << "4 - Atnaujinti pazymi\n";
        cout << "5 - Pasalinti mokini\n";
        cout << "0 - Iseiti\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;

        if (pasirinkimas == 0) {
            programIsRunning = false;
            break;
        }

        // -----------------------------
        // 1. PRIDĖTI MOKINĮ
        // -----------------------------
        if (pasirinkimas == 1) {

            if (mokiniuKiekis >= 100) {
                cout << "Pasiektas maksimalus mokiniu skaicius\n";
                continue;
            }

            cout << "Iveskite mokinio varda: ";
            cin >> vardai[mokiniuKiekis];

            cout << "Kiek pazymiu (max 10): ";
            cin >> pazymiuKiekis[mokiniuKiekis];

            if (pazymiuKiekis[mokiniuKiekis] > 10)
                pazymiuKiekis[mokiniuKiekis] = 10;

            for (int i = 0; i < pazymiuKiekis[mokiniuKiekis]; i++) {
                cout << "Iveskite " << i + 1 << " pazymi: ";
                cin >> pazymiai[mokiniuKiekis][i];
            }

            mokiniuKiekis++;
            cout << "Mokinys pridetas!\n";
        }

        // -----------------------------
        // 2. RODYTI VISUS
        // -----------------------------
        else if (pasirinkimas == 2) {

            if (mokiniuKiekis == 0) {
                cout << "Nera mokiniu\n";
                continue;
            }

            for (int i = 0; i < mokiniuKiekis; i++) {
                cout << i + 1 << ". " << vardai[i] << ": ";

                for (int j = 0; j < pazymiuKiekis[i]; j++) {
                    cout << pazymiai[i][j] << " ";
                }

                cout << endl;
            }
        }

        // -----------------------------
        // 3. RODYTI VIENĄ
        // -----------------------------
        else if (pasirinkimas == 3) {

            string vardas;
            cout << "Iveskite mokinio varda: ";
            cin >> vardas;

            bool rastas = false;

            for (int i = 0; i < mokiniuKiekis; i++) {
                if (vardai[i] == vardas) {

                    cout << vardai[i] << ": ";

                    for (int j = 0; j < pazymiuKiekis[i]; j++) {
                        cout << pazymiai[i][j] << " ";
                    }

                    cout << endl;
                    rastas = true;
                    break;
                }
            }

            if (!rastas)
                cout << "Mokinys nerastas\n";
