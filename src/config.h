#pragma once

#define _CMT_Volume				"#��������ΧΪ0~100��Ĭ��Ϊ100(���ֵ)"
#define _CMT_AutoPlay			"#�Զ����ţ�����������ʱ��Ч��Ĭ��Ϊ1(���ô����)"
#define _CMT_SkipVoice			"#�Ի���ر�ʱ����ֹ������Ĭ��Ϊ1(���ô����)"
#define _CMT_DisableDialogSE	"#����������ʱ�����öԻ���ر�(�л�)ʱ����Ч��Ĭ��Ϊ1(���ô����)"
#define _CMT_DisableDududu		"#����������ʱ������������ʾ��������Ĭ��Ϊ1(���ô����)"

#define _CMT_ShowInfo	"#��ʾ��Ϣ��ģʽ�������£�\n"\
						";    0    �رգ�����ʾ��Ϣ\n"\
						";    1    ���ñ仯ʱ����ʾ��Ϣ\n"\
						";    2    ���ñ仯ʱ����ʾ��Ϣ��ͬʱ�ڲ����������������ʾ�Զ����ŵķ���(���������Զ�����)\n"\
						"#Ĭ��Ϊ1"
#define _CMT_FontName	"#��Ϣ������(��·��)������Ϊ����ϵͳ�а�װ�����塣Ĭ��Ϊ����"
#define _CMT_FontColor	"#��Ϣ������ɫ����ʽΪ0xAARRGGBB��Ĭ��Ϊ0xFFFFFFFF(��ɫ)"

#define _CMT_EnableKeys	"#���ð������ƣ������������£�\n"\
						";    +    Volume��1(��ͬʱ��סSHIFT���5)\n"\
						";    -    Volume��1(��ͬʱ��סSHIFT���5)\n"\
						";    0    ����/ȡ������(���ھ���״̬������Volume������״̬�ᱻȡ��)\n"\
						";    9    �л�AutoPlay��ֵ\n"\
						";    8    �л�SkipVoice��ֵ\n"\
						";    7    �л�DisableDialogSE��ֵ\n"\
						";    6    �л�DisableDududu��ֵ\n"\
						";    5    �л�ShowInfo��ֵ\n"\
						";  -+ͬʱ ȡ��������ͬʱ��\n"\
						";         1.��SaveChangeΪ1ʱ����EnableKeys��SaveChange�����������������ΪĬ��ֵ��\n"\
						";         2.��SaveChangeΪ0ʱ�����¼����������ļ���(�������ļ�ʱ��ͬ1)\n"\
						"#ע�⣺�������۳����೤ʱ�䣬����Ϊһ�ΰ���\n"\
						"#Ĭ��Ϊ1(����)"

#define _CMT_SaveChange	"#������Ϸ���޸������ã��Ƿ񱣴���ġ�\n"\
						"#��������������������һ�������������\n"\
						"#Ĭ��Ϊ0(������)"

#define DEFINE_CONFIG_COMMON(name) static constexpr char STR_##name[] = #name;\
									static constexpr char CMT_##name[] = _CMT_##name;\

#define DEFINE_CONFIG(name, dft) int name; \
								static constexpr int DFT_##name = dft;\
								DEFINE_CONFIG_COMMON(name);

#define DEFINE_CONFIG_WMAX(name, dft, max) DEFINE_CONFIG(name, dft)\
											static constexpr int MAX_##name = max;

#define DEFINE_STRCONFIG(name, dft, len) char name[len+1]; \
										static constexpr char DFT_##name[] = dft;\
										DEFINE_CONFIG_COMMON(name);

struct Config
{
	DEFINE_CONFIG_WMAX(Volume, 100, 100);
	DEFINE_CONFIG(AutoPlay, 1);
	DEFINE_CONFIG(SkipVoice, 1);
	DEFINE_CONFIG(DisableDialogSE, 1);
	DEFINE_CONFIG(DisableDududu, 1);
	DEFINE_CONFIG_WMAX(ShowInfo, 1, 2);
	DEFINE_STRCONFIG(FontName, "����", 31);
	DEFINE_CONFIG(FontColor, 0xFFFFFFFF);

	DEFINE_CONFIG(EnableKeys, 1);
	DEFINE_CONFIG(SaveChange, 0);

	bool LoadConfig(const char* configFn);
	bool SaveConfig(const char* configFn) const;

	void Reset(bool all = false) { load_default(all); }
	Config() { load_default(); }
	Config(const char* configFn) { LoadConfig(configFn); }
private:
	void load_default(bool all = true);
};



