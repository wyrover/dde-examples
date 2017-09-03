// DdeServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DdeServer.h"
#include "DdeServerDlg.h"
#include "..\\DdeClass\\Dde.h"

#ifdef _DEBUG
    #define new DEBUG_NEW
    #undef THIS_FILE
    static char THIS_FILE[] = __FILE__;
#endif

CMyDde theDDEObj;

/////////////////////////////////////////////////////////////////////////////
// CDdeServerDlg dialog

CDdeServerDlg::CDdeServerDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CDdeServerDlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDdeServerDlg)
    m_strText = _T("");
    //}}AFX_DATA_INIT
    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDdeServerDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDdeServerDlg)
    DDX_Text(pDX, IDC_TEXT, m_strText);
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDdeServerDlg, CDialog)
    //{{AFX_MSG_MAP(CDdeServerDlg)
    ON_WM_TIMER()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDdeServerDlg message handlers

BOOL CDdeServerDlg::OnInitDialog()
{
    CDialog::OnInitDialog();
    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);         // Set big icon
    SetIcon(m_hIcon, FALSE);        // Set small icon
    SetTimer(1, 900, NULL);
    theDDEObj.DdeServer("data received!");
    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDdeServerDlg::OnTimer(UINT nIDEvent)
{
    m_strText = theDDEObj.GetRequest();
    UpdateData(FALSE);
    CDialog::OnTimer(nIDEvent);
    CDialog::OnTimer(nIDEvent);
}
