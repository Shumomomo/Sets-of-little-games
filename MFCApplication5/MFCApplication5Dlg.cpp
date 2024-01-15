
// MFCApplication5Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication5Dlg 对话框



CMFCApplication5Dlg::CMFCApplication5Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION5_DIALOG, pParent)
	, caozuo(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	dianshu = 0;
	dianshux = 0;
}

void CMFCApplication5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, caozuo);
	DDX_Text(pDX, IDC_EDIT4, shuchu);
}

BEGIN_MESSAGE_MAP(CMFCApplication5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication5Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication5Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication5Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication5Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication5Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMFCApplication5Dlg 消息处理程序

BOOL CMFCApplication5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication5Dlg::shibai() {
	MessageBox(_T("你输了"), _T(" "), MB_OK);
	dianshu = dianshux = 0;
	return;
}

void CMFCApplication5Dlg::shengli() {
	MessageBox(_T("你赢了"), _T(" "), MB_OK);
	dianshu = dianshux = 0;
	return;
}

void CMFCApplication5Dlg::duiju() {
	char s[1009], t[1009], u[1009];
	srand(time(0));
	int caozuox = rand() % (dianshux + 2) - 1;
	if (caozuo == 0) {
		sprintf_s(u, "你出了石头\r\n");
	}
	else if (caozuo == -1) {
		sprintf_s(u, "你出了积点\r\n");
	}
	else sprintf_s(u, "你出了 %d 枪\r\n", caozuo);
	if (caozuox == 0) {
		sprintf_s(t, "%s我出了石头\r\n",u);
	}
	else if (caozuox == -1) {
		sprintf_s(t, "%s我出了积点\r\n",u);
	}
	else sprintf_s(t, "%s我出了 %d 枪\r\n", u,caozuox);
	if (caozuo > dianshu) {
		sprintf_s(s, "%s你自爆了，你有 %d 个点，但你出了 %d 枪\r\n我赢了！\r\n哈哈哈！\r\n", t, dianshu, caozuo);
		shuchu = s;
		caozuo = 0;
		UpdateData(false);
		shibai();
		return;
	}
	dianshu -= caozuo;
	dianshux -= caozuox;
	if (caozuox <= 0 && caozuo <= 0)sprintf_s(s, "%s游戏继续！\r\n", t);
	else if (caozuox > caozuo) {
		if (caozuox <= 3 && caozuo == 0)sprintf_s(s, "%s游戏继续！\r\n", t);
		else sprintf_s(s, "%s我赢了！\r\n哈哈哈！\r\n", t);
	}
	else if (caozuox < caozuo) {
		if (caozuo <= 3 && caozuox == 0)sprintf_s(s, "%s游戏继续！\r\n",t);
		else sprintf_s(s, "%s我输了！\r\n呜呜呜！\r\n",t);

	}
	else sprintf_s(s, "%s游戏继续！\r\n", t);
	shuchu = s;
	caozuo = 0;
	int tmp = strlen(s);
	UpdateData(false);
	if (s[tmp - 5] == -2)shibai();
	if (s[tmp - 5] == -40)shengli();
	return;
}

void CMFCApplication5Dlg::OnBnClickedButton3()
{
	caozuo = -1;
	duiju();
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication5Dlg::OnBnClickedButton2()
{
	caozuo = 0;
	duiju();
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication5Dlg::OnBnClickedButton5()
{
	caozuo = 1;
	duiju();
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication5Dlg::OnBnClickedButton6()
{
	caozuo = 2;
	duiju();
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication5Dlg::OnBnClickedButton4()
{
	UpdateData(true);
	duiju();
	// TODO: 在此添加控件通知处理程序代码
}

void CMFCApplication5Dlg::OnOK()
{
	OnBnClickedButton4();
	// TODO: 在此添加控件通知处理程序代码
}
