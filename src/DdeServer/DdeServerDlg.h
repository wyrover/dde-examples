// DdeServerDlg.h : header file
//

#if !defined(AFX_DDESERVERDLG_H__095ACD2F_7A7B_49BE_A399_486A335EB349__INCLUDED_)
#define AFX_DDESERVERDLG_H__095ACD2F_7A7B_49BE_A399_486A335EB349__INCLUDED_

#if _MSC_VER > 1000
    #pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDdeServerDlg dialog

class CDdeServerDlg : public CDialog
{
// Construction
public:
    CDdeServerDlg(CWnd* pParent = NULL);    // standard constructor

// Dialog Data
    //{{AFX_DATA(CDdeServerDlg)
    enum { IDD = IDD_DDESERVER_DIALOG };
    CString m_strText;
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDdeServerDlg)
protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    HICON m_hIcon;

    // Generated message map functions
    //{{AFX_MSG(CDdeServerDlg)
    virtual BOOL OnInitDialog();
    afx_msg void OnTimer(UINT nIDEvent);
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDESERVERDLG_H__095ACD2F_7A7B_49BE_A399_486A335EB349__INCLUDED_)
