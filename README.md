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

