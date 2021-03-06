﻿#include "Game.h"


Game::Game(HINSTANCE hIns,int W,int H,char* name)
{
	this->hInstance = hIns;
	this->Width = W;
	this->Height = H;
	this->hWnd = NULL;
	strcpy(this->windowName,name);
}


Game::~Game(void)
{
}

LRESULT CALLBACK Game::WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	if(message == WM_DESTROY)
	{
		PostQuitMessage(0);
	}
	return DefWindowProc(hWnd,message,wParam,lParam);
}

bool Game::InitWindow()
{
	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hIconSm = 0;
	wndclass.hIcon = 0;
	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndclass.hInstance = this->hInstance;
	wndclass.lpfnWndProc = (WNDPROC)WndProc;
	wndclass.lpszClassName = "Game";
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	if(!RegisterClassEx(&wndclass))
	{
		return false;
	}
	this->hWnd = CreateWindow("Game",this->windowName,WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,this->Width,this->Height,NULL,NULL,this->hInstance,NULL);
	if(!this->hWnd)
		return false;
	ShowWindow(this->hWnd,SW_NORMAL);
	UpdateWindow(this->hWnd);
	//tạo màn hình vẽ
	graphic = new MGraphic(this->hWnd,300,600);


	if(!graphic->InitD3D())
		return false;	
	//Chỗ này làm ẩu nên nó không logic một tí. các bạn tự fix lại	
	content = new MContent(graphic->GetDevice());
	return true;
}

void Game::InitGame()
{
	ball = new Ball();
	ball->Init(content);
	bat = new Bat();
	bat->Init(content);
	keyboard = new MKeyboard(hInstance,hWnd);
	keyboard->Init();


}


void Game::Update(float gameTime)
{	
	ball->Update(gameTime);
	//lay trang thai ban phim
	keyboard->GetState();
	bat->Update(gameTime,keyboard);
	//xét va chạm
	if(Check(bat->rect,ball->rect))
	{
		ball->dy  = - ball->dy;
	}
}
void Game::Render()
{
	//Bắt đầu vẽ
	//Ở đây xóa màn hình bằng màu trắng. 
	//Bạn có thể sửa lại. Mình làm nhanh nên để vậy luôn ^^
	graphic->Begin();
	ball->Render(graphic);
	bat->Render(graphic);
	graphic->End();
}
