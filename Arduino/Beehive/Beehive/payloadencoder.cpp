#include "payloadencoder.h"
#include <stdlib.h>

myPayloadEncoder::myPayloadEncoder():
    _payloadIdentifier {0},
    _battery {0},
    _position {0},
    _beeAlarm{0},
    _beeactivitySensor {0},
    _honey {0},
    _latitude {0},
    _longitude {0},
    _bufferSize {0}
{
    _buffer = static_cast<uint8_t *>(malloc(SENSOR_PAYLOAD_SIZE));
}

myPayloadEncoder::~myPayloadEncoder()
{
    free(_buffer);
}

void myPayloadEncoder::composePayloadMain()
{
    _bufferSize = 0;
    _bufferSize = add_uint8(_bufferSize, _payloadIdentifier);
    _bufferSize = add_uint8(_bufferSize, _battery);
    _bufferSize = add_uint8(_bufferSize, _beeactivitySensor);
    _bufferSize = add_uint8(_bufferSize, _honey);
}

void myPayloadEncoder::composePayloadGPS()
{
    _bufferSize = 0;
    _bufferSize = add_uint8(_bufferSize, _payloadIdentifier);
    _bufferSize = add_int32(_bufferSize, _latitude);
    _bufferSize = add_int32(_bufferSize, _longitude);
    _bufferSize = add_uint8(_bufferSize, _position);
    _bufferSize = add_uint8(_bufferSize, _beeAlarm);
}



unsigned char myPayloadEncoder::add_uint8 (unsigned char idx_in, const uint8_t value) {
    _buffer[idx_in++] = (value) & 0xFF;
    return (idx_in);
}

unsigned char myPayloadEncoder::add_int32 (unsigned char idx_in, int32_t value) {
   for (uint8_t i=0; i<4; i++) {
        _buffer[idx_in++] = (value >> 24) & 0xFF;
        value = value << 8;
    }
    return (idx_in);
}
