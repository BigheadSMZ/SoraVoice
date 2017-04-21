﻿#pragma once

#define _CMT_Volume					"#音量，范围为0~100，默认为100(最大值)"

#define _CMT_AutoPlay				"#自动播放。模式罗列如下：\n"\
									";    0    关闭\n"\
									";    1    仅在有语音时启用自动播放\n"\
									";    2    对所有字幕启用自动播放\n"\
									";接下来的3个参数为设置自动播放时间的选项。\n"\
									"#默认为2\n"\
									"###注意：当启用此选项时，会强制启用选项SkipVoice。###";
#define _CMT_WaitTimePerChar		"#无语音时，为每个字分配的等待时间。默认为60(单位毫秒，下同)";
#define _CMT_WaitTimeDialog			"#无语音时，为对话框分配的额外等待时间。默认为800。\n"\
									"#则在默认配置下，一个20字的对话框的等待时间为800+20x60=2000毫秒";
#define _CMT_WaitTimeDialogVoice	"#有语音时，语音播放结束后额外的等待时间。默认为100"

#define _CMT_SkipVoice			"#对话框关闭时，终止语音。默认为1(启用此项功能)\n"\
								"###注意：当关闭此选项时，会强制关闭选项AutoPlay。###";
#define _CMT_DisableDialogSE	"#在语音播放时，禁用对话框关闭(切换)时的音效。默认为1(启用此项功能)"
#define _CMT_DisableDududu		"#在语音播放时，禁用文字显示的嘟嘟声。默认为1(启用此项功能)"
#define _CMT_ShowInfo	"#显示信息。模式罗列如下：\n"\
						";    0    关闭，不显示信息\n"\
						";    1    配置变化时，显示信息\n"\
						";    2    配置变化时，显示信息；同时在自动播放的情况下显示自动播放的符号\n"\
						"#默认为1"

#define _CMT_FontName	"#信息字体名(非路径)。必须为已在系统中安装的字体。默认为黑体"
#define _CMT_FontColor	"#信息字体颜色。格式为0xAARRGGBB。默认为0xFFFFFFFF(白色)"

#define _CMT_EnableKeys	"#启用按键控制，按键配置如下：\n"\
						";    +    Volume加1(若同时按住SHIFT则加5)\n"\
						";    -    Volume减1(若同时按住SHIFT则减5)\n"\
						";    0    静音/取消静音(若在静音状态调整了Volume，静音状态会被取消)\n"\
						";    9    切换AutoPlay的值\n"\
						";    8    切换SkipVoice的值\n"\
						";    7    切换DisableDialogSE的值\n"\
						";    6    切换DisableDududu的值\n"\
						";    5    切换ShowInfo的值\n"\
						";  -+同时 取消静音，同时：\n"\
						";         1.当SaveChange为1时，将EnableKeys和SaveChange以外的所有配置项设为默认值；\n"\
						";         2.当SaveChange为0时，重新加载配置项文件。(无配置文件时，同1)\n"\
						"###注意：长按不论持续多长时间，均视为一次按键###\n"\
						"#默认为1(启用)"

#define _CMT_SaveChange	"#若在游戏中修改了配置，是否保存更改。\n"\
						"#这个配置项仅在启用了上一配置项后有意义\n"\
						"#默认为0(不保存)\n"\
						"###注意：静音状态不会被保存###";

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
	static constexpr int ShowInfo_Off = 0;
	static constexpr int ShowInfo_On = 1;
	static constexpr int ShowInfo_WithMark = 2;

	static constexpr int AutoPlay_Off = 0;
	static constexpr int AutoPlay_Voice = 1;
	static constexpr int AutoPlay_ALL = 2;

	DEFINE_CONFIG_WMAX(Volume, 100, 100);

	DEFINE_CONFIG_WMAX(AutoPlay, AutoPlay_ALL, 2);
	DEFINE_CONFIG(WaitTimePerChar, 60);
	DEFINE_CONFIG(WaitTimeDialog, 800);
	DEFINE_CONFIG(WaitTimeDialogVoice, 100);

	DEFINE_CONFIG(SkipVoice, 1);
	DEFINE_CONFIG(DisableDialogSE, 1);
	DEFINE_CONFIG(DisableDududu, 1);
	DEFINE_CONFIG_WMAX(ShowInfo, ShowInfo_On, 2);

	DEFINE_STRCONFIG(FontName, "黑体", 31);
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



