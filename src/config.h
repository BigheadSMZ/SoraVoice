#pragma once

#define STR_Volume "Volume"
#define STR_AutoPlay "AutoPlay"
#define STR_SkipVoice "SkipVoice"
#define STR_DisableDialogSE "DisableDialogSE"
#define STR_DisableDududu "DisableDududu"

#define STR_EnableKeys "EnableKeys"
#define STR_SaveChange "SaveChange"

#define MAX_Volume 100

#define DFT_Volume			MAX_Volume
#define DFT_AutoPlay		1
#define DFT_SkipVoice		1
#define DFT_DisableDialogSE	1
#define DFT_DisableDududu	1

#define DFT_EnableKeys 1
#define DFT_SaveChange 0

struct Config
{
	int Volume;
	int AutoPlay;
	int SkipVoice;
	int DisableDialogSE;
	int DisableDududu;

	int EnableKeys;
	int SaveChange;

	bool LoadConfig(const char* configFn);
	bool SaveConfig(const char* configFn) const;

	void Reset(bool all = false) { load_default(all); }
	Config() { load_default(); }
private:
	void load_default(bool all = true);
};

#define CMT_Volume			"#��������ΧΪ0~100��Ĭ��Ϊ100(���ֵ)"
#define CMT_AutoPlay		"#�Զ����ţ�����������ʱ��Ч��Ĭ��Ϊ1(����)"
#define CMT_SkipVoice		"#�Ի���ر�ʱ����ֹ������Ĭ��Ϊ1(����)"
#define CMT_DisableDialogSE	"#����������ʱ�����öԻ���ر�(�л�)ʱ����Ч��Ĭ��Ϊ1(����)"
#define CMT_DisableDududu	"#����������ʱ������������ʾ��������Ĭ��Ϊ1(����)"

#define CMT_EnableKeys	"#���ð������ƣ������������£�\n"\
						";    +    Volume��1(��ͬʱ��סSHIFT���5)\n"\
						";    -    Volume��1(��ͬʱ��סSHIFT���5)\n"\
						";    0    ����/ȡ������(���ھ���״̬������Volume������״̬�ᱻȡ��)\n"\
						";    9    �л�AutoPlay��ֵ\n"\
						";    8    �л�SkipVoice��ֵ\n"\
						";    7    �л�DisableDialogSE��ֵ\n"\
						";    6    �л�DisableDududu��ֵ\n"\
						";  -+ͬʱ ȡ��������ͬʱ��\n"\
						";         1.��SaveChangeΪ1ʱ����EnableKeys��SaveChange��������������Ĭ��ֵ��\n"\
						";         2.��SaveChangeΪ0ʱ�����¼����������ļ���(�������ļ�ʱ��ͬ1)\n"\
						"#ע�⣺�������۳����೤ʱ�䣬����Ϊһ�ΰ���\n"\
						"#Ĭ��Ϊ1(����)"

#define CMT_SaveChange	"#������Ϸ���޸������ã��Ƿ񱣴���ġ�\n"\
						"#��������������������һ�������������\n"\
						"#Ĭ��Ϊ0(������)"


