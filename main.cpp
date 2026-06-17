#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


struct Car {
    int id;
    string make;
    string model;
    int year;
    int mileage;
    double price;
};


void loadFromFile(const string& filename, vector<Car>& cars);
void saveToFile(const string& filename, const vector<Car>& cars);

void listCars(const vector<Car>& cars);
void createCar(vector<Car>& cars);
void updateCar(vector<Car>& cars);
void deleteCar(vector<Car>& cars);

void searchByMake(const vector<Car>& cars);
void sortByPrice(vector<Car>& cars);

void showMenu();


void loadFromFile(const string& filename, vector<Car>& cars) {
    cars.clear();
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Nepavyko atidaryti failo: " << filename << endl;
        return;
    }

    string line;
    getline(in, line);

    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string token;
        Car c;

        getline(ss, token, ';');
        c.id = stoi(token);

        getline(ss, c.make, ';');
        getline(ss, c.model, ';');

        getline(ss, token, ';');
        c.year = stoi(token);

        getline(ss, token, ';');
        c.mileage = stoi(token);

        getline(ss, token, ';');
        c.price = stod(token);

        cars.push_back(c);
    }

    in.close();
}


void saveToFile(const string& filename, const vector<Car>& cars) {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "Nepavyko atidaryti failo rasymui: " << filename << endl;
        return;
    }

    out << "ID;Marke;Modelis;Metai;Rida;Kaina\n";
    for (const auto& c : cars) {
        out << c.id << ";"
            << c.make << ";"
            << c.model << ";"
            << c.year << ";"
            << c.mileage << ";"
            << c.price << "\n";
    }

    out.close();
}


void listCars(const vector<Car>& cars) {
    if (cars.empty()) {
        cout << "Nera irasu." << endl;
        return;
    }

    cout << "--------------------------------------------------------\n";
    cout << "ID  Marke   Modelis   Metai   Rida     Kaina\n";
    cout << "--------------------------------------------------------\n";
    for (const auto& c : cars) {
        cout << c.id << "  "
             << c.make << "  "
             << c.model << "  "
             << c.year << "  "
             << c.mileage << "  "
             << c.price << endl;
    }
    cout << "--------------------------------------------------------\n";
}


void createCar(vector<Car>& cars) {
    Car c;
    int maxId = 0;
    for (const auto& car : cars) {
        if (car.id > maxId) maxId = car.id;
    }
    c.id = maxId + 1;

    cout << "Iveskite marke: ";
    getline(cin, c.make);
    cout << "Iveskite modeli: ";
    getline(cin, c.model);
    cout << "Iveskite metus: ";
    cin >> c.year;
    cout << "Iveskite rida: ";
    cin >> c.mileage;
    cout << "Iveskite kaina: ";
    cin >> c.price;
    cin.ignore();

    cars.push_back(c);
    cout << "Automobilis pridetas. ID: " << c.id << endl;
}


void updateCar(vector<Car>& cars) {
    if (cars.empty()) {
        cout << "Nera irasu." << endl;
        return;
    }

    int id;
    cout << "Iveskite automobilio ID, kuri norite redaguoti: ";
    cin >> id;
    cin.ignore();

    bool found = false;
    for (auto& c : cars) {
        if (c.id == id) {
            found = true;
            cout << "Redaguojamas: " << c.make << " " << c.model << endl;

            cout << "Nauja marke (palikite tuscia, jei nekeisite): ";
            string input;
            getline(cin, input);
            if (!input.empty()) c.make = input;

            cout << "Naujas modelis (palikite tuscia, jei nekeisite): ";
            getline(cin, input);
            if (!input.empty()) c.model = input;

            cout << "Nauji metai (0 - nekeisti): ";
            int year;
            cin >> year;
            if (year != 0) c.year = year;

            cout << "Nauja rida (0 - nekeisti): ";
            int mileage;
            cin >> mileage;
            if (mileage != 0) c.mileage = mileage;

            cout << "Nauja kaina (0 - nekeisti): ";
            double price;
            cin >> price;
            if (price != 0) c.price = price;
            cin.ignore();

            cout << "Irasas atnaujintas." << endl;
            break;
        }
    }

    if (!found) cout << "Automobilis su tokiu ID nerastas." << endl;
}


void deleteCar(vector<Car>& cars) {
    if (cars.empty()) {
        cout << "Nera irasu." << endl;
        return;
    }

    int id;
    cout << "Iveskite automobilio ID, kuri norite pasalinti: ";
    cin >> id;
    cin.ignore();

    auto it = remove_if(cars.begin(), cars.end(), [id](const Car& c) {
        return c.id == id;
    });

    if (it != cars.end()) {
        cars.erase(it, cars.end());
        cout << "Automobilis pasalintas." << endl;
    } else {
        cout << "Automobilis su tokiu ID nerastas." << endl;
    }
}


void searchByMake(const vector<Car>& cars) {
    cout << "Iveskite marke paieskai: ";
    string make;
    getline(cin, make);

    bool found = false;
    for (const auto& c : cars) {
        if (c.make == make) {
            if (!found) {
                cout << "Rasti automobiliai:\n";
                cout << "ID  Marke   Modelis   Metai   Rida     Kaina\n";
            }
            found = true;
            cout << c.id << "  "
                 << c.make << "  "
                 << c.model << "  "
                 << c.year << "  "
                 << c.mileage << "  "
                 << c.price << endl;
        }
    }

    if (!found) cout << "Automobiliu su tokia marke nerasta." << endl;
}


void sortByPrice(vector<Car>& cars) {
    cout << "Rikiuoti pagal kaina (1 - didejanciai, 2 - mazejanciai): ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.price < b.price;
        });
        cout << "Surikiuota didejanciai pagal kaina." << endl;
    } else if (choice == 2) {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.price > b.price;
        });
        cout << "Surikiuota mazejanciai pagal kaina." << endl;
    } else {
        cout << "Neteisingas pasirinkimas." << endl;
    }
}


void showMenu() {
    cout << "\n===== Automobiliu duomenu valdymo sistema =====\n";
    cout << "1. Perziureti visus automobilius\n";
    cout << "2. Prideti nauja automobili\n";
    cout << "3. Redaguoti automobili\n";
    cout << "4. Pasalinti automobili\n";
    cout << "5. Paieska pagal marke\n";
    cout << "6. Rikiuoti pagal kaina\n";
    cout << "7. Issaugoti i faila\n";
    cout << "0. Baigti darba\n";
    cout << "Pasirinkite: ";
}


int main() {
    string filename = "cars.txt";
    vector<Car> cars;

    loadFromFile(filename, cars);

    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                listCars(cars);
                break;
            case 2:
                createCar(cars);
                break;
            case 3:
                updateCar(cars);
                break;
            case 4:
                deleteCar(cars);
                break;
            case 5:
                searchByMake(cars);
                break;
            case 6:
                sortByPrice(cars);
                break;
            case 7:
                saveToFile(filename, cars);
                cout << "Duomenys issaugoti i faila." << endl;
                break;
            case 0:
                cout << "Programa baigia darba." << endl;
                break;
            default:
                cout << "Neteisingas pasirinkimas." << endl;
        }

    } while (choice != 0);

    return 0;
}
