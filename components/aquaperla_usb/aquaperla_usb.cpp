#include "aquaperla_usb.h"
#include "esphome/core/log.h"

namespace aquaperla_usb {

static const char *TAG = "aquaperla_usb";  // Logging-Tag für die AqaPerla-Integration

/**
 * @brief Setup-Methode für den Sensor.
 * 
 * Diese Methode wird einmal beim Start von ESPHome aufgerufen,
 * um den Sensor initial einzurichten.
 */
void AqaPerlaSensor::setup() {
  ESP_LOGCONFIG(TAG, "Setting up AqaPerlaSensor...");
}

/**
 * @brief Update-Methode für den Sensor.
 * 
 * Diese Methode wird gemäß dem `update_interval` aufgerufen,
 * um neue Daten vom Gerät abzufragen.
 */
void AqaPerlaSensor::update() {
  ESP_LOGD(TAG, "Sending command to query 24h consumption...");
  send_command(0x08);  // Befehl zum Abfragen des 24-Stunden-Verbrauchs
}

/**
 * @brief Sendet ein Kommando an das Gerät.
 * 
 * Diese Methode erstellt eine Nachricht basierend auf dem
 * definierten Protokollaufbau und sendet sie über UART.
 * 
 * @param command Das zu sendende Kommando.
 */
void AqaPerlaSensor::send_command(uint8_t command) {
  // Berechnung der Prüfsumme
  uint8_t crc = 0x0D + command + 1;

  // Aufbau des Datenpakets: <Startbyte><Kommando><Länge><CRC><Stopbyte>
  uint8_t data[] = {0x0D, command, 0x01, crc, 0x0A};

  // Senden der Daten über UART
  this->write_array(data, sizeof(data));

  // Verarbeitung der Antwort
  this->process_response();
}

/**
 * @brief Verarbeitet die Antwort vom Gerät.
 * 
 * Diese Methode liest die Antwort aus dem UART-Puffer,
 * überprüft die Daten und aktualisiert den Sensorwert.
 */
void AqaPerlaSensor::process_response() {
  // Wartezeit, um sicherzustellen, dass die Antwort vollständig ist
  delay(100);

  // Prüfen, ob genügend Daten im UART-Puffer verfügbar sind
  if (this->available() >= 5) {
    uint8_t response[5];
    this->read_array(response, 5);  // Antwortdaten auslesen

    // Überprüfen, ob die Antwort auf das gesendete Kommando passt
    if (response[1] == 0x08) {  // Überprüfen, ob es sich um Verbrauchsdaten handelt
      int value = response[3] + (response[4] << 8);  // Wert aus LSB und MSB berechnen
      ESP_LOGI(TAG, "Received 24h consumption: %d L", value);

      // Aktualisieren des Sensorwerts
      this->verbrauch_24h->publish_state(value);
    } else {
      ESP_LOGW(TAG, "Unexpected response received");
    }
  } else {
    ESP_LOGW(TAG, "No response or incomplete response received");
  }
}

}  // namespace aquaperla_usb
