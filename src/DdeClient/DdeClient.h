// DdeClient.h : main header file for the DDECLIENT application
//

#if !defined(AFX_DDECLIENT_H__32C24A24_157F_4A1D_9267_CB58492D259B__INCLUDED_)
#define AFX_DDECLIENT_H__32C24A24_157F_4A1D_9267_CB58492D259B__INCLUDED_

#if _MSC_VER > 1000
    #pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
    #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDdeClientApp:
// See DdeClient.cpp for the implementation of this class
//

class CDdeClientApp : public CWinApp
{
public:
    CDdeClientApp();

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDdeClientApp)
public:
    virtual BOOL InitInstance();
    //}}AFX_VIRTUAL

// Implementation

    //{{AFX_MSG(CDdeClientApp)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDECLIENT_H__32C24A24_157F_4A1D_9267_CB58492D259B__INCLUDED_)
