/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#include "platform.h"

#ifdef USE_CMS
#ifdef USE_RPM_LIMIT

#include "cms/cms.h"
#include "cms/cms_types.h"
#include "cms/cms_menu_rpm_limit.h"

#include "config/config.h"
#include "pg/stats.h"

#include "flight/mixer.h"

uint16_t rpm_limit_value;
uint16_t motor_kv;
bool rpm_limit;
//bool dynamic_rpm_limit;

static const void *cmsx_RpmLimit_onEnter(displayPort_t *pDisp)
{
    UNUSED(pDisp);

    rpm_limit_value = mixerConfig()->rpm_limit_value;
    motor_kv = motorConfig()->kv;
    rpm_limit = mixerConfig()->rpm_limit;
    dynamic_rpm_limit = mixerConfig()->dynamic_rpm_limit; // Считывание default значение
    min_dynamic_rpm_limit_value = mixerConfig()->min_dynamic_rpm_limit_value; // Считывание default значение
    max_dynamic_rpm_limit_value = mixerConfig()->max_dynamic_rpm_limit_value; // Считывание default значение

    return NULL;
}

static const void *cmsx_RpmLimit_onExit(displayPort_t *pDisp, const OSD_Entry *self)
{
    UNUSED(pDisp);
    UNUSED(self);

    mixerConfigMutable()->rpm_limit_value = rpm_limit_value;
    motorConfigMutable()->kv = motor_kv;
    mixerConfigMutable()->rpm_limit = rpm_limit;
    mixerConfigMutable()->dynamic_rpm_limit = dynamic_rpm_limit; // установка значение через OSD
    mixerConfigMutable()->min_dynamic_rpm_limit_value = min_dynamic_rpm_limit_value; // установка значение через OSD
    mixerConfigMutable()->max_dynamic_rpm_limit_value = max_dynamic_rpm_limit_value; // установка значение через OSD

    return NULL;
}

static const OSD_Entry cmsx_menuRpmLimitEntries[] =
{
    {"-- RPM LIMIT --", OME_Label, NULL, NULL},
    { "ACTIVE",   OME_Bool | REBOOT_REQUIRED,  NULL, &rpm_limit },
    { "DYNAMIC",   OME_Bool | REBOOT_REQUIRED,  NULL, &dynamic_rpm_limit }, // Включение DYNAMIC RPM
    {"CONST RPM", OME_UINT16, NULL, &(OSD_UINT16_t){ &rpm_limit_value, 0, UINT16_MAX, 100}},
    {"MAX RPM", OME_UINT16, NULL, &(OSD_UINT16_t){ &max_dynamic_rpm_limit_value, 0, UINT16_MAX, 100}}, // тут можно задать MAX значение
    {"MIN RPM", OME_UINT16, NULL, &(OSD_UINT16_t){ &min_dynamic_rpm_limit_value, 0, UINT16_MAX, 100}}, // тут можно задать MIN значение
    {"KV", OME_UINT16, NULL, &(OSD_UINT16_t){ &motor_kv, 0, UINT16_MAX, 1}},

    { "SAVE&REBOOT",     OME_OSD_Exit, cmsMenuExit,   (void *)CMS_POPUP_SAVEREBOOT},
    {"BACK", OME_Back, NULL, NULL},
    { NULL, OME_END, NULL, NULL}
};

CMS_Menu cmsx_menuRpmLimit = {
#ifdef CMS_MENU_DEBUG
    .GUARD_text = "RPMLIMIT",
    .GUARD_type = OME_MENU,
#endif
    .onEnter = cmsx_RpmLimit_onEnter,
    .onExit = cmsx_RpmLimit_onExit,
    .onDisplayUpdate = NULL,
    .entries = cmsx_menuRpmLimitEntries
};

#endif
#endif // USE_RPM_LIMIT
