// DdeServer.h : main header file for the DDESERVER application
//

#if !defined(AFX_DDESERVER_H__B9CA838E_5B88_4C5C_AD16_0C75E7006720__INCLUDED_)
#define AFX_DDESERVER_H__B9CA838E_5B88_4C5C_AD16_0C75E7006720__INCLUDED_

#if _MSC_VER > 1000
    #pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
    #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDdeServerApp:
// See DdeServer.cpp for the implementation of this class
//

class CDdeServerApp : public CWinApp
{
public:
    CDdeServerApp();

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDdeServerApp)
public:
    virtual BOOL InitInstance();
    //}}AFX_VIRTUAL

// Implementation

    //{{AFX_MSG(CDdeServerApp)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDESERVER_H__B9CA838E_5B88_4C5C_AD16_0C75E7006720__INCLUDED_)
