# CRC
CRC (Class, Responsibility, Collaboration) är en modelleringsmetod som används inom objektorienterad systemutveckling och mjukvaruarkitektur. Det hjälper till att skapa en strukturerad förståelse för ett system och dess komponenter, speciellt när man utvecklar mjukvaruapplikationer med hjälp av objektorienterade principer.

## Hur:
CRC-modellering används ofta under den tidiga design- och analysfasen av systemutveckling. Syftet är att definiera de grundläggande klasserna som kommer att ingå i systemet, deras ansvar och hur de kommer att samarbeta med varandra. Här är en översikt över de tre huvudkomponenterna i CRC-modellering:

1. Class (Klass): I detta sammanhang representerar "klass" en abstrakt beskrivning av en komponent eller entitet i systemet. En klass kan tänkas som en blåsprint eller mall för att skapa objekt. Varje klass har attribut och metoder som beskriver dess egenskaper och beteende.

2. Responsibility (Ansvar): "Ansvar" refererar till vad en klass är ansvarig för inom systemet. Det handlar om att definiera och dokumentera de specifika uppgifter och funktioner som en klass måste utföra för att uppfylla systemets krav. Genom att klargöra ansvarsområden för varje klass blir det lättare att organisera och strukturera systemet.

3. Collaboration (Samarbete): "Samarbete" handlar om hur klasserna interagerar med varandra för att uppnå systemets funktionalitet. Det beskriver de relationer och kommunikationsmönster som finns mellan klasserna. Genom att identifiera och modellera dessa samarbetsrelationer kan man förstå hur olika klasser samverkar för att uppfylla systemets mål.

## Varför:
CRC-modellering är viktigt av flera skäl:

1. Klarhet: Det hjälper till att skapa en tydlig och förståelig beskrivning av systemets struktur och funktion.

2. Kommunikation: Det underlättar kommunikationen mellan utvecklare, designers och intressenter, eftersom det ger en gemensam modell som alla kan använda som grund för diskussion.

3. Design och arkitektur: Det är ett verktyg som hjälper utvecklare att planera och designa mjukvarusystem på ett organiserat sätt, vilket i sin tur kan leda till mer robusta och underhållbara system.

4. Flexibilitet: Genom att tydligt definiera ansvarsområden och samarbetsmönster kan systemet vara mer flexibelt och anpassningsbart till förändrade krav och behov.

## Sammanfattning:
Sammanfattningsvis används CRC-modellering inom mjukvaruutveckling för att skapa en strukturerad och förståelig modell av ett system genom att definiera klasser, deras ansvar och hur de samarbetar. Detta hjälper utvecklare att skapa bättre mjukvarusystem och underlättar kommunikationen inom utvecklingsteamet och med intressenterna.

CRC-kort ser i princip ut som tabell Överst finns en rad där man skriver klassens namn. Resten av kortet
är delat vertikalt. Till vänster anges klassens ansvar och för varje sådant ansvar anger man till höger vilka
andra klasser som samarbete förekommer me

| Beställning | |
---
| Kontrollera om vara finns i lager | Beställningsrad, Lager |
| Bestäm pris                       | Beställningsrad, Prislista |
| Kontrollera betalning             | Kund |
| Avsänd till leveransadress        | Kund |


