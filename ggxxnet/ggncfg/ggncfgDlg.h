// ggncfgDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once

#define IMG_ADDR_LIST_SIZE	2048
#define PAL_ADDR_LIST_SIZE	12

// CggncfgDlg �_�C�A���O
class CggncfgDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CggncfgDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^
	~CggncfgDlg(void);

// �_�C�A���O �f�[�^
	enum { IDD = IDD_GGNCFG_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g

// ����
protected:
	HICON m_hIcon;

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void	readSettingFile(void);
	void	writeSettingFile(void);

	CString	getSettingPath(void);
	
	CString getPalDirPath(void);
	CString getPalettePath(int p_cid, int p_palidx);
	CString getGGXXPath(void);
	CString getDataPath(int p_id);

	void clearImageOffset(void);
	void addImageOffset(int p_fid, int p_offset);
	void readImageData(int p_imgidx, int p_palidx);

	void changeColorEditChara(int p_charaid);

	void drawImage(bool p_inv = false);
	void drawPalette(void);

	CRect getImageRect(void);
	CRect getPaletteRect(void);
	void arrangeControls(void);

	afx_msg void OnClose();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);

	afx_msg void OnBnClickedEditcolor();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnCbnSelchangeEditchara();
	afx_msg void OnCbnSelchangeEditcolor();
	afx_msg void OnCbnSelchangeEditsprite();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedSavecolor();
	afx_msg void OnTimer(UINT nIDEvent);

	int		getSelectPalette(void)						{ return m_selectPalette; }
	DWORD	getPaletteColor(int p_pidx)					{ return m_palette[p_pidx]; }
	void	setPaletteColor(int p_pidx, DWORD p_color)	{ m_palette[p_pidx] = p_color; }
	void	setPaletteChanged(bool p_value)				{ m_paletteChanged = p_value; }

	int  checkSavePalette(void);
	bool readPalette(CString p_palFilePath);
	void writePalette(void);

	void updateGGXXPalette(int p_flash);

private:
	CButton*	m_ctl_ignoreSlow;

	CButton*	m_ctl_showGGNVer;

	CComboBox*	m_ctl_editColor;
	CComboBox*	m_ctl_editChara;
	CComboBox*	m_ctl_editSprite;
	CButton*	m_ctl_saveColor;

//////////////////////////////////
	HDC		m_windc;

	HDC		m_imgdc;
	HBITMAP	m_imgbmp;
	HBITMAP	m_imgoldbmp;
	DWORD*	m_imgbits;
	
	HDC		m_paldc;
	HBITMAP	m_palbmp;
	HBITMAP	m_paloldbmp;
	DWORD*	m_palbits;

	int		m_imageW;
	int		m_imageH;
	int		m_palsize;
	DWORD	m_palette[256];
	DWORD	m_palHeader[16];
	BYTE*	m_image;
	DWORD	m_imageAddrList[IMG_ADDR_LIST_SIZE];
	char	m_imageFIDList[IMG_ADDR_LIST_SIZE];
	int		m_imageAddrListCount;
	DWORD	m_palAddrList[PAL_ADDR_LIST_SIZE];
	int		m_palAddrListCount;

	int		m_selectPalette;
	bool	m_paletteChanged;
	int		m_curCID;
	int		m_curPalette;

	WORD	m_setting_wins;
	char	m_setting_rank;
	int		m_setting_score;
	int		m_setting_totalBattle;
	int		m_setting_totalWin;
	int		m_setting_totalLose;
	int		m_setting_totalDraw;
	int		m_setting_totalError;
	int		m_setting_slowRate;

	int		m_datVersion;	// �N�����ɊJ����dat�̃o�[�W�����@�t�H�[�}�b�g�ύX���鎞�̓o�b�N�A�b�v���
public:
	enum { DATVERSION = 120 };

public:
	CString	m_setting_msg;

	afx_msg void OnBnClickedDeleteaddr();
public:
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnEnChangeTrip();
	afx_msg void OnBnClickedUsercolor();
};
