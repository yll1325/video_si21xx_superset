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
/*************************************************************************************
                  Silicon Laboratories Broadcast Si2176 Layer 1 API
   API properties strings functions definitions
   FILE: Si2176_L1_Properties.c
   Supported IC : Si2176
   Compiled for ROM 13 firmware 3_2_build_6
   Revision: 0.1
   Tag:  TAGNAME
   Date: December 22 2011
**************************************************************************************/
#define   Si2176_COMMAND_PROTOTYPES

#include "Si2176_L1_API.h"
#include "Si2176_Properties_Strings.h"

#ifdef Si2176_COMMAND_LINE_APPLICATION

/* define a local PropObj variable to use for the Property Dictionary initializer */
Si2176_PropObj Si2176_prop;
char optionText[20];

/* _properties_features_text_insertion_start */
char *Si2176_featureText[] =
{
  "ATV",
  "COMMON",
  "DTV",
  "TUNER",
};
/* _properties_features_text_insertion_point */

/* _properties_strings_insertion_start */
Si2176_optionStruct    Si2176_ATV_AFC_RANGE_PROP_RANGE_KHZ[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE", 65535}
};
Si2176_fieldDicoStruct Si2176_ATV_AFC_RANGE_PROP_FIELDS[] =
{
  {"RANGE_KHZ", Si2176_UNSIGNED_INT, &Si2176_prop.atv_afc_range.range_khz, sizeof(Si2176_ATV_AFC_RANGE_PROP_RANGE_KHZ)/sizeof(Si2176_optionStruct), Si2176_ATV_AFC_RANGE_PROP_RANGE_KHZ},
};

Si2176_optionStruct    Si2176_ATV_AF_OUT_PROP_VOLUME[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",    63}
};
Si2176_fieldDicoStruct Si2176_ATV_AF_OUT_PROP_FIELDS[] =
{
  {"VOLUME", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_af_out.volume, sizeof(Si2176_ATV_AF_OUT_PROP_VOLUME)/sizeof(Si2176_optionStruct), Si2176_ATV_AF_OUT_PROP_VOLUME},
};

Si2176_optionStruct    Si2176_ATV_AGC_SPEED_PROP_IF_AGC_SPEED[] =
{
  {"AUTO",       0},
  {"89",        89},
  {"105",      105},
  {"121",      121},
  {"137",      137},
  {"158",      158},
  {"172",      172},
  {"178",      178},
  {"185",      185},
  {"196",      196},
  {"206",      206},
  {"216",      216},
  {"219",      219},
  {"222",      222},
  {"248",      248},
  {"250",      250},
  {"251",      251},
  {"CUSTOM",     1},
};
Si2176_fieldDicoStruct Si2176_ATV_AGC_SPEED_PROP_FIELDS[] =
{
  {"IF_AGC_SPEED", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_agc_speed.if_agc_speed, sizeof(Si2176_ATV_AGC_SPEED_PROP_IF_AGC_SPEED)/sizeof(Si2176_optionStruct), Si2176_ATV_AGC_SPEED_PROP_IF_AGC_SPEED},
};

Si2176_optionStruct    Si2176_ATV_AUDIO_MODE_PROP_AUDIO_SYS[] =
{
  {"DEFAULT",             0},
  {"MONO",                1},
  {"MONO_NICAM",          2},
  {"A2",                  3},
  {"A2_DK2",              4},
  {"A2_DK3",              5},
  {"BTSC",                6},
  {"EIAJ",                7},
  {"SCAN",                8},
  {"A2_DK4",              9},
  {"WIDE_SCAN",          10},
  {"MONO_NICAM_6DB",     11},
  {"MONO_NICAM_10DB",    12},
};
Si2176_optionStruct    Si2176_ATV_AUDIO_MODE_PROP_DEMOD_MODE[] =
{
  {"SIF",     0},
  {"AM",      1},
  {"FM1",     2},
  {"FM2",     3},
};
Si2176_optionStruct    Si2176_ATV_AUDIO_MODE_PROP_CHAN_BW[] =
{
  {"DEFAULT",            0},
  {"4X_OVERMOD",         1},
  {"8X_OVERMOD",         2},
  {"12X_OVERMOD",        3},
  {"7P5_KHZ_OFFSET",     4},
  {"15_KHZ_OFFSET",      5},
  {"30_KHZ_OFFSET",      6},
  {"75_KHZ_OFFSET",      7},
  {"150_KHZ_OFFSET",     8},
};
Si2176_fieldDicoStruct Si2176_ATV_AUDIO_MODE_PROP_FIELDS[] =
{
  {"AUDIO_SYS",  Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_audio_mode.audio_sys , sizeof(Si2176_ATV_AUDIO_MODE_PROP_AUDIO_SYS )/sizeof(Si2176_optionStruct), Si2176_ATV_AUDIO_MODE_PROP_AUDIO_SYS },
  {"DEMOD_MODE", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_audio_mode.demod_mode, sizeof(Si2176_ATV_AUDIO_MODE_PROP_DEMOD_MODE)/sizeof(Si2176_optionStruct), Si2176_ATV_AUDIO_MODE_PROP_DEMOD_MODE},
  {"CHAN_BW",    Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_audio_mode.chan_bw   , sizeof(Si2176_ATV_AUDIO_MODE_PROP_CHAN_BW   )/sizeof(Si2176_optionStruct), Si2176_ATV_AUDIO_MODE_PROP_CHAN_BW   },
};

Si2176_optionStruct    Si2176_ATV_CVBS_OUT_PROP_OFFSET[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",   255}
};
Si2176_optionStruct    Si2176_ATV_CVBS_OUT_PROP_AMP[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",   255}
};
Si2176_fieldDicoStruct Si2176_ATV_CVBS_OUT_PROP_FIELDS[] =
{
  {"OFFSET", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_cvbs_out.offset, sizeof(Si2176_ATV_CVBS_OUT_PROP_OFFSET)/sizeof(Si2176_optionStruct), Si2176_ATV_CVBS_OUT_PROP_OFFSET},
  {"AMP",    Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_cvbs_out.amp   , sizeof(Si2176_ATV_CVBS_OUT_PROP_AMP   )/sizeof(Si2176_optionStruct), Si2176_ATV_CVBS_OUT_PROP_AMP   },
};

Si2176_optionStruct    Si2176_ATV_CVBS_OUT_FINE_PROP_OFFSET[] =
{
  {"MIN_RANGE",  -128},
  {"MAX_RANGE",   127}
};
Si2176_optionStruct    Si2176_ATV_CVBS_OUT_FINE_PROP_AMP[] =
{
  {"MIN_RANGE",    25},
  {"MAX_RANGE",   100}
};
Si2176_fieldDicoStruct Si2176_ATV_CVBS_OUT_FINE_PROP_FIELDS[] =
{
  {"OFFSET",   Si2176_SIGNED_CHAR, &Si2176_prop.atv_cvbs_out_fine.offset, sizeof(Si2176_ATV_CVBS_OUT_FINE_PROP_OFFSET)/sizeof(Si2176_optionStruct), Si2176_ATV_CVBS_OUT_FINE_PROP_OFFSET},
  {"AMP",    Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_cvbs_out_fine.amp   , sizeof(Si2176_ATV_CVBS_OUT_FINE_PROP_AMP   )/sizeof(Si2176_optionStruct), Si2176_ATV_CVBS_OUT_FINE_PROP_AMP   },
};

Si2176_optionStruct    Si2176_ATV_IEN_PROP_CHLIEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_ATV_IEN_PROP_PCLIEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_ATV_IEN_PROP_DLIEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_ATV_IEN_PROP_SNRLIEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_ATV_IEN_PROP_SNRHIEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_fieldDicoStruct Si2176_ATV_IEN_PROP_FIELDS[] =
{
  {"CHLIEN",  Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_ien.chlien , sizeof(Si2176_ATV_IEN_PROP_CHLIEN )/sizeof(Si2176_optionStruct), Si2176_ATV_IEN_PROP_CHLIEN },
  {"PCLIEN",  Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_ien.pclien , sizeof(Si2176_ATV_IEN_PROP_PCLIEN )/sizeof(Si2176_optionStruct), Si2176_ATV_IEN_PROP_PCLIEN },
  {"DLIEN",   Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_ien.dlien  , sizeof(Si2176_ATV_IEN_PROP_DLIEN  )/sizeof(Si2176_optionStruct), Si2176_ATV_IEN_PROP_DLIEN  },
  {"SNRLIEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_ien.snrlien, sizeof(Si2176_ATV_IEN_PROP_SNRLIEN)/sizeof(Si2176_optionStruct), Si2176_ATV_IEN_PROP_SNRLIEN},
  {"SNRHIEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_ien.snrhien, sizeof(Si2176_ATV_IEN_PROP_SNRHIEN)/sizeof(Si2176_optionStruct), Si2176_ATV_IEN_PROP_SNRHIEN},
};

Si2176_optionStruct    Si2176_ATV_INT_SENSE_PROP_CHLNEGEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_ATV_INT_SENSE_PROP_PCLNEGEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_ATV_INT_SENSE_PROP_DLNEGEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_ATV_INT_SENSE_PROP_SNRLNEGEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_ATV_INT_SENSE_PROP_SNRHNEGEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_ATV_INT_SENSE_PROP_CHLPOSEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_ATV_INT_SENSE_PROP_PCLPOSEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_ATV_INT_SENSE_PROP_DLPOSEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_ATV_INT_SENSE_PROP_SNRLPOSEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_ATV_INT_SENSE_PROP_SNRHPOSEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_fieldDicoStruct Si2176_ATV_INT_SENSE_PROP_FIELDS[] =
{
  {"CHLNEGEN",  Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_int_sense.chlnegen , sizeof(Si2176_ATV_INT_SENSE_PROP_CHLNEGEN )/sizeof(Si2176_optionStruct), Si2176_ATV_INT_SENSE_PROP_CHLNEGEN },
  {"PCLNEGEN",  Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_int_sense.pclnegen , sizeof(Si2176_ATV_INT_SENSE_PROP_PCLNEGEN )/sizeof(Si2176_optionStruct), Si2176_ATV_INT_SENSE_PROP_PCLNEGEN },
  {"DLNEGEN",   Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_int_sense.dlnegen  , sizeof(Si2176_ATV_INT_SENSE_PROP_DLNEGEN  )/sizeof(Si2176_optionStruct), Si2176_ATV_INT_SENSE_PROP_DLNEGEN  },
  {"SNRLNEGEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_int_sense.snrlnegen, sizeof(Si2176_ATV_INT_SENSE_PROP_SNRLNEGEN)/sizeof(Si2176_optionStruct), Si2176_ATV_INT_SENSE_PROP_SNRLNEGEN},
  {"SNRHNEGEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_int_sense.snrhnegen, sizeof(Si2176_ATV_INT_SENSE_PROP_SNRHNEGEN)/sizeof(Si2176_optionStruct), Si2176_ATV_INT_SENSE_PROP_SNRHNEGEN},
  {"CHLPOSEN",  Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_int_sense.chlposen , sizeof(Si2176_ATV_INT_SENSE_PROP_CHLPOSEN )/sizeof(Si2176_optionStruct), Si2176_ATV_INT_SENSE_PROP_CHLPOSEN },
  {"PCLPOSEN",  Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_int_sense.pclposen , sizeof(Si2176_ATV_INT_SENSE_PROP_PCLPOSEN )/sizeof(Si2176_optionStruct), Si2176_ATV_INT_SENSE_PROP_PCLPOSEN },
  {"DLPOSEN",   Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_int_sense.dlposen  , sizeof(Si2176_ATV_INT_SENSE_PROP_DLPOSEN  )/sizeof(Si2176_optionStruct), Si2176_ATV_INT_SENSE_PROP_DLPOSEN  },
  {"SNRLPOSEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_int_sense.snrlposen, sizeof(Si2176_ATV_INT_SENSE_PROP_SNRLPOSEN)/sizeof(Si2176_optionStruct), Si2176_ATV_INT_SENSE_PROP_SNRLPOSEN},
  {"SNRHPOSEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_int_sense.snrhposen, sizeof(Si2176_ATV_INT_SENSE_PROP_SNRHPOSEN)/sizeof(Si2176_optionStruct), Si2176_ATV_INT_SENSE_PROP_SNRHPOSEN},
};

Si2176_optionStruct    Si2176_ATV_RF_TOP_PROP_ATV_RF_TOP[] =
{
  {"AUTO",      0},
  {"0DB",       6},
  {"M1DB",      7},
  {"M2DB",      8},
  {"M3DB",      9},
  {"M4DB",     10},
  {"M5DB",     11},
  {"M6DB",     12},
  {"M7DB",     13},
  {"M8DB",     14},
  {"M9DB",     15},
  {"M10DB",    16},
  {"M11DB",    17},
  {"M12DB",    18},
};
Si2176_fieldDicoStruct Si2176_ATV_RF_TOP_PROP_FIELDS[] =
{
  {"ATV_RF_TOP", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_rf_top.atv_rf_top, sizeof(Si2176_ATV_RF_TOP_PROP_ATV_RF_TOP)/sizeof(Si2176_optionStruct), Si2176_ATV_RF_TOP_PROP_ATV_RF_TOP},
};

Si2176_optionStruct    Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP_LO[] =
{
  {"MIN_RANGE",  -128},
  {"MAX_RANGE",   127}
};
Si2176_optionStruct    Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP_HI[] =
{
  {"MIN_RANGE",  -128},
  {"MAX_RANGE",   127}
};
Si2176_fieldDicoStruct Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP_FIELDS[] =
{
  {"LO",   Si2176_SIGNED_CHAR, &Si2176_prop.atv_rsq_rssi_threshold.lo, sizeof(Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP_LO)/sizeof(Si2176_optionStruct), Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP_LO},
  {"HI",   Si2176_SIGNED_CHAR, &Si2176_prop.atv_rsq_rssi_threshold.hi, sizeof(Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP_HI)/sizeof(Si2176_optionStruct), Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP_HI},
};

Si2176_optionStruct    Si2176_ATV_RSQ_SNR_THRESHOLD_PROP_LO[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",   255}
};
Si2176_optionStruct    Si2176_ATV_RSQ_SNR_THRESHOLD_PROP_HI[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",   255}
};
Si2176_fieldDicoStruct Si2176_ATV_RSQ_SNR_THRESHOLD_PROP_FIELDS[] =
{
  {"LO", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_rsq_snr_threshold.lo, sizeof(Si2176_ATV_RSQ_SNR_THRESHOLD_PROP_LO)/sizeof(Si2176_optionStruct), Si2176_ATV_RSQ_SNR_THRESHOLD_PROP_LO},
  {"HI", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_rsq_snr_threshold.hi, sizeof(Si2176_ATV_RSQ_SNR_THRESHOLD_PROP_HI)/sizeof(Si2176_optionStruct), Si2176_ATV_RSQ_SNR_THRESHOLD_PROP_HI},
};

Si2176_optionStruct    Si2176_ATV_SIF_OUT_PROP_OFFSET[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",   255}
};
Si2176_optionStruct    Si2176_ATV_SIF_OUT_PROP_AMP[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",   255}
};
Si2176_fieldDicoStruct Si2176_ATV_SIF_OUT_PROP_FIELDS[] =
{
  {"OFFSET", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_sif_out.offset, sizeof(Si2176_ATV_SIF_OUT_PROP_OFFSET)/sizeof(Si2176_optionStruct), Si2176_ATV_SIF_OUT_PROP_OFFSET},
  {"AMP",    Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_sif_out.amp   , sizeof(Si2176_ATV_SIF_OUT_PROP_AMP   )/sizeof(Si2176_optionStruct), Si2176_ATV_SIF_OUT_PROP_AMP   },
};

Si2176_optionStruct    Si2176_ATV_SOUND_AGC_LIMIT_PROP_MAX_GAIN[] =
{
  {"MIN_RANGE",   -84},
  {"MAX_RANGE",    84}
};
Si2176_optionStruct    Si2176_ATV_SOUND_AGC_LIMIT_PROP_MIN_GAIN[] =
{
  {"MIN_RANGE",   -84},
  {"MAX_RANGE",    84}
};
Si2176_fieldDicoStruct Si2176_ATV_SOUND_AGC_LIMIT_PROP_FIELDS[] =
{
  {"MAX_GAIN",   Si2176_SIGNED_CHAR, &Si2176_prop.atv_sound_agc_limit.max_gain, sizeof(Si2176_ATV_SOUND_AGC_LIMIT_PROP_MAX_GAIN)/sizeof(Si2176_optionStruct), Si2176_ATV_SOUND_AGC_LIMIT_PROP_MAX_GAIN},
  {"MIN_GAIN",   Si2176_SIGNED_CHAR, &Si2176_prop.atv_sound_agc_limit.min_gain, sizeof(Si2176_ATV_SOUND_AGC_LIMIT_PROP_MIN_GAIN)/sizeof(Si2176_optionStruct), Si2176_ATV_SOUND_AGC_LIMIT_PROP_MIN_GAIN},
};

Si2176_optionStruct    Si2176_ATV_SOUND_AGC_SPEED_PROP_SYSTEM_L[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",    15}
};
Si2176_optionStruct    Si2176_ATV_SOUND_AGC_SPEED_PROP_OTHER_SYSTEMS[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",    15}
};
Si2176_fieldDicoStruct Si2176_ATV_SOUND_AGC_SPEED_PROP_FIELDS[] =
{
  {"SYSTEM_L",      Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_sound_agc_speed.system_l     , sizeof(Si2176_ATV_SOUND_AGC_SPEED_PROP_SYSTEM_L     )/sizeof(Si2176_optionStruct), Si2176_ATV_SOUND_AGC_SPEED_PROP_SYSTEM_L     },
  {"OTHER_SYSTEMS", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_sound_agc_speed.other_systems, sizeof(Si2176_ATV_SOUND_AGC_SPEED_PROP_OTHER_SYSTEMS)/sizeof(Si2176_optionStruct), Si2176_ATV_SOUND_AGC_SPEED_PROP_OTHER_SYSTEMS},
};

Si2176_optionStruct    Si2176_ATV_VIDEO_EQUALIZER_PROP_SLOPE[] =
{
  {"MIN_RANGE",    -8},
  {"MAX_RANGE",     7}
};
Si2176_fieldDicoStruct Si2176_ATV_VIDEO_EQUALIZER_PROP_FIELDS[] =
{
  {"SLOPE",   Si2176_SIGNED_CHAR, &Si2176_prop.atv_video_equalizer.slope, sizeof(Si2176_ATV_VIDEO_EQUALIZER_PROP_SLOPE)/sizeof(Si2176_optionStruct), Si2176_ATV_VIDEO_EQUALIZER_PROP_SLOPE},
};

Si2176_optionStruct    Si2176_ATV_VIDEO_MODE_PROP_VIDEO_SYS[] =
{
  {"B",      0},
  {"GH",     1},
  {"M",      2},
  {"N",      3},
  {"I",      4},
  {"DK",     5},
  {"L",      6},
  {"LP",     7},
};
Si2176_optionStruct    Si2176_ATV_VIDEO_MODE_PROP_COLOR[] =
{
  {"PAL_NTSC",     0},
  {"SECAM",        1},
};
Si2176_optionStruct    Si2176_ATV_VIDEO_MODE_PROP_TRANS[] =
{
  {"TERRESTRIAL",     0},
  {"CABLE",           1},
};
Si2176_optionStruct    Si2176_ATV_VIDEO_MODE_PROP_INVERT_SIGNAL[] =
{
  {"NORMAL",       0},
  {"INVERTED",     1},
};
Si2176_fieldDicoStruct Si2176_ATV_VIDEO_MODE_PROP_FIELDS[] =
{
  {"VIDEO_SYS",     Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_video_mode.video_sys    , sizeof(Si2176_ATV_VIDEO_MODE_PROP_VIDEO_SYS    )/sizeof(Si2176_optionStruct), Si2176_ATV_VIDEO_MODE_PROP_VIDEO_SYS    },
  {"COLOR",         Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_video_mode.color        , sizeof(Si2176_ATV_VIDEO_MODE_PROP_COLOR        )/sizeof(Si2176_optionStruct), Si2176_ATV_VIDEO_MODE_PROP_COLOR        },
  {"TRANS",         Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_video_mode.trans        , sizeof(Si2176_ATV_VIDEO_MODE_PROP_TRANS        )/sizeof(Si2176_optionStruct), Si2176_ATV_VIDEO_MODE_PROP_TRANS        },
  {"INVERT_SIGNAL", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_video_mode.invert_signal, sizeof(Si2176_ATV_VIDEO_MODE_PROP_INVERT_SIGNAL)/sizeof(Si2176_optionStruct), Si2176_ATV_VIDEO_MODE_PROP_INVERT_SIGNAL},
};

Si2176_optionStruct    Si2176_ATV_VSNR_CAP_PROP_ATV_VSNR_CAP[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",   127}
};
Si2176_fieldDicoStruct Si2176_ATV_VSNR_CAP_PROP_FIELDS[] =
{
  {"ATV_VSNR_CAP", Si2176_UNSIGNED_CHAR, &Si2176_prop.atv_vsnr_cap.atv_vsnr_cap, sizeof(Si2176_ATV_VSNR_CAP_PROP_ATV_VSNR_CAP)/sizeof(Si2176_optionStruct), Si2176_ATV_VSNR_CAP_PROP_ATV_VSNR_CAP},
};

Si2176_optionStruct    Si2176_CRYSTAL_TRIM_PROP_XO_CAP[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",    15}
};
Si2176_fieldDicoStruct Si2176_CRYSTAL_TRIM_PROP_FIELDS[] =
{
  {"XO_CAP", Si2176_UNSIGNED_CHAR, &Si2176_prop.crystal_trim.xo_cap, sizeof(Si2176_CRYSTAL_TRIM_PROP_XO_CAP)/sizeof(Si2176_optionStruct), Si2176_CRYSTAL_TRIM_PROP_XO_CAP},
};

Si2176_optionStruct    Si2176_DTV_AGC_FREEZE_INPUT_PROP_LEVEL[] =
{
  {"LOW",      0},
  {"HIGH",     1},
};
Si2176_optionStruct    Si2176_DTV_AGC_FREEZE_INPUT_PROP_PIN[] =
{
  {"NONE",      0},
  {"GPIO1",     1},
  {"GPIO2",     2},
  {"GPIO3",     3},
};
Si2176_fieldDicoStruct Si2176_DTV_AGC_FREEZE_INPUT_PROP_FIELDS[] =
{
  {"LEVEL", Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_agc_freeze_input.level, sizeof(Si2176_DTV_AGC_FREEZE_INPUT_PROP_LEVEL)/sizeof(Si2176_optionStruct), Si2176_DTV_AGC_FREEZE_INPUT_PROP_LEVEL},
  {"PIN",   Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_agc_freeze_input.pin  , sizeof(Si2176_DTV_AGC_FREEZE_INPUT_PROP_PIN  )/sizeof(Si2176_optionStruct), Si2176_DTV_AGC_FREEZE_INPUT_PROP_PIN  },
};

Si2176_optionStruct    Si2176_DTV_AGC_SPEED_PROP_IF_AGC_SPEED[] =
{
  {"AUTO",     0},
  {"39",      39},
  {"54",      54},
  {"63",      63},
  {"89",      89},
  {"105",    105},
  {"121",    121},
  {"137",    137},
  {"158",    158},
  {"172",    172},
  {"185",    185},
  {"196",    196},
  {"206",    206},
  {"216",    216},
  {"219",    219},
  {"222",    222},
};
Si2176_optionStruct    Si2176_DTV_AGC_SPEED_PROP_AGC_DECIM[] =
{
  {"OFF",     0},
  {"2",       1},
  {"4",       2},
  {"8",       3},
};
Si2176_fieldDicoStruct Si2176_DTV_AGC_SPEED_PROP_FIELDS[] =
{
  {"IF_AGC_SPEED", Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_agc_speed.if_agc_speed, sizeof(Si2176_DTV_AGC_SPEED_PROP_IF_AGC_SPEED)/sizeof(Si2176_optionStruct), Si2176_DTV_AGC_SPEED_PROP_IF_AGC_SPEED},
  {"AGC_DECIM",    Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_agc_speed.agc_decim   , sizeof(Si2176_DTV_AGC_SPEED_PROP_AGC_DECIM   )/sizeof(Si2176_optionStruct), Si2176_DTV_AGC_SPEED_PROP_AGC_DECIM   },
};

Si2176_optionStruct    Si2176_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE[] =
{
  {"LIF_IF1",         0},
  {"LIF_IF2",         1},
  {"LIF_SE_IF1A",     4},
  {"LIF_SE_IF2A",     5},
};
Si2176_optionStruct    Si2176_DTV_CONFIG_IF_PORT_PROP_DTV_AGC_SOURCE[] =
{
  {"INTERNAL",          0},
  {"DLIF_AGC_3DB",      1},
  {"ALIF_AGC_3DB",      2},
  {"DLIF_AGC_FULL",     3},
  {"ALIF_AGC_FULL",     4},
};
Si2176_fieldDicoStruct Si2176_DTV_CONFIG_IF_PORT_PROP_FIELDS[] =
{
  {"DTV_OUT_TYPE",   Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_config_if_port.dtv_out_type  , sizeof(Si2176_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE  )/sizeof(Si2176_optionStruct), Si2176_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE  },
  {"DTV_AGC_SOURCE", Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_config_if_port.dtv_agc_source, sizeof(Si2176_DTV_CONFIG_IF_PORT_PROP_DTV_AGC_SOURCE)/sizeof(Si2176_optionStruct), Si2176_DTV_CONFIG_IF_PORT_PROP_DTV_AGC_SOURCE},
};

Si2176_optionStruct    Si2176_DTV_EXT_AGC_PROP_MIN_10MV[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",   215}
};
Si2176_optionStruct    Si2176_DTV_EXT_AGC_PROP_MAX_10MV[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",   215}
};
Si2176_fieldDicoStruct Si2176_DTV_EXT_AGC_PROP_FIELDS[] =
{
  {"MIN_10MV", Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_ext_agc.min_10mv, sizeof(Si2176_DTV_EXT_AGC_PROP_MIN_10MV)/sizeof(Si2176_optionStruct), Si2176_DTV_EXT_AGC_PROP_MIN_10MV},
  {"MAX_10MV", Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_ext_agc.max_10mv, sizeof(Si2176_DTV_EXT_AGC_PROP_MAX_10MV)/sizeof(Si2176_optionStruct), Si2176_DTV_EXT_AGC_PROP_MAX_10MV},
};

Si2176_optionStruct    Si2176_DTV_FILTER_SELECT_PROP_FILTER[] =
{
  {"DEFAULT",     0},
  {"CUSTOM1",     1},
  {"CUSTOM2",     2},
};
Si2176_fieldDicoStruct Si2176_DTV_FILTER_SELECT_PROP_FIELDS[] =
{
  {"FILTER", Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_filter_select.filter, sizeof(Si2176_DTV_FILTER_SELECT_PROP_FILTER)/sizeof(Si2176_optionStruct), Si2176_DTV_FILTER_SELECT_PROP_FILTER},
};

Si2176_optionStruct    Si2176_DTV_IEN_PROP_CHLIEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_fieldDicoStruct Si2176_DTV_IEN_PROP_FIELDS[] =
{
  {"CHLIEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_ien.chlien, sizeof(Si2176_DTV_IEN_PROP_CHLIEN)/sizeof(Si2176_optionStruct), Si2176_DTV_IEN_PROP_CHLIEN},
};

Si2176_optionStruct    Si2176_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED[] =
{
  {"AUTO",     0},
  {"39",      39},
  {"54",      54},
  {"63",      63},
  {"89",      89},
  {"105",    105},
  {"121",    121},
  {"137",    137},
  {"158",    158},
  {"172",    172},
  {"185",    185},
  {"196",    196},
  {"206",    206},
  {"216",    216},
  {"219",    219},
  {"222",    222},
};
Si2176_optionStruct    Si2176_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM[] =
{
  {"OFF",     0},
  {"2",       1},
  {"4",       2},
  {"8",       3},
};
Si2176_fieldDicoStruct Si2176_DTV_INITIAL_AGC_SPEED_PROP_FIELDS[] =
{
  {"IF_AGC_SPEED", Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_initial_agc_speed.if_agc_speed, sizeof(Si2176_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED)/sizeof(Si2176_optionStruct), Si2176_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED},
  {"AGC_DECIM",    Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_initial_agc_speed.agc_decim   , sizeof(Si2176_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM   )/sizeof(Si2176_optionStruct), Si2176_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM   },
};

Si2176_optionStruct    Si2176_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE", 65535}
};
Si2176_fieldDicoStruct Si2176_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_FIELDS[] =
{
  {"PERIOD", Si2176_UNSIGNED_INT, &Si2176_prop.dtv_initial_agc_speed_period.period, sizeof(Si2176_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD)/sizeof(Si2176_optionStruct), Si2176_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_PERIOD},
};

Si2176_optionStruct    Si2176_DTV_INTERNAL_ZIF_PROP_ATSC[] =
{
  {"LIF",     0},
  {"ZIF",     1},
};
Si2176_optionStruct    Si2176_DTV_INTERNAL_ZIF_PROP_QAM_US[] =
{
  {"LIF",     0},
  {"ZIF",     1},
};
Si2176_optionStruct    Si2176_DTV_INTERNAL_ZIF_PROP_DVBT[] =
{
  {"LIF",     0},
  {"ZIF",     1},
};
Si2176_optionStruct    Si2176_DTV_INTERNAL_ZIF_PROP_DVBC[] =
{
  {"LIF",     0},
  {"ZIF",     1},
};
Si2176_optionStruct    Si2176_DTV_INTERNAL_ZIF_PROP_ISDBT[] =
{
  {"LIF",     0},
  {"ZIF",     1},
};
Si2176_optionStruct    Si2176_DTV_INTERNAL_ZIF_PROP_ISDBC[] =
{
  {"LIF",     0},
  {"ZIF",     1},
};
Si2176_optionStruct    Si2176_DTV_INTERNAL_ZIF_PROP_DTMB[] =
{
  {"LIF",     0},
  {"ZIF",     1},
};
Si2176_fieldDicoStruct Si2176_DTV_INTERNAL_ZIF_PROP_FIELDS[] =
{
  {"ATSC",   Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_internal_zif.atsc  , sizeof(Si2176_DTV_INTERNAL_ZIF_PROP_ATSC  )/sizeof(Si2176_optionStruct), Si2176_DTV_INTERNAL_ZIF_PROP_ATSC  },
  {"QAM_US", Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_internal_zif.qam_us, sizeof(Si2176_DTV_INTERNAL_ZIF_PROP_QAM_US)/sizeof(Si2176_optionStruct), Si2176_DTV_INTERNAL_ZIF_PROP_QAM_US},
  {"DVBT",   Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_internal_zif.dvbt  , sizeof(Si2176_DTV_INTERNAL_ZIF_PROP_DVBT  )/sizeof(Si2176_optionStruct), Si2176_DTV_INTERNAL_ZIF_PROP_DVBT  },
  {"DVBC",   Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_internal_zif.dvbc  , sizeof(Si2176_DTV_INTERNAL_ZIF_PROP_DVBC  )/sizeof(Si2176_optionStruct), Si2176_DTV_INTERNAL_ZIF_PROP_DVBC  },
  {"ISDBT",  Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_internal_zif.isdbt , sizeof(Si2176_DTV_INTERNAL_ZIF_PROP_ISDBT )/sizeof(Si2176_optionStruct), Si2176_DTV_INTERNAL_ZIF_PROP_ISDBT },
  {"ISDBC",  Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_internal_zif.isdbc , sizeof(Si2176_DTV_INTERNAL_ZIF_PROP_ISDBC )/sizeof(Si2176_optionStruct), Si2176_DTV_INTERNAL_ZIF_PROP_ISDBC },
  {"DTMB",   Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_internal_zif.dtmb  , sizeof(Si2176_DTV_INTERNAL_ZIF_PROP_DTMB  )/sizeof(Si2176_optionStruct), Si2176_DTV_INTERNAL_ZIF_PROP_DTMB  },
};

Si2176_optionStruct    Si2176_DTV_INT_SENSE_PROP_CHLNEGEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_DTV_INT_SENSE_PROP_CHLPOSEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_fieldDicoStruct Si2176_DTV_INT_SENSE_PROP_FIELDS[] =
{
  {"CHLNEGEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_int_sense.chlnegen, sizeof(Si2176_DTV_INT_SENSE_PROP_CHLNEGEN)/sizeof(Si2176_optionStruct), Si2176_DTV_INT_SENSE_PROP_CHLNEGEN},
  {"CHLPOSEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_int_sense.chlposen, sizeof(Si2176_DTV_INT_SENSE_PROP_CHLPOSEN)/sizeof(Si2176_optionStruct), Si2176_DTV_INT_SENSE_PROP_CHLPOSEN},
};

Si2176_optionStruct    Si2176_DTV_LIF_FREQ_PROP_OFFSET[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",  7000}
};
Si2176_fieldDicoStruct Si2176_DTV_LIF_FREQ_PROP_FIELDS[] =
{
  {"OFFSET", Si2176_UNSIGNED_INT, &Si2176_prop.dtv_lif_freq.offset, sizeof(Si2176_DTV_LIF_FREQ_PROP_OFFSET)/sizeof(Si2176_optionStruct), Si2176_DTV_LIF_FREQ_PROP_OFFSET},
};

Si2176_optionStruct    Si2176_DTV_LIF_OUT_PROP_OFFSET[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",   255}
};
Si2176_optionStruct    Si2176_DTV_LIF_OUT_PROP_AMP[] =
{
  {"MIN_RANGE",     0},
  {"MAX_RANGE",   255}
};
Si2176_fieldDicoStruct Si2176_DTV_LIF_OUT_PROP_FIELDS[] =
{
  {"OFFSET", Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_lif_out.offset, sizeof(Si2176_DTV_LIF_OUT_PROP_OFFSET)/sizeof(Si2176_optionStruct), Si2176_DTV_LIF_OUT_PROP_OFFSET},
  {"AMP",    Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_lif_out.amp   , sizeof(Si2176_DTV_LIF_OUT_PROP_AMP   )/sizeof(Si2176_optionStruct), Si2176_DTV_LIF_OUT_PROP_AMP   },
};

Si2176_optionStruct    Si2176_DTV_MODE_PROP_BW[] =
{
  {"BW_6MHZ",     6},
  {"BW_7MHZ",     7},
  {"BW_8MHZ",     8},
};
Si2176_optionStruct    Si2176_DTV_MODE_PROP_MODULATION[] =
{
  {"ATSC",       0},
  {"QAM_US",     1},
  {"DVBT",       2},
  {"DVBC",       3},
  {"ISDBT",      4},
  {"ISDBC",      5},
  {"DTMB",       6},
  {"CW",        15},
};
Si2176_optionStruct    Si2176_DTV_MODE_PROP_INVERT_SPECTRUM[] =
{
  {"NORMAL",       0},
  {"INVERTED",     1},
};
Si2176_fieldDicoStruct Si2176_DTV_MODE_PROP_FIELDS[] =
{
  {"BW",              Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_mode.bw             , sizeof(Si2176_DTV_MODE_PROP_BW             )/sizeof(Si2176_optionStruct), Si2176_DTV_MODE_PROP_BW             },
  {"MODULATION",      Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_mode.modulation     , sizeof(Si2176_DTV_MODE_PROP_MODULATION     )/sizeof(Si2176_optionStruct), Si2176_DTV_MODE_PROP_MODULATION     },
  {"INVERT_SPECTRUM", Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_mode.invert_spectrum, sizeof(Si2176_DTV_MODE_PROP_INVERT_SPECTRUM)/sizeof(Si2176_optionStruct), Si2176_DTV_MODE_PROP_INVERT_SPECTRUM},
};

Si2176_optionStruct    Si2176_DTV_RF_TOP_PROP_DTV_RF_TOP[] =
{
  {"AUTO",      0},
  {"0DB",       6},
  {"M1DB",      7},
  {"M2DB",      8},
  {"M3DB",      9},
  {"M4DB",     10},
  {"M5DB",     11},
  {"M6DB",     12},
  {"M7DB",     13},
  {"M8DB",     14},
  {"M9DB",     15},
  {"M10DB",    16},
  {"M11DB",    17},
  {"M12DB",    18},
};
Si2176_fieldDicoStruct Si2176_DTV_RF_TOP_PROP_FIELDS[] =
{
  {"DTV_RF_TOP", Si2176_UNSIGNED_CHAR, &Si2176_prop.dtv_rf_top.dtv_rf_top, sizeof(Si2176_DTV_RF_TOP_PROP_DTV_RF_TOP)/sizeof(Si2176_optionStruct), Si2176_DTV_RF_TOP_PROP_DTV_RF_TOP},
};

Si2176_optionStruct    Si2176_DTV_RSQ_RSSI_THRESHOLD_PROP_LO[] =
{
  {"MIN_RANGE",  -128},
  {"MAX_RANGE",   127}
};
Si2176_optionStruct    Si2176_DTV_RSQ_RSSI_THRESHOLD_PROP_HI[] =
{
  {"MIN_RANGE",  -128},
  {"MAX_RANGE",   127}
};
Si2176_fieldDicoStruct Si2176_DTV_RSQ_RSSI_THRESHOLD_PROP_FIELDS[] =
{
  {"LO",   Si2176_SIGNED_CHAR, &Si2176_prop.dtv_rsq_rssi_threshold.lo, sizeof(Si2176_DTV_RSQ_RSSI_THRESHOLD_PROP_LO)/sizeof(Si2176_optionStruct), Si2176_DTV_RSQ_RSSI_THRESHOLD_PROP_LO},
  {"HI",   Si2176_SIGNED_CHAR, &Si2176_prop.dtv_rsq_rssi_threshold.hi, sizeof(Si2176_DTV_RSQ_RSSI_THRESHOLD_PROP_HI)/sizeof(Si2176_optionStruct), Si2176_DTV_RSQ_RSSI_THRESHOLD_PROP_HI},
};

Si2176_optionStruct    Si2176_MASTER_IEN_PROP_TUNIEN[] =
{
  {"OFF",     0},
  {"ON",      1},
};
Si2176_optionStruct    Si2176_MASTER_IEN_PROP_ATVIEN[] =
{
  {"OFF",     0},
  {"ON",      1},
};
Si2176_optionStruct    Si2176_MASTER_IEN_PROP_DTVIEN[] =
{
  {"OFF",     0},
  {"ON",      1},
};
Si2176_optionStruct    Si2176_MASTER_IEN_PROP_ERRIEN[] =
{
  {"OFF",     0},
  {"ON",      1},
};
Si2176_optionStruct    Si2176_MASTER_IEN_PROP_CTSIEN[] =
{
  {"OFF",     0},
  {"ON",      1},
};
Si2176_fieldDicoStruct Si2176_MASTER_IEN_PROP_FIELDS[] =
{
  {"TUNIEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.master_ien.tunien, sizeof(Si2176_MASTER_IEN_PROP_TUNIEN)/sizeof(Si2176_optionStruct), Si2176_MASTER_IEN_PROP_TUNIEN},
  {"ATVIEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.master_ien.atvien, sizeof(Si2176_MASTER_IEN_PROP_ATVIEN)/sizeof(Si2176_optionStruct), Si2176_MASTER_IEN_PROP_ATVIEN},
  {"DTVIEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.master_ien.dtvien, sizeof(Si2176_MASTER_IEN_PROP_DTVIEN)/sizeof(Si2176_optionStruct), Si2176_MASTER_IEN_PROP_DTVIEN},
  {"ERRIEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.master_ien.errien, sizeof(Si2176_MASTER_IEN_PROP_ERRIEN)/sizeof(Si2176_optionStruct), Si2176_MASTER_IEN_PROP_ERRIEN},
  {"CTSIEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.master_ien.ctsien, sizeof(Si2176_MASTER_IEN_PROP_CTSIEN)/sizeof(Si2176_optionStruct), Si2176_MASTER_IEN_PROP_CTSIEN},
};

Si2176_optionStruct    Si2176_TUNER_BLOCKED_VCO_PROP_VCO_CODE[] =
{
  {"MIN_RANGE", -32768},
  {"MAX_RANGE", 32767}
};
Si2176_fieldDicoStruct Si2176_TUNER_BLOCKED_VCO_PROP_FIELDS[] =
{
  {"VCO_CODE",   Si2176_SIGNED_INT, &Si2176_prop.tuner_blocked_vco.vco_code, sizeof(Si2176_TUNER_BLOCKED_VCO_PROP_VCO_CODE)/sizeof(Si2176_optionStruct), Si2176_TUNER_BLOCKED_VCO_PROP_VCO_CODE},
};

Si2176_optionStruct    Si2176_TUNER_IEN_PROP_TCIEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_TUNER_IEN_PROP_RSSILIEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_TUNER_IEN_PROP_RSSIHIEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_fieldDicoStruct Si2176_TUNER_IEN_PROP_FIELDS[] =
{
  {"TCIEN",    Si2176_UNSIGNED_CHAR, &Si2176_prop.tuner_ien.tcien   , sizeof(Si2176_TUNER_IEN_PROP_TCIEN   )/sizeof(Si2176_optionStruct), Si2176_TUNER_IEN_PROP_TCIEN   },
  {"RSSILIEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.tuner_ien.rssilien, sizeof(Si2176_TUNER_IEN_PROP_RSSILIEN)/sizeof(Si2176_optionStruct), Si2176_TUNER_IEN_PROP_RSSILIEN},
  {"RSSIHIEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.tuner_ien.rssihien, sizeof(Si2176_TUNER_IEN_PROP_RSSIHIEN)/sizeof(Si2176_optionStruct), Si2176_TUNER_IEN_PROP_RSSIHIEN},
};

Si2176_optionStruct    Si2176_TUNER_INT_SENSE_PROP_TCNEGEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_TUNER_INT_SENSE_PROP_RSSILNEGEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_TUNER_INT_SENSE_PROP_RSSIHNEGEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_TUNER_INT_SENSE_PROP_TCPOSEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_TUNER_INT_SENSE_PROP_RSSILPOSEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_optionStruct    Si2176_TUNER_INT_SENSE_PROP_RSSIHPOSEN[] =
{
  {"DISABLE",     0},
  {"ENABLE",      1},
};
Si2176_fieldDicoStruct Si2176_TUNER_INT_SENSE_PROP_FIELDS[] =
{
  {"TCNEGEN",    Si2176_UNSIGNED_CHAR, &Si2176_prop.tuner_int_sense.tcnegen   , sizeof(Si2176_TUNER_INT_SENSE_PROP_TCNEGEN   )/sizeof(Si2176_optionStruct), Si2176_TUNER_INT_SENSE_PROP_TCNEGEN   },
  {"RSSILNEGEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.tuner_int_sense.rssilnegen, sizeof(Si2176_TUNER_INT_SENSE_PROP_RSSILNEGEN)/sizeof(Si2176_optionStruct), Si2176_TUNER_INT_SENSE_PROP_RSSILNEGEN},
  {"RSSIHNEGEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.tuner_int_sense.rssihnegen, sizeof(Si2176_TUNER_INT_SENSE_PROP_RSSIHNEGEN)/sizeof(Si2176_optionStruct), Si2176_TUNER_INT_SENSE_PROP_RSSIHNEGEN},
  {"TCPOSEN",    Si2176_UNSIGNED_CHAR, &Si2176_prop.tuner_int_sense.tcposen   , sizeof(Si2176_TUNER_INT_SENSE_PROP_TCPOSEN   )/sizeof(Si2176_optionStruct), Si2176_TUNER_INT_SENSE_PROP_TCPOSEN   },
  {"RSSILPOSEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.tuner_int_sense.rssilposen, sizeof(Si2176_TUNER_INT_SENSE_PROP_RSSILPOSEN)/sizeof(Si2176_optionStruct), Si2176_TUNER_INT_SENSE_PROP_RSSILPOSEN},
  {"RSSIHPOSEN", Si2176_UNSIGNED_CHAR, &Si2176_prop.tuner_int_sense.rssihposen, sizeof(Si2176_TUNER_INT_SENSE_PROP_RSSIHPOSEN)/sizeof(Si2176_optionStruct), Si2176_TUNER_INT_SENSE_PROP_RSSIHPOSEN},
};

Si2176_optionStruct    Si2176_TUNER_LO_INJECTION_PROP_BAND_1[] =
{
  {"LOW_SIDE",      0},
  {"HIGH_SIDE",     1},
};
Si2176_optionStruct    Si2176_TUNER_LO_INJECTION_PROP_BAND_2[] =
{
  {"LOW_SIDE",      0},
  {"HIGH_SIDE",     1},
};
Si2176_optionStruct    Si2176_TUNER_LO_INJECTION_PROP_BAND_3[] =
{
  {"LOW_SIDE",      0},
  {"HIGH_SIDE",     1},
};
Si2176_optionStruct    Si2176_TUNER_LO_INJECTION_PROP_BAND_4[] =
{
  {"LOW_SIDE",      0},
  {"HIGH_SIDE",     1},
};
Si2176_optionStruct    Si2176_TUNER_LO_INJECTION_PROP_BAND_5[] =
{
  {"LOW_SIDE",      0},
  {"HIGH_SIDE",     1},
};
Si2176_fieldDicoStruct Si2176_TUNER_LO_INJECTION_PROP_FIELDS[] =
{
  {"BAND_1", Si2176_UNSIGNED_CHAR, &Si2176_prop.tuner_lo_injection.band_1, sizeof(Si2176_TUNER_LO_INJECTION_PROP_BAND_1)/sizeof(Si2176_optionStruct), Si2176_TUNER_LO_INJECTION_PROP_BAND_1},
  {"BAND_2", Si2176_UNSIGNED_CHAR, &Si2176_prop.tuner_lo_injection.band_2, sizeof(Si2176_TUNER_LO_INJECTION_PROP_BAND_2)/sizeof(Si2176_optionStruct), Si2176_TUNER_LO_INJECTION_PROP_BAND_2},
  {"BAND_3", Si2176_UNSIGNED_CHAR, &Si2176_prop.tuner_lo_injection.band_3, sizeof(Si2176_TUNER_LO_INJECTION_PROP_BAND_3)/sizeof(Si2176_optionStruct), Si2176_TUNER_LO_INJECTION_PROP_BAND_3},
  {"BAND_4", Si2176_UNSIGNED_CHAR, &Si2176_prop.tuner_lo_injection.band_4, sizeof(Si2176_TUNER_LO_INJECTION_PROP_BAND_4)/sizeof(Si2176_optionStruct), Si2176_TUNER_LO_INJECTION_PROP_BAND_4},
  {"BAND_5", Si2176_UNSIGNED_CHAR, &Si2176_prop.tuner_lo_injection.band_5, sizeof(Si2176_TUNER_LO_INJECTION_PROP_BAND_5)/sizeof(Si2176_optionStruct), Si2176_TUNER_LO_INJECTION_PROP_BAND_5},
};

Si2176_propertyInfoStruct Si2176_propertyDictionary[] =
{
  {Si2176_ATV   , "ATV_AFC_RANGE"               , sizeof(Si2176_ATV_AFC_RANGE_PROP_FIELDS               )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_AFC_RANGE_PROP_FIELDS                , Si2176_ATV_AFC_RANGE_PROP                },
  {Si2176_ATV   , "ATV_AF_OUT"                  , sizeof(Si2176_ATV_AF_OUT_PROP_FIELDS                  )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_AF_OUT_PROP_FIELDS                   , Si2176_ATV_AF_OUT_PROP                   },
  {Si2176_ATV   , "ATV_AGC_SPEED"               , sizeof(Si2176_ATV_AGC_SPEED_PROP_FIELDS               )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_AGC_SPEED_PROP_FIELDS                , Si2176_ATV_AGC_SPEED_PROP                },
  {Si2176_ATV   , "ATV_AUDIO_MODE"              , sizeof(Si2176_ATV_AUDIO_MODE_PROP_FIELDS              )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_AUDIO_MODE_PROP_FIELDS               , Si2176_ATV_AUDIO_MODE_PROP               },
  {Si2176_ATV   , "ATV_CVBS_OUT"                , sizeof(Si2176_ATV_CVBS_OUT_PROP_FIELDS                )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_CVBS_OUT_PROP_FIELDS                 , Si2176_ATV_CVBS_OUT_PROP                 },
  {Si2176_ATV   , "ATV_CVBS_OUT_FINE"           , sizeof(Si2176_ATV_CVBS_OUT_FINE_PROP_FIELDS           )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_CVBS_OUT_FINE_PROP_FIELDS            , Si2176_ATV_CVBS_OUT_FINE_PROP            },
  {Si2176_ATV   , "ATV_IEN"                     , sizeof(Si2176_ATV_IEN_PROP_FIELDS                     )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_IEN_PROP_FIELDS                      , Si2176_ATV_IEN_PROP                      },
  {Si2176_ATV   , "ATV_INT_SENSE"               , sizeof(Si2176_ATV_INT_SENSE_PROP_FIELDS               )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_INT_SENSE_PROP_FIELDS                , Si2176_ATV_INT_SENSE_PROP                },
  {Si2176_ATV   , "ATV_RF_TOP"                  , sizeof(Si2176_ATV_RF_TOP_PROP_FIELDS                  )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_RF_TOP_PROP_FIELDS                   , Si2176_ATV_RF_TOP_PROP                   },
  {Si2176_ATV   , "ATV_RSQ_RSSI_THRESHOLD"      , sizeof(Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP_FIELDS      )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP_FIELDS       , Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP       },
  {Si2176_ATV   , "ATV_RSQ_SNR_THRESHOLD"       , sizeof(Si2176_ATV_RSQ_SNR_THRESHOLD_PROP_FIELDS       )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_RSQ_SNR_THRESHOLD_PROP_FIELDS        , Si2176_ATV_RSQ_SNR_THRESHOLD_PROP        },
  {Si2176_ATV   , "ATV_SIF_OUT"                 , sizeof(Si2176_ATV_SIF_OUT_PROP_FIELDS                 )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_SIF_OUT_PROP_FIELDS                  , Si2176_ATV_SIF_OUT_PROP                  },
  {Si2176_ATV   , "ATV_SOUND_AGC_LIMIT"         , sizeof(Si2176_ATV_SOUND_AGC_LIMIT_PROP_FIELDS         )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_SOUND_AGC_LIMIT_PROP_FIELDS          , Si2176_ATV_SOUND_AGC_LIMIT_PROP          },
  {Si2176_ATV   , "ATV_SOUND_AGC_SPEED"         , sizeof(Si2176_ATV_SOUND_AGC_SPEED_PROP_FIELDS         )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_SOUND_AGC_SPEED_PROP_FIELDS          , Si2176_ATV_SOUND_AGC_SPEED_PROP          },
  {Si2176_ATV   , "ATV_VIDEO_EQUALIZER"         , sizeof(Si2176_ATV_VIDEO_EQUALIZER_PROP_FIELDS         )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_VIDEO_EQUALIZER_PROP_FIELDS          , Si2176_ATV_VIDEO_EQUALIZER_PROP          },
  {Si2176_ATV   , "ATV_VIDEO_MODE"              , sizeof(Si2176_ATV_VIDEO_MODE_PROP_FIELDS              )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_VIDEO_MODE_PROP_FIELDS               , Si2176_ATV_VIDEO_MODE_PROP               },
  {Si2176_ATV   , "ATV_VSNR_CAP"                , sizeof(Si2176_ATV_VSNR_CAP_PROP_FIELDS                )/sizeof(Si2176_fieldDicoStruct), Si2176_ATV_VSNR_CAP_PROP_FIELDS                 , Si2176_ATV_VSNR_CAP_PROP                 },
  {Si2176_COMMON, "CRYSTAL_TRIM"                , sizeof(Si2176_CRYSTAL_TRIM_PROP_FIELDS                )/sizeof(Si2176_fieldDicoStruct), Si2176_CRYSTAL_TRIM_PROP_FIELDS                 , Si2176_CRYSTAL_TRIM_PROP                 },
  {Si2176_COMMON, "MASTER_IEN"                  , sizeof(Si2176_MASTER_IEN_PROP_FIELDS                  )/sizeof(Si2176_fieldDicoStruct), Si2176_MASTER_IEN_PROP_FIELDS                   , Si2176_MASTER_IEN_PROP                   },
  {Si2176_DTV   , "DTV_AGC_FREEZE_INPUT"        , sizeof(Si2176_DTV_AGC_FREEZE_INPUT_PROP_FIELDS        )/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_AGC_FREEZE_INPUT_PROP_FIELDS         , Si2176_DTV_AGC_FREEZE_INPUT_PROP         },
  {Si2176_DTV   , "DTV_AGC_SPEED"               , sizeof(Si2176_DTV_AGC_SPEED_PROP_FIELDS               )/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_AGC_SPEED_PROP_FIELDS                , Si2176_DTV_AGC_SPEED_PROP                },
  {Si2176_DTV   , "DTV_CONFIG_IF_PORT"          , sizeof(Si2176_DTV_CONFIG_IF_PORT_PROP_FIELDS          )/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_CONFIG_IF_PORT_PROP_FIELDS           , Si2176_DTV_CONFIG_IF_PORT_PROP           },
  {Si2176_DTV   , "DTV_EXT_AGC"                 , sizeof(Si2176_DTV_EXT_AGC_PROP_FIELDS                 )/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_EXT_AGC_PROP_FIELDS                  , Si2176_DTV_EXT_AGC_PROP                  },
  {Si2176_DTV   , "DTV_FILTER_SELECT"           , sizeof(Si2176_DTV_FILTER_SELECT_PROP_FIELDS           )/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_FILTER_SELECT_PROP_FIELDS            , Si2176_DTV_FILTER_SELECT_PROP            },
  {Si2176_DTV   , "DTV_IEN"                     , sizeof(Si2176_DTV_IEN_PROP_FIELDS                     )/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_IEN_PROP_FIELDS                      , Si2176_DTV_IEN_PROP                      },
  {Si2176_DTV   , "DTV_INITIAL_AGC_SPEED"       , sizeof(Si2176_DTV_INITIAL_AGC_SPEED_PROP_FIELDS       )/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_INITIAL_AGC_SPEED_PROP_FIELDS        , Si2176_DTV_INITIAL_AGC_SPEED_PROP        },
  {Si2176_DTV   , "DTV_INITIAL_AGC_SPEED_PERIOD", sizeof(Si2176_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_FIELDS)/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_FIELDS , Si2176_DTV_INITIAL_AGC_SPEED_PERIOD_PROP },
  {Si2176_DTV   , "DTV_INTERNAL_ZIF"            , sizeof(Si2176_DTV_INTERNAL_ZIF_PROP_FIELDS            )/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_INTERNAL_ZIF_PROP_FIELDS             , Si2176_DTV_INTERNAL_ZIF_PROP             },
  {Si2176_DTV   , "DTV_INT_SENSE"               , sizeof(Si2176_DTV_INT_SENSE_PROP_FIELDS               )/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_INT_SENSE_PROP_FIELDS                , Si2176_DTV_INT_SENSE_PROP                },
  {Si2176_DTV   , "DTV_LIF_FREQ"                , sizeof(Si2176_DTV_LIF_FREQ_PROP_FIELDS                )/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_LIF_FREQ_PROP_FIELDS                 , Si2176_DTV_LIF_FREQ_PROP                 },
  {Si2176_DTV   , "DTV_LIF_OUT"                 , sizeof(Si2176_DTV_LIF_OUT_PROP_FIELDS                 )/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_LIF_OUT_PROP_FIELDS                  , Si2176_DTV_LIF_OUT_PROP                  },
  {Si2176_DTV   , "DTV_MODE"                    , sizeof(Si2176_DTV_MODE_PROP_FIELDS                    )/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_MODE_PROP_FIELDS                     , Si2176_DTV_MODE_PROP                     },
  {Si2176_DTV   , "DTV_RF_TOP"                  , sizeof(Si2176_DTV_RF_TOP_PROP_FIELDS                  )/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_RF_TOP_PROP_FIELDS                   , Si2176_DTV_RF_TOP_PROP                   },
  {Si2176_DTV   , "DTV_RSQ_RSSI_THRESHOLD"      , sizeof(Si2176_DTV_RSQ_RSSI_THRESHOLD_PROP_FIELDS      )/sizeof(Si2176_fieldDicoStruct), Si2176_DTV_RSQ_RSSI_THRESHOLD_PROP_FIELDS       , Si2176_DTV_RSQ_RSSI_THRESHOLD_PROP       },
  {Si2176_TUNER , "TUNER_BLOCKED_VCO"           , sizeof(Si2176_TUNER_BLOCKED_VCO_PROP_FIELDS           )/sizeof(Si2176_fieldDicoStruct), Si2176_TUNER_BLOCKED_VCO_PROP_FIELDS            , Si2176_TUNER_BLOCKED_VCO_PROP            },
  {Si2176_TUNER , "TUNER_IEN"                   , sizeof(Si2176_TUNER_IEN_PROP_FIELDS                   )/sizeof(Si2176_fieldDicoStruct), Si2176_TUNER_IEN_PROP_FIELDS                    , Si2176_TUNER_IEN_PROP                    },
  {Si2176_TUNER , "TUNER_INT_SENSE"             , sizeof(Si2176_TUNER_INT_SENSE_PROP_FIELDS             )/sizeof(Si2176_fieldDicoStruct), Si2176_TUNER_INT_SENSE_PROP_FIELDS              , Si2176_TUNER_INT_SENSE_PROP              },
  {Si2176_TUNER , "TUNER_LO_INJECTION"          , sizeof(Si2176_TUNER_LO_INJECTION_PROP_FIELDS          )/sizeof(Si2176_fieldDicoStruct), Si2176_TUNER_LO_INJECTION_PROP_FIELDS           , Si2176_TUNER_LO_INJECTION_PROP           },
};
/* _properties_strings_insertion_point */

int   Si2176_PropertyNames        (L1_Si2176_Context *api, char *msg)
{
  int propIndex;
  int size;
  api = api; /* to avoid 'unused parameter' warning */
  size = sizeof(Si2176_propertyDictionary)/sizeof(Si2176_propertyInfoStruct);
  msg[0]='\0';
  for (propIndex=0; propIndex<size; propIndex++)
  {
    strcat(msg,Si2176_propertyDictionary[propIndex].name);
    if (propIndex< (size-1)) strcat(msg," ");
  }
  return propIndex;
};

int   Si2176_PropertyIndex        (L1_Si2176_Context *api, char *property)
{
  int propIndex;
  int size;
  api = api; /* to avoid 'unused parameter' warning */
  size = sizeof(Si2176_propertyDictionary)/sizeof(Si2176_propertyInfoStruct);
  for (propIndex=0; propIndex <size; propIndex++)
  {
    if (strcmp_nocase(property, Si2176_propertyDictionary[propIndex].name)==0)
    {
      return propIndex;
    }
  }
  return -1;
};

int   Si2176_PropertyFields       (L1_Si2176_Context *api, int propIndex, char *msg)
{
  int fieldIndex;
  api = api; /* to avoid 'unused parameter' warning */
  msg[0]='\0';
  for (fieldIndex=0; fieldIndex < Si2176_propertyDictionary[propIndex].nbFields; fieldIndex++)
  {
    strcat(msg, Si2176_propertyDictionary[propIndex].field[fieldIndex].name);
    if (fieldIndex< (Si2176_propertyDictionary[propIndex].nbFields-1)) strcat(msg," ");
  }
  return -1;
};

int   Si2176_PropertyFieldIndex   (L1_Si2176_Context *api, int propIndex, char *field)
{
  int fieldIndex;
  api = api; /* to avoid 'unused parameter' warning */
  for (fieldIndex=0; fieldIndex < Si2176_propertyDictionary[propIndex].nbFields; fieldIndex++)
  {
    if (strcmp_nocase(field, Si2176_propertyDictionary[propIndex].field[fieldIndex].name)==0)
    {
      return fieldIndex;
    }
  }
  return -1;
};

int   Si2176_PropertyFieldEnums   (L1_Si2176_Context *api, int propIndex, int fieldIndex, char *msg)
{
  int enumIndex;
  api = api; /* to avoid 'unused parameter' warning */
  msg[0]='\0';
  for (enumIndex=0; enumIndex < Si2176_propertyDictionary[propIndex].field[fieldIndex].nbOptions; enumIndex++)
  {
    strcat(msg, Si2176_propertyDictionary[propIndex].field[fieldIndex].option[enumIndex].name);
    if (enumIndex < (Si2176_propertyDictionary[propIndex].field[fieldIndex].nbOptions-1)) strcat(msg," ");
  }
  return enumIndex;
};

int   Si2176_PropertyFieldRanges  (L1_Si2176_Context *api, int propIndex, int fieldIndex, char *msg)
{
  int index;
  char buf[10];
  api = api; /* to avoid 'unused parameter' warning */
  msg[0]='\0';
  for (index=0; index < 2; index++)
  {
    itoa(Si2176_propertyDictionary[propIndex].field[fieldIndex].option[index].value,buf,10);
    strcat(msg, buf);
    if (index < 1) strcat(msg," - ");
  }
  return index;
};

int   Si2176_GetValueFromEntry    (L1_Si2176_Context *api, Si2176_fieldDicoStruct field, char *entry, int *value)
{
  int optionIndex;
  api = api; /* to avoid 'unused parameter' warning */

  if (!strcmp_nocase(field.option[0].name,"MIN_RANGE"))
  {
    if (field.datatype== Si2176_UNSIGNED_INT || field.datatype== Si2176_UNSIGNED_CHAR)
    {
      *value = (unsigned int)atoi(entry);
      return 1;
    }
    else if (field.datatype == Si2176_SIGNED_INT || field.datatype == Si2176_SIGNED_CHAR)
    {
      *value = (int)atoi(entry);
      return 1;
    }
  }
  for (optionIndex=0; optionIndex < field.nbOptions; optionIndex++)
  {
    if (strcmp_nocase(entry, field.option[optionIndex].name     )==0)
    {
      *value = field.option[optionIndex].value;
      return 1;
    }
  }
  return 0;
};

char *Si2176_GetEnumFromValue     (L1_Si2176_Context *api, Si2176_fieldDicoStruct field, int iValue)
{
  int optionIndex;
  api = api; /* to avoid 'unused parameter' warning */
  if (field.nbOptions ==0 )
    {
    sprintf(optionText, "%d", iValue);
    return optionText;
  }
  for (optionIndex=0; optionIndex < field.nbOptions; optionIndex++)
  {
    if (iValue == field.option[optionIndex].value)
    {
      return field.option[optionIndex].name;
    }
  }
  return (char*)NULL;
};

int   Si2176_GetValueFromField    (L1_Si2176_Context *api, Si2176_fieldDicoStruct field)
{
  short intValue;
  short *fieldAsInt;
  short iTmp=0;
  fieldAsInt = &intValue;

  if (field.datatype == Si2176_SIGNED_INT   )
  {
      fieldAsInt= (short *) ((field.pField-(void *) &Si2176_prop)+ (void *)api->prop);
  }
  else if (field.datatype == Si2176_UNSIGNED_CHAR)
  {
      iTmp = *((unsigned char *) ((field.pField-(void *) &Si2176_prop)+ (void *)api->prop));
      fieldAsInt = &iTmp;
  }
  else if (field.datatype == Si2176_SIGNED_CHAR)
  {
      iTmp= *((char *) ((field.pField-(void *) &Si2176_prop)+ (void *)api->prop));
      fieldAsInt = &iTmp;
  }
  else /* if (field.datatype == Si2176_UNSIGNED_INT) */
  {
      fieldAsInt = (unsigned short *) ((field.pField-(void *) &Si2176_prop)+ (void *)api->prop);
  }

  return  *fieldAsInt;
};

char *Si2176_GetEnumFromField     (L1_Si2176_Context *api, Si2176_fieldDicoStruct field)
{
  int intValue;
  int *fieldAsInt;
  int iTmp=0;
  fieldAsInt = &intValue;

  if (field.datatype == Si2176_SIGNED_INT   )
  {
      fieldAsInt= (int *) ((field.pField-(void *) &Si2176_prop) + (void *)api->prop);
  }
  else if (field.datatype == Si2176_UNSIGNED_CHAR)
  {
      iTmp = *((unsigned char *) ((field.pField-(void *) &Si2176_prop) + (void *)api->prop));
      fieldAsInt = &iTmp;
  }
  else if (field.datatype == Si2176_SIGNED_CHAR)
  {
      iTmp= *((char *) ((field.pField-(void *) &Si2176_prop) + (void *)api->prop));
      fieldAsInt = &iTmp;
  }
  else /* if (field.datatype == Si2176_UNSIGNED_INT) */
  {
      fieldAsInt = (unsigned int *)((field.pField-(void *) &Si2176_prop) + (void *)api->prop);
  }

  return Si2176_GetEnumFromValue(api, field, *fieldAsInt);
};

int   Si2176_SetFieldFromEntry    (L1_Si2176_Context *api, Si2176_fieldDicoStruct field, char *entry)
{
  int *fieldAsInt;
  int iTmp=0;
  fieldAsInt = &iTmp;
  if (Si2176_GetValueFromEntry(api, field, entry, fieldAsInt) == 0) return 0;
  if (field.datatype == Si2176_SIGNED_INT )
  {
    *( (int *) ((field.pField-(void *) &Si2176_prop) + (void *)api->prop))=iTmp;
  }
  else if (field.datatype == Si2176_UNSIGNED_CHAR)
  {
    *( (unsigned char *) ((field.pField-(void *) &Si2176_prop) + (void *)api->prop))=iTmp;
  }
  else if (field.datatype == Si2176_SIGNED_CHAR)
  {
    *( (char *) ((field.pField-(void *) &Si2176_prop) + (void *)api->prop))=iTmp;
  }
  else /* if (field.datatype == Si2176_UNSIGNED_INT) */
  {
    *( (unsigned int *) ((field.pField-(void *) &Si2176_prop) + (void *)api->prop))=iTmp;
  }

  return 1;
};

void  Si2176_showProperty         (L1_Si2176_Context *api, int propIndex)
{
  int fieldIndex;
  for (fieldIndex=0; fieldIndex<Si2176_propertyDictionary[propIndex].nbFields; fieldIndex++)
  {
    printf("%s:%s:%s = ", Si2176_featureText[Si2176_propertyDictionary[propIndex].feature], Si2176_propertyDictionary[propIndex].name, Si2176_propertyDictionary[propIndex].field[fieldIndex].name);
    printf("<%s>\n", Si2176_GetEnumFromField(api, Si2176_propertyDictionary[propIndex].field[fieldIndex]));
  }

}

void  Si2176_showPropertyNamed    (L1_Si2176_Context *api, char *property)
{
  int propIndex;

  if ((propIndex = Si2176_PropertyIndex(api, property)) >= 0)
  {
    Si2176_showProperty(api, propIndex);
  }
  else
  {
    printf("Unknown property '%s'\n", property);
  }

}

int   Si2176_showProperties       (L1_Si2176_Context *api, Si2176_featureEnum feature)
{
  int propertyIndex;
  int dictSize;

  dictSize=sizeof(Si2176_propertyDictionary)/sizeof(Si2176_propertyInfoStruct);

  printf("\n%s current properties:\n\n", Si2176_featureText[feature]);

  for (propertyIndex=0; propertyIndex<dictSize; propertyIndex++)
  {
    if (Si2176_propertyDictionary[propertyIndex].feature != feature) continue;
    Si2176_showProperty(api, propertyIndex);
  }
  return 0;
}

void  Si2176_setupProperty        (L1_Si2176_Context *api, int propIndex)
{
  #define LMAX 20
  char entry[LMAX];
  char setup_msg[1000];
  int fieldIndex;
  char isRangeType = 1;

  for (fieldIndex=0; fieldIndex<Si2176_propertyDictionary[propIndex].nbFields; fieldIndex++)
  {
    isRangeType = (strcmp_nocase(Si2176_propertyDictionary[propIndex].field[fieldIndex].option->name,"MIN_RANGE") == 0);

    printf("%s:%s:%s = ", Si2176_featureText[Si2176_propertyDictionary[propIndex].feature], Si2176_propertyDictionary[propIndex].name, Si2176_propertyDictionary[propIndex].field[fieldIndex].name);

    if ( isRangeType )
    {
      printf("<%d>\n", Si2176_GetValueFromField(api, Si2176_propertyDictionary[propIndex].field[fieldIndex]));
      Si2176_PropertyFieldRanges(api, propIndex, fieldIndex, setup_msg);
      printf("Range: <%s>  ",setup_msg);
    }
    else
    {
      Si2176_PropertyFieldEnums(api, propIndex, fieldIndex, setup_msg);
      printf("<%s>\n Options: <%s>\n", Si2176_GetEnumFromField(api, Si2176_propertyDictionary[propIndex].field[fieldIndex]), setup_msg);
    }

    fgets(entry,LMAX,stdin);

    if (strlen(entry) > 1)
    {
      entry[strlen(entry)-1]='\0';
      if (!Si2176_SetFieldFromEntry(api, Si2176_propertyDictionary[propIndex].field[fieldIndex], entry))
      {
        printf("Invalid entry!\n");
      }
    }

    if (isRangeType)
      printf("<%d>\n\n", Si2176_GetValueFromField(api, Si2176_propertyDictionary[propIndex].field[fieldIndex]));
    else
      printf("<%s>\n\n", Si2176_GetEnumFromField(api, Si2176_propertyDictionary[propIndex].field[fieldIndex]));
  }
}

int   Si2176_setupProperties      (L1_Si2176_Context *api, Si2176_featureEnum feature)
{
  int propertyIndex;
  int dictSize;

  dictSize=sizeof(Si2176_propertyDictionary)/sizeof(Si2176_propertyInfoStruct);

  printf("\n%s properties:\n\n", Si2176_featureText[feature]);

  for (propertyIndex=0; propertyIndex<dictSize; propertyIndex++)
  {
    if (Si2176_propertyDictionary[propertyIndex].feature != feature) continue;
    Si2176_setupProperty(api, propertyIndex);
  }
  return 0;
}

#endif /* Si2176_COMMAND_LINE_APPLICATION */

/* _property_string_functions_insertion_start */
#ifdef    Si2176_COMMAND_LINE_APPLICATION
int Si2176_showATVProperties       (L1_Si2176_Context *api)
{
  return Si2176_showProperties(api, Si2176_ATV);
};

int Si2176_showCOMMONProperties    (L1_Si2176_Context *api)
{
  return Si2176_showProperties(api, Si2176_COMMON);
};

int Si2176_showDTVProperties       (L1_Si2176_Context *api)
{
  return Si2176_showProperties(api, Si2176_DTV);
};

int Si2176_showTUNERProperties     (L1_Si2176_Context *api)
{
  return Si2176_showProperties(api, Si2176_TUNER);
};

int Si2176_showAllProperties       (L1_Si2176_Context *api)
{
  Si2176_showATVProperties       (api);
  Si2176_showCOMMONProperties    (api);
  Si2176_showDTVProperties       (api);
  Si2176_showTUNERProperties     (api);
  return 0;
};

#endif /* Si2176_COMMAND_LINE_APPLICATION */
void Si2176_setupATVDefaults        (L1_Si2176_Context *api)
{
  SiTRACE("Si2176_setupATVDefaults       \n");
  api->prop->atv_afc_range.range_khz              =  1000; /* (default  1000) */

  api->prop->atv_af_out.volume                    =     0; /* (default     0) */

  api->prop->atv_agc_speed.if_agc_speed           = Si2176_ATV_AGC_SPEED_PROP_IF_AGC_SPEED_AUTO ; /* (default 'AUTO') */

  api->prop->atv_audio_mode.audio_sys             = Si2176_ATV_AUDIO_MODE_PROP_AUDIO_SYS_DEFAULT  ; /* (default 'DEFAULT') */
  api->prop->atv_audio_mode.demod_mode            = Si2176_ATV_AUDIO_MODE_PROP_DEMOD_MODE_SIF     ; /* (default 'SIF') */
  api->prop->atv_audio_mode.chan_bw               = Si2176_ATV_AUDIO_MODE_PROP_CHAN_BW_DEFAULT    ; /* (default 'DEFAULT') */

  api->prop->atv_cvbs_out.offset                  =    25; /* (default    25) */
  api->prop->atv_cvbs_out.amp                     =   200; /* (default   200) */

  api->prop->atv_cvbs_out_fine.offset             =     0; /* (default     0) */
  api->prop->atv_cvbs_out_fine.amp                =   100; /* (default   100) */

  api->prop->atv_ien.chlien                       = Si2176_ATV_IEN_PROP_CHLIEN_ENABLE  ; /* (default 'DISABLE') */
  api->prop->atv_ien.pclien                       = Si2176_ATV_IEN_PROP_PCLIEN_DISABLE  ; /* (default 'DISABLE') */
  api->prop->atv_ien.dlien                        = Si2176_ATV_IEN_PROP_DLIEN_DISABLE   ; /* (default 'DISABLE') */
  api->prop->atv_ien.snrlien                      = Si2176_ATV_IEN_PROP_SNRLIEN_DISABLE ; /* (default 'DISABLE') */
  api->prop->atv_ien.snrhien                      = Si2176_ATV_IEN_PROP_SNRHIEN_DISABLE ; /* (default 'DISABLE') */

  api->prop->atv_int_sense.chlnegen               = Si2176_ATV_INT_SENSE_PROP_CHLNEGEN_DISABLE  ; /* (default 'DISABLE') */
  api->prop->atv_int_sense.pclnegen               = Si2176_ATV_INT_SENSE_PROP_PCLNEGEN_DISABLE  ; /* (default 'DISABLE') */
  api->prop->atv_int_sense.dlnegen                = Si2176_ATV_INT_SENSE_PROP_DLNEGEN_DISABLE   ; /* (default 'DISABLE') */
  api->prop->atv_int_sense.snrlnegen              = Si2176_ATV_INT_SENSE_PROP_SNRLNEGEN_DISABLE ; /* (default 'DISABLE') */
  api->prop->atv_int_sense.snrhnegen              = Si2176_ATV_INT_SENSE_PROP_SNRHNEGEN_DISABLE ; /* (default 'DISABLE') */
  api->prop->atv_int_sense.chlposen               = Si2176_ATV_INT_SENSE_PROP_CHLPOSEN_ENABLE   ; /* (default 'ENABLE') */
  api->prop->atv_int_sense.pclposen               = Si2176_ATV_INT_SENSE_PROP_PCLPOSEN_ENABLE   ; /* (default 'ENABLE') */
  api->prop->atv_int_sense.dlposen                = Si2176_ATV_INT_SENSE_PROP_DLPOSEN_ENABLE    ; /* (default 'ENABLE') */
  api->prop->atv_int_sense.snrlposen              = Si2176_ATV_INT_SENSE_PROP_SNRLPOSEN_ENABLE  ; /* (default 'ENABLE') */
  api->prop->atv_int_sense.snrhposen              = Si2176_ATV_INT_SENSE_PROP_SNRHPOSEN_ENABLE  ; /* (default 'ENABLE') */

  api->prop->atv_rf_top.atv_rf_top                = Si2176_ATV_RF_TOP_PROP_ATV_RF_TOP_AUTO ; /* (default 'AUTO') */

  api->prop->atv_rsq_rssi_threshold.lo            =   -70; /* (default   -70) */
  api->prop->atv_rsq_rssi_threshold.hi            =     0; /* (default     0) */

  api->prop->atv_rsq_snr_threshold.lo             =    25; /* (default    25) */
  api->prop->atv_rsq_snr_threshold.hi             =    45; /* (default    45) */

  api->prop->atv_sif_out.offset                   =   135; /* (default   135) */
  api->prop->atv_sif_out.amp                      =    60; /* (default    60) */

  api->prop->atv_sound_agc_limit.max_gain         =    84; /* (default    84) */
  api->prop->atv_sound_agc_limit.min_gain         =   -84; /* (default   -84) */

  api->prop->atv_sound_agc_speed.system_l         =     5; /* (default     5) */
  api->prop->atv_sound_agc_speed.other_systems    =     4; /* (default     4) */

  api->prop->atv_video_equalizer.slope            =     0; /* (default     0) */

  api->prop->atv_video_mode.video_sys             = Si2176_ATV_VIDEO_MODE_PROP_VIDEO_SYS_B               ; /* (default 'B') */
  api->prop->atv_video_mode.color                 = Si2176_ATV_VIDEO_MODE_PROP_COLOR_PAL_NTSC            ; /* (default 'PAL_NTSC') */
  api->prop->atv_video_mode.trans                 = Si2176_ATV_VIDEO_MODE_PROP_TRANS_TERRESTRIAL         ; /* (default 'TERRESTRIAL') */
  api->prop->atv_video_mode.invert_signal         =     0; /* (default     0) */

  api->prop->atv_vsnr_cap.atv_vsnr_cap            =     0; /* (default     0) */

};

void Si2176_setupCOMMONDefaults     (L1_Si2176_Context *api)
{
  SiTRACE("Si2176_setupCOMMONDefaults    \n");
  api->prop->crystal_trim.xo_cap                  =     8; /* (default     8) */

  api->prop->master_ien.tunien                    = Si2176_MASTER_IEN_PROP_TUNIEN_OFF ; /* (default 'OFF') */
  api->prop->master_ien.atvien                    = Si2176_MASTER_IEN_PROP_ATVIEN_OFF ; /* (default 'OFF') */
  api->prop->master_ien.dtvien                    = Si2176_MASTER_IEN_PROP_DTVIEN_OFF ; /* (default 'OFF') */
  api->prop->master_ien.errien                    = Si2176_MASTER_IEN_PROP_ERRIEN_OFF ; /* (default 'OFF') */
  api->prop->master_ien.ctsien                    = Si2176_MASTER_IEN_PROP_CTSIEN_OFF ; /* (default 'OFF') */

};

void Si2176_setupDTVDefaults        (L1_Si2176_Context *api)
{
  SiTRACE("Si2176_setupDTVDefaults       \n");
  api->prop->dtv_agc_freeze_input.level           = Si2176_DTV_AGC_FREEZE_INPUT_PROP_LEVEL_LOW  ; /* (default 'LOW') */
  api->prop->dtv_agc_freeze_input.pin             = Si2176_DTV_AGC_FREEZE_INPUT_PROP_PIN_NONE   ; /* (default 'NONE') */

  api->prop->dtv_agc_speed.if_agc_speed           = Si2176_DTV_AGC_SPEED_PROP_IF_AGC_SPEED_AUTO ; /* (default 'AUTO') */
  api->prop->dtv_agc_speed.agc_decim              = Si2176_DTV_AGC_SPEED_PROP_AGC_DECIM_OFF     ; /* (default 'OFF') */

  api->prop->dtv_config_if_port.dtv_out_type      = Si2176_DTV_CONFIG_IF_PORT_PROP_DTV_OUT_TYPE_LIF_IF1   ; /* (default 'LIF_IF1') */
  api->prop->dtv_config_if_port.dtv_agc_source    =     0; /* (default     0) */

  api->prop->dtv_ext_agc.min_10mv                 =    50; /* (default    50) */
  api->prop->dtv_ext_agc.max_10mv                 =   200; /* (default   200) */

  api->prop->dtv_filter_select.filter             = Si2176_DTV_FILTER_SELECT_PROP_FILTER_DEFAULT ; /* (default 'DEFAULT') */

  api->prop->dtv_ien.chlien                       = Si2176_DTV_IEN_PROP_CHLIEN_ENABLE ; /* (default 'DISABLE') */

  api->prop->dtv_initial_agc_speed.if_agc_speed   = Si2176_DTV_INITIAL_AGC_SPEED_PROP_IF_AGC_SPEED_AUTO ; /* (default 'AUTO') */
  api->prop->dtv_initial_agc_speed.agc_decim      = Si2176_DTV_INITIAL_AGC_SPEED_PROP_AGC_DECIM_OFF     ; /* (default 'OFF') */

  api->prop->dtv_initial_agc_speed_period.period  =     0; /* (default     0) */

  api->prop->dtv_internal_zif.atsc                = Si2176_DTV_INTERNAL_ZIF_PROP_ATSC_LIF   ; /* (default 'LIF') */
  api->prop->dtv_internal_zif.qam_us              = Si2176_DTV_INTERNAL_ZIF_PROP_QAM_US_LIF ; /* (default 'LIF') */
  api->prop->dtv_internal_zif.dvbt                = Si2176_DTV_INTERNAL_ZIF_PROP_DVBT_LIF   ; /* (default 'LIF') */
  api->prop->dtv_internal_zif.dvbc                = Si2176_DTV_INTERNAL_ZIF_PROP_DVBC_LIF   ; /* (default 'LIF') */
  api->prop->dtv_internal_zif.isdbt               = Si2176_DTV_INTERNAL_ZIF_PROP_ISDBT_LIF  ; /* (default 'LIF') */
  api->prop->dtv_internal_zif.isdbc               = Si2176_DTV_INTERNAL_ZIF_PROP_ISDBC_LIF  ; /* (default 'LIF') */
  api->prop->dtv_internal_zif.dtmb                = Si2176_DTV_INTERNAL_ZIF_PROP_DTMB_LIF   ; /* (default 'LIF') */

  api->prop->dtv_int_sense.chlnegen               = Si2176_DTV_INT_SENSE_PROP_CHLNEGEN_DISABLE ; /* (default 'DISABLE') */
  api->prop->dtv_int_sense.chlposen               = Si2176_DTV_INT_SENSE_PROP_CHLPOSEN_ENABLE  ; /* (default 'ENABLE') */

  api->prop->dtv_lif_freq.offset                  =  5000; /* (default  5000) */

  api->prop->dtv_lif_out.offset                   =   148; /* (default   148) */
  api->prop->dtv_lif_out.amp                      =    27; /* (default    27) */

  api->prop->dtv_mode.bw                          = Si2176_DTV_MODE_PROP_BW_BW_8MHZ              ; /* (default 'BW_8MHZ') */
  api->prop->dtv_mode.modulation                  = Si2176_DTV_MODE_PROP_MODULATION_DVBT         ; /* (default 'DVBT') */
  api->prop->dtv_mode.invert_spectrum             =     0; /* (default     0) */

  api->prop->dtv_rf_top.dtv_rf_top                = Si2176_DTV_RF_TOP_PROP_DTV_RF_TOP_AUTO ; /* (default 'AUTO') */

  api->prop->dtv_rsq_rssi_threshold.lo            =   -80; /* (default   -80) */
  api->prop->dtv_rsq_rssi_threshold.hi            =     0; /* (default     0) */

};

void Si2176_setupTUNERDefaults      (L1_Si2176_Context *api)
{
  SiTRACE("Si2176_setupTUNERDefaults     \n");
  api->prop->tuner_blocked_vco.vco_code           = 0x8000; /* (default 0x8000) */

  api->prop->tuner_ien.tcien                      = Si2176_TUNER_IEN_PROP_TCIEN_ENABLE    ; /* (default 'DISABLE') */
  api->prop->tuner_ien.rssilien                   = Si2176_TUNER_IEN_PROP_RSSILIEN_DISABLE ; /* (default 'DISABLE') */
  api->prop->tuner_ien.rssihien                   = Si2176_TUNER_IEN_PROP_RSSIHIEN_DISABLE ; /* (default 'DISABLE') */

  api->prop->tuner_int_sense.tcnegen              = Si2176_TUNER_INT_SENSE_PROP_TCNEGEN_DISABLE    ; /* (default 'DISABLE') */
  api->prop->tuner_int_sense.rssilnegen           = Si2176_TUNER_INT_SENSE_PROP_RSSILNEGEN_DISABLE ; /* (default 'DISABLE') */
  api->prop->tuner_int_sense.rssihnegen           = Si2176_TUNER_INT_SENSE_PROP_RSSIHNEGEN_DISABLE ; /* (default 'DISABLE') */
  api->prop->tuner_int_sense.tcposen              = Si2176_TUNER_INT_SENSE_PROP_TCPOSEN_ENABLE     ; /* (default 'ENABLE') */
  api->prop->tuner_int_sense.rssilposen           = Si2176_TUNER_INT_SENSE_PROP_RSSILPOSEN_ENABLE  ; /* (default 'ENABLE') */
  api->prop->tuner_int_sense.rssihposen           = Si2176_TUNER_INT_SENSE_PROP_RSSIHPOSEN_ENABLE  ; /* (default 'ENABLE') */

  api->prop->tuner_lo_injection.band_1            = Si2176_TUNER_LO_INJECTION_PROP_BAND_1_HIGH_SIDE ; /* (default 'HIGH_SIDE') */
  api->prop->tuner_lo_injection.band_2            = Si2176_TUNER_LO_INJECTION_PROP_BAND_2_LOW_SIDE  ; /* (default 'LOW_SIDE') */
  api->prop->tuner_lo_injection.band_3            = Si2176_TUNER_LO_INJECTION_PROP_BAND_3_LOW_SIDE  ; /* (default 'LOW_SIDE') */
  api->prop->tuner_lo_injection.band_4            = Si2176_TUNER_LO_INJECTION_PROP_BAND_4_LOW_SIDE  ; /* (default 'LOW_SIDE') */
  api->prop->tuner_lo_injection.band_5            = Si2176_TUNER_LO_INJECTION_PROP_BAND_5_LOW_SIDE  ; /* (default 'LOW_SIDE') */

};

void Si2176_setupAllDefaults       (L1_Si2176_Context *api)
{
  Si2176_setupATVDefaults       (api);
  Si2176_setupCOMMONDefaults    (api);
  Si2176_setupDTVDefaults       (api);
  Si2176_setupTUNERDefaults     (api);
};

int Si2176_setupATVProperties       (L1_Si2176_Context *api)
{
  SiTRACE("Si2176_setupATVProperties       \n");
#ifdef    Si2176_COMMAND_LINE_APPLICATION
  Si2176_setupProperties(api, Si2176_ATV);
#else  /* Si2176_COMMAND_LINE_APPLICATION */
  Si2176_setupATVDefaults(api);
#endif /* Si2176_COMMAND_LINE_APPLICATION */
  return 0;
};

int Si2176_setupCOMMONProperties    (L1_Si2176_Context *api)
{
  SiTRACE("Si2176_setupCOMMONProperties    \n");
#ifdef    Si2176_COMMAND_LINE_APPLICATION
  Si2176_setupProperties(api, Si2176_COMMON);
#else  /* Si2176_COMMAND_LINE_APPLICATION */
  Si2176_setupCOMMONDefaults(api);
#endif /* Si2176_COMMAND_LINE_APPLICATION */
  return 0;
};

int Si2176_setupDTVProperties       (L1_Si2176_Context *api)
{
  SiTRACE("Si2176_setupDTVProperties       \n");
#ifdef    Si2176_COMMAND_LINE_APPLICATION
  Si2176_setupProperties(api, Si2176_DTV);
#else  /* Si2176_COMMAND_LINE_APPLICATION */
  Si2176_setupDTVDefaults(api);
#endif /* Si2176_COMMAND_LINE_APPLICATION */
  return 0;
};

int Si2176_setupTUNERProperties     (L1_Si2176_Context *api)
{
  SiTRACE("Si2176_setupTUNERProperties     \n");
#ifdef    Si2176_COMMAND_LINE_APPLICATION
  Si2176_setupProperties(api, Si2176_TUNER);
#else  /* Si2176_COMMAND_LINE_APPLICATION */
  Si2176_setupTUNERDefaults(api);
#endif /* Si2176_COMMAND_LINE_APPLICATION */
  return 0;
};

int Si2176_setupAllProperties  (L1_Si2176_Context *api)
{
  Si2176_setupATVProperties       (api);
  Si2176_setupCOMMONProperties    (api);
  Si2176_setupDTVProperties       (api);
  Si2176_setupTUNERProperties     (api);
  return 0;
};


 /*****************************************************************************************
 NAME: Si2176_downloadATVProperties
  DESCRIPTION: Setup Si2176 ATV properties configuration
  This function will download all the ATV configuration properties.
  The function SetupATVDefaults() should be called before the first call to this function.
  Parameter:  Pointer to Si2176 Context
  Returns:    I2C transaction error code, NO_Si2176_ERROR if successful
  Programming Guide Reference:    ATV setup flowchart
******************************************************************************************/
int  Si2176_downloadATVProperties(L1_Si2176_Context *api)
{
  SiTRACE("Si2176_downloadATVProperties     \n");
#ifdef    Si2176_ATV_AFC_RANGE_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_AFC_RANGE_PROP_CODE               ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_AFC_RANGE_PROP */
#ifdef    Si2176_ATV_AF_OUT_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_AF_OUT_PROP_CODE                  ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_AF_OUT_PROP */
#ifdef    Si2176_ATV_AGC_SPEED_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_AGC_SPEED_PROP_CODE               ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_AGC_SPEED_PROP */
#ifdef    Si2176_ATV_AUDIO_MODE_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_AUDIO_MODE_PROP_CODE              ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_AUDIO_MODE_PROP */
#ifdef    Si2176_ATV_CVBS_OUT_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_CVBS_OUT_PROP_CODE                ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_CVBS_OUT_PROP */
#ifdef    Si2176_ATV_CVBS_OUT_FINE_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_CVBS_OUT_FINE_PROP_CODE           ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_CVBS_OUT_FINE_PROP */
#ifdef    Si2176_ATV_IEN_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_IEN_PROP_CODE                     ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_IEN_PROP */
#ifdef    Si2176_ATV_INT_SENSE_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_INT_SENSE_PROP_CODE               ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_INT_SENSE_PROP */
#ifdef    Si2176_ATV_RF_TOP_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_RF_TOP_PROP_CODE                  ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_RF_TOP_PROP */
#ifdef    Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP_CODE      ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_RSQ_RSSI_THRESHOLD_PROP */
#ifdef    Si2176_ATV_RSQ_SNR_THRESHOLD_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_RSQ_SNR_THRESHOLD_PROP_CODE       ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_RSQ_SNR_THRESHOLD_PROP */
#ifdef    Si2176_ATV_SIF_OUT_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_SIF_OUT_PROP_CODE                 ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_SIF_OUT_PROP */
#ifdef    Si2176_ATV_SOUND_AGC_LIMIT_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_SOUND_AGC_LIMIT_PROP_CODE         ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_SOUND_AGC_LIMIT_PROP */
#ifdef    Si2176_ATV_SOUND_AGC_SPEED_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_SOUND_AGC_SPEED_PROP_CODE         ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_SOUND_AGC_SPEED_PROP */
#ifdef    Si2176_ATV_VIDEO_EQUALIZER_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_VIDEO_EQUALIZER_PROP_CODE         ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_VIDEO_EQUALIZER_PROP */
#ifdef    Si2176_ATV_VIDEO_MODE_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_VIDEO_MODE_PROP_CODE              ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_VIDEO_MODE_PROP */
#ifdef    Si2176_ATV_VSNR_CAP_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_ATV_VSNR_CAP_PROP_CODE                ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_ATV_VSNR_CAP_PROP */
return NO_Si2176_ERROR;
};

 /*****************************************************************************************
 NAME: Si2176_downloadCOMMONProperties
  DESCRIPTION: Setup Si2176 COMMON properties configuration
  This function will download all the COMMON configuration properties.
  The function SetupCOMMONDefaults() should be called before the first call to this function.
  Parameter:  Pointer to Si2176 Context
  Returns:    I2C transaction error code, NO_Si2176_ERROR if successful
  Programming Guide Reference:    COMMON setup flowchart
******************************************************************************************/
int  Si2176_downloadCOMMONProperties(L1_Si2176_Context *api)
{
  SiTRACE("Si2176_downloadCOMMONProperties                \n");
#ifdef    Si2176_CRYSTAL_TRIM_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_CRYSTAL_TRIM_PROP_CODE                ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_CRYSTAL_TRIM_PROP */
#ifdef    Si2176_MASTER_IEN_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_MASTER_IEN_PROP_CODE                  ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_MASTER_IEN_PROP */
return NO_Si2176_ERROR;
};

 /*****************************************************************************************
 NAME: Si2176_downloadDTVProperties
  DESCRIPTION: Setup Si2176 DTV properties configuration
  This function will download all the DTV configuration properties.
  The function SetupDTVDefaults() should be called before the first call to this function.
  Parameter:  Pointer to Si2176 Context
  Returns:    I2C transaction error code, NO_Si2176_ERROR if successful
  Programming Guide Reference:    DTV setup flowchart
******************************************************************************************/
int  Si2176_downloadDTVProperties(L1_Si2176_Context *api)
{
  SiTRACE("Si2176_downloadDTVProperties                  \n");
#ifdef    Si2176_DTV_AGC_FREEZE_INPUT_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_AGC_FREEZE_INPUT_PROP_CODE        ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_AGC_FREEZE_INPUT_PROP */
#ifdef    Si2176_DTV_AGC_SPEED_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_AGC_SPEED_PROP_CODE               ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_AGC_SPEED_PROP */
#ifdef    Si2176_DTV_CONFIG_IF_PORT_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_CONFIG_IF_PORT_PROP_CODE          ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_CONFIG_IF_PORT_PROP */
#ifdef    Si2176_DTV_EXT_AGC_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_EXT_AGC_PROP_CODE                 ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_EXT_AGC_PROP */
#ifdef    Si2176_DTV_FILTER_SELECT_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_FILTER_SELECT_PROP_CODE           ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_FILTER_SELECT_PROP */
#ifdef    Si2176_DTV_IEN_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_IEN_PROP_CODE                     ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_IEN_PROP */
#ifdef    Si2176_DTV_INITIAL_AGC_SPEED_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_INITIAL_AGC_SPEED_PROP_CODE       ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_INITIAL_AGC_SPEED_PROP */
#ifdef    Si2176_DTV_INITIAL_AGC_SPEED_PERIOD_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_INITIAL_AGC_SPEED_PERIOD_PROP_CODE) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_INITIAL_AGC_SPEED_PERIOD_PROP */
#ifdef    Si2176_DTV_INTERNAL_ZIF_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_INTERNAL_ZIF_PROP_CODE            ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_INTERNAL_ZIF_PROP */
#ifdef    Si2176_DTV_INT_SENSE_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_INT_SENSE_PROP_CODE               ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_INT_SENSE_PROP */
#ifdef    Si2176_DTV_LIF_FREQ_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_LIF_FREQ_PROP_CODE                ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_LIF_FREQ_PROP */
#ifdef    Si2176_DTV_LIF_OUT_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_LIF_OUT_PROP_CODE                 ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_LIF_OUT_PROP */
#ifdef    Si2176_DTV_MODE_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_MODE_PROP_CODE                    ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_MODE_PROP */
#ifdef    Si2176_DTV_RF_TOP_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_RF_TOP_PROP_CODE                  ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_RF_TOP_PROP */
#ifdef    Si2176_DTV_RSQ_RSSI_THRESHOLD_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_DTV_RSQ_RSSI_THRESHOLD_PROP_CODE      ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_DTV_RSQ_RSSI_THRESHOLD_PROP */
return NO_Si2176_ERROR;
};

 /*****************************************************************************************
 NAME: Si2176_downloadTUNERProperties
  DESCRIPTION: Setup Si2176 TUNER properties configuration
  This function will download all the TUNER configuration properties.
  The function SetupTUNERDefaults() should be called before the first call to this function.
  Parameter:  Pointer to Si2176 Context
  Returns:    I2C transaction error code, NO_Si2176_ERROR if successful
  Programming Guide Reference:    TUNER setup flowchart
******************************************************************************************/
int  Si2176_downloadTUNERProperties(L1_Si2176_Context *api)
{
  SiTRACE("Si2176_downloadTUNERProperties      \n");
#ifdef    Si2176_TUNER_BLOCKED_VCO_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_TUNER_BLOCKED_VCO_PROP_CODE           ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_TUNER_BLOCKED_VCO_PROP */
#ifdef    Si2176_TUNER_IEN_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_TUNER_IEN_PROP_CODE                   ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_TUNER_IEN_PROP */
#ifdef    Si2176_TUNER_INT_SENSE_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_TUNER_INT_SENSE_PROP_CODE             ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_TUNER_INT_SENSE_PROP */
#ifdef    Si2176_TUNER_LO_INJECTION_PROP
  if (Si2176_L1_SetProperty2(api, Si2176_TUNER_LO_INJECTION_PROP_CODE          ) != NO_Si2176_ERROR) {return ERROR_Si2176_SENDING_COMMAND;}
#endif /* Si2176_TUNER_LO_INJECTION_PROP */
return NO_Si2176_ERROR;
};

int Si2176_downloadAllProperties       (L1_Si2176_Context *api)
{
  Si2176_downloadATVProperties       (api);
  Si2176_downloadCOMMONProperties    (api);
  Si2176_downloadDTVProperties       (api);
  Si2176_downloadTUNERProperties     (api);
  return 0;
};

/* _property_string_functions_insertion_point */





