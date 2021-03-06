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
                  Silicon Laboratories Broadcast Si2158B Layer 1 API


   API properties functions definitions
   FILE: Si2158B_Properties_Functions.h
   Supported IC : Si2158B
   Compiled for ROM 51 firmware 4_1_build_3
   Revision: 0.1
   Date: June 23 2016
**************************************************************************************/
#ifndef   _Si2158B_PROPERTIES_FUNCTIONS_H_
#define   _Si2158B_PROPERTIES_FUNCTIONS_H_

void          Si2158B_storeUserProperties           (Si2158B_PropObj   *prop);
unsigned char Si2158B_PackProperty                  (Si2158B_PropObj   *prop, unsigned int prop_code, int *data);
unsigned char Si2158B_UnpackProperty                (Si2158B_PropObj   *prop, unsigned int prop_code, int  data);
void          Si2158B_storePropertiesDefaults       (Si2158B_PropObj   *prop);

int  Si2158B_downloadATVProperties   (L1_Si2158B_Context *api);
int  Si2158B_downloadCOMMONProperties(L1_Si2158B_Context *api);
int  Si2158B_downloadDTVProperties   (L1_Si2158B_Context *api);
int  Si2158B_downloadTUNERProperties (L1_Si2158B_Context *api);
int  Si2158B_downloadAllProperties   (L1_Si2158B_Context *api);

#endif /* _Si2158B_PROPERTIES_FUNCTIONS_H_ */







