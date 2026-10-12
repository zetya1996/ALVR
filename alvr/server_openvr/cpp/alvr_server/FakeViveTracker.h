#pragma once

#include "TrackedDevice.h"
#include "bindings.h"
#include "openvr_driver_wrap.h"

constexpr vr::ETrackedDeviceProperty Prop_Custom_QRCode_String = 
    static_cast<vr::ETrackedDeviceProperty>(10500);
    
class FakeViveTracker : public TrackedDevice {
public:
    FakeViveTracker(uint64_t deviceID);
    void OnPoseUpdated(uint64_t targetTimestampNs, const FfiDeviceMotion* motion);
    void SetQRValue(const std::string& value);
    void CheckPastPoseUpdateTime(uint64_t targetTimestampNs);
private:
    // TrackedDevice
    bool activate() final;
    void* get_component(const char*) final { return nullptr; }

    uint64_t lastPoseUpdateTime;
};
