#include "include/PluginInterface.h"

#include <string>
using std::wstring;

class CustomTMP : public IPluginItem {
public:
    CustomTMP(const wstring &name, const wstring &id) : m_name(name), m_id(id) {}
    ~CustomTMP() = default;

    virtual const wchar_t *GetItemName() const override { return m_name.c_str(); }
    virtual const wchar_t *GetItemId() const override { return m_id.c_str(); }
    virtual const wchar_t *GetItemLableText() const override { return L""; }
    virtual const wchar_t *GetItemValueText() const override { return m_temperature.c_str(); }
    virtual const wchar_t *GetItemValueSampleText() const override { return L"99 °C"; }
    virtual bool IsCustomDraw() const override { return false; }

    void setTemperature(int temperature) { m_temperature = std::to_wstring(temperature) + L" °C"; }

private:
    wstring m_name{};
    wstring m_id{};
    wstring m_temperature{};
};