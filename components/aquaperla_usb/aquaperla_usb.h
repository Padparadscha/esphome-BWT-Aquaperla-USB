#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"
#include "esphome/components/sensor/sensor.h"

namespace aquaperla_usb {

class AqaPerlaSensor : public esphome::PollingComponent, public esphome::uart::UARTDevice {
 public:
  // Konstruktor
  AqaPerlaSensor(esphome::uart::UARTComponent *parent) : esphome::uart::UARTDevice(parent) {}

  // Initialisierung
  void setup() override;

  // Regelmäßiges Update
  void update() override;

  // Verbrauchssensor
  esphome::sensor::Sensor *verbrauch_24h = new esphome::sensor::Sensor();

 private:
  void send_command(uint8_t command);
  void process_response();
};

}  // namespace aquaperla_usb
