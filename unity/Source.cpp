//#include <windows.h>		// ������������ ���� ��� Windows
//#include <gl.h>		// ������������ ���� ��� OpenGL32 ����������
//#include <glu.h>		// ������������ ���� ��� GLu32 ����������
//#include <glut.h>
//#include <Glaux.h>		// ������������ ���� ��� GLaux ����������
//#include <math.h>
//
//
//static HGLRC hRC;		// ���������� �������� ����������
//static HDC hDC;			// ��������� �������� ���������� GDI
//BOOL	keys[256];		// ������ ��� ��������� ��������� ����������
//bool lInEs = false;
//bool task5 = false;
//double t = 0;
//double s = 25;
//double angel = 0.0;
//GLfloat ambient[4] = { 0.5, 0.3, 0.5, 1 };
//GLfloat yellow[3] = { 1,1,0 };
//GLfloat color[3] = { 1,1,1 };
//
//float bright = 93;
//float pos[4] = { 15,0,20,1 };
//float dir[3] = { 0, 0, -1 };
//
//GLvoid InitGL(GLsizei Width, GLsizei Height)	// ������� ����� ��������
//// ���� GL
//
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// ������� ������ � ������ ����
//	AUX_RGBImageRec* ImageSky;
//	ImageSky = auxDIBImageLoad("water.bmp");
//	GLuint	SingleTex;
//	glGenTextures(1, &SingleTex);// ��������� ������ ��������������
//	glBindTexture(GL_TEXTURE_2D, SingleTex);
//	glTexImage2D(GL_TEXTURE_2D, 0, 3,
//		ImageSky->sizeX, ImageSky->sizeY,
//		0, GL_RGB, GL_UNSIGNED_BYTE, ImageSky->data);
//	gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
//		ImageSky->sizeX,
//		ImageSky->sizeY, GL_RGB,
//		GL_UNSIGNED_BYTE, ImageSky->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	// ������� ������
//	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//	glEnable(GL_TEXTURE_2D);
//}
//GLvoid ReSizeGLScene(GLsizei Width, GLsizei Height)
//{
//	if (Height == 0)		// �������������� ������� �� ����, 
////���� ���� ������� ����
//Height = 1;
//
//	glViewport(0, 0, Width, Height);   // ����� ������� ������� ������ 
//}
//GLvoid DrawGLScene(GLvoid)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 	// ������� ������
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 	// ������� ������
//// ����� ��������� �������
//	if (keys[VK_LEFT]) {
//		angel += 1;
//	}
//	if (keys[VK_RIGHT]) {
//		angel -= 1;
//	}
//	glEnable(GL_DEPTH_TEST);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	////gluPerspective(50, 1024./600., 0, 10);
//	////gluLookAt(zoom*cos(t),1,zoom*sin(t),0,1,0, 0,1,0);
//	//glScalef(0.625, 1, 1);
//	//glRotated(t, 0, 1, 0);
//	//glColor3d(1, 0, 1);
//	//glBegin(GL_QUADS);
//	//glTexCoord2f(0.0, 0.0);
//	//glVertex3f(-1, 1, 0.); //����� ������� ����
//	//glTexCoord2f(1, 0);
//	//glVertex3f(-1, -1, 0.); //����� ������ ����
//	//glTexCoord2f(1, 1);
//	//glVertex3f(1, -1, 0.); //������ ������ ����
//	//glTexCoord2f(0, 1);
//	//glVertex3f(1, 1, 0.); //������ ������� ����
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 	// ������� ������
//	glLightfv(GL_LIGHT0, GL_POSITION, pos);
//	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluPerspective(90, 1.7, 1, 40);
//	gluLookAt(s * cos(t), 1, s * sin(t), 0, 1, 0, 0, 1, 0);
//	glRotatef(-90, 1, 0, 0);
//	//glEnable(GL_LINE_SMOOTH);
//	GLUquadricObj* quadricObj;
//	quadricObj = gluNewQuadric();
//	gluQuadricDrawStyle(quadricObj, GLU_FILL);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &bright);
//	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
//	gluSphere(quadricObj, 6, 20, 20);
//	
//	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, yellow);
//	gluSphere(quadricObj, 2.9, 20, 20);
//	glTranslated(9, 4, 10);
//	
//
//	gluDeleteQuadric(quadricObj);
//	glDisable(GL_DEPTH_TEST);
//	glEnd();
//
//}
//
//LRESULT CALLBACK WndProc(HWND	hWnd,
//	UINT	message,
//	WPARAM	wParam,
//	LPARAM	lParam)
//{
//	RECT	Screen;		// ������������ ������� ��� �������� ����
//	GLuint	PixelFormat;
//	static	PIXELFORMATDESCRIPTOR pfd =
//	{
//		sizeof(PIXELFORMATDESCRIPTOR),	// ������ ���� ���������
//	1,				// ����� ������ (?)
//	  PFD_DRAW_TO_WINDOW |		// ������ ��� ����
//	PFD_SUPPORT_OPENGL |		// ������ ��� OpenGL
//	PFD_DOUBLEBUFFER,		// ������ ��� �������� ������
//	PFD_TYPE_RGBA,		// ��������� RGBA ������
//	16,				// ����� 16 ��� ������� �����
//	0, 0, 0, 0, 0, 0,		// ������������� �������� ����� (?)
//	0,				// ��� ������ ������������
//	0,				// ��������� ��� ������������ (?)
//	0,				// ��� ������ �����������
//	0, 0, 0, 0,			// ���� ����������� ������������ (?)
//	16,				// 16 ������ Z-����� (����� �������)
//	0,				// ��� ������ ����������
//	0,				// ��� ��������������� ������� (?)
//	PFD_MAIN_PLANE,		// ������� ���� ���������
//	0,				// ������ (?)
//	0, 0, 0			// ����� ���� ������������ (?)
//	};
//	switch (message)	// ��� ���������
//	{
//	case WM_CREATE:
//		hDC = GetDC(hWnd);	// �������� �������� ���������� ��� ����
//		PixelFormat = ChoosePixelFormat(hDC, &pfd);
//		// ����� ��������� ���������� ��� ������ ������� ��������
//		if (!PixelFormat)
//		{
//			MessageBox(0, "Can't Find A SuitablePixelFormat.", "Error", MB_OK | MB_ICONERROR);
//			PostQuitMessage(0);
//			// ��� ��������� �������, ��� ��������� ������ �����������
//			break;	// �������������� ������� ����
//		}
//		if (!SetPixelFormat(hDC, PixelFormat, &pfd))
//		{
//			MessageBox(0, "Can't Set ThePixelFormat.", "Error", MB_OK | MB_ICONERROR);
//			PostQuitMessage(0);
//			break;
//		}
//		hRC = wglCreateContext(hDC);
//		if (!hRC)
//		{
//			MessageBox(0,
//				"Can't Create A GLRenderingContext.",
//				"Error", MB_OK | MB_ICONERROR);
//			PostQuitMessage(0);
//			break;
//		}
//		if (!wglMakeCurrent(hDC, hRC))
//		{
//			MessageBox(0, "Can't activate GLRC.", "Error", MB_OK | MB_ICONERROR);
//			PostQuitMessage(0);
//			break;
//		}
//		GetClientRect(hWnd, &Screen);
//		InitGL(Screen.right, Screen.bottom);
//		break;
//	case WM_DESTROY:
//	case WM_CLOSE:
//		ChangeDisplaySettings(NULL, 0);
//
//		wglMakeCurrent(hDC, NULL);
//		wglDeleteContext(hRC);
//		ReleaseDC(hWnd, hDC);
//		PostQuitMessage(0);
//		break;
//	case WM_KEYDOWN:
//		keys[wParam] = TRUE;
//		break;
//
//	case WM_KEYUP:
//		keys[wParam] = FALSE;
//		break;
//	case WM_SIZE:
//		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));
//		break;
//	default:
//		return (DefWindowProc(hWnd, message, wParam, lParam));
//	}
//	return (0);
//}
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//	LPSTR lpCmdLine, int nCmdShow)
//{
//	MSG		msg;	// ��������� ��������� Windows
//	WNDCLASS	wc;   // ��������� ������ Windows ��� ��������� ���� ����
//	HWND		hWnd;	// ���������� ����������� ����
//	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
//	wc.lpfnWndProc = (WNDPROC)WndProc;
//	wc.cbClsExtra = 0;
//	wc.cbWndExtra = 0;
//	wc.hInstance = hInstance;
//	wc.hIcon = NULL;
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = NULL;
//	wc.lpszMenuName = NULL;
//	wc.lpszClassName = "OpenGL WinClass";
//	if (!RegisterClass(&wc))
//	{
//		MessageBox(0,
//			"Failed To Register The WindowClass.",
//			"Error", MB_OK | MB_ICONERROR);
//		return FALSE;
//	}
//	hWnd = CreateWindow("OpenGL WinClass",
//		"First OpenGL program",	// ��������� ������ ����
//
//		WS_POPUP |
//		WS_CLIPCHILDREN |
//		WS_CLIPSIBLINGS,
//		0, 0,			// ������� ���� �� ������
//		1024, 600,		// ������ � ������ ����
//		NULL,
//		NULL,
//		hInstance,
//		NULL);
//	if (!hWnd)
//	{
//		MessageBox(0, "Window Creation Error.", "Error", MB_OK | MB_ICONERROR);
//		return FALSE;
//	}
//	if (!hWnd)
//	{
//		MessageBox(0, "Window Creation Error.", "Error", MB_OK | MB_ICONERROR);
//		return FALSE;
//	}
//	DEVMODE dmScreenSettings;		// ����� ������
//	memset(&dmScreenSettings, 0, sizeof(DEVMODE));
//	// ������� ��� �������� ���������
//	dmScreenSettings.dmSize = sizeof(DEVMODE);// ������ ��������� Devmode
//	dmScreenSettings.dmPelsWidth = 1024;			// ������ ������
//	dmScreenSettings.dmPelsHeight = 600;			// ������ ������
//	dmScreenSettings.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;// ����� �������
//	ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);
//	// ������������ � ������ �����
//
//	ShowWindow(hWnd, SW_SHOW);
//	UpdateWindow(hWnd);
//	SetFocus(hWnd);
//	while (1)
//	{		// ��������� ���� ���������
//		while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
//		{
//			if (GetMessage(&msg, NULL, 0, 0))
//			{
//				TranslateMessage(&msg);
//				DispatchMessage(&msg);
//			}
//			else
//			{
//				return TRUE;
//			}
//		}
//
//		DrawGLScene();				// ���������� �����
//		SwapBuffers(hDC);		// ����������� ����� ������
//		if (keys[VK_ESCAPE]) SendMessage(hWnd, WM_CLOSE, 0, 0);	// ���� ESC - �����
//		if (keys[VK_LEFT]) {
//			t += 0.1;
//			if (t > 360) t = 0;
//		}
//		if (keys[VK_RIGHT]) {
//			t -= 0.1;
//			if (t < 0) t = 360;
//		}
//		if (keys[VK_UP] ) {
//			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//		}
//		if (keys[VK_DOWN]) {
//			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//		}
//	}
//}
#include <windows.h>		// ������������ ���� ��� Windows
#include <gl\gl.h>		// ������������ ���� ��� OpenGL32 ����������
#include <gl\glu.h>		// ������������ ���� ��� GLu32 ����������
#include <glaux.h>		// ������������ ���� ��� GLaux ����������
#include <math.h>
static HGLRC hRC;		// ���������� �������� ����������
static HDC hDC;			// ��������� �������� ���������� GDI
BOOL	keys[256];		// ������ ��� ��������� ��������� ����������
bool lInEs = false;
bool task5 = false;
double t = 0;
double s = 25;
GLfloat ambient[4] = { 0.5, 0.3, 0.5, 1 };
GLfloat white[3] = { 1,1,1 };
GLfloat color[3] = { 1,1,1 };

float bright = 93;
float pos[4] = { 15,0,20,1 };
float dir[3] = { 0, 0, -1 };
unsigned int photo_tex;
AUX_RGBImageRec* photo_image;

unsigned int space_tex;
AUX_RGBImageRec* space_image;
void CALLBACK display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glColor3d(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, space_tex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(-5, -5, -0.1);
	glTexCoord2d(0, 1); glVertex3d(-5, 5, -0.1);
	glTexCoord2d(1, 1); glVertex3d(5, 5, -0.1);
	glTexCoord2d(1, 0); glVertex3d(5, -5, -0.1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, photo_tex);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex2d(-4, -4);
	glTexCoord2d(0, 2); glVertex2d(-4, 4);
	glTexCoord2d(3, 2); glVertex2d(4, 4);
	glTexCoord2d(3, 0); glVertex2d(4, -4);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	auxSwapBuffers();
}
GLvoid InitGL(GLsizei Width, GLsizei Height)	// ������� ����� ��������
// ���� GL

{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// ������� ������ � ������ ����
	//AUX_RGBImageRec* ImageSky;
	//ImageSky = auxDIBImageLoad("water.bmp");
	//GLuint	SingleTex;
	//glGenTextures(1, &SingleTex);// ��������� ������ ��������������
	//glBindTexture(GL_TEXTURE_2D, SingleTex);
	//glTexImage2D(GL_TEXTURE_2D, 0, 3,
	//	ImageSky->sizeX, ImageSky->sizeY,
	//	0, GL_RGB, GL_UNSIGNED_BYTE, ImageSky->data);
	//gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
	//	ImageSky->sizeX,
	//	ImageSky->sizeY, GL_RGB,
	//	GL_UNSIGNED_BYTE, ImageSky->data);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//// ������� ������
	////glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	//glEnable(GL_TEXTURE_2D);
	auxInitPosition(50, 10, 400, 400);
	auxInitDisplayMode(AUX_RGB | AUX_DEPTH | AUX_DOUBLE);
	auxInitWindow("Shapes");
	auxIdleFunc(display);
	//auxReshapeFunc(resize);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	photo_image = auxDIBImageLoad("water.bmp");
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		photo_image->sizeX,
		photo_image->sizeY,
		0, GL_RGB, GL_UNSIGNED_BYTE,
		photo_image->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	auxMainLoop(display);
}
GLvoid ReSizeGLScene(GLsizei Width, GLsizei Height)
{
	if (Height == 0)		// �������������� ������� �� ����, 
//���� ���� ������� ����
Height = 1;

	glViewport(0, 0, Width, Height);   // ����� ������� ������� ������ 
}
GLvoid DrawGLScene(GLvoid)
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 	// ������� ������
	//glLightfv(GL_LIGHT0, GL_POSITION, pos);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
	//glEnable(GL_DEPTH_TEST);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//gluPerspective(90, 1.7, 1, 40);
	//gluLookAt(s * cos(t), 1, s * sin(t), 0, 1, 0, 0, 1, 0);
	//glRotatef(-90, 1, 0, 0);
	////glEnable(GL_LINE_SMOOTH);
	//GLUquadricObj* quadricObj;
	//quadricObj = gluNewQuadric();
	//gluQuadricDrawStyle(quadricObj, GLU_FILL);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &bright);
	////glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
	//gluSphere(quadricObj, 6, 20, 20);

	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
	//gluSphere(quadricObj, 2.9, 20, 20);
	//glTranslated(9, 4, 10);


	//gluDeleteQuadric(quadricObj);
	//glDisable(GL_DEPTH_TEST);
}

LRESULT CALLBACK WndProc(HWND	hWnd,
	UINT	message,
	WPARAM	wParam,
	LPARAM	lParam)
{
	RECT	Screen;		// ������������ ������� ��� �������� ����
	GLuint	PixelFormat;
	static	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),	// ������ ���� ���������
	1,				// ����� ������ (?)
	  PFD_DRAW_TO_WINDOW |		// ������ ��� ����
	PFD_SUPPORT_OPENGL |		// ������ ��� OpenGL
	PFD_DOUBLEBUFFER,		// ������ ��� �������� ������
	PFD_TYPE_RGBA,		// ��������� RGBA ������
	16,				// ����� 16 ��� ������� �����
	0, 0, 0, 0, 0, 0,		// ������������� �������� ����� (?)
	0,				// ��� ������ ������������
	0,				// ��������� ��� ������������ (?)
	0,				// ��� ������ �����������
	0, 0, 0, 0,			// ���� ����������� ������������ (?)
	16,				// 16 ������ Z-����� (����� �������)
	0,				// ��� ������ ����������
	0,				// ��� ��������������� ������� (?)
	PFD_MAIN_PLANE,		// ������� ���� ���������
	0,				// ������ (?)
	0, 0, 0			// ����� ���� ������������ (?)
	};
	switch (message)	// ��� ���������
	{
	case WM_CREATE:
		hDC = GetDC(hWnd);	// �������� �������� ���������� ��� ����
		PixelFormat = ChoosePixelFormat(hDC, &pfd);
		// ����� ��������� ���������� ��� ������ ������� ��������
		if (!PixelFormat)
		{
			MessageBox(0, "Can't Find A SuitablePixelFormat.", "Error", MB_OK | MB_ICONERROR);
			PostQuitMessage(0);
			// ��� ��������� �������, ��� ��������� ������ �����������
			break;	// �������������� ������� ����
		}
		if (!SetPixelFormat(hDC, PixelFormat, &pfd))
		{
			MessageBox(0, "Can't Set ThePixelFormat.", "Error", MB_OK | MB_ICONERROR);
			PostQuitMessage(0);
			break;
		}
		hRC = wglCreateContext(hDC);
		if (!hRC)
		{
			MessageBox(0,
				"Can't Create A GLRenderingContext.",
				"Error", MB_OK | MB_ICONERROR);
			PostQuitMessage(0);
			break;
		}
		if (!wglMakeCurrent(hDC, hRC))
		{
			MessageBox(0, "Can't activate GLRC.", "Error", MB_OK | MB_ICONERROR);
			PostQuitMessage(0);
			break;
		}
		GetClientRect(hWnd, &Screen);
		InitGL(Screen.right, Screen.bottom);
		break;
	case WM_DESTROY:
	case WM_CLOSE:
		ChangeDisplaySettings(NULL, 0);

		wglMakeCurrent(hDC, NULL);
		wglDeleteContext(hRC);
		ReleaseDC(hWnd, hDC);
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		keys[wParam] = TRUE;
		break;

	case WM_KEYUP:
		keys[wParam] = FALSE;
		break;
	case WM_SIZE:
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));
		break;
	default:
		return (DefWindowProc(hWnd, message, wParam, lParam));
	}
	return (0);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	MSG		msg;	// ��������� ��������� Windows
	WNDCLASS	wc;   // ��������� ������ Windows ��� ��������� ���� ����
	HWND		hWnd;	// ���������� ����������� ����
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "OpenGL WinClass";
	if (!RegisterClass(&wc))
	{
		MessageBox(0,
			"Failed To Register The WindowClass.",
			"Error", MB_OK | MB_ICONERROR);
		return FALSE;
	}
	hWnd = CreateWindow("OpenGL WinClass",
		"First OpenGL program",	// ��������� ������ ����

		WS_POPUP |
		WS_CLIPCHILDREN |
		WS_CLIPSIBLINGS,
		0, 0,			// ������� ���� �� ������
		1024, 600,		// ������ � ������ ����
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!hWnd)
	{
		MessageBox(0, "Window Creation Error.", "Error", MB_OK | MB_ICONERROR);
		return FALSE;
	}
	if (!hWnd)
	{
		MessageBox(0, "Window Creation Error.", "Error", MB_OK | MB_ICONERROR);
		return FALSE;
	}
	DEVMODE dmScreenSettings;		// ����� ������
	memset(&dmScreenSettings, 0, sizeof(DEVMODE));
	// ������� ��� �������� ���������
	dmScreenSettings.dmSize = sizeof(DEVMODE);// ������ ��������� Devmode
	dmScreenSettings.dmPelsWidth = 1024;			// ������ ������
	dmScreenSettings.dmPelsHeight = 600;			// ������ ������
	dmScreenSettings.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;// ����� �������
	ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);
	// ������������ � ������ �����

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	SetFocus(hWnd);
	while (1)
	{		// ��������� ���� ���������
		while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				return TRUE;
			}
		}

		DrawGLScene();				// ���������� �����
		SwapBuffers(hDC);		// ����������� ����� ������
		if (keys[VK_ESCAPE]) SendMessage(hWnd, WM_CLOSE, 0, 0);	// ���� ESC - �����
		if (keys[VK_LEFT]) {
			t += 0.005;
			if (t > 360) t = 0;
		}
		if (keys[VK_RIGHT]) {
			t -= 0.005;
			if (t == 0) t = 360;
		}
		if (keys[VK_UP] && s < 40) {
			s += 0.01;
		}
		if (keys[VK_DOWN] && s > 1) {
			s -= 0.01;
		}
	}
}