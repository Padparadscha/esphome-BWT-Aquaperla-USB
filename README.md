# esphome-BWT-Aquaperla-USB

Integration der BWT AQA Perla mit ESPHome.

## Übersicht

Dieses Projekt ermöglicht es, die BWT AQA Perla mit einem ESP32 oder ESP8266 zu verbinden, um relevante Daten auszulesen und in einer Smart-Home-Umgebung, wie Home Assistant, verfügbar zu machen.

---

## Befehle und Parameter

Die folgenden Kommandos wurden für die AQA Perla S identifiziert:

| **Code** | **Wert**                                      | **Parameter**   | **Kommentar**                              |
|----------|-----------------------------------------------|-----------------|--------------------------------------------|
| `0x01`   | Typ                                           | keine           | `12` = AQA Perla S                         |
| `0x02`   | Restkapazität Säule 1                        | keine           |                                            |
| `0x03`   | Restkapazität Säule 2                        | keine           |                                            |
| `0x04`   | Regenerationsschritt                         | keine           |                                            |
| `0x05`   | Verbrauchsdaten Allgemein Spitzendurchfluss  | keine           |                                            |
| `0x06`   | Verbrauchsdaten Allgemein Spitzendurchfluss 24h | keine         |                                            |
| `0x07`   | Verbrauchsdaten seit IBN Spitzendurchfluss   | keine           |                                            |
| `0x08`   | Verbrauchsdaten Allgemein Verbrauch 24h      | keine           |                                            |
| `0x09`   | Verbrauchsdaten seit IBN Verbrauch 24h       | keine           |                                            |
| `0x10`   | Verbrauchsdaten seit IBN Verbrauch           | keine           |                                            |
| `0x11`   | Regenerationen seit IBN                      | keine           |                                            |
| `0x12`   | Regenerationen seit letztem Service          | keine           |                                            |
| `0x13`   | Verbrauchsdaten seit IBN Salzverbrauch       | keine           |                                            |
| `0x14`   | Verbrauchsdaten seit IBN Reg-Mitteleinsparung | keine          |                                            |
| `0x15`   | IBN Datum                                    | keine           | Text                                       |
| `0x19`   | Softwareversion                              | keine           | Text                                       |
| `0x20`   | Abfrage Alarm                                | Zähler          |                                            |
| `0x21`   | Abfrage Log                                  | Monat           | Text                                       |
| `0x24`   | Abfrage KW                                   | KW Jahr         | Text                                       |
| `0x25`   | Sollkapazität Säule 1                       | keine           |                                            |
| `0x26`   | Sollkapazität Säule 2                       | keine           |                                            |
| `0x27`   | unbekannt                                    | unbekannt       |                                            |
| `0x28`   | unbekannt                                    | unbekannt       |                                            |

---

## Protokollaufbau

Das Kommunikationsprotokoll ist einfach strukturiert und besteht aus den folgenden Teilen:

1. **Startbyte**: `0x0D`
2. **Kommando**: Siehe Tabelle oben
3. **Anzahl der Parameter/Werte**: In Byte
4. **Parameter/Werte**
5. **Prüfsumme**: Summe aller bisher gesendeten Bytes (inkl. Startbyte)
6. **Stopbyte**: `0x0A`

Die von der AQA Perla gelieferten Werte werden in der Reihenfolge **LSB → HSB** gesendet.

---

## Dank an

Ein besonderer Dank geht an Dietmar für die bereitgestellten Informationen:  
[https://community.symcon.de/t/bwt-aqa-perla-goes-ip-symcon/35259](https://community.symcon.de/t/bwt-aqa-perla-goes-ip-symcon/35259)

---

## Lizenz

Dieses Projekt steht unter der [MIT-Lizenz](https://opensource.org/licenses/MIT).
