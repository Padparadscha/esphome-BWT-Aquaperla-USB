#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"

namespace esphome {
namespace aquaperla_usb {

class AquaperlaUSB : public Component {
 public:
  void setup() override;
  void loop() override;

  // Beispiel: Debug-Nachricht
  std::string get_debug_message();

  // Sensoren
  sensor::Sensor *verbrauch_24h_sensor = nullptr;
};

}  // namespace aquaperla_usb
}  // namespace esphome
