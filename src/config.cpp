#include "config.h"

#include <fstream>
#include <map>

using namespace std;

#define MAXCH_ONELINE 1024

using KeyValue = map<string, string>;

static bool _setValue(int& var, KeyValue& kv, const char* name) {
	auto it = kv.find(name);
	if (it == kv.end()) return false;

	int rad = 10;
	if (it->second[0] == '0' && (it->second[1] == 'x' || it->second[1] == 'X')) {
		rad = 16;
	}
	char *p;
	var = (int)std::strtoll(it->second.c_str(), &p, rad);
	return true;
}

bool Config::LoadConfig(const char * configFn)
{
	load_default();

	ifstream ifs(configFn);

	if (!ifs) return false;
	KeyValue kv;

	char buff[MAXCH_ONELINE];
	while (ifs.getline(buff, sizeof(buff)))
	{
		if (buff[0] == 0 || buff[0] == '#' || buff[0] == ';') continue;
		buff[sizeof(buff) - 1] = 0;

		string key, value;
		
		char* p = buff;
		while (*p && (*p == ' ' || *p == '\t')) p++;

		while (*p && *p != '=') key.push_back(*p++);
		if (*p++ != '=') continue;

		while (!key.empty() && (key.back() == ' ' || key.back() == '\t')) key.pop_back();
		if (key.empty()) continue;

		while (*p && (*p == ' ' || *p == '\t')) p++;
		while (*p) value.push_back(*p++);
		while (!value.empty() && (value.back() == ' ' || value.back() == '\t')) value.pop_back();

		kv.insert({ key, value });
	}

	_setValue(this->Volume, kv, STR_Volume);
	if (this->Volume > MAX_Volume) this->Volume = MAX_Volume;
	if (this->Volume < 0) this->Volume = 0;

	_setValue(this->AutoPlay, kv, STR_AutoPlay);
	if (this->AutoPlay) this->AutoPlay = 1;

	_setValue(this->SkipVoice, kv, STR_SkipVoice);
	if (this->SkipVoice) this->SkipVoice = 1;

	_setValue(this->DisableDialogSE, kv, STR_DisableDialogSE);
	if (this->DisableDialogSE) this->DisableDialogSE = 1;

	_setValue(this->DisableDududu, kv, STR_DisableDududu);
	if (this->DisableDududu) this->DisableDududu = 1;


	_setValue(this->EnableKeys, kv, STR_EnableKeys);
	if (this->EnableKeys) this->EnableKeys = 1;

	_setValue(this->SaveChange, kv, STR_SaveChange);
	if (this->SaveChange) this->SaveChange = 1;

	return true;
}

bool Config::SaveConfig(const char * configFn) const
{
	ofstream ofs(configFn);
	if (!ofs) return false;
	ofs << CMT_Volume << '\n'
		<< STR_Volume << " = " << this->Volume << '\n'
		<< '\n'
		<< CMT_AutoPlay << '\n'
		<< STR_AutoPlay << " = " << this->AutoPlay << '\n'
		<< '\n' 
		<< CMT_SkipVoice << '\n'
		<< STR_SkipVoice << " = " << this->SkipVoice << '\n'
		<< '\n'
		<< CMT_DisableDialogSE << '\n'
		<< STR_DisableDialogSE << " = " << this->DisableDialogSE << '\n'
		<< '\n'
		<< CMT_DisableDududu << '\n'
		<< STR_DisableDududu << " = " << this->DisableDududu << '\n'
		<< '\n'
		<< '\n'
		<< CMT_EnableKeys << '\n'
		<< STR_EnableKeys << " = " << this->EnableKeys << '\n'
		<< '\n'
		<< CMT_SaveChange << '\n'
		<< STR_SaveChange << " = " << this->SaveChange << '\n'
		;

	ofs.close();
	return true;
}

void Config::load_default(bool all)
{
	this->Volume = DFT_Volume;
	this->AutoPlay = DFT_AutoPlay;
	this->SkipVoice = DFT_SkipVoice;
	this->DisableDialogSE = DFT_DisableDialogSE;
	this->DisableDududu = DFT_DisableDududu;

	if (all) {
		this->EnableKeys = DFT_EnableKeys;
		this->SaveChange = DFT_SaveChange;
	}
}