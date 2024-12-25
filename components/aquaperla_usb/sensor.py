import esphome.codegen as cg
import esphome.components.text_sensor as text_sensor
from esphome.const import CONF_ID

DEPENDENCIES = ['text_sensor']

aquaperla_ns = cg.esphome_ns.namespace('aquaperla_usb')
AquaperlaUSB = aquaperla_ns.class_('AquaperlaUSB', cg.Component)

CONFIG_SCHEMA = text_sensor.TEXT_SENSOR_SCHEMA.extend({
    cg.GenerateID(): cg.declare_id(AquaperlaUSB),
}).extend(cg.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    yield text_sensor.register_text_sensor(var, config)
