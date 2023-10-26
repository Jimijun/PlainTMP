#include "plain_tmp.h"

PlainTMP *PlainTMP::instance()
{
    static PlainTMP m_instance;
    return &m_instance;
}

IPluginItem *PlainTMP::GetItem(int index)
{
    switch (index) {
    case 0:
        return &m_cpu_temperature;
    case 1:
        return &m_gpu_temperature;
    default:
        break;
    }
    return nullptr;
}

const wchar_t *PlainTMP::GetInfo(PluginInfoIndex index)
{
    switch (index) {
    case TMI_NAME:
        return L"PlainTMP";
    default:
        break;
    }
    return L"";
}

void PlainTMP::OnMonitorInfo(const MonitorInfo &monitor_info)
{
    instance()->m_cpu_temperature.setTemperature(monitor_info.cpu_temperature);
    instance()->m_gpu_temperature.setTemperature(monitor_info.gpu_temperature);
}

ITMPlugin* TMPluginGetInstance()
{
    return PlainTMP::instance();
}