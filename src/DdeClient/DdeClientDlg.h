// DdeClientDlg.h : header file
//

#if !defined(AFX_DDECLIENTDLG_H__6D9BE56B_AB20_4714_95AB_7F1EF50F5C30__INCLUDED_)
#define AFX_DDECLIENTDLG_H__6D9BE56B_AB20_4714_95AB_7F1EF50F5C30__INCLUDED_

#if _MSC_VER > 1000
    #pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDdeClientDlg dialog

class CDdeClientDlg : public CDialog
{
// Construction
public:
    CDdeClientDlg(CWnd* pParent = NULL);    // standard constructor

// Dialog Data
    //{{AFX_DATA(CDdeClientDlg)
    enum { IDD = IDD_DDECLIENT_DIALOG };
    CString m_strText;
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDdeClientDlg)
protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    HICON m_hIcon;

    // Generated message map functions
    //{{AFX_MSG(CDdeClientDlg)
    virtual BOOL OnInitDialog();
    afx_msg void OnSend();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDECLIENTDLG_H__6D9BE56B_AB20_4714_95AB_7F1EF50F5C30__INCLUDED_)
