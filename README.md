# Automobilių duomenų valdymo sistema

## Projekto tikslas
Sukurti C++ konsolinę programą, kuri leidžia valdyti automobilių duomenis, taikant struktūrinio programavimo principus, darbą su failais ir CRUD operacijas.

## Projekto tema
Automobilių duomenų valdymo sistema. Programa leidžia saugoti, peržiūrėti, redaguoti ir šalinti automobilių įrašus, taip pat atlikti paiešką ir rikiavimą pagal pasirinktus kriterijus.

## Programos funkcionalumas

###  CRUD funkcijos
- **Create** – naujo automobilio įrašymas.
- **Read** – visų automobilių peržiūra lentelės formatu.
- **Update** – automobilio redagavimas pagal ID.
- **Delete** – automobilio pašalinimas pagal ID.

###  Papildomos funkcijos
- **Paieška pagal markę** – vartotojas įveda markę, programa išveda visus ją atitinkančius automobilius.
- **Rikiavimas pagal kainą** – galima pasirinkti rikiavimą didėjančia arba mažėjančia tvarka.

###  Failų naudojimas
- Programa nuskaito duomenis iš failo **cars.txt**.
- Programa gali išsaugoti pakeistus duomenis atgal į failą.
- Failas naudoja CSV formato struktūrą su `;` skyrikliu.

## Naudojami failai

### `main.cpp`
Pagrindinis programos failas, kuriame yra:
- struktūra `Car`
- CRUD funkcijos
- papildomos funkcijos (paieška, rikiavimas)
- meniu sistema
- failų nuskaitymas ir išsaugojimas

### `cars.txt`
Pradinis duomenų failas su bent 15 įrašų.  
Formatas:


## Programos paleidimas

1. Atsisiųskite projektą iš GitHub.
2. Įsitikinkite, kad failas **cars.txt** yra šalia `main.cpp` arba programos `.exe`.
3. Atidarykite projektą Code::Blocks arba kompiliuokite terminale:


4. Paleiskite programą:


5. Sekite ekrane rodomą meniu ir pasirinkite norimus veiksmus.

## Naudotos programavimo konstrukcijos
- Kintamieji ir pagrindiniai duomenų tipai (`int`, `double`, `string`)
- Sąlygos: `if`, `else`, `switch`
- Ciklai: `for`, `while`, `do-while`
- Funkcijos
- Vartotojo sukurta struktūra `struct Car`
- Duomenų kolekcija `vector<Car>`
- Failų nuskaitymas (`ifstream`) ir rašymas (`ofstream`)
- Duomenų apdorojimas naudojant `stringstream` ir `algorithm`

## Išvados
Projektas įgyvendina visus reikalavimus:
- CRUD operacijos
- Papildomos funkcijos
- Darbas su failais
- Struktūrinis programavimas
- Aiški meniu sąsaja

Studentas gali paaiškinti:
- kaip veikia failų nuskaitymas
- kaip realizuotos CRUD funkcijos
- kaip veikia paieška ir rikiavimas
- kodėl naudojamas `vector` ir `struct`
