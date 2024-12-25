#pragma once

#include "esphome.h"

class AquaperlaUSB : public PollingComponent {
 public:
  // Konstruktor
  AquaperlaUSB();

  // Funktion, um die Komponente zu initialisieren
  void setup() override;

  // Funktion, um periodische Aufgaben auszuführen
  void update() override;

  // Beispiel für ein Sensor-Objekt (Wasserverbrauch, Regenerationen, etc.)
  Sensor *verbrauch_24h_sensor = new Sensor();
  Sensor *regenerationen_seit_ibn_sensor = new Sensor();

 private:
  // Weitere private Member-Variablen können hier definiert werden, z.B. UART-Kommunikation
  UARTComponent *uart_ = nullptr;
};
