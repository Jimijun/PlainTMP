#include "include/PluginInterface.h"
#include "custom_tmp.hpp"

class PlainTMP : public ITMPlugin {
public:
    static PlainTMP *instance();

    virtual IPluginItem *GetItem(int index) override;
    virtual void DataRequired() override {}
    virtual const wchar_t *GetInfo(PluginInfoIndex index) override;
    virtual void OnMonitorInfo(const MonitorInfo &monitor_info) override;

private:
    PlainTMP() = default;
    ~PlainTMP() = default;

    CustomTMP m_cpu_temperature{L"CPUTMP", L"CPUTMP"};
    CustomTMP m_gpu_temperature{L"GPUTMP", L"GPUTMP"};
};

#ifdef __cplusplus
extern "C" {
#endif
    __declspec(dllexport) ITMPlugin* TMPluginGetInstance();

#ifdef __cplusplus
}
#endif