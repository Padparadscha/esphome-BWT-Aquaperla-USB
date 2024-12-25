# esphome-BWT-Aquaperla-USB

Connect BWT Aquaperla to ESPHome


on the Web I found following:

Folgende "Kommandos habe ich für die Aqa Perla S herausgefunden:

Code,Wert,Parameter,Kommentar
0x01,Typ,keine,12=Aqa Perla S
0x02,Restkapazität Säule 1,keine,
0x03,Restkapazität Säule 2,keine,
0x04,Regenerationsschritt,keine,
0x05,Verbrauchdaten Allgemein Spitzendurchfluss,keine,
0x06,Verbrauchdaten Allgemein Spitzendurchfluss 24h,keine,
0x07,Verbrauchdaten seit IBN Spitzendurchfluss,keine,
0x08,Verbrauchdaten Allgemein Verbrauch 24h,keine,
0x09,Verbrauchdaten seit IBN Verbrauch 24h,keine,
0x10,Verbrauchdaten seit IBN Verbrauch,keine,
0x11,Regenerationen seit IBN,keine,
0x12,Regenerationen seit letztem Service,keine,
0x13,Verbrauchdaten seit IBN Salzverbrauch,keine,
0x14,Verbrauchdaten seit IBN Reg-Mitteleinsparung,keine,
0x15,IBN Datum,keine,Text
0x19,Softwareversion,keine,Text
0x20,Abfrage Alarm,Zähler,
0x21,Abfrage Log,Monat,Text
0x24,Abfrage KW,KW Jahr,Text
0x25,Sollkapazität Säule 1,keine,
0x26,Sollkapazität Säule 2,keine,
0x27,unbekannt,unbekannt,
0x28,unbekannt,unbekannt,

Das Protokoll ist sehr einfach aufgebaut.
<Startbyte><Kommando><Anzahl der Parameter/Werte><Parameter/Werte><Prüfsumme><Stopbyte>
Startbyte=0x0d
Stopbyte=0x0A
Kommando=siehe Code in Tabelle
Anzahl der Parameter/Werte in Byte
Parameter/Werte
Summe aller bisher gesendeten Bytes incl. Startbyte
Stopbyte

Die von der Aqa Perla gelieferten Werte werden von LSB nach HSB gesendet.

Gruß,
Dietmar

thanks to for these informations:
https://community.symcon.de/t/bwt-aqa-perla-goes-ip-symcon/35259
