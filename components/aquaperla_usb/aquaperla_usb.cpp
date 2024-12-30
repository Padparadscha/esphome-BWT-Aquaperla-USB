#include "aquaperla_usb.h"
#include "esphome/core/log.h"

namespace aquaperla_usb {

static const char *TAG = "aquaperla_usb";

// Setup-Methode
void AqaPerlaSensor::setup() {
  ESP_LOGCONFIG(TAG, "Setting up AqaPerlaSensor...");
}

// Update-Methode
void AqaPerlaSensor::update() {
  ESP_LOGD(TAG, "Sending command to query 24h consumption...");
  send_command(0x08);  // Befehl zum Abfragen des 24-Stunden-Verbrauchs
}

// Methode zum Senden eines Befehls
void AqaPerlaSensor::send_command(uint8_t command) {
  uint8_t crc = 0x0D + command + 1;  // Berechnung der Prüfsumme
  uint8_t data[] = {0x0D, command, 0x01, crc, 0x0A};
  this->write_array(data, sizeof(data));  // Daten über UART senden

  // Verarbeitung der Antwort
  this->process_response();
}

// Methode zum Verarbeiten der Antwort
void AqaPerlaSensor::process_response() {
  // Warte auf eine Antwort mit 5 Bytes
  delay(100);

  if (this->available() >= 5) {
    uint8_t response[5];
    this->read_array(response, 5);  // Antwortdaten lesen

    // Überprüfen, ob die Antwort auf unser Kommando passt
    if (response[1] == 0x08) {
      int value = response[3] + (response[4] << 8);  // Wert berechnen
      ESP_LOGI(TAG, "Received 24h consumption: %d L", value);
      this->verbrauch_24h->publish_state(value);  // Sensorwert veröffentlichen
    } else {
      ESP_LOGW(TAG, "Unexpected response received");
    }
  } else {
    ESP_LOGW(TAG, "No response or incomplete response received");
  }
}

}  // namespace aquaperla_usb
