#include "aquaperla_usb.h"

namespace esphome {
namespace aquaperla_usb {

void AquaperlaUSB::setup() {
  ESP_LOGCONFIG(TAG, "Setting up AquaperlaUSB component...");
}

void AquaperlaUSB::loop() {
  // Hier könnte Code für die USB-Kommunikation stehen.
}

std::string AquaperlaUSB::get_debug_message() {
  return "Hello from AquaperlaUSB!";
}

}  // namespace aquaperla_usb
}  // namespace esphome
