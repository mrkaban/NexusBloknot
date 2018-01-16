//---------------------------------------------------------------------------

#ifndef BlFormulaH
#define BlFormulaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <OleCtnrs.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormulaForm : public TForm
{
__published:	// IDE-managed Components
        TOleContainer *OleContainer1;
        TPanel *Panel1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormulaForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormulaForm *FormulaForm;
//---------------------------------------------------------------------------
#endif
