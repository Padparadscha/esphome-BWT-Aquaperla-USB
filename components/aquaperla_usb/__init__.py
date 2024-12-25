from esphome import automation
import esphome.config_validation as cv
import esphome.codegen as cg

# Namespace für unsere Komponente
aquaperla_usb_ns = cg.esphome_ns.namespace("aquaperla_usb")
AquaperlaUSB = aquaperla_usb_ns.class_("AquaperlaUSB", cg.Component)

# Schema für die Hauptkonfiguration in der YAML-Datei
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(AquaperlaUSB),
    cv.Required("device"): cv.string,  # Pfad zum USB-Gerät (z.B. /dev/ttyUSB0)
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    """Verbindung zwischen YAML und C++ herstellen."""
    var = cg.new_Pvariable(config[cv.GenerateID()])
    cg.add(var.set_device(config["device"]))
    await cg.register_component(var, config)
