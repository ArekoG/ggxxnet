#pragma once

//******************************************************************
// structures
//******************************************************************
#pragma pack(push)
#pragma pack(1)


typedef struct
{
	int		ver;
	char	scriptAddress[256];
	char	addressList[10][256];

	char	userName[41];	// 40byte�����邪���ۂɂ�20byte�܂�
	char	trip[11];
	char	enableNet;
	WORD	port;
	char	delay;

	char	ignoreMisNode;
	char	ignoreSlow;
	short	wait;

	char	useEx;

	char	dispInvCombo;
	char	showfps;
	WORD	wins;
	char	rank;
	int		score;
	int		totalBattle;
	int		totalWin;
	int		totalLose;
	int		totalDraw;
	int		totalError;
	int		slowRate;	/* �����������@�펞60fps������ꍇ100%�ɂȂ� */
	char	rounds;
	char	msg[256];
	char	watchBroadcast;		// �z�M����
	char	watchIntrusion;		// ��������
	char	watchSaveReplay;	// �ϐ킵�����v���C��ۑ����邩�H
	char	watchMaxNodes;		// 1���z�M��t��
}SettingInfo;	// ver1.20�`

#pragma pack(pop)

//******************************************************************
// proto types
//******************************************************************
void getSettings(void);