#pragma once

#include "esphome/core/component.h"
#include <string>

namespace esphome {
namespace aquaperla_usb {

class AquaperlaUSB : public Component {
 public:
  void setup() override;
  void loop() override;

  // Debug-Methode
  std::string get_debug_message();
};

}  // namespace aquaperla_usb
}  // namespace esphome
