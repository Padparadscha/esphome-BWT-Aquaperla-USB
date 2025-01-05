import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor, uart
from esphome.const import CONF_ID

aquaperla_usb_ns = cg.esphome_ns.namespace('aquaperla_usb')
AqaPerlaSensor = aquaperla_usb_ns.class_('AqaPerlaSensor', cg.Component, uart.UARTDevice)

CONFIG_SCHEMA = (
    cv.Schema({
        cv.GenerateID(): cv.declare_id(AqaPerlaSensor),
    })
    .extend(cv.COMPONENT_SCHEMA)
    .extend(uart.UART_DEVICE_SCHEMA)
)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await uart.register_uart_device(var, config)
