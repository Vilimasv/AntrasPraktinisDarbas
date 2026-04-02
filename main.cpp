#include <iostream>
using namespace std;

// Funkcija, su kuria ivedame pazymi
int gautiPazymi() {
    int p;

    // Kartojasi kol ivedamas teisingas pazymys
    do {
        cout << "Iveskite pazymi (1-10): ";
        cin >> p;

        // tikrinama ar tinkamas pazymys
        if (p < 1 || p > 10) {
            cout << "Blogas pazymys! Galimi tik 1-10.\n";
        }

    } while (p < 1 || p > 10);

    return p; // irasome pazymi
}

int main() {

    // While ciklas
    bool programIsRunning = true;

    // Masyvas, kuris saugo mokiniu pazymius
    string vardai[100];

    // 2 masyvas pazymiams
    int pazymiai[100][10];

    // Kiek pazymiu turi kiekvienas mokinys
    int pazymiuKiekis[100];

    // Kiek siuo metu yra mokiniu
    int mokiniuKiekis = 0;

    // Pagrindinis programos ciklas
    while (programIsRunning) {

        int pasirinkimas;

        // Meniu
        cout << "\n--- MENIU ---\n";
        cout << "1 - Prideti mokini\n";
        cout << "2 - Rodyti visus mokinius\n";
        cout << "3 - Rodyti konkretu mokini\n";
        cout << "4 - Atnaujinti pazymi\n";
        cout << "5 - Pasalinti mokini\n";
        cout << "0 - Iseiti\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;

        // Jei pasirenkama 0 – iseinama is programos
        if (pasirinkimas == 0) {
            programIsRunning = false;
            break;
        }

        // =============================
        // 1. Pridedame mokini
        // =============================
        if (pasirinkimas == 1) {

            // Tikriname ar neviršytas limitas
            if (mokiniuKiekis >= 100) {
                cout << "Pasiektas maksimalus mokiniu skaicius\n";
                continue;
            }

            // Ivedamas mokinio vardas
            cout << "Iveskite mokinio varda: ";
            cin >> vardai[mokiniuKiekis];

            // Ivedamas norimas pazymiu kiekis
            cout << "Kiek pazymiu (1-10): ";
            cin >> pazymiuKiekis[mokiniuKiekis];

            // Apibreziam ribas
            if (pazymiuKiekis[mokiniuKiekis] < 1)
                pazymiuKiekis[mokiniuKiekis] = 1;

            if (pazymiuKiekis[mokiniuKiekis] > 10)
                pazymiuKiekis[mokiniuKiekis] = 10;

            // Ivedami pazymiai
            for (int i = 0; i < pazymiuKiekis[mokiniuKiekis]; i++) {
                pazymiai[mokiniuKiekis][i] = gautiPazymi();
            }

            // Padidinam mokiniu skaiciu
            mokiniuKiekis++;

            cout << "Mokinys pridetas!\n";
        }

        // =============================
        // 2. RODYTI VISUS MOKINIUS
        // =============================
        else if (pasirinkimas == 2) {

            // Jei nera mokiniu
            if (mokiniuKiekis == 0) {
                cout << "Nera mokiniu\n";
                continue;
            }

            // Einame per visus mokinius
            for (int i = 0; i < mokiniuKiekis; i++) {

                // Spausdiname vardus
                cout << i + 1 << ". " << vardai[i] << ": ";

                // Spausdiname pazymius
                for (int j = 0; j < pazymiuKiekis[i]; j++) {
                    cout << pazymiai[i][j] << " ";
                }

                cout << endl;
            }
        }

        // =============================
        // 3. RODYTI KONKRETU MOKINI
        // =============================
        else if (pasirinkimas == 3) {

            string vardas;

            // Ivedamas norimo mokinio vardas
            cout << "Iveskite mokinio varda: ";
            cin >> vardas;

            bool rastas = false;

            // Ieskome mokinio
            for (int i = 0; i < mokiniuKiekis; i++) {
                if (vardai[i] == vardas) {

                    // Jei randame – spausdiname
                    cout << vardai[i] << ": ";

                    for (int j = 0; j < pazymiuKiekis[i]; j++) {
                        cout << pazymiai[i][j] << " ";
                    }

                    cout << endl;
                    rastas = true;
                    break;
                }
            }

            // Jei nerandame
            if (!rastas)
                cout << "Mokinys nerastas\n";
        }

        // =============================
        // 4. ATNAUJINTI PAZYMI
        // =============================
        else if (pasirinkimas == 4) {

            string vardas;

            // Ivedamas mokinio vardas
            cout << "Iveskite mokinio varda: ";
            cin >> vardas;

            bool rastas = false;

            // Ieskome mokinio
            for (int i = 0; i < mokiniuKiekis; i++) {
                if (vardai[i] == vardas) {

                    int nr;

                    // Pasirenkame kuri pazymi norime keisti
                    cout << "Kuri pazymi norite keisti (1,2,...): ";
                    cin >> nr;

                    // Tikriname ar numeris teisingas
                    if (nr < 1 || nr > pazymiuKiekis[i]) {
                        cout << "Blogas numeris\n";
                        rastas = true;
                        break;
                    }

                    // Irasome nauja pazymi
                    pazymiai[i][nr - 1] = gautiPazymi();

                    cout << "Pazymys atnaujintas!\n";
                    rastas = true;
                    break;
                }
            }

            if (!rastas)
                cout << "Mokinys nerastas\n";
        }

        // =============================
        // 5. PASALINTI MOKINI
        // =============================
        else if (pasirinkimas == 5) {

            string vardas;

            // Ivedamas mokinio vardas
            cout << "Iveskite mokinio varda: ";
            cin >> vardas;

            bool rastas = false;

            // Ieskome mokinio
            for (int i = 0; i < mokiniuKiekis; i++) {
                if (vardai[i] == vardas) {

                    // Perstumiame visus mokinius i kaire
                    for (int j = i; j < mokiniuKiekis - 1; j++) {

                        vardai[j] = vardai[j + 1];
                        pazymiuKiekis[j] = pazymiuKiekis[j + 1];

                        // Kopijuojame pazymius
                        for (int k = 0; k < 10; k++) {
                            pazymiai[j][k] = pazymiai[j + 1][k];
                        }
                    }

                    // Atnaujinam mokiniu kieki
                    mokiniuKiekis--;

                    cout << "Mokinys pasalintas!\n";
                    rastas = true;
                    break;
                }
            }

            if (!rastas)
                cout << "Mokinys nerastas\n";
        }

        // Jei ivestas blogas pasirinkimas1
        else {
            cout << "Neteisingas pasirinkimas\n";
        }
    }

    return 0;
}