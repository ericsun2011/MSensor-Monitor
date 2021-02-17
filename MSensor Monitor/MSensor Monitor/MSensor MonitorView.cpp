
// MSensor MonitorView.cpp : implementation of the CMSensorMonitorView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MSensor Monitor.h"
#endif

#include "MSensor MonitorDoc.h"
#include "MSensor MonitorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMSensorMonitorView

IMPLEMENT_DYNCREATE(CMSensorMonitorView, CView)

BEGIN_MESSAGE_MAP(CMSensorMonitorView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMSensorMonitorView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMSensorMonitorView construction/destruction

CMSensorMonitorView::CMSensorMonitorView() noexcept
{
	// TODO: add construction code here

}

CMSensorMonitorView::~CMSensorMonitorView()
{
}

BOOL CMSensorMonitorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMSensorMonitorView drawing

void CMSensorMonitorView::OnDraw(CDC* /*pDC*/)
{
	CMSensorMonitorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMSensorMonitorView printing


void CMSensorMonitorView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMSensorMonitorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMSensorMonitorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMSensorMonitorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMSensorMonitorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMSensorMonitorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMSensorMonitorView diagnostics

#ifdef _DEBUG
void CMSensorMonitorView::AssertValid() const
{
	CView::AssertValid();
}

void CMSensorMonitorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMSensorMonitorDoc* CMSensorMonitorView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMSensorMonitorDoc)));
	return (CMSensorMonitorDoc*)m_pDocument;
}
#endif //_DEBUG


// CMSensorMonitorView message handlers
