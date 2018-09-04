#include <mgos.h>
#include "mgos_dallas_rmt.h"
#include "OnewireRmt.h"

DallasRmt *mgos_dallas_rmt_create(OnewireRmt *ow) {
  if (ow == nullptr) return nullptr;
  return new DallasRmt(ow);
}

DallasRmt *mgos_dallas_rmt_create_with_channels(uint8_t pin, uint8_t rmt_rx,
                                                uint8_t rmt_tx) {
  return new DallasRmt(pin, rmt_rx, rmt_tx);
}

void mgos_dallas_rmt_close(DallasRmt *dt) {
  if (dt != nullptr) {
    delete dt;
    dt = nullptr;
  }
}

void mgos_dallas_rmt_begin(DallasRmt *dt) {
  if (dt == nullptr) return;
  dt->begin();
}

int mgos_dallas_rmt_get_device_count(DallasRmt *dt) {
  if (dt == nullptr) return 0;
  return dt->getDeviceCount();
}

bool mgos_dallas_rmt_valid_address(DallasRmt *dt, const char *addr) {
  if (dt == nullptr) return false;
  return dt->validAddress((uint8_t *) addr);
}

bool mgos_dallas_rmt_valid_family(DallasRmt *dt, const char *addr) {
  if (dt == nullptr) return false;
  return dt->validFamily((uint8_t *) addr);
}

bool mgos_dallas_rmt_get_address(DallasRmt *dt, char *addr, int idx) {
  if (dt == nullptr) return false;
  return dt->getAddress((uint8_t *) addr, idx);
}

bool mgos_dallas_rmt_is_connected(DallasRmt *dt, const char *addr) {
  if (dt == nullptr) return false;
  return dt->isConnected((uint8_t *) addr);
}

bool mgos_dallas_rmt_is_connected_sp(DallasRmt *dt, const char *addr,
                                     char *sp) {
  if (dt == nullptr) return false;
  return dt->isConnected((uint8_t *) addr, (uint8_t *) sp);
}

bool mgos_dallas_rmt_read_scratch_pad(DallasRmt *dt, const char *addr,
                                      char *sp) {
  if (dt == nullptr) return false;
  return dt->readScratchPad((uint8_t *) addr, (uint8_t *) sp);
}

void mgos_dallas_rmt_write_scratch_pad(DallasRmt *dt, const char *addr,
                                       const char *sp) {
  if (dt == nullptr) return;
  dt->writeScratchPad((uint8_t *) addr, (uint8_t *) sp);
}

bool mgos_dallas_rmt_read_power_supply(DallasRmt *dt, const char *addr) {
  if (dt == nullptr) return false;
  return dt->readPowerSupply((uint8_t *) addr);
}

int mgos_dallas_rmt_get_global_resolution(DallasRmt *dt) {
  if (dt == nullptr) return 0;
  return dt->getResolution();
}

void mgos_dallas_rmt_set_global_resolution(DallasRmt *dt, int res) {
  if (dt == nullptr) return;
  dt->setResolution(res);
}

int mgos_dallas_rmt_get_resolution(DallasRmt *dt, const char *addr) {
  if (dt == nullptr) return 0;
  return dt->getResolution((uint8_t *) addr);
}

bool mgos_dallas_rmt_set_resolution(DallasRmt *dt, const char *addr, int res,
                                    bool skip_global_calc) {
  if (dt == nullptr) return false;
  return dt->setResolution((uint8_t *) addr, res, skip_global_calc);
}

void mgos_dallas_rmt_set_wait_for_conversion(DallasRmt *dt, bool f) {
  if (dt == nullptr) return;
  dt->setWaitForConversion(f);
}

bool mgos_dallas_rmt_get_wait_for_conversion(DallasRmt *dt) {
  if (dt == nullptr) return false;
  return dt->getWaitForConversion();
}

void mgos_dallas_rmt_set_check_for_conversion(DallasRmt *dt, bool f) {
  if (dt == nullptr) return;
  dt->setCheckForConversion(f);
}

bool mgos_dallas_rmt_get_check_for_conversion(DallasRmt *dt) {
  if (dt == nullptr) return false;
  return dt->getCheckForConversion();
}

void mgos_dallas_rmt_request_temperatures(DallasRmt *dt) {
  if (dt == nullptr) return;
  dt->requestTemperatures();
}

bool mgos_dallas_rmt_request_temperatures_by_address(DallasRmt *dt,
                                                     const char *addr) {
  if (dt == nullptr) return false;
  return dt->requestTemperaturesByAddress((uint8_t *) addr);
}

bool mgos_dallas_rmt_request_temperatures_by_index(DallasRmt *dt, int idx) {
  if (dt == nullptr) return false;
  return dt->requestTemperaturesByIndex(idx);
}

int16_t mgos_dallas_rmt_get_temp(DallasRmt *dt, const char *addr) {
  if (dt == nullptr) return DEVICE_DISCONNECTED_RAW;
  return dt->getTemp((uint8_t *) addr);
}

int mgos_dallas_rmt_get_tempc(DallasRmt *dt, const char *addr) {
  if (dt == nullptr) return DEVICE_DISCONNECTED_C;
  return (int) (0.5 + dt->getTempC((uint8_t *) addr) * 100.0);
}

int mgos_dallas_rmt_get_tempf(DallasRmt *dt, const char *addr) {
  if (dt == nullptr) return DEVICE_DISCONNECTED_F;
  return (int) (0.5 + dt->getTempF((uint8_t *) addr) * 100.0);
}

int mgos_dallas_rmt_get_tempc_by_index(DallasRmt *dt, int idx) {
  if (dt == nullptr) return DEVICE_DISCONNECTED_C;
  return (int) (0.5 + dt->getTempCByIndex(idx) * 100.0);
}

int mgos_dallas_rmt_get_tempf_by_index(DallasRmt *dt, int idx) {
  if (dt == nullptr) return DEVICE_DISCONNECTED_F;
  return (int) (0.5 + dt->getTempFByIndex(idx) * 100.0);
}

bool mgos_dallas_rmt_is_parasite_power_mode(DallasRmt *dt) {
  if (dt == nullptr) return false;
  return dt->isParasitePowerMode();
}

bool mgos_dallas_rmt_is_conversion_complete(DallasRmt *dt) {
  if (dt == nullptr) return false;
  return dt->isConversionComplete();
}

int16_t mgos_dallas_rmt_millis_to_wait_for_conversion(DallasRmt *dt, int res) {
  if (dt == nullptr) return 0;
  return dt->millisToWaitForConversion(res);
}
