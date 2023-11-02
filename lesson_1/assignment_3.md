# Cohesion
Cohesion berättar om hur sammanhängande rutinerna och datan i en klass eller modul är. Om en klass har låg cohesion så kommer den klassen att nyttja många rutiner och värden utanför sig själv och arbetar inte heller mycket på sin egna data. När en klass har hög cohesion så betyder det att funktionerna och datan samspelar på ett bra sätt och har ett gemensamt syfte. I jämförelse med en klass som har dålig cohesion så kommer en klass med stark cohesion att vara mycket lättare att hantera och kommer att ha större sannolikhet att fortsätta fungera korrekt efter ändringar.

"Strong functional cohesion" betyder helt enkelt att en klass eller modul följer god praxis omkring cohesion och coupling, och ser till att vad den gör är sammanhängande och inte överskrider sitt ansvarsområde.

## Functional Cohesion
"Functional cohesion" är den starkaste och bästa formen av cohesion (enligt McConnell, bland andra) och sker när en rutin hanterar ett enda scenario. Denna sortens rutin skall alltså inte göra mer än vad dens namn säger att den gör.

## Logical Cohesion
"Logical cohesion" händer när man har flera subrutiner eller algoritmer som man placerar inuti en gemensam funktion där användaren kan välja vilken subrutin som ska köras med t.ex. en flagga som argument.

## Practical Examples (from McConnell)
sin(), GetCustomerName(), EraseFile(), CalculateLoanPayment(), and AgeFromBirthdate().
