#pragma once



// CLeftView �� ���Դϴ�.

class CLeftView : public CFormView
{
	DECLARE_DYNCREATE(CLeftView)

protected:
	CLeftView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CLeftView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strDept;
	CString m_strName;
	bool m_bHobby[3];
	int m_nSex;
	virtual void OnInitialUpdate();
	afx_msg void OnRadioMale();
	afx_msg void OnRadioFemale();
	afx_msg void OnClickedCheckReading();
	afx_msg void OnClickedCheckSports();
	afx_msg void OnClickedCheckFishing();
	afx_msg void OnClickedButtonOk();
};


