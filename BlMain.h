//---------------------------------------------------------------------------
#ifndef BlMainH
#define BlMainH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ComCtrls.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Menus.hpp>
#include <vcl\Dialogs.hpp>
#include <ToolWin.hpp>
#include <ExtDlgs.hpp>
#include "RxRichEd.hpp"
//---------------------------------------------------------------------------
class TBlock : public TForm
{
__published:	// IDE-managed Components
  TStatusBar *StatusBar;
  TMainMenu *MainMenu;
  TMenuItem *FileMenu;
  TMenuItem *FileNew;
  TMenuItem *FileOpen;
  TMenuItem *FileSave;
  TMenuItem *FileSaveAs;
  TMenuItem *N1;
  TMenuItem *FileExit;
  TMenuItem *Edit1;
  TMenuItem *N4;
  TMenuItem *EditPaste;
  TMenuItem *EditCopy;
  TMenuItem *EditCut;
  TMenuItem *N5;
  TMenuItem *EditUndo;
  TMenuItem *Help1;
  TMenuItem *HelpAbout;
  TMenuItem *HelpContents;
  TMenuItem *EditSelectAll;
  TMenuItem *N3;
  TMenuItem *EditWordWrap;
  TOpenDialog *OpenDialog;
  TSaveDialog *SaveDialog;
  TPopupMenu *MemoPopup;
  TMenuItem *PopupCut;
  TMenuItem *PopupCopy;
  TMenuItem *PopupPaste;
    TToolBar *ToolBar1;
    TToolButton *ToolButton1;
    TSpeedButton *NewButton;
    TSpeedButton *OpenButton;
    TSpeedButton *SaveButton;
    TSpeedButton *SaveAsButton;
    TToolButton *ToolButton2;
    TSpeedButton *CopyButton;
    TSpeedButton *CutButton;
    TSpeedButton *PrintButton;
    TPrintDialog *PrintDialog1;
    TMenuItem *N2;
    TFontDialog *FontDialog1;
        TSpeedButton *PasteButton;
    TMenuItem *FontD;
        TButton *Button1;
        TRxRichEdit *Memo;
        TMenuItem *N6;
        TMenuItem *F1;
        TMenuItem *F2;
        TMenuItem *F3;
        TMenuItem *F4;
        TToolButton *ToolButton4;
        TSpeedButton *FormulaButton;
  void __fastcall EditCutClick(TObject *Sender);
  void __fastcall EditCopyClick(TObject *Sender);
  void __fastcall EditPasteClick(TObject *Sender);
  void __fastcall FileNewClick(TObject *Sender);
  void __fastcall FileOpenClick(TObject *Sender);
  void __fastcall FileSaveClick(TObject *Sender);
  void __fastcall FileSaveAsClick(TObject *Sender);
  void __fastcall EditUndoClick(TObject *Sender);
  void __fastcall EditSelectAllClick(TObject *Sender);
  void __fastcall EditWordWrapClick(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  
    void __fastcall PrintButtonClick(TObject *Sender);
    
    void __fastcall FontDClick(TObject *Sender);
        void __fastcall F4Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormulaButtonClick(TObject *Sender);
        void __fastcall HelpAboutClick(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall FileExitClick(TObject *Sender);
private:	// User declarations
  void __fastcall OnHint(TObject* Sender);
public:		// User declarations
  __fastcall TBlock(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBlock *Block;
//---------------------------------------------------------------------------
#endif
