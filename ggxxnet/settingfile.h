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

	char	userName[41];
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
	int		slowRate;
	char	rounds;
	char	msg[256];
	char	watchBroadcast;
	char	watchIntrusion;
	char	watchSaveReplay;
	char	watchMaxNodes;
}SettingInfo;	// ver1.20Å`