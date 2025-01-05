#pragma once  // Verhindert, dass die Datei mehrfach eingebunden wird

#include "esphome/core/component.h"  // Basis-Komponentenklasse in ESPHome
#include "esphome/components/uart/uart.h"  // UART-Funktionalität
#include "esphome/components/sensor/sensor.h"  // Sensor-Basis für ESPHome

namespace aquaperla_usb {

/**
 * @brief Klasse für die AqaPerla-Sensor-Integration.
 * 
 * Diese Klasse ermöglicht die Kommunikation mit einem AqaPerla-Gerät
 * über UART und das Abfragen von Sensorwerten.
 */
class AqaPerlaSensor : public esphome::PollingComponent,  // Ermöglicht zyklische Updates
                       public esphome::uart::UARTDevice {  // Unterstützt UART-Kommunikation
 public:
  /**
   * @brief Konstruktor für die AqaPerla-Sensor-Klasse.
   * 
   * @param parent UART-Komponente, mit der dieses Gerät verbunden ist.
   */
  explicit AqaPerlaSensor(esphome::uart::UARTComponent *parent)
      : esphome::uart::UARTDevice(parent) {}

  /**
   * @brief Initialisiert den Sensor.
   * 
   * Diese Methode wird einmal beim Start von ESPHome aufgerufen und
   * dient der Einrichtung des Sensors.
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
  esphome::sensor::Sensor verbrauch_24h;

 private:
  /**
   * @brief Sendet ein Kommando an das AqaPerla-Gerät.
   * 
   * Diese Funktion sendet ein Kommando gemäß dem Protokollaufbau
   * an das angeschlossene Gerät.
   * 
   * @param command Das zu sendende Kommando (siehe Protokolldokumentation).
   */
  void send_command(uint8_t command);

  /**
   * @brief Verarbeitet die Antwort des Geräts.
   * 
   * Diese Methode liest die Antwort aus dem UART-Puffer,
   * dekodiert die Daten und aktualisiert die zugehörigen Sensorwerte.
   */
  void process_response();
};

}  // namespace aquaperla_usb
