#pragma once

class Message {
public:
	static constexpr char Title[] = "����֮�켣����������";
	static constexpr char Version[] = "�汾 %s";
	static constexpr char VersionNum[] = "0.4.0";

	static constexpr char On[] = "��";
	static constexpr char Off[] = "��";
	static constexpr const char* Switch[] = { Off, On };
	
	static constexpr char Volume[] = "������%d";
	static constexpr char Mute[] = "����";

	static constexpr char Reset[] = "��������";
	
	static constexpr char AutoPlay[] = "�Զ����ţ�%s";
	static constexpr char SkipVoice[] = "�Ի���ر�ʱ��ֹ������%s";
	static constexpr char DisableDialogSE[] = "���öԻ���ر���Ч��%s";
	static constexpr char DisableDududu[] = "����������ʾ��Ч��%s";
	
	static constexpr char ShowInfo[] = "��Ϣ��ʾ��%s";
	static constexpr char ShowInfoAuto[] = "��(��ʾ�Զ����ŷ���)";
	static constexpr const char* ShowInfoSwitch[] = {Off, On, ShowInfoAuto};
	
	static constexpr char AutoPlayMark[] = "AUTO";
};


