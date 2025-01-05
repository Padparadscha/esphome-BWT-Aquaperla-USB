#pragma once  // Verhindert, dass die Datei mehrfach eingebunden wird

#include "esphome/core/component.h"         // Basis-Komponente in ESPHome
#include "esphome/components/uart/uart.h"   // UART-Funktionalität
#include "esphome/components/sensor/sensor.h"  // Sensor-Basis in ESPHome

namespace aquaperla_usb {

/**
 * @brief AqaPerla-Sensor-Klasse für die Integration in ESPHome.
 * 
 * Diese Klasse implementiert die Kommunikation mit dem AqaPerla-Gerät
 * über UART und die Abfrage spezifischer Sensorwerte.
 */
class AquaPerlaSensor : public esphome::PollingComponent,  // Ermöglicht zyklische Updates
                       public esphome::uart::UARTDevice {  // Unterstützt UART-Kommunikation
 public:
  /**
   * @brief Konstruktor für die AqaPerla-Sensor-Klasse.
   * 
   * @param parent UART-Komponente, mit der dieses Gerät verbunden ist.
   */
  explicit AquaPerlaSensor(esphome::uart::UARTComponent *parent);

  /**
   * @brief Initialisiert den Sensor.
   * 
   * Diese Methode wird einmal beim Start von ESPHome aufgerufen.
   */
  void setup() override;

  /**
   * @brief Führt regelmäßige Updates durch.
   * 
   * Diese Methode wird gemäß dem definierten `update_interval` aufgerufen
   * und dient dazu, neue Daten vom AqaPerla-Gerät abzufragen.
   */
  void update() override;

  /**
   * @brief Sensor für den Wasserverbrauch der letzten 24 Stunden.
   */
  esphome::sensor::Sensor *verbrauch_24h = new esphome::sensor::Sensor();

 private:
  /**
   * @brief Sendet ein Kommando an das AqaPerla-Gerät.
   * 
   * Diese Methode erstellt eine Nachricht basierend auf dem definierten
   * Protokollaufbau und sendet sie über UART.
   * 
   * @param command Das zu sendende Kommando.
   */
  void send_command(uint8_t command);

  /**
   * @brief Verarbeitet die Antwort des Geräts.
   * 
   * Diese Methode liest die Antwort aus dem UART-Puffer, überprüft die Daten
   * und aktualisiert den Sensorwert.
   */
  void process_response();
};

}  // namespace aquaperla_usb
