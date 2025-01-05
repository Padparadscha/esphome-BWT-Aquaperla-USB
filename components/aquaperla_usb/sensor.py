import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor, uart
from esphome.const import CONF_ID, UNIT_LITERS, ICON_WATER

# Definiere Abhängigkeit von der UART-Komponente
DEPENDENCIES = ["uart"]

# Namespace für die benutzerdefinierte C++-Komponente
aquaperla_ns = cg.esphome_ns.namespace("aquaperla_usb")
AqaPerlaSensor = aquaperla_ns.class_("AqaPerlaSensor", cg.PollingComponent, uart.UARTDevice)

# Schema für die YAML-Konfiguration
CONFIG_SCHEMA = sensor.sensor_schema(UNIT_LITERS, ICON_WATER, 2).extend(
    {
        cv.GenerateID(): cv.declare_id(AqaPerlaSensor),  # ID der benutzerdefinierten Komponente
    }
)

# Methode zur Code-Generierung
async def to_code(config):
    # Initialisiere die C++-Komponente
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)  # Registriere die Komponente als ESPHome-Element
    await sensor.register_sensor(var, config)  # Registriere die Sensor-Funktionalität

    # UART-Konfiguration für die Kommunikation
    uart_config = await uart.new_uart_device(config)
    cg.add(var.init_uart(uart_config))
