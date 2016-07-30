#ifndef CONFIG_PRECIP_SECTION_H
#define CONFIG_PRECIP_SECTION_H

#include <map>
#include "Defines.h"
#include "TimeUnit.h"
#include "DistancePerTimeUnits.h"
#include "DatedName.h"
#include "PrecipType.h"
#include "ConfigSection.h"

class PrecipConfigSection : public ConfigSection {

	public:
		PrecipConfigSection();
		~PrecipConfigSection();

		DatedName *GetFileName();
		char *GetLoc() { return loc; }
		TimeUnit *GetFreq() { return &freq; }
		TimeUnit *GetUnitTime() { return unit.GetTime(); }
		SUPPORTED_PRECIP_TYPES GetType() { return type.GetType(); }		
		CONFIG_SEC_RET ProcessKeyValue(char *name, char *value);
		CONFIG_SEC_RET ValidateSection();

		static bool IsDuplicate(char *name);

	private:
		bool locSet, freqSet, nameSet, unitSet, typeSet;
		char loc[CONFIG_MAX_LEN];
		DatedName fileName;	
		TimeUnit freq;
		DistancePerTimeUnits unit;
		PrecipType type;
			
		
};

extern std::map<std::string, PrecipConfigSection *> g_precipConfigs;

#endif
