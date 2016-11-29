#include "GameScene.hh"
#include "GUI.hh"
#include "System.hh"
#include "Logger.hh"
#include "mainMenu.hh"
#include "SceneManager.hh"
using namespace Logger;
#define SM SceneManager::Instance()
#define CELL_WIDTH 80
#define CELL_HEIGHT 80

MainMenu::MainMenu(void) {
	m_background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::BG_01 };
	m_button = { {400,200,W.GetWidth(), W.GetHeight() }, ObjectID::PLAY_BUTTON };
}

MainMenu::~MainMenu(void) {
}

void MainMenu::OnEntry(void) {
}

void MainMenu::OnExit(void) {
}

void MainMenu::Update(void) {  //385 x 130 --> PLAY_BUTTON
	static MouseCoords mouseCoords(0, 0);
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) {
		Println("===============");
		Println("mxp: ", mouseCoords);
		mouseCoords = IM.GetMouseCoords();
	}
	else if (IM.IsMouseUp<MOUSE_BUTTON_LEFT>()) {
		Println("mxn: ", IM.GetMouseCoords());
		if (IM.GetMouseCoords().x >= 400 || IM.GetMouseCoords().x <= 400 + 385 || IM.GetMouseCoords().y >= 200 || IM.GetMouseCoords().y >= 200 + 130) {
			SM.SetCurScene<GameScene>();
		}
	}
							// Test InputManager key methods
	if (IM.IsKeyHold<'a'>()) Println("a hold");
	if (IM.IsKeyDown<'0'>()) Println("0 down");
	if (IM.IsKeyUp<KEY_BUTTON_DOWN>()) Println("down arrow up");
}

void MainMenu::Draw(void) {
	m_background.Draw(); // Render background
	m_button.Draw();
}
