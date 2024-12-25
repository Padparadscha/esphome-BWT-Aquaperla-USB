import esphome.config_validation as cv
from esphome.components import sensor
from esphome import core

# Definiere die Sensorklasse
class AquaperlaSensor(sensor.Sensor):
    def __init__(self, name, address, unit_of_measurement, update_interval, device_class=None):
        self._name = name
        self._address = address
        self._unit_of_measurement = unit_of_measurement
        self._update_interval = update_interval
        self._device_class = device_class
        self._state = None

    def update(self, state):
        """Aktualisiert den Wert des Sensors"""
        self._state = state
        self.publish_state(self._state)

    @property
    def name(self):
        return self._name

    @property
    def unit_of_measurement(self):
        return self._unit_of_measurement

    @property
    def device_class(self):
        return self._device_class

    @property
    def state(self):
        return self._state

    @property
    def update_interval(self):
        return self._update_interval

# Definiere, wie die Sensoren in YAML integriert werden
def validate_aquaperla_sensor(config):
    """Validiert die Sensor-Konfiguration"""
    return config

aquaperla_sensor = cv.Schema({
    cv.Required('name'): cv.string,
    cv.Required('address'): cv.string,
    cv.Required('unit_of_measurement'): cv.string,
    cv.Required('update_interval'): cv.time_period,
    cv.Optional('device_class', default=None): cv.string,
}).extend(cv.COMPONENT_SCHEMA)

# Sensoren zur Component-Hierarchie hinzufügen
def to_code(config):
    var = 'aquaperla_sensor'
    core.add_job(lambda: aquaperla_sensor(config))
    return var
