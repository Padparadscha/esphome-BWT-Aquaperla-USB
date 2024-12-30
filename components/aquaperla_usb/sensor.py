import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor, uart
from esphome.const import CONF_NAME, UNIT_LITERS, ICON_WATER

DEPENDENCIES = ["uart"]

aquaperla_ns = cg.esphome_ns.namespace("aquaperla_usb")
AqaPerlaSensor = aquaperla_ns.class_("AqaPerlaSensor", cg.PollingComponent, uart.UARTDevice)

CONFIG_SCHEMA = sensor.sensor_schema(UNIT_LITERS, ICON_WATER, 2).extend(
    {
        cv.GenerateID(): cv.declare_id(AqaPerlaSensor),
    }
)

async def to_code(config):
    # Initialisiere den Sensor
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    
    # Automatische UART-Konfiguration
    uart_config = uart.UARTDeviceConfig(
        tx_pin="TX",  # Pin kann hier geändert werden
        rx_pin="RX",
        baud_rate=19200,
        data_bits=8,
        stop_bits=1,
        parity="NONE"
    )
    cg.add(var.init_uart(uart_config))
