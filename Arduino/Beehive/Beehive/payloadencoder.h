/*!
 \file payloadencoder.h
 \brief payloadencoder class
 \author Michelle Udo (m.udo@student.han.nl)
 \date See version table
 \version see version table

 # Version history

 Version|Date        |Note
 -------|------------|-----------------
 0.1    | 3-3-2020   | Initial version
 0.2    | 14-9-2020  | replaced exisiting implementenation fro one with a buffer, added setters and getters.


 */

#ifndef MYPAYLOADENCODER_H
#define MYPAYLOADENCODER_H

#include <stdint.h>

const uint8_t SENSOR_PAYLOAD_SIZE = 52;     ///< Maximum payload size for sensor data

/// \brief payload endoder class
/// This class wil encode variables for the LoRaWAN application in to a single payload
/// The class is setup using both .h and .cpp files where the setters and getters are
/// placed in to the .cpp file.
class myPayloadEncoder
{
private:
    uint8_t _payloadIdentifier;  ///< Payload identification number
    uint8_t _battery;            ///< Battery level
    uint8_t _position;           ///< Position beehive
    uint8_t _beeactivitySensor;  ///< Sound sensor to measure bee activity in hive
    uint8_t _beeAlarm;            ///< Alarm is sent when bees are swarming
    uint8_t _honey;              ///< Amount of honey produced (in Kilograms)
    int32_t _latitude;           ///< GPS latitude
    int32_t _longitude;          ///< GPS longitude

    uint8_t *_buffer;            ///< Buffer containing payload with sensor data
    uint8_t _bufferSize;         ///< Size of payload for housekeeping.

    /// \brief add int32 to payload
    /// \param idx_in start location in _buffer
    /// \param value int32_t value
    /// \return First free location at which new data can be stored in _buffer
    unsigned char add_int32 (unsigned char idx_in, const int32_t value);

    /// \brief add uint8 to payload
    /// \param idx_in start location in _buffer
    /// \param value uint8_t value
    /// \return First free location at which new data can be stored in _buffer
    unsigned char add_uint8 (unsigned char idx_in, const uint8_t value);

public:
    myPayloadEncoder();     ///< Constructor
    ~myPayloadEncoder();    ///< Destructor

    /// \brief "Setter" to set _payloadIdentifier variable
    /// \param[in] var variable of the type unsigned integer of one byte
    void setPayloadIdentifier(const uint8_t var){_payloadIdentifier = static_cast<uint8_t>(var);}

    /// \brief "Setter" to set _battery variable
    /// \param[in] var variable of the type unsigned integer of one byte
    void setBattery(const uint8_t var){_battery = static_cast<uint8_t>(var);}

    /// \brief "Setter" to set _position variable
    /// \param[in] var variable of the type unsigned integer of one byte
    void setPosition(const uint8_t var){_position = static_cast<uint8_t>(var);}

    /// \brief "Setter" to set _beeactivitySensor variable
    /// \param[in] var variable of the type unsigned integer of one byte
    void setbeeactivitySensor(const uint8_t var){_beeactivitySensor = static_cast<uint8_t>(var);}

    /// \brief "Setter" to set _honey variable
    /// \param[in] var variable of the type unsigned integer of one byte
    void sethoney(const uint8_t var){_honey = static_cast<uint8_t>(var);}

    /// \brief "Setter" to set _latitude variable
    /// \param[in] var variable of the type signed integer of four bytes
    void setLatitude(const int32_t var){_latitude = static_cast<int32_t>(var);}

    /// \brief "Setter" to set _longitude variable
    /// \param[in] var variable of the type signed integer of four bytes
    void setLongitude(const int32_t var){_longitude = static_cast<int32_t>(var);}

    /// \brief "Setter" to set _beeAlarm variable
    /// \param[in] var variable of the type unsigned integer of one byte
    void setbeeAlarm(const uint8_t var){_beeAlarm = static_cast<uint8_t>(var);}

    /// \brief compose main payload
    /// \pre all variables that shall be added to the payload shall be set.
    void composePayloadMain();

    /// \brief compose GPS payload
    /// \pre all variables that shall be added to the payload shall be set.
    void composePayloadGPS();

    /// \brief get payload size.
    /// \return buffer size in bytes
    uint8_t getPayloadSize(){return _bufferSize;}

    /// \brief get payload.
    /// \return pointer to buffer
    uint8_t *getPayload(){return _buffer;}
};

#endif // PAYLOADENCODER_H
