#pragma once

#include "AP_RangeFinder_Backend_CAN.h"

#ifndef AP_RANGEFINDER_NRA24_CAN_ENABLED
#define AP_RANGEFINDER_NRA24_CAN_ENABLED (HAL_MAX_CAN_PROTOCOL_DRIVERS && AP_RANGEFINDER_BACKEND_DEFAULT_ENABLED)
#endif

#if AP_RANGEFINDER_NRA24_CAN_ENABLED

class AP_RangeFinder_NRA24_CAN : public AP_RangeFinder_Backend_CAN {
public:
    AP_RangeFinder_NRA24_CAN(RangeFinder::RangeFinder_State &_state, AP_RangeFinder_Params &_params);

    void update(void) override;

    // handler for incoming frames
    bool handle_frame(AP_HAL::CANFrame &frame) override;

    static const struct AP_Param::GroupInfo var_info[];

private:

    uint32_t get_radar_id(uint32_t id) const { return ((id & 0xF0U)/0x10U); }

    static RangeFinder_MultiCAN *multican_NRA24;

    uint32_t last_heartbeat_ms; // last status message received from the sensor
};

#endif  // AP_RANGEFINDER_USD1_CAN_ENABLED