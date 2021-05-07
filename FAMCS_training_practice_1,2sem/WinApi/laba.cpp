#include <windows.h>
#include "windowsx.h"
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


#define ID_FIRSTCHILD	100
#define ID_SECONDCHILD	101
#define ID_THIRDCHILD	102

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChildProc(HWND, UINT, WPARAM, LPARAM); // дочернее окно

HINSTANCE hinst;

char szAppName[] = "Программа";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR szCmdLine, int iCmdShow)
{
    HWND        hwnd;
    MSG         msg;
    WNDCLASSEX  wndclass;


    wndclass.cbSize = sizeof(wndclass);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;

    //если создано меню как ресурс с идентификатором IDR_MENU1, то отображения меню нужно:
    //wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);  

    wndclass.lpszClassName = szAppName;
    wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    RegisterClassEx(&wndclass);

    hwnd = CreateWindow(szAppName,        // window class name
        "The Program",   // window caption
        WS_OVERLAPPEDWINDOW,     // window style
        CW_USEDEFAULT,           // initial x position
        CW_USEDEFAULT,           // initial y position
        CW_USEDEFAULT,           // initial x size
        CW_USEDEFAULT,           // initial y size
        NULL,                    // parent window handle
        NULL,                    // window menu handle
        hInstance,               // program instance handle
        NULL);		   // creation parameters


    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    HDC         hdc;	// дескриптор контекста устройства
    PAINTSTRUCT ps;	    // Структура PAINTSTRUCT содержит информацию для приложения. Эта информация может быть использована для отрисовки клиентской области окна, которым владеет приложение.
    RECT        rect;	// Структура RECT определяет координаты верхнего левого и нижнего правого углов прямоугольника.
    
    RECT r;

    WORD xPos, yPos, nSize; // для вывода текста
    char szBuf[80];
    POINT pt;
    
    

    static HMENU hMenu; // для меню
    static HMENU hPopupMenu1, hPopupMenu2; // для подменю
    
    static HWND  hwndedit, hbutton, hbutton2; //кнопка
    static int   len;             

    static char* str, *strOut = new char[strlen("")]; //данные, вводимые пользователем
    strcpy(strOut, "");

    static bool  able = false;
    static bool  illustrationAble = false;
    static bool  drawPicture = false;


    HBRUSH hbr1, hbr2;
    hbr1 = CreateHatchBrush(HS_BDIAGONAL, RGB(207, 0, 32));  //создание кисти зелёные горизонатьльные полоски
    hbr2 = CreateSolidBrush(RGB(207, 0, 32));

    HFONT       font1, font2; // формат текста
    font1 = CreateFont(36, 0, 0, 0, 1000, TRUE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH, "Times New Roman");
    font2 = CreateFont(16, 0, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH, "Times New Roman");

    switch(iMsg)
    {
        case WM_CREATE: // Менюшки
        { 
            hMenu = CreateMenu();     // Создаем подменю.
        
            hPopupMenu1 = CreatePopupMenu(); // добавить элементы меню
            hPopupMenu2 = CreatePopupMenu(); // добавить элементы меню

            AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hPopupMenu1, "Файл");
            AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hPopupMenu2, "Операции");
       
            //AppendMenu(hPopupMenu1, MF_STRING, 1002, "-"); // добавить подменю
            //AppendMenu(hPopupMenu1, MF_STRING | MF_CHECKED, 1003, "-");  // пункт подменю, помеченный галочкой

            AppendMenu(hPopupMenu2, MF_STRING, 1004, "Вывести фигуру"); // добавить подменю
            AppendMenu(hPopupMenu2, MF_STRING, 1006, "Удалить фигуру");
            AppendMenu(hPopupMenu2, MF_STRING, 1005, "Создать модальное диалоговое окно"); 
            AppendMenu(hPopupMenu2, MF_STRING, 1007, "Создать окно с графическим изображением");
            AppendMenu(hPopupMenu2, MF_STRING, 1008, "Закрыть все");

            SetMenu(hwnd, hMenu); //привязать созданые меню пункты к окну


            // создаем кнопку
            hbutton2 = CreateWindow("button", "Чтобы вывести картинку, нажмите на кнопку", WS_CHILD | WS_VISIBLE, 150, 30, 350, 22, hwnd, (HMENU)10002, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
            hbutton = CreateWindow("button", "Ввод", WS_CHILD | WS_VISIBLE, 700, 60, 70, 22, hwnd, (HMENU)10001, ((LPCREATESTRUCT)lParam)->hInstance, NULL);

            hwndedit = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 700, 30, 100, 22, hwnd, (HMENU)2, ((LPCREATESTRUCT)lParam)->hInstance, NULL);

            

            return 0;
        }
        
        case WM_LBUTTONDOWN:
        {
            hdc = GetDC(hwnd);
            // Выводим координаты курсора мыши
            // в точке, соответствующей положению
            // курсора мыши 

            xPos = (int)LOWORD(lParam);
            yPos = (int)HIWORD(lParam);


            sprintf(szBuf, "%d, %d", xPos, yPos);
            nSize = strlen(szBuf);
            TextOut(hdc, xPos, yPos, "Hello world", sizeof("Hello world"));
            ReleaseDC(hwnd, hdc);
        }

        case WM_SETFOCUS:   // для работы кнопки и ввода текста
        {   
            SetFocus(hwndedit); 
            return 0; 
        }

        case WM_SIZE:       // для работы кнопки и ввода текста
        {
            return 0;
        }

        case WM_PAINT: // Текст в окне
        {
            hdc = BeginPaint(	               //Подготавливает окно к pаскpаске в ответ на сообщение wm_Paint. Заполняет Paint инфоpмацией для pаскpаски.
                hwnd,                          //Вновь pаскpашиваемое окно.
                &ps	                           //Стpуктуpа, пpинимающая инфоpмацию о pаскpаске.
            );                                 // Возвpащаемое значение: Идентификатоp контекста устpойства.

            GetClientRect(	    //Функция GetClientRect возвращает координаты клиентской области окна. Клиентские координаты определяют верхний левый и правый нижний углы клиентской области. 
                                //Поскольку клиентские координаты относительны левого угла клиентской области окна, то координатой верхнего левого угла является (0, 0).
                hwnd,           //идентифицирует окно, клиентские координаты которого возвращаются.
                &rect           //указывает на структуру, получающую клиентские координаты. Члены left и top равны нулю. Члены right и bottom содержат ширину и высоту окна.
            );                  //В случае успеха возвращается ненулевое значение. В случае неудачи возвращается нуль. Для получения дополнительной информации об ошибке вызовите функцию GetLastError.

            SelectObject(hdc, font1);           // Объект, которым мы рисуем 
            SetTextColor(hdc, RGB(71, 74, 81)); // цвет, которым мы рисуем
            DrawText(                           //Рисует фоpматиpованный текст.
                hdc,                                  //Идентификатоp контекста устpойства.
                "Найдович Олег Андреевич",            //Рисуемая стpока.
                -1,                                   //Если Count=-1, то строка должна заканчиваться пустым символом.
                &rect,                                //огpаничивающий текст.
                DT_SINGLELINE | DT_CENTER | DT_VCENTER//Тип фоpматиpования
            );	            // Возвpащаемое значение:   Высота текста.

            // Пишется текст над кнопкой
            SelectObject(hdc, font2); // но в одним момент времени может быть только 1 
            TextOut(hdc, 700, 13, "Введи строку:", 13);
            
            if (able)
            {
                TextOut(hdc, 700, 100, (LPSTR)strOut, strlen(strOut));
                TextOut(hdc, 700, 100, (LPSTR)str, len);
            }
            if (illustrationAble == true)
            {
                r.top = 130;
                r.left = 20;
                r.right = 320;
                r.bottom = 430;

                SetBkColor(hdc, RGB(102, 255, 0));
                FillRect(hdc, &r, hbr1);         // нарисуем прямоугольник и закрасим зелёной кистью
                FrameRect(hdc, &r, hbr2);        // делает рамку
                Ellipse(hdc, 140, 70, 210, 130); // нарисовали круг
            }


            EndPaint(	    //Указывает конец pаскpаски в Wnd.
                hwnd,   	//Пеpекpашиваемое окно.
                &ps	        //Стpуктуpа, полученная из функции BeginPaint.
            );
            return 0;
        }



        case WM_COMMAND: // Работа с текстом в менюшке
        {
            // Если выбрали пункт подмею меню.
            // для меню из ресурса,необходимо посмотреть в файле resource.h, какое число назначено
            if (LOWORD(wParam) == 1005)
            {
                MessageBox(hwnd, "Вы создали модальное диалоговое окно!", "Модальное диалоговое окно", NULL); // Options - название окна
            }
            if (LOWORD(wParam) == 1007)
            {
                    WNDCLASS w;
                    memset(&w, 0, sizeof(WNDCLASS));
                    w.lpfnWndProc = ChildProc;
                    w.hInstance = hinst;
                    w.hbrBackground = GetStockBrush(WHITE_BRUSH);
                    w.lpszClassName = "ChildWClass";
                    w.hCursor = LoadCursor(NULL, IDC_CROSS);
                    RegisterClass(&w);
                    HWND child;
                    child = CreateWindowEx(0, "ChildWClass", (LPCTSTR)NULL,
                        WS_CHILD | WS_BORDER | WS_VISIBLE, 0, 0,
                        250, 250, hwnd, (HMENU)(int)(ID_FIRSTCHILD), hinst, NULL);
                    ShowWindow(child, SW_NORMAL);
                    UpdateWindow(child);

                    return 0;

            }
            if (LOWORD(wParam) == 1008)
            {
                ChildProc(hwnd, WM_DESTROY, 0, 0);
            }
            if (lParam == (LPARAM)hbutton2)
            {
                illustrationAble = true;
            }
            if (LOWORD(wParam) == 1004)
            {
                illustrationAble = true;
            }
            if (LOWORD(wParam) == 1006)
            {
                illustrationAble = false;
            }

            if (HIWORD(wParam) == BN_CLICKED) // Если нажали на кнопку
            {
                len = GetWindowTextLength(hwndedit);
                str = new char[len + 1];
                GetWindowText(hwndedit, str, len + 1);
                able = true;
                InvalidateRect(hwnd, NULL, TRUE); //-предназначена для перерисовки окна из любого места программы. Эта функция посылает в программу сообщение WM_PAINT. 
               //Именно эту API-функцию вы должны использовать для перерисовки из обработчиков для разных сообщений Windows.
            }


            return 0;
        }

        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
    }
    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

// создание дочернего окна
LRESULT CALLBACK ChildProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
    HDC hDC, hCompatibleDC;
    PAINTSTRUCT PaintStruct;
    HANDLE hOldBitmap;
    HANDLE hBitmap;
    RECT Rect;
    BITMAP Bitmap;
    switch (Message)
    {
    case WM_PAINT:
        hDC = BeginPaint(hwnd, &PaintStruct);
        hBitmap = (HBITMAP)LoadImage(NULL, "MARBLES.BMP", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); 
        GetObject(hBitmap, sizeof(BITMAP), &Bitmap);
        hCompatibleDC = CreateCompatibleDC(hDC);
        hOldBitmap = SelectObject(hCompatibleDC, hBitmap);
        GetClientRect(hwnd, &Rect);
        StretchBlt(hDC, 0, 0, Rect.right, Rect.bottom,
            hCompatibleDC, 0, 0, Bitmap.bmWidth,
            Bitmap.bmHeight, SRCCOPY);
        SelectObject(hCompatibleDC, hOldBitmap);
        DeleteObject(hBitmap);
        DeleteDC(hCompatibleDC);
        EndPaint(hwnd, &PaintStruct);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    

    return DefWindowProc(hwnd, Message, wparam, lparam);

    if (Message == WM_DESTROY)
    {
        return 0;
    }
    return DefWindowProc(hwnd, Message, wparam, lparam);
}
