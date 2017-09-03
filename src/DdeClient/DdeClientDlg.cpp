// DdeClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DdeClient.h"
#include "DdeClientDlg.h"
#include "..\\DdeClass\\Dde.h"

#ifdef _DEBUG
    #define new DEBUG_NEW
    #undef THIS_FILE
    static char THIS_FILE[] = __FILE__;
#endif

CMyDde theDDEObj;
/////////////////////////////////////////////////////////////////////////////
// CDdeClientDlg dialog

CDdeClientDlg::CDdeClientDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CDdeClientDlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDdeClientDlg)
    m_strText = _T("");
    //}}AFX_DATA_INIT
    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDdeClientDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDdeClientDlg)
    DDX_Text(pDX, IDC_TEXT, m_strText);
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDdeClientDlg, CDialog)
    //{{AFX_MSG_MAP(CDdeClientDlg)
    ON_BN_CLICKED(IDC_SEND, OnSend)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDdeClientDlg message handlers

BOOL CDdeClientDlg::OnInitDialog()
{
    CDialog::OnInitDialog();
    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);         // Set big icon
    SetIcon(m_hIcon, FALSE);        // Set small icon
    // TODO: Add extra initialization here
    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDdeClientDlg::OnSend()
{
    UpdateData();
    theDDEObj.DdeClient(m_strText);
    m_strText = theDDEObj.GetReply();
    UpdateData(FALSE);
}
