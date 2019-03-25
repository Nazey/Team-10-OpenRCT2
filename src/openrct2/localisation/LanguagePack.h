/*****************************************************************************
 * Copyright (c) 2014-2019 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../common.h"

#include <string>

interface ILanguagePack
{
    virtual ~ILanguagePack() = default;

    virtual uint16_t GetId() const abstract;
    virtual uint32_t GetCount() const abstract;

    virtual void RemoveString(rct_string_id stringId) abstract;
    virtual void SetString(rct_string_id stringId, const std::string& str) abstract;
    virtual const utf8* GetString(rct_string_id stringId) const abstract;
    virtual rct_string_id GetObjectOverrideStringId(const char* objectIdentifier, uint8_t index) abstract;
    virtual rct_string_id GetScenarioOverrideStringId(const utf8* scenarioFilename, uint8_t index) abstract;
};

namespace LanguagePackFactory
{
    ILanguagePack* FromFile(uint16_t id, const utf8* path);
    ILanguagePack* FromText(uint16_t id, const utf8* text);
} // namespace LanguagePackFactory
