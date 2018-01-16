//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#include <Clipbrd.hpp>
#include <IniFiles.hpp>
#pragma hdrstop

#include "BlMain.h"
#include "BlFormula.h"
#include "blAbout.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RxRichEd"
#pragma resource "*.dfm"
TBlock *Block;


AnsiString FilesName[4];
TOleContainer *Formula[4];


// если ругается  "Ambiduity between 'CHARFORMAT2A' and 'RichEdit::CHARFORMAT2A'"
//то заменить CHARFORMAT2A на   RichEdit::CHARFORMAT2A

//---------------------------------------------------------------------------
__fastcall TBlock::TBlock(TComponent* Owner)
  : TForm(Owner)
{
}


//---------------------------------------------------------------------------
void __fastcall TBlock::EditCutClick(TObject *Sender)
{
  Memo->CutToClipboard();   //вырезаем выделенное в буфер
}


//---------------------------------------------------------------------------
void __fastcall TBlock::EditCopyClick(TObject *Sender)
{
  Memo->CopyToClipboard();  //копируем выделенное в буфер
}


//---------------------------------------------------------------------------
void __fastcall TBlock::EditPasteClick(TObject *Sender)
{
  Memo->PasteFromClipboard();    //вставляем из буфера
}


//---------------------------------------------------------------------------
void __fastcall TBlock::EditSelectAllClick(TObject *Sender)
{
  Memo->SelectAll();  // выделяем весь текст
}


//---------------------------------------------------------------------------
void __fastcall TBlock::FileNewClick(TObject *Sender)  // открытие нового файла и
                                                       //проверка необходимости сохранения
{
  if (Memo->Modified)                           // Если текст изменен
   {
    int Res = Application->MessageBox(          // вызываем диалоговое окно
      "Текущий файл изменен. Сохранить изменения?","Блокнот: Предупреждение", MB_YESNOCANCEL);

    if (Res == IDCANCEL) return;                // если нажато "Отмена" возвращаемся
    if (Res == IDYES) FileSaveClick(Sender);    // если нажато "Да" вызываем процедуру сохранения файла
                                                // если нажато "Нет" ничего не делаем
   }
  if (Memo->Lines->Count > 0) Memo->Clear();    // если в поле "Мемо" есть строки, то удаляем их

  SaveDialog->FileName = "";                    //очищаем имя файла, что у нас явялется признаком нового файла
}


//---------------------------------------------------------------------------
void __fastcall TBlock::FileOpenClick(TObject *Sender)  // открытие файла
{

  if (Memo->Modified)                           // Если текст изменен
   {
    int Res = Application->MessageBox(          // вызываем диалоговое окно
      "Текущий файл изменен. Сохранить изменения?","Блокнот: Предупреждение", MB_YESNOCANCEL);

    if (Res == IDCANCEL) return;                // если нажато "Отмена" возвращаемся
    if (Res == IDYES) FileSaveClick(0);         // если нажато "Да" вызываем процедуру сохранения файла
                                                // если нажато "Нет" ничего не делаем
   }

  OpenDialog->FileName = "";
  OpenDialog->Title = "Открыть";                     // устанавливаем имя диалога
  if (OpenDialog->Execute())                         //вызываем диалог сохранения файла
  {
    if (Memo->Lines->Count > 0) Memo->Clear();      // если в поле "Мемо" есть строки, то удаляем их
    Memo->Lines->LoadFromFile(OpenDialog->FileName); // загружаем выбранный файл
    SaveDialog->FileName = OpenDialog->FileName;     // запоминаем имя файла для сохранения







    int i;

  //создание "истории" открытия файлов
  for (i = 0; i< 4; i++)
    if (FilesName[i] == "<empty>")
   {
    FilesName[i] = OpenDialog->FileName;
    break;
   }


   if (i == 4)
    {
      FilesName[3] = FilesName[2];
      FilesName[2] = FilesName[1];
      FilesName[1] = FilesName[0];
      FilesName[0] = OpenDialog->FileName;
    }

   F1->Caption = FilesName[0];
   F2->Caption = FilesName[1];
   F3->Caption = FilesName[2];
   F4->Caption = FilesName[3];





  }
}


//---------------------------------------------------------------------------
void __fastcall TBlock::FileSaveClick(TObject *Sender)
{
  SaveDialog->Title = "Сохранить";       // устанавливаем имя диалога
  if (SaveDialog->FileName != "")        // если у нас есть имя файла, сохраняем файл
   {
    Memo->Lines->SaveToFile(SaveDialog->FileName);
    Memo->Modified = false;  // убираем флаг изменения тектста, так как текст мы сохранили
   }
   else
    FileSaveAsClick(Sender);      // если у нас нет имени файла (т.е. файл новый) вызываем процедуру
                                  // сохранения под другим именем
}



//---------------------------------------------------------------------------
void __fastcall TBlock::FileSaveAsClick(TObject *Sender)
{
  SaveDialog->Title = "Сохранить как";       // устанавливаем имя диалога
  if (SaveDialog->Execute())        // вызываем диалог сохранения файла под новым именем
   {
    Memo->Lines->SaveToFile(SaveDialog->FileName);
    Memo->Modified = false;              // убираем флаг изменения текста, так как текст мы сохранили
   }
}


//пункт меню отмены изменений
//---------------------------------------------------------------------------
void __fastcall TBlock::EditUndoClick(TObject *Sender)
{
  SendMessage(Memo->Handle, WM_UNDO, 0, 0);  // вызываем отмену изменений
}



//пункт меню "перенос"
//---------------------------------------------------------------------------
void __fastcall TBlock::EditWordWrapClick(TObject *Sender)
{
  Memo->WordWrap = !Memo->WordWrap;        // меняем свойство TMemo::WordWrap
  EditWordWrap->Checked = Memo->WordWrap;  //Устанавливаем в меню флажок, если
                                           //у нас TMemo->WordWrap = true

  if (Memo->WordWrap) Memo->ScrollBars = ssVertical; //Если у нас включен перенос,
                                // то выводим только вертикальную полосу прокрутки
   else
    Memo->ScrollBars = ssBoth;   // иначе выводим обе полосы прокрутки
}


//---------------------------------------------------------------------------
void __fastcall TBlock::PrintButtonClick(TObject *Sender)     //выводим диалог печати
{
 if (PrintDialog1->Execute()) Memo->Print(Block->Caption);   //если нажато ОК печатаем
}


//---------------------------------------------------------------------------
void __fastcall TBlock::FontDClick(TObject *Sender)      //выводим диалог выбора шрифта
{
 if (FontDialog1->Execute()) Memo->Font = FontDialog1->Font;    //если нажато ОК меняем шрифт
}


//---------------------------------------------------------------------------
void __fastcall TBlock::OnHint(TObject* Sender)         // обработка подсказок
{
  StatusBar->SimpleText = Application->Hint;
}


//---------------------------------------------------------------------------
void __fastcall TBlock::FormCreate(TObject *Sender)         //создание формы
{
  Application->OnHint = OnHint;
}



//---------------------------------------------------------------------------
void __fastcall TBlock::F4Click(TObject *Sender)   //открытие файлов из "истории"
{
  int n;
  if (Sender == F1) n = 0;
  if (Sender == F2) n = 1;
  if (Sender == F3) n = 2;
  if (Sender == F4) n = 3;


 if (FilesName[n] != "<empty>")
 {
 if (Memo->Modified)                           // Если текст изменен
   {
    int Res = Application->MessageBox(          // вызываем диалоговое окно
      "Текущий файл изменен. Сохранить изменения?","Блокнот: Предупреждение", MB_YESNOCANCEL);

    if (Res == IDCANCEL) return;                // если нажато "Отмена" возвращаемся
    if (Res == IDYES) FileSaveClick(0);         // если нажато "Да" вызываем процедуру сохранения файла
                                                // если нажато "Нет" ничего не делаем
   }
   Memo->Lines->LoadFromFile(FilesName[n]); //загружаем из файла
   }
}




//---------------------------------------------------------------------------
void __fastcall TBlock::FormActivate(TObject *Sender)     //инициализация программы
{

//считываем список истории файлов
TIniFile *RegFile;
  RegFile = new TIniFile(ExtractFilePath(Application->ExeName) + "prog.ini"); //открываем ini файл

  FilesName[0] = RegFile->ReadString("Names", "1", "<empty>");
  FilesName[1] = RegFile->ReadString("Names", "2", "<empty>");
  FilesName[2] = RegFile->ReadString("Names", "3", "<empty>");
  FilesName[3] = RegFile->ReadString("Names", "4", "<empty>");

 RegFile->Free();

   F1->Caption = FilesName[0];
   F2->Caption = FilesName[1];
   F3->Caption = FilesName[2];
   F4->Caption = FilesName[3];




}
//---------------------------------------------------------------------------



void __fastcall TBlock::FormClose(TObject *Sender, TCloseAction &Action)     //выход из формы
{

//записываем историю файлов
  TIniFile *RegFile;
  RegFile = new TIniFile(ExtractFilePath(Application->ExeName)+ "prog.ini"); //открываем ini файл

  RegFile->WriteString("Names", "1", FilesName[0]);
  RegFile->WriteString("Names", "2", FilesName[1]);
  RegFile->WriteString("Names", "3", FilesName[2]);
  RegFile->WriteString("Names", "4", FilesName[3]);

  RegFile->Free();        
}
//---------------------------------------------------------------------------



void __fastcall TBlock::FormulaButtonClick(TObject *Sender)      //вставка из буфера
{
 if (FormulaForm->ShowModal() == mrOk) Memo->PasteFromClipboard();
        
}
//---------------------------------------------------------------------------


void __fastcall TBlock::HelpAboutClick(TObject *Sender)          //показать окно "о программе"
{
AboutBox->ShowModal();        
}
//---------------------------------------------------------------------------

void __fastcall TBlock::FormCloseQuery(TObject *Sender, bool &CanClose)    //выход
{
  if (Memo->Modified)                           // Если текст изменен
   {
    int Res = Application->MessageBox(          // вызываем диалоговое окно
      "Текущий файл изменен. Сохранить изменения?", "Блокнот: Предупреждение", MB_YESNOCANCEL);

    if (Res == IDCANCEL)                        // если нажато "Отмена" возвращаемся
     {
       CanClose = false;
       return;
     }
    if (Res == IDYES) FileSaveClick(0);         // если нажато "Да" вызываем процедуру сохранения файла
                                                // если нажато "Нет" ничего не делаем
   }

}
//---------------------------------------------------------------------------

void __fastcall TBlock::FileExitClick(TObject *Sender)   //пункт меню "выход"
{
 Close();        
}
//---------------------------------------------------------------------------

