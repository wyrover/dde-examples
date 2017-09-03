// DDE.cpp: 实现CDDE类.
//
#include "stdafx.h"
#include "DDE.h"

CMyDde* CMyDde::fakeThis = NULL;

CMyDde::CMyDde()
{
}

CMyDde::~CMyDde()
{
}

void CMyDde::DdeServer(CString strReply)
{
    m_strReply = strReply;
    fakeThis = this;
    // 建立DDE.
    DdeInitialize(&idInst, DdeCallback, APPCLASS_STANDARD |
                  CBF_FAIL_ADVISES |
                  CBF_FAIL_POKES |
                  CBF_SKIP_REGISTRATIONS |
                  CBF_SKIP_UNREGISTRATIONS, 0L);
    // 注册服务名MyDDEService,使该程序作为DDE服务器.
    AppName = "MyDDEService";
    HSZ hszService = DdeCreateStringHandle(idInst, AppName, 0);
    DdeNameService(idInst, hszService, NULL, DNS_REGISTER);
}

void CMyDde::DdeClient(CString strRequest)
{
    m_strRequest = strRequest;
    idInst = 0;
    DdeInitialize(&idInst, NULL, APPCLASS_STANDARD |
                  CBF_FAIL_ADVISES |
                  CBF_FAIL_POKES |
                  CBF_SKIP_REGISTRATIONS |
                  CBF_SKIP_UNREGISTRATIONS, 0L);
    DdeCall(XTYP_EXECUTE, TEXT("MyDDEService"), TEXT("data"), TEXT("1"));
    DdeCall(XTYP_REQUEST, TEXT("MyDDEService"), TEXT("query"), TEXT("1"));
}

HDDEDATA CALLBACK CMyDde::DdeCallback(UINT iType,
                                      UINT iFmt, HCONV hConv,
                                      HSZ hsz1,   // Topic.
                                      HSZ hsz2,   // atom.
                                      HDDEDATA hData, DWORD dwData1, DWORD data2)
{
    char szBuffer[100];

    switch (iType) {
    // 建立交易连接.
    case XTYP_CONNECT:
        // 获得应用名.
        DdeQueryString(fakeThis->idInst, hsz2,
                       szBuffer, sizeof(szBuffer), 0);

        // 如果此应用不能被此服务器支持,返回NULL.
        if (strcmp(szBuffer, fakeThis->AppName))
            return NULL;

        // 获得topic名.
        DdeQueryString(fakeThis->idInst, hsz1,
                       szBuffer, sizeof(szBuffer), 0);
        // 如果连接成功,返回1.
        return (HDDEDATA)1;

    case XTYP_REQUEST:
        // 获得topic名.
        DdeQueryString(fakeThis->idInst, hsz1,
                       szBuffer, sizeof(szBuffer), 0);

        if (strcmp(szBuffer, "query") == 0) {
            // 获得Item 名.
            DdeQueryString(fakeThis->idInst, hsz2,
                           szBuffer, sizeof(szBuffer), 0);
            strcpy(szBuffer, fakeThis->m_strReply);
            return DdeCreateDataHandle(fakeThis->idInst,
                                       (LPBYTE)szBuffer, sizeof(szBuffer), 0, hsz2, CF_TEXT, 0);
        }

        break;

    case XTYP_EXECUTE:
        // 获得topic名.
        DdeQueryString(fakeThis->idInst, hsz1,
                       szBuffer, sizeof(szBuffer), 0);

        if (strcmp(szBuffer, "data") == 0) {
            // 获得数据.
            DdeGetData(hData, (LPBYTE)szBuffer, 40L, 0L);
            fakeThis->m_strRequest = szBuffer;
            return (HDDEDATA)1;
        }

        break;
    }

    return NULL;
}

void CMyDde::DdeCall(UINT iType, LPCSTR szSvr, LPCSTR szTopic, LPCSTR szItem)
{
    HSZ hszServName = DdeCreateStringHandle(idInst, szSvr, CP_WINANSI);
    HSZ hszTopic = DdeCreateStringHandle(idInst, szTopic, CP_WINANSI);
    HSZ hszItem =  DdeCreateStringHandle(idInst, szItem, CP_WINANSI);
    HCONV hConv =   DdeConnect(idInst, hszServName, hszTopic, NULL);
    HDDEDATA hData;
    DWORD dwResult;
    char szBuffer[100];
    DWORD dwLength;

    switch (iType) {
    case XTYP_REQUEST:
        // 向服务器发送请求.
        hData = DdeClientTransaction(NULL, 0, hConv,
                                     hszItem, CF_TEXT, iType, 5000, &dwResult);
        // 从服务器取得返回值.
        dwLength = DdeGetData(hData, (LPBYTE)szBuffer, sizeof(szBuffer), 0);

        if (dwLength > 0)
            m_strReply = szBuffer;

        break;

    case XTYP_EXECUTE:
        strcpy(szBuffer, m_strRequest);
        // 向服务器发送执行命令.
        hData = DdeClientTransaction((LPBYTE)szBuffer,
                                     sizeof(szBuffer), hConv,
                                     hszItem, CF_TEXT, iType, 5000, &dwResult);
        break;
    }

    DdeDisconnect(hConv);
    DdeFreeStringHandle(idInst, hszServName);
    DdeFreeStringHandle(idInst, hszTopic);
    DdeFreeStringHandle(idInst, hszItem);
}