// DDE.h: 定义CMyDde类.
//
#ifndef _DDE_H__INCLUDED
#define _DDE_H__INCLUDED
#include <ddeml.h>

class CMyDde
{
public:
    CMyDde();
    ~CMyDde();

    // 静态回调成员函数.
    static HDDEDATA CALLBACK DdeCallback(UINT iType, UINT iFmt,
                                         HCONV hConv, HSZ hsz1, HSZ hsz2,
                                         HDDEDATA hData, DWORD dwData1, DWORD data2);

    void DdeCall(UINT iType, LPCSTR szSvr, LPCSTR szTopic, LPCSTR szAtom);

    void DdeServer(CString strReply);
    void DdeClient(CString strRequest);

    CString GetReply()
    {
        return m_strReply;
    }
    CString GetRequest()
    {
        return m_strRequest;
    }

private:
    static CMyDde* fakeThis;
    DWORD    idInst;
    CString  AppName;
    CString m_strReply;
    CString m_strRequest;
};

#endif