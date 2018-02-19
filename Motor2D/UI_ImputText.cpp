#include "UI_ImputText.h"
#include "UI.h"
#include "j1Gui.h"
#include "j1Fonts.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "j1Input.h"
#include "UI_Button.h"
#include "j1Menu.h"
#include "j1Input.h"

ImputText::ImputText(int x, int y) : UI_Element(x, y) {

	type = IMPUT_TEXT;
	original_pos = position;

	Image_imputText = (Image*)App->gui->AdUIElement(x, y, IMAGE);
	Label_ImputText = (Label*)App->gui->AdUIElement(x, y, LABEL);


}

ImputText::~ImputText() {

}


bool ImputText::Update(float dt) {
	
	if (InputText_Actived) {
		App->font->CalcSize("|", W, H);
		App->render->DrawQuad({ 1000,10,W,H }, 255, 255, 255, 255);
		SDL_Event event;
		
		e.windowID;

		//Uint32 qq = event.text.type;
		//SDL_IsTextInputActive()
		Label_ImputText->SetText(event.text.text);
	}

	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN) {
		InputText_Actived = !InputText_Actived;
		if (InputText_Actived) {
			Label_ImputText->SetText("");
			SDL_StartTextInput();

		}
		else if (!InputText_Actived) {
			Label_ImputText->SetText("Your Name");
			SDL_StopTextInput();
		}
	}

	return true;
}
bool ImputText::CleanUp() {

	return true;
}