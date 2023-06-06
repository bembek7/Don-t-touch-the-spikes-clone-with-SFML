# PROI Projekt nr 5

Projekt polega na adaptacji na PC gry mobilnej "Don't touch the spikes".

Screenshot z gry:

![Example game looks](./screenshots/example_game1.jpg)

Gracz steruje ptakiem i jego celem jest jak najdłużej utrzymać się w grze, nie dotykając kolców.
Ptak poddany jest sile symulującej grawitację więc ciągle spada w dół na kolce, jednocześnie również leci on w jedną stronę, a po odbiciu się od ściany w drugą. Gracz ma jedną opcje sterowania - nadanie siły, która wyrzuca ptaka do góry.
Góra i dół są zawsze pokryte kolcami, a kolce na ścianach są generowane losowo po odbiciu się gracza od przeciwnej ściany.

Mechaniki do zaimplementowania:

-stworzenia ptaka i poddanie go grawitacji,

-sprawienie, żeby ptak leciał do ściany i odbijał się od niej,

-input gracza - wyrzucenie ptaka w górę,

-generowanie kolców po odbiciu, zawsze tak, by gracz miał możliwość odbicia,

-zwiększanie prędkości gracza po każdym odbiciu.

-zapis/odczyt do/z pliku

Technologia, której używamy: biblioteka SFML

Krótki opis projektu:

1. BoxCollider:
   - reprezentuje prostokątny kolider, posiada metody umożliwiające ustawianie pozycji, szerokości i wysokości kolidera, sprawdzanie kolizji z innymi koliderami, pobieranie pozycji kolidera, oraz ustawianie stanu aktywności kolidera.

2. Spike.hpp:
   - reprezentuje kolec - przeszkodę dla gracza, kolce mogą być obracane i przesuwane, można sprawdzić kolizję z igraczem oraz ustawić ich widoczność.

3. Player.hpp:
   - reprezentuje gracza, zapewnia funkcjonalności związane z ruchem gracza, animacją oraz skokami.

4. Level.hpp:
   - reprezentuje poziom - mapę, po której porusza się gracz.
   - zarządza kolcami na planszy, sprawdza kolizje z graczem, rysuje kolce oraz obsługuje logikę gry.

5. Klasa Game:
   - Klasa "Game" zarządza poziomami, aktualizuje logikę gry, obsługuje wejście użytkownika oraz renderuje grafikę.
