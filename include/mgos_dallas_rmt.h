#pragma once
#include <stdbool.h>
#include <stdint.h>

#include "mgos_onewire_rmt.h"
#ifdef __cplusplus
#include "DallasRmt.h"
#else
typedef struct DallasRmtTag DallasRmt;
typedef struct OnewireRmtTag OnewireRmt;
#endif

#ifdef __cplusplus
extern "C"
{
#endif
    /* Initializes the DallasRmt driver with a `OnewireRmt*` object.
     * Return value: handle opaque pointer.
     */
    DallasRmt *mgos_dallas_rmt_create(OnewireRmt* ow);

    /* Initializes the DallasRmt driver with a GPIO `pin`, the RMT receive channel `rmt_rx`
     * and the RMT transmit channel `rmt_tx`.
     * Return value: handle opaque pointer.
     */
    DallasRmt* mgos_dallas_rmt_create_with_channels(uint8_t pin, uint8_t rmt_rx, uint8_t rmt_tx);

    /*
     *  Close DallasRmt handle. Return value: none.
     */
    void mgos_dallas_rmt_close(DallasRmt *dt);

    /*
     *  Initialises the 1-Wire bus.
     */
    void mgos_dallas_rmt_begin(DallasRmt *dt);

    /* 
     * Returns the number of devices found on the bus.
     * Return always 0 if an operaiton failed.
     */
    int mgos_dallas_rmt_get_device_count(DallasRmt *dt);

    /*
     * Returns true if address is valid.
     * Return always false if an operaiton failed.
     */
    bool mgos_dallas_rmt_valid_address(DallasRmt *dt, const char *addr);

    /*
     * Returns true if address is of the family of sensors the lib supports.
     * Return always false if an operaiton failed.
     */
    bool mgos_dallas_rmt_valid_family(DallasRmt *dt, const char *addr);

    /*
     * Finds an address at a given index on the bus.
     * Return false if the device was not found or an operaiton failed.
     * Returns true otherwise.
     */
    bool mgos_dallas_rmt_get_address(DallasRmt *dt, char *addr, int idx);

    /*
     * Attempt to determine if the device at the given address is connected to the bus.
     * Return false if the device is not connected or an operaiton failed.
     * Returns true otherwise.
     */
    bool mgos_dallas_rmt_is_connected(DallasRmt *dt, const char *addr);

    /*
     * Attempts to determine if the device at the given address is connected to the bus.
     * Also allows for updating the read scratchpad.
     * Return false if the device is not connected or an operaiton failed.
     * Returns true otherwise.
     */
    bool mgos_dallas_rmt_is_connected_sp(DallasRmt *dt, const char *addr, char *sp);

    /*
     * Reads device's scratchpad.
     * Returns false if an operaiton failed.
     * Returns true otherwise.
     */
    bool mgos_dallas_rmt_read_scratch_pad(DallasRmt *dt, const char *addr, char *sp);

    /*
     * Writes device's scratchpad.
     */
    void mgos_dallas_rmt_write_scratch_pad(DallasRmt *dt, const char *addr, const char *sp);

    /*
     * Read device's power requirements.
     * Return true if device needs parasite power.
     * Return always false if an operaiton failed.
     */
    bool mgos_dallas_rmt_read_power_supply(DallasRmt *dt, const char *addr);

    /*
     * Get global resolution.
     */
    int mgos_dallas_rmt_get_global_resolution(DallasRmt *dt);

    /*
     * Set global resolution to 9, 10, 11, or 12 bits.
     */
    void mgos_dallas_rmt_set_global_resolution(DallasRmt *dt, int res);

    /*
     * Returns the device resolution: 9, 10, 11, or 12 bits.
     * Returns 0 if device not found or if an operation failed.
     */
    int mgos_dallas_rmt_get_resolution(DallasRmt *dt, const char *addr);

    /*
     * Set resolution of a device to 9, 10, 11, or 12 bits.
     * If new resolution is out of range, 9 bits is used.
     * Return true if a new value was stored.
     * Returns false otherwise.
     */
    bool mgos_dallas_rmt_set_resolution(DallasRmt *dt, const char *addr, int res, bool skip_global_calc);

    /*
     * Sets the waitForConversion flag.
     */
    void mgos_dallas_rmt_set_wait_for_conversion(DallasRmt *dt, bool f);

    /*
     * Gets the value of the waitForConversion flag.
     * Return always false if an operaiton failed.
     */
    bool mgos_dallas_rmt_get_wait_for_conversion(DallasRmt *dt);

    /*
     * Sets the checkForConversion flag.
     */
    void mgos_dallas_rmt_set_check_for_conversion(DallasRmt *dt, bool f);

    /*
     * Gets the value of the waitForConversion flag.
     * Return always false if an operaiton failed.
     */
    bool mgos_dallas_rmt_get_check_for_conversion(DallasRmt *dt);

    /*
     * Sends command for all devices on the bus to perform a temperature conversion.
     * Returns false if a device is disconnected or if an operaiton failed.
     * Returns true otherwise.
     */
    void mgos_dallas_rmt_request_temperatures(DallasRmt *dt);

    /*
     * Sends command for one device to perform a temperature conversion by address.
     * Returns false if a device is disconnected or if an operaiton failed.
     * Returns true otherwise.
     */
    bool mgos_dallas_rmt_request_temperatures_by_address(DallasRmt *dt, const char *addr);

    /*
     * Sends command for one device to perform a temperature conversion by index.
     * Returns false if a device is disconnected or if an operaiton failed.
     * Returns true otherwise.
     */
    bool mgos_dallas_rmt_request_temperatures_by_index(DallasRmt *dt, int idx);

    /*
     * Returns temperature raw value (12 bit integer of 1/128 degrees C)
     * or DEVICE_DISCONNECTED_RAW if an operaiton failed.
     */
    int16_t mgos_dallas_rmt_get_temp(DallasRmt *dt, const char *addr);

    /*
     * Returns temperature in degrees C * 100
     * or DEVICE_DISCONNECTED_C if an operaiton failed.
     */
    int mgos_dallas_rmt_get_tempc(DallasRmt *dt, const char *addr);

    /*
     * Returns temperature in degrees F * 100
     * or DEVICE_DISCONNECTED_F if an operaiton failed.
     */
    int mgos_dallas_rmt_get_tempf(DallasRmt *dt, const char *addr);

    /*
     * Returns temperature for device index in degrees C * 100 (slow)
     * or DEVICE_DISCONNECTED_C if an operaiton failed.
     */
    int mgos_dallas_rmt_get_tempc_by_index(DallasRmt *dt, int idx);

    /*
     * Returns temperature for device index in degrees F * 100 (slow)
     * or DEVICE_DISCONNECTED_F if an operaiton failed.
     */
    int mgos_dallas_rmt_get_tempf_by_index(DallasRmt *dt, int idx);

    /*
     * Returns true if the bus requires parasite power.
     * Returns always false if an operaiton failed.
     */
    bool mgos_dallas_rmt_is_parasite_power_mode(DallasRmt *dt);

    /*
     * Is a conversion complete on the wire?
     * Return always false if an operaiton failed.
     */
    bool mgos_dallas_rmt_is_conversion_complete(DallasRmt *dt);

    /*
     * Returns number of milliseconds to wait till conversion is complete (based on IC datasheet)
     * or 0 if an operaiton failed.
     */
    int16_t mgos_dallas_rmt_millis_to_wait_for_conversion(DallasRmt *dt, int res);

#ifdef __cplusplus
}
#endif
