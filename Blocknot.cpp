//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEFORM("BlMain.cpp", Block);
USEFORM("BlFormula.cpp", FormulaForm);
USEFORM("blAbout.cpp", AboutBox);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TBlock), &Block);
                 Application->CreateForm(__classid(TFormulaForm), &FormulaForm);
                 Application->CreateForm(__classid(TAboutBox), &AboutBox);
                 Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
