/*************************************************************************************************************
Copyright 2015-2019, Silicon Laboratories, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 *************************************************************************************************************/
/***************************************************************************************
                  Silicon Laboratories Broadcast Si2176 Layer 2 API
   L2 API for commands and properties
   FILE: Si2176_L2_API.c
   Supported IC : Si2176
   Compiled for ROM 13 firmware 3_2_build_6
   Revision: 0.1
   Tag:  TAGNAME
   Date: December 22 2011
****************************************************************************************/
#include <string.h>
/* Si2176 API Defines */
/* define this if using the ATV video filter */
#undef USING_ATV_FILTER
/* define this if using the DTV video filter */
#undef USING_DLIF_FILTER
/************************************************************************************************************************/
/* Si2176 API Specific Includes */
#include "Si2176_L2_API.h"               /* Include file for this code */
#include "Si2176_Firmware_3_2_build_6.h"       /* firmware compatible with Si2176-marking */
#define Si2176_BYTES_PER_LINE 8
#ifdef USING_ATV_FILTER
#include "write_ATV_video_coeffs.h"   /* .h file from custom Video filter Tool output */
#endif
#ifdef USING_DLIF_FILTER
#include "write_DLIF_video_coeffs.h"   /* .h file from custom Video filter Tool output */
#endif
/************************************************************************************************************************/

/************************************************************************************************************************
  NAME: Si2176_UpdateChannelScanFrequency
  DESCRIPTION:  This routine allows the user to implement an update of the current channel scan operation with
                the current frequency being scanned.
  Parameter:    Current frequency of the scan routine
  Parameter:  channelsFound = 0 if channel not found at that frequency , channelsFound > 0  the number of channels
        currently found( including this frequency )
  Returns:      1 if scan abort requested, 0 if ok.
************************************************************************************************************************/
int Si2176_UpdateChannelScanFrequency(int freq,int channelsFound)
{
  int abort = 0;
  static int previousFrequency;
/*** Insert user code to display realtime updates of the frequency being scanned and channel status (number found ) **/
/* add check for user abort here */
  if (channelsFound)
  {
    /* Terminate the previous scan message */
    printf("Found Frequency %d\n",freq);
  }
  else
  {
    if (freq==previousFrequency)
      printf("Not Found\n");
    else
      printf("Scanning Frequency %d, ",freq);
  }
  previousFrequency=freq;

  if (abort)
    return 1;
  else
    return 0;
}
/************************************************************************************************************************
  NAME: Si2176_GetRF
  DESCRIPTIION: Retieve Si2176 tune freq

  Parameter:  Pointer to Si2176 Context (I2C address)
  Returns  :  frequency (Hz) as an int
************************************************************************************************************************/
int  Si2176_GetRF             (L1_Si2176_Context *api)
{
    Si2176_L1_TUNER_STATUS (api, Si2176_TUNER_STATUS_CMD_INTACK_OK);
        return api->rsp->tuner_status.freq;
}
/************************************************************************************************************************
  NAME: Si2176_Tune
  DESCRIPTIION: Tune Si2176 in specified mode (ATV/DTV) at center frequency, wait for TUNINT and xTVINT with timeout

  Parameter:  Pointer to Si2176 Context (I2C address)
  Parameter:  Mode (ATV or DTV) use Si2176_TUNER_TUNE_FREQ_CMD_MODE_ATV or Si2176_TUNER_TUNE_FREQ_CMD_MODE_DTV constants
  Parameter:  frequency (Hz) as a unsigned long integer
  Parameter:  rsp - commandResp structure to returns tune status info.
  Returns:    0 if channel found.  A nonzero value means either an error occurred or channel not locked.
  Programming Guide Reference:    Flowchart A.7 (Tune flowchart)
************************************************************************************************************************/
int  Si2176_Tune              (L1_Si2176_Context *api, unsigned char mode, unsigned long freq)
{
   int start_time  = 0;
    int return_code = 0;

    /* set a timeout of 70 ms for tune complete (ATV and DTV) */
    int timeout     = 70;

    start_time = system_time();

    if (Si2176_L1_TUNER_TUNE_FREQ (api,
                                   mode,
                                   freq) != 0)
    {
        return ERROR_Si2176_SENDING_COMMAND;
    }

    /* wait for TUNINT, timeout is 70ms */
    while ( (system_time() - start_time) < timeout )
    {
        if ((return_code = Si2176_L1_CheckStatus(api)) != 0)
            return return_code;
        if (api->status->tunint)
            break;
    }
    if (!api->status->tunint) {
      SiTRACE("Timeout waiting for TUNINT\n");
      return ERROR_Si2176_TUNINT_TIMEOUT;
    }

    /* wait for xTVINT, timeout is 150ms for ATVINT and 10 ms for DTVINT */
    start_time = system_time();
    timeout    = ((mode==Si2176_TUNER_TUNE_FREQ_CMD_MODE_ATV) ? 150 : 10);
    while ( (system_time() - start_time) < timeout )
    {
        if ((return_code = Si2176_L1_CheckStatus(api)) != 0)
            return return_code;
        if (mode==Si2176_TUNER_TUNE_FREQ_CMD_MODE_ATV)
        {
         if (api->status->atvint)
            break;
        }
        else
        {
         if (api->status->dtvint)
            break;
        }
    }

    if (mode==Si2176_TUNER_TUNE_FREQ_CMD_MODE_ATV)
    {
      if (api->status->atvint)
      {

        SiTRACE("ATV Tune Successful\n");
        return NO_Si2176_ERROR;
      }
      else
        SiTRACE("Timeout waiting for ATVINT\n");
    }
    else
    {
        if (api->status->dtvint)
        {
          SiTRACE("DTV Tune Successful \n");
          return NO_Si2176_ERROR;
        }
        else
          SiTRACE("Timeout waiting for DTVINT\n");
    }

    return ERROR_Si2176_xTVINT_TIMEOUT;
}
/************************************************************************************************************************
  NAME: Si2176_ATVTune
  DESCRIPTION:Update ATV_VIDEO_MODE and tune ATV mode at center frequency
  Parameter:  Pointer to Si2176 Context (I2C address)
  Parameter:  frequency (Hz)
  Parameter:  Video system , e.g. use constant Si2176_ATV_VIDEO_MODE_PROP_VIDEO_SYS_M for system M
  Parameter:  transport,  e.g. use constant Si2176_ATV_VIDEO_MODE_PROP_TRANS_TERRESTRIAL for terrestrial
  Parameter:  color , e.g. use constant Si2176_ATV_VIDEO_MODE_PROP_COLOR_PAL_NTSC for PAL or NTSC
  Parameter:  invert_signal, 0= normal, 1= inverted
  Parameter:  rsp - commandResp structure to returns tune status info.
  Returns:    I2C transaction error code, 0 if successful
  Programming Guide Reference:    Flowchart A.7 (Tune flowchart)
************************************************************************************************************************/
int  Si2176_ATVTune           (L1_Si2176_Context *Si2176, unsigned long freq, unsigned char video_sys, unsigned char trans, unsigned char color, unsigned char invert_signal)
{
    /* update ATV_VIDEO_MODE property */
    Si2176->prop->atv_video_mode.video_sys = video_sys;
    Si2176->prop->atv_video_mode.trans = trans;
    Si2176->prop->atv_video_mode.color = color;
    Si2176->prop->atv_video_mode.invert_signal=invert_signal;
    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_VIDEO_MODE_PROP) != NO_Si2176_ERROR)
    {
      return ERROR_Si2176_SENDING_COMMAND;
    }

    return Si2176_Tune (Si2176, Si2176_TUNER_TUNE_FREQ_CMD_MODE_ATV, freq);
}
/************************************************************************************************************************
  NAME: Si2176_DTVTune
  DESCRIPTION: Update DTV_MODE and tune DTV mode at center frequency
  Parameter:  Pointer to Si2176 Context (I2C address)
  Parameter:  frequency (Hz)
  Parameter:  bandwidth , 6,7 or 8 MHz
  Parameter:  modulation,  e.g. use constant Si2176_DTV_MODE_PROP_MODULATION_DVBT for DVBT mode
  Returns:    I2C transaction error code, 0 if successful
  Programming Guide Reference:    Flowchart A.7 (Tune flowchart)
************************************************************************************************************************/
int  Si2176_DTVTune           (L1_Si2176_Context *Si2176, unsigned long freq, unsigned char bw, unsigned char modulation, unsigned char invert_spectrum)
{
    int return_code;
    return_code = NO_Si2176_ERROR;

    /* update DTV_MODE_PROP property */
    Si2176->prop->dtv_mode.bw = bw;
    Si2176->prop->dtv_mode.invert_spectrum = invert_spectrum;
    Si2176->prop->dtv_mode.modulation = modulation;
    if (Si2176_L1_SetProperty2(Si2176, Si2176_DTV_MODE_PROP) != NO_Si2176_ERROR)
    {
      return ERROR_Si2176_SENDING_COMMAND;
    }

    return_code = Si2176_Tune (Si2176, Si2176_TUNER_TUNE_FREQ_CMD_MODE_DTV, freq);

    return return_code;
}

/************************************************************************************************************************
  NAME: Si2176_Configure
  DESCRIPTION: Setup Si2176 video filters, GPIOs/clocks, Common Properties startup, Tuner startup, ATV startup, and DTV startup.
  Parameter:  Pointer to Si2176 Context
  Returns:    I2C transaction error code, NO_Si2176_ERROR if successful
************************************************************************************************************************/
int Si2176_Configure           (L1_Si2176_Context *api)
{
    int return_code;
    return_code = NO_Si2176_ERROR;
   /* load ATV video filter file */
  #ifdef USING_ATV_FILTER
    if ((return_code = LoadVideofilter(api,ATV_VIDFILT_TABLE,ATV_VIDFILT_LINES)) != NO_Si2176_ERROR)
       return return_code;
  #endif

  /* load DTV video filter file */
  #ifdef USING_DLIF_FILTER
     if ((return_code = LoadVideofilter(api,DLIF_VIDFILT_TABLE,DLIF_VIDFILT_LINES)) != NO_Si2176_ERROR)
       return return_code;
  #endif
    /* Set All Properties startup configuration */
    Si2176_setupAllDefaults     (api);
    Si2176_downloadAllProperties(api);

    return return_code;
}
/************************************************************************************************************************
  NAME: Si2176_PowerUpWithPatch
  DESCRIPTION: Send Si2176 API PowerUp Command with PowerUp to bootloader,
  Check the Chip rev and part, and ROMID are compared to expected values.
  Load the Firmware Patch then Start the Firmware.
  Programming Guide Reference:    Flowchart A.2 (POWER_UP with patch flowchart)

  Parameter:  pointer to Si2176 Context
  Returns:    Si2176/I2C transaction error code, NO_Si2176_ERROR if successful
************************************************************************************************************************/
int Si2176_PowerUpWithPatch    (L1_Si2176_Context *api)
{
    int return_code;
    return_code = NO_Si2176_ERROR;

    /* always wait for CTS prior to POWER_UP command */
    if ((return_code = Si2176_pollForCTS  (api)) != NO_Si2176_ERROR) {
        SiTRACE ("Si2176_pollForCTS error 0x%02x\n", return_code);
        return return_code;
    }

    if ((return_code = Si2176_L1_POWER_UP (api,
                            Si2176_POWER_UP_CMD_SUBCODE_CODE,
                            Si2176_POWER_UP_CMD_RESERVED1_RESERVED,
                            Si2176_POWER_UP_CMD_RESERVED2_RESERVED,
                            Si2176_POWER_UP_CMD_RESERVED3_RESERVED,
                            Si2176_POWER_UP_CMD_CLOCK_MODE_XTAL,
                            Si2176_POWER_UP_CMD_CLOCK_FREQ_CLK_24MHZ,
                            Si2176_POWER_UP_CMD_ADDR_MODE_CURRENT,
                            Si2176_POWER_UP_CMD_FUNC_BOOTLOADER,        /* start in bootloader mode */
                            Si2176_POWER_UP_CMD_CTSIEN_DISABLE,
                            Si2176_POWER_UP_CMD_WAKE_UP_WAKE_UP)) != NO_Si2176_ERROR)
    {
        SiTRACE ("Si2176_L1_POWER_UP error 0x%02x: %s\n", return_code, Si2176_L1_API_ERROR_TEXT(return_code) );
        return return_code;
    }

    /* Get the Part Info from the chip.   This command is only valid in Bootloader mode */
    if ((return_code = Si2176_L1_PART_INFO(api)) != NO_Si2176_ERROR) {
        SiTRACE ("Si2176_L1_PART_INFO error 0x%02x: %s\n", return_code, Si2176_L1_API_ERROR_TEXT(return_code) );
        return return_code;
    }
    SiTRACE("chiprev %d\n",        api->rsp->part_info.chiprev);
    SiTRACE("part    Si21%d\n",    api->rsp->part_info.part   );
    SiTRACE("pmajor  %d\n",        api->rsp->part_info.pmajor );
    if (api->rsp->part_info.pmajor >= 0x30) {
    SiTRACE("pmajor '%c'\n",       api->rsp->part_info.pmajor );
    }
    SiTRACE("pminor  %d\n",        api->rsp->part_info.pminor );
    if (api->rsp->part_info.pminor >= 0x30) {
    SiTRACE("pminor '%c'\n",       api->rsp->part_info.pminor );
    }
    SiTRACE("romid %3d/0x%02x\n",  api->rsp->part_info.romid,  api->rsp->part_info.romid );
#ifdef    PART_INTEGRITY_CHECKS
    /* Check the Chip revision, part and ROMID against expected values and report an error if incompatible */
    if (api->rsp->part_info.chiprev != api->chiprev) {
        SiTRACE ("INCOMPATIBLE PART error chiprev %d (expected %d)\n", api->rsp->part_info.chiprev, api->chiprev);
        return_code = ERROR_Si2176_INCOMPATIBLE_PART;
    }
    /* Part Number is represented as the last 2 digits */
    if (api->rsp->part_info.part != api->part) {
        SiTRACE ("INCOMPATIBLE PART error part   %d (expected %d)\n", api->rsp->part_info.part, api->part);
        return_code = ERROR_Si2176_INCOMPATIBLE_PART;
    }
    /* Part Major Version in ASCII */
    if (api->rsp->part_info.pmajor != api->partMajorVersion) {
        SiTRACE ("INCOMPATIBLE PART error pmajor %d (expected %d)\n", api->rsp->part_info.pmajor, api->partMajorVersion);
        return_code = ERROR_Si2176_INCOMPATIBLE_PART;
    }
    /* Part Minor Version in ASCII */
    if (api->rsp->part_info.pminor != api->partMinorVersion) {
        SiTRACE ("INCOMPATIBLE PART error pminor %d (expected %d)\n", api->rsp->part_info.pminor, api->partMinorVersion);
        return_code = ERROR_Si2176_INCOMPATIBLE_PART;
    }
    /* ROMID in byte representation */
    if (api->rsp->part_info.romid != api->partRomid) {
        SiTRACE ("INCOMPATIBLE PART error romid %3d (expected %2d)\n", api->rsp->part_info.romid, api->partRomid);
        return_code = ERROR_Si2176_INCOMPATIBLE_PART;
    }
    if (return_code != NO_Si2176_ERROR) return return_code;
#endif /* PART_INTEGRITY_CHECKS */

    if (api->rsp->part_info.romid == 0x13) {
      /* Load the Firmware */
       if ((return_code = Si2176_LoadFirmware(api, Si2176_FW_3_2b6, FIRMWARE_LINES_3_2b6)) != NO_Si2176_ERROR) {
         SiTRACE ("Si2176_LoadFirmware error 0x%02x: %s\n", return_code, Si2176_L1_API_ERROR_TEXT(return_code) );
         return return_code;
       }
    }

    /*Start the Firmware */
    if ((return_code = Si2176_StartFirmware(api)) != NO_Si2176_ERROR) { /* Start firmware */
        SiTRACE ("Si2176_StartFirmware error 0x%02x: %s\n", return_code, Si2176_L1_API_ERROR_TEXT(return_code) );
        return return_code;
    }

    return NO_Si2176_ERROR;
}
/************************************************************************************************************************
  NAME: Si2176_LoadFirmware
  DESCRIPTON: Load firmware from FIRMWARE_TABLE array in Si2176_Firmware_x_y_build_z.h file into Si2176
              Requires Si2176 to be in bootloader mode after PowerUp
  Programming Guide Reference:    Flowchart A.3 (Download FW PATCH flowchart)

  Parameter:  Si2176 Context (I2C address)
  Parameter:  pointer to firmware table array
  Parameter:  number of lines in firmware table array (size in bytes / BYTES_PER_LINE)
  Returns:    Si2176/I2C transaction error code, NO_Si2176_ERROR if successful
************************************************************************************************************************/
int Si2176_LoadFirmware        (L1_Si2176_Context *api, unsigned char fw_table[], int nbLines)
{
    int return_code;
    int line;
    return_code = NO_Si2176_ERROR;

    SiTRACE ("Si2176_LoadFirmware starting...\n");
    SiTRACE ("Si2176_LoadFirmware nbLines %d\n", nbLines);

    /* for each line in fw_table */
    for (line = 0; line < nbLines; line++)
    {
        /* send Si2176_BYTES_PER_LINE fw bytes to Si2176 */
        if ((return_code = Si2176_L1_API_Patch(api, Si2176_BYTES_PER_LINE, fw_table + Si2176_BYTES_PER_LINE*line)) != NO_Si2176_ERROR)
        {
          SiTRACE("Si2176_LoadFirmware error 0x%02x patching line %d: %s\n", return_code, line, Si2176_L1_API_ERROR_TEXT(return_code) );
          if (line == 0) {
          SiTRACE("The firmware is incompatible with the part!\n");
          }
          return ERROR_Si2176_LOADING_FIRMWARE;
        }
        if (line==3) SiTraceConfiguration("traces -output none");
    }
    SiTraceConfiguration("traces -output file");
    SiTRACE ("Si2176_LoadFirmware complete...\n");
    return NO_Si2176_ERROR;
}
/************************************************************************************************************************
  NAME: Si2176_StartFirmware
  DESCRIPTION: Start Si2176 firmware (put the Si2176 into run mode)
  Parameter:   Si2176 Context (I2C address)
  Parameter (passed by Reference):   ExitBootloadeer Response Status byte : tunint, atvint, dtvint, err, cts
  Returns:     I2C transaction error code, NO_Si2176_ERROR if successful
************************************************************************************************************************/
int Si2176_StartFirmware       (L1_Si2176_Context *api)
{

    if (Si2176_L1_EXIT_BOOTLOADER(api, Si2176_EXIT_BOOTLOADER_CMD_FUNC_TUNER, Si2176_EXIT_BOOTLOADER_CMD_CTSIEN_OFF) != NO_Si2176_ERROR)
    {
        return ERROR_Si2176_STARTING_FIRMWARE;
    }

    return NO_Si2176_ERROR;
}
/************************************************************************************************************************
  NAME: Si2176_Init
  DESCRIPTION:Reset and Initialize Si2176
  Parameter:  Si2176 Context (I2C address)
  Returns:    I2C transaction error code, NO_Si2176_ERROR if successful
************************************************************************************************************************/
int Si2176_Init                (L1_Si2176_Context *api)
{
    int return_code;
    SiTRACE("Si2176_Init starting...\n");

    if ((return_code = Si2176_PowerUpWithPatch(api)) != NO_Si2176_ERROR) {   /* PowerUp into bootloader */
        SiTRACE ("Si2176_PowerUpWithPatch error 0x%02x: %s\n", return_code, Si2176_L1_API_ERROR_TEXT(return_code) );
        return return_code;
    }
    /* At this point, FW is loaded and started.  */
    Si2176_Configure(api);
    SiTRACE("Si2176_Init complete...\n");
    return NO_Si2176_ERROR;
}
/************************************************************************************************************************
  NAME: Si2176_LoadVideofilter
  DESCRIPTION:        Load video filters from vidfiltTable in Si2176_write_xTV_video_coeffs.h file into Si2176
  Programming Guide Reference:    Flowchart A.4 (Download Video Filters flowchart)

  Parameter:  Si2176 Context (I2C address)
  Parameter:  pointer to video filter table array
  Parameter:  number of lines in video filter table array (size in bytes / BYTES_PER_LINE)
  Returns:    Si2176/I2C transaction error code, 0 if successful
************************************************************************************************************************/
int Si2176_LoadVideofilter     (L1_Si2176_Context *api,unsigned char* vidfiltTable,int lines)
{
#define BYTES_PER_LINE 8
    int line;

    /* for each 8 bytes in VIDFILT_TABLE */
    for (line = 0; line < lines; line++)
    {
        /* send that 8 byte I2C command to Si2176 */
        if (Si2176_L1_API_Patch(api, BYTES_PER_LINE, vidfiltTable+BYTES_PER_LINE*line) != 0)
        {
            return ERROR_Si2176_SENDING_COMMAND;
        }
    }
    return NO_Si2176_ERROR;
}
/************************************************************************************************************************
  NAME: Si2176_ClockOn
  Parameter:  Pointer to Si2176 Context (I2C address)
  Returns:    I2C transaction error code, 0 if successful
************************************************************************************************************************/
int Si2176_ClockOn             (L1_Si2176_Context *api)
{
    int return_code;
    SiTRACE("Si2176_CLOCK_ON: Turning clock ON\n");

    if ((return_code = Si2176_L1_CONFIG_PINS (api,
                               Si2176_CONFIG_PINS_CMD_GPIO1_MODE_NO_CHANGE,
                               Si2176_CONFIG_PINS_CMD_GPIO1_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_GPIO2_MODE_NO_CHANGE,
                               Si2176_CONFIG_PINS_CMD_GPIO2_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_GPIO3_MODE_NO_CHANGE,
                               Si2176_CONFIG_PINS_CMD_GPIO3_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_BCLK1_MODE_XOUT,
                               Si2176_CONFIG_PINS_CMD_BCLK1_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_XOUT_MODE_DISABLE)) !=0)
    return return_code;

    return NO_Si2176_ERROR;
}
/************************************************************************************************************************
  NAME: Si2176_ClockOff
  Parameter:  Pointer to Si2176 Context (I2C address)
  Returns:    I2C transaction error code, 0 if successful
************************************************************************************************************************/
int Si2176_ClockOff            (L1_Si2176_Context *api)
{
    int return_code;
    SiTRACE("Si2176_CLOCK_OFF: Turning clock OFF\n");

    if ((return_code = Si2176_L1_CONFIG_PINS (api,
                               Si2176_CONFIG_PINS_CMD_GPIO1_MODE_NO_CHANGE,
                               Si2176_CONFIG_PINS_CMD_GPIO1_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_GPIO2_MODE_NO_CHANGE,
                               Si2176_CONFIG_PINS_CMD_GPIO2_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_GPIO3_MODE_NO_CHANGE,
                               Si2176_CONFIG_PINS_CMD_GPIO3_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_BCLK1_MODE_DISABLE,
                               Si2176_CONFIG_PINS_CMD_BCLK1_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_XOUT_MODE_DISABLE)) !=0)
    return return_code;

    return NO_Si2176_ERROR;
}
/************************************************************************************************************************
  NAME: Si2176_XOUTOn
  Parameter:  Pointer to Si2176 Context (I2C address)
  Returns:    I2C transaction error code, NO_Si2176_ERROR if successful
************************************************************************************************************************/
int Si2176_XOUTOn           (L1_Si2176_Context *api)
{
    int return_code;
    SiTRACE("Si2176_XOUT_ON: Turning XOUT ON\n");

    if ((return_code = Si2176_L1_CONFIG_PINS (api,
                               Si2176_CONFIG_PINS_CMD_GPIO1_MODE_NO_CHANGE,
                               Si2176_CONFIG_PINS_CMD_GPIO1_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_GPIO2_MODE_NO_CHANGE,
                               Si2176_CONFIG_PINS_CMD_GPIO2_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_GPIO3_MODE_NO_CHANGE,
                               Si2176_CONFIG_PINS_CMD_GPIO3_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_BCLK1_MODE_NO_CHANGE,
                               Si2176_CONFIG_PINS_CMD_BCLK1_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_XOUT_MODE_XOUT)) != NO_Si2176_ERROR)
    return return_code;

    return NO_Si2176_ERROR;
}
/************************************************************************************************************************
  NAME: Si2176_XOUTOff
  Parameter:  Pointer to Si2176 Context (I2C address)
  Returns:    I2C transaction error code, NO_Si2176_ERROR if successful
************************************************************************************************************************/
int Si2176_XOUTOff         (L1_Si2176_Context *api)
{
    int return_code;
    SiTRACE("Si2176_XOUT_OFF: Turning clock OFF\n");

    if ((return_code = Si2176_L1_CONFIG_PINS (api,
                               Si2176_CONFIG_PINS_CMD_GPIO1_MODE_NO_CHANGE,
                               Si2176_CONFIG_PINS_CMD_GPIO1_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_GPIO2_MODE_NO_CHANGE,
                               Si2176_CONFIG_PINS_CMD_GPIO2_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_GPIO3_MODE_NO_CHANGE,
                               Si2176_CONFIG_PINS_CMD_GPIO3_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_BCLK1_MODE_NO_CHANGE,
                               Si2176_CONFIG_PINS_CMD_BCLK1_READ_DO_NOT_READ,
                               Si2176_CONFIG_PINS_CMD_XOUT_MODE_DISABLE)) != NO_Si2176_ERROR)
    return return_code;

    return NO_Si2176_ERROR;
}
/************************************************************************************************************************
  NAME: Si2176_Standby
  Parameter:  Pointer to Si2176 Context (I2C address)
  Returns:    I2C transaction error code, NO_Si2176_ERROR if successful
************************************************************************************************************************/
int Si2176_Standby         (L1_Si2176_Context *api)
{
    int return_code;
    SiTRACE("Si2176_Standby: Putting chip in Standby\n");

    if ((return_code = Si2176_L1_STANDBY(api,Si2176_STANDBY_CMD_TYPE_NORMAL)) != NO_Si2176_ERROR)
    return return_code;

    return NO_Si2176_ERROR;
}
/************************************************************************************************************************
  NAME: Si2176_Powerdown
  Parameter:  Pointer to Si2176 Context (I2C address)
  Returns:    I2C transaction error code, NO_Si2176_ERROR if successful
************************************************************************************************************************/
int Si2176_Powerdown         (L1_Si2176_Context *api)
{
    int return_code;
    SiTRACE("Si2176_CLOCK_OFF: Turning clock OFF\n");

    if ((return_code = Si2176_L1_POWER_DOWN(api)) != NO_Si2176_ERROR)
    return return_code;

    return NO_Si2176_ERROR;
}
/************************************************************************************************************************
  NAME: Si2176_ATV_Channel_Scan_M
  DESCRIPTION: Performs a channel scan for NTSC (System M) of the band
  Programming Guide Reference:    Flowchart A.11.0 and A11.1 (ATV Channel Scan flowchart for System M)

  Parameter:  Pointer to Si2176 Context (I2C address)
  Parameter:  starting Frequency Hz
  Parameter:  ending Frequency Hz
  Parameter:  min RSSI dBm
  Parameter:  max RSSI dBm
  Parameter:  min SNR 1/2 dB
  Parameter:  max SNR 1/2 dB
  Returns:    0 if successful, otherwise an error.
************************************************************************************************************************/
int Si2176_ATV_Channel_Scan_M (L1_Si2176_Context *Si2176, unsigned long rangeMinHz, unsigned long rangeMaxHz, int minRSSIdBm, int maxRSSIdBm, int minSNRHalfdB, int maxSNRHalfdB)
{
    #define SCAN_INTERVAL     1000000
    #define CHANNEL_BANDWIDTH 6000000
    #define CHANNEL_NOT_FOUND       0

    unsigned long freq;
    int i;

    /*Clear the channel list size and channel array */
    Si2176->ChannelListSize=0;

    for (i=0; i< MAX_POSSIBLE_CHANNELS;i++)
    Si2176->ChannelList[i]=0;
    /* configure the VideoMode property to System M, NTSC*/
    Si2176->prop->atv_video_mode.video_sys = Si2176_ATV_VIDEO_MODE_PROP_VIDEO_SYS_M;    /* M ATV demodulation */
    Si2176->prop->atv_video_mode.color     = Si2176_ATV_VIDEO_MODE_PROP_COLOR_PAL_NTSC;    /* PAL_NTSC color system */
    Si2176->prop->atv_video_mode.trans     = Si2176_ATV_VIDEO_MODE_PROP_TRANS_TERRESTRIAL;    /* set trans to Terrestrial */
    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_VIDEO_MODE_PROP) != NO_Si2176_ERROR)
    {
       return ERROR_Si2176_SENDING_COMMAND;
    }
    /* configure the RSQ / RSSI threshold properties */
    Si2176->prop->atv_rsq_rssi_threshold.lo = minRSSIdBm;
    Si2176->prop->atv_rsq_rssi_threshold.hi = maxRSSIdBm;

    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP) != NO_Si2176_ERROR)
    {
       return ERROR_Si2176_SENDING_COMMAND;
    }

  /* configure the RSQ / SNR threshold properties */
    Si2176->prop->atv_rsq_snr_threshold.lo = minSNRHalfdB;
    Si2176->prop->atv_rsq_snr_threshold.hi = maxSNRHalfdB;

    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_RSQ_SNR_THRESHOLD_PROP) != NO_Si2176_ERROR)
    {
      return ERROR_Si2176_SENDING_COMMAND;
    }

  /* setup IEN properties to enable TUNINT on TC  */
    Si2176->prop->tuner_ien.tcien     =  Si2176_TUNER_IEN_PROP_TCIEN_ENABLE;
    Si2176->prop->tuner_ien.rssilien  =  Si2176_TUNER_IEN_PROP_RSSILIEN_DISABLE;
    Si2176->prop->tuner_ien.rssihien  =  Si2176_TUNER_IEN_PROP_RSSIHIEN_DISABLE;

    if (Si2176_L1_SetProperty2(Si2176, Si2176_TUNER_IEN_PROP) != NO_Si2176_ERROR)
    {
      return ERROR_Si2176_SENDING_COMMAND;
    }

   /* setup IEN properties to enable ATVINT on CHL  */
    Si2176->prop->atv_ien.chlien    =  Si2176_ATV_IEN_PROP_CHLIEN_ENABLE;
    Si2176->prop->atv_ien.pclien    =  Si2176_ATV_IEN_PROP_PCLIEN_DISABLE;
    Si2176->prop->atv_ien.dlien     =  Si2176_ATV_IEN_PROP_DLIEN_DISABLE;
    Si2176->prop->atv_ien.snrlien   =  Si2176_ATV_IEN_PROP_SNRLIEN_DISABLE;
    Si2176->prop->atv_ien.snrhien   =  Si2176_ATV_IEN_PROP_SNRHIEN_DISABLE;
    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_IEN_PROP) != NO_Si2176_ERROR)
    {
      return ERROR_Si2176_SENDING_COMMAND;
    }
    /* setup ATV audio property for wide SIF scanning*/
    Si2176->prop->atv_audio_mode.audio_sys    =  Si2176_ATV_AUDIO_MODE_PROP_AUDIO_SYS_DEFAULT;
    Si2176->prop->atv_audio_mode.chan_bw    =  Si2176_ATV_AUDIO_MODE_PROP_CHAN_BW_DEFAULT;
    Si2176->prop->atv_audio_mode.demod_mode    =  Si2176_ATV_AUDIO_MODE_PROP_DEMOD_MODE_SIF;
    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_AUDIO_MODE_PROP) != NO_Si2176_ERROR)
    {
      return ERROR_Si2176_SENDING_COMMAND;
    }
   /* setup AFC acquistion range property to 1.5MHz for scanning */
    Si2176->prop->atv_afc_range.range_khz    =  1500;
    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_AFC_RANGE_PROP) != NO_Si2176_ERROR)
    {
       return ERROR_Si2176_SENDING_COMMAND;
    }
   /* Start Scanning */
    for (freq=rangeMinHz; freq < rangeMaxHz; )
    {

    /* before calling tune provide a callback stub that the user can update the frequency */
    /* if user requested abort then break from the loop */
    if (Si2176_UpdateChannelScanFrequency(freq, CHANNEL_NOT_FOUND))
      break;

    /* Call the Tune command to tune the frequency */
    /* if successful (a station was found) then the return value will be 0. */
    if (!Si2176_Tune (Si2176, Si2176_TUNER_TUNE_FREQ_CMD_MODE_ATV, freq))
    {

            /* Get ATV status */
      if (Si2176_L1_ATV_STATUS (Si2176, Si2176_ATV_STATUS_CMD_INTACK_OK))
      {
        return ERROR_Si2176_SENDING_COMMAND;
      }


      /* Add the afc_freq (khz) to the center frequency and add to the channel list */
      Si2176->ChannelList[Si2176->ChannelListSize]= freq + (Si2176->rsp->atv_status.afc_freq * 1000);
      /* Update the callback to indicate the channel is found */
      /* if user requested abort then break from the loop */
      if (Si2176_UpdateChannelScanFrequency(freq + (Si2176->rsp->atv_status.afc_freq * 1000), Si2176->ChannelListSize+1))
        break;

            freq = Si2176->ChannelList[Si2176->ChannelListSize++] + CHANNEL_BANDWIDTH;
         }
         else  /* We didn't find a station at this frequency so increment and move on */
         {
        /* if user requested abort then break from the loop */
      if (Si2176_UpdateChannelScanFrequency(freq, CHANNEL_NOT_FOUND))
        break;
      /*  channel not found! **/
             freq += SCAN_INTERVAL;
         }
    }
    /* Set AFC Range back to 100  */
    Si2176->prop->atv_afc_range.range_khz    =  100;
    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_AFC_RANGE_PROP) != NO_Si2176_ERROR)
    {
        return ERROR_Si2176_SENDING_COMMAND;
    }

 return 0;
}
/************************************************************************************************************************
  NAME: Si2176_ATV_Channel_Scan_PAL
  DESCRIPTION: Performs a channel scan for PAL (Systems B/G, D/K, L/L', and I) of the band
  Programming Guide Reference:    Flowchart A.10.0 - A10.3 (ATV Channel Scan flowchart for PAL)

  NOTE: this function requires an external sound processor to determine the PAL standard.  The user is
  required to implement the functions: L0_InitSoundProcessor(); and L0_AcquireSoundStandard(..);

  Parameter:  Pointer to Si2176 Context (I2C address)
  Parameter:  starting Frequency Hz
  Parameter:  ending Frequency Hz
  Parameter:  min RSSI dBm
  Parameter:  max RSSI dBm
  Parameter:  min SNR 1/2 dB
  Parameter:  max SNR 1/2 dB
  Returns:    0 if successful, otherwise an error.
************************************************************************************************************************/
int Si2176_ATV_Channel_Scan_PAL(L1_Si2176_Context *Si2176, unsigned long rangeMinHz, unsigned long rangeMaxHz, int minRSSIdBm, int maxRSSIdBm, int minSNRHalfdB, int maxSNRHalfdB)
{

  #define VHF_MAX 300000000
  #define SCAN_INTERVAL 1000000
  #define CHANNEL_NOT_FOUND 0
  char standard = Si2176_ATV_VIDEO_MODE_PROP_VIDEO_SYS_B;
  unsigned long freq;
  unsigned long channelIncrement;
  char posModulation;  /* flag for pos or neg modulation */
  int i;

  /*Clear the channel list size and channel array */
  Si2176->ChannelListSize=0;

  for (i=0; i< MAX_POSSIBLE_CHANNELS;i++)
  {
    Si2176->ChannelList[i]=0;
    Si2176->ChannelType[i][0]='\0';
  }
    /* configure the RSQ / RSSI threshold properties */
    Si2176->prop->atv_rsq_rssi_threshold.lo = minRSSIdBm;
    Si2176->prop->atv_rsq_rssi_threshold.hi = maxRSSIdBm;

    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP) != NO_Si2176_ERROR)
    {
       return ERROR_Si2176_SENDING_COMMAND;
    }
 /* configure the RSQ / SNR threshold properties */
    Si2176->prop->atv_rsq_snr_threshold.lo = minSNRHalfdB;
    Si2176->prop->atv_rsq_snr_threshold.hi = maxSNRHalfdB;

    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_RSQ_SNR_THRESHOLD_PROP) != NO_Si2176_ERROR)
    {
      return ERROR_Si2176_SENDING_COMMAND;
    }
  /* setup IEN properties to enable TUNINT on TC  */
    Si2176->prop->tuner_ien.tcien     =  Si2176_TUNER_IEN_PROP_TCIEN_ENABLE;
    Si2176->prop->tuner_ien.rssilien  =  Si2176_TUNER_IEN_PROP_RSSILIEN_DISABLE;
    Si2176->prop->tuner_ien.rssihien  =  Si2176_TUNER_IEN_PROP_RSSIHIEN_DISABLE;

    if (Si2176_L1_SetProperty2(Si2176, Si2176_TUNER_IEN_PROP) != NO_Si2176_ERROR)
    {
      return ERROR_Si2176_SENDING_COMMAND;
    }

   /* setup IEN properties to enable ATVINT on CHL  */
  Si2176->prop->atv_ien.chlien    =  Si2176_ATV_IEN_PROP_CHLIEN_ENABLE;
    Si2176->prop->atv_ien.pclien    =  Si2176_ATV_IEN_PROP_PCLIEN_DISABLE;
    Si2176->prop->atv_ien.dlien     =  Si2176_ATV_IEN_PROP_DLIEN_DISABLE;
    Si2176->prop->atv_ien.snrlien   =  Si2176_ATV_IEN_PROP_SNRLIEN_DISABLE;
    Si2176->prop->atv_ien.snrhien   =  Si2176_ATV_IEN_PROP_SNRHIEN_DISABLE;
    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_IEN_PROP) != NO_Si2176_ERROR)
    {
      return ERROR_Si2176_SENDING_COMMAND;
    }
  /* setup ATV audio property for wide SIF scanning*/
    Si2176->prop->atv_audio_mode.audio_sys    =  Si2176_ATV_AUDIO_MODE_PROP_AUDIO_SYS_DEFAULT;
    Si2176->prop->atv_audio_mode.chan_bw    =  Si2176_ATV_AUDIO_MODE_PROP_CHAN_BW_DEFAULT;
    Si2176->prop->atv_audio_mode.demod_mode    =  Si2176_ATV_AUDIO_MODE_PROP_DEMOD_MODE_SIF;
    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_AUDIO_MODE_PROP) != NO_Si2176_ERROR)
    {
      return ERROR_Si2176_SENDING_COMMAND;
    }
   /* setup AFC acquistion range property to 1.5MHz for scanning */
    Si2176->prop->atv_afc_range.range_khz    =  1500;
    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_AFC_RANGE_PROP) != NO_Si2176_ERROR)
    {
       return ERROR_Si2176_SENDING_COMMAND;
    }
   /* Start Scanning */
    for (freq=rangeMinHz; freq < rangeMaxHz; )
    {
    /* before calling tune provide a callback stub that the user can update the frequency */
    /* if user requested abort then break from the loop */
    if (Si2176_UpdateChannelScanFrequency(freq, CHANNEL_NOT_FOUND))
      break;
    /* set the modulation flag to 0 (neg) */
    posModulation=0;
    /* Negative Modulation configure the VideoMode property to System DK, PAL*/
    Si2176->prop->atv_video_mode.video_sys = Si2176_ATV_VIDEO_MODE_PROP_VIDEO_SYS_DK;    /* M ATV demodulation */
    Si2176->prop->atv_video_mode.color     = Si2176_ATV_VIDEO_MODE_PROP_COLOR_PAL_NTSC;    /* PAL_NTSC color system */
    Si2176->prop->atv_video_mode.trans     = Si2176_ATV_VIDEO_MODE_PROP_TRANS_TERRESTRIAL;    /* set trans to Terrestrial */
    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_VIDEO_MODE_PROP) != NO_Si2176_ERROR)
    {
       return ERROR_Si2176_SENDING_COMMAND;
    }

    /* Call the Tune command to tune the frequency */
    /* if successful (a station was found) then the return value will be 0. */
    if (!Si2176_Tune (Si2176, Si2176_TUNER_TUNE_FREQ_CMD_MODE_ATV, freq))
    {
      posModulation = 0;
         }
         else  /* We didn't find a station so try positive modulation */
         {
      /* Pos Modulation configure the VideoMode property to System DK, PAL*/
      Si2176->prop->atv_video_mode.video_sys = Si2176_ATV_VIDEO_MODE_PROP_VIDEO_SYS_L;    /* L ATV demodulation */
      Si2176->prop->atv_video_mode.color     = Si2176_ATV_VIDEO_MODE_PROP_COLOR_SECAM;    /* SECAM color system */
      Si2176->prop->atv_video_mode.trans     = Si2176_ATV_VIDEO_MODE_PROP_TRANS_TERRESTRIAL;    /* set trans to Terrestrial */
      if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_VIDEO_MODE_PROP) != NO_Si2176_ERROR)
      {
         return ERROR_Si2176_SENDING_COMMAND;
      }
      /* Call the Tune command to tune the frequency */
      /* if successful (a station was found) then the return value will be 0. */
      if (!Si2176_Tune (Si2176, Si2176_TUNER_TUNE_FREQ_CMD_MODE_ATV, freq))
      {
        posModulation=1;
      }
      else
      {
            /* if user requested abort then break from the loop */
          if (Si2176_UpdateChannelScanFrequency(freq, CHANNEL_NOT_FOUND))
            break;

        /* we didn't find any channels goto flowchart section B */
        freq += SCAN_INTERVAL;
        continue;
      }
         }
    /* Initialize the sound processor.   This may or may not be required for your application */
/*    L1_InitSoundProcessor();*/
    /* Run the sound processor and return the standard(s) */
    #define SOUND_PROCESSOR_TIMEOUT 10
/*    L1_AcquireSoundStandard(SOUND_PROCESSOR_TIMEOUT , &standard);*/
    if ((standard == Si2176_ATV_VIDEO_MODE_PROP_VIDEO_SYS_B) || (standard == Si2176_ATV_VIDEO_MODE_PROP_VIDEO_SYS_GH))
    {
      /* check for positive modulation */
      if (posModulation)
      {
            /* if user requested abort then break from the loop */
          if (Si2176_UpdateChannelScanFrequency(freq, CHANNEL_NOT_FOUND))
            break;

        /* goto flowchart section B */
        freq += SCAN_INTERVAL;
        continue;
      }
      else
      {
        if (freq < VHF_MAX)
        {
          Si2176->ChannelType[Si2176->ChannelListSize][0]='B';
          Si2176->ChannelType[Si2176->ChannelListSize][1]='\0';
        }
        else
        {
          Si2176->ChannelType[Si2176->ChannelListSize][0]='G';
          Si2176->ChannelType[Si2176->ChannelListSize][1]='H';
          Si2176->ChannelType[Si2176->ChannelListSize][2]='\0';
        }
      }
    }
    else if (standard == Si2176_ATV_VIDEO_MODE_PROP_VIDEO_SYS_I)
    {
        if (posModulation)
        {
                /* if user requested abort then break from the loop */
              if (Si2176_UpdateChannelScanFrequency(freq, CHANNEL_NOT_FOUND))
                break;

          /* goto flowchart section B */
          freq += SCAN_INTERVAL;
          continue;
        }
        else
        {
          Si2176->ChannelType[Si2176->ChannelListSize][0]='I';
          Si2176->ChannelType[Si2176->ChannelListSize][1]='\0';
        }
    }
    else if ((standard == Si2176_ATV_VIDEO_MODE_PROP_VIDEO_SYS_L) || (standard == Si2176_ATV_VIDEO_MODE_PROP_VIDEO_SYS_DK))
    {
        if (posModulation)
        {
          Si2176->ChannelType[Si2176->ChannelListSize][0]='L';
          Si2176->ChannelType[Si2176->ChannelListSize][1]='\0';
        }
        else
        {
          Si2176->ChannelType[Si2176->ChannelListSize][0]='D';
          Si2176->ChannelType[Si2176->ChannelListSize][1]='K';
          Si2176->ChannelType[Si2176->ChannelListSize][2]='\0';
        }
    }
    else
    {
      /* standard not found */
            /* if user requested abort then break from the loop */
            if (Si2176_UpdateChannelScanFrequency(freq, CHANNEL_NOT_FOUND))
          break;

      /* goto flowchart section B */
      freq += SCAN_INTERVAL;
      continue;
    }
    /* if we got here, then we have a valid channel with a channelType */
    /* Get ATV status */
    if (Si2176_L1_ATV_STATUS (Si2176, Si2176_ATV_STATUS_CMD_INTACK_OK))
    {
      return ERROR_Si2176_SENDING_COMMAND;
    }
    if (Si2176->ChannelType[Si2176->ChannelListSize][0]=='B')
    {
      /* Add the afc_freq (khz) to the center frequency and add to the channel list */
      Si2176->ChannelList[Si2176->ChannelListSize]= freq + (Si2176->rsp->atv_status.afc_freq * 1000)-500000;
      channelIncrement = 7000000;
    }
    else
    {
    /* Add the afc_freq (khz) to the center frequency and add to the channel list */
      Si2176->ChannelList[Si2176->ChannelListSize]= freq + (Si2176->rsp->atv_status.afc_freq * 1000);
      channelIncrement = 8000000;
    }
    /* Update the callback to indicate the channel is found */
    /* if user requested abort then break from the loop */
    if (Si2176_UpdateChannelScanFrequency(Si2176->ChannelList[Si2176->ChannelListSize], Si2176->ChannelListSize+1))
      break;
    /* go to the next frequency in the loop */
    freq = Si2176->ChannelList[Si2176->ChannelListSize++] + channelIncrement;
    }
    /* Set AFC Range back to 100  */
    Si2176->prop->atv_afc_range.range_khz    =  100;
    if (Si2176_L1_SetProperty2(Si2176, Si2176_ATV_AFC_RANGE_PROP) != NO_Si2176_ERROR)
    {
        return ERROR_Si2176_SENDING_COMMAND;
    }

 return 0;
}




