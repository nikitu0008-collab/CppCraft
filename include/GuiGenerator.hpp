#ifndef GUIGENERATOR_HPP
#define GUIGENERATOR_HPP

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Check_Browser.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_File_Chooser.H>
#include <string>
#include <vector>

#include "CodeGenerator.hpp"

class GuiGenerator {
public:
    GuiGenerator();
    void run();

private:
    CodeGenerator gen;
    Fl_Window* mainWin;
    Fl_Text_Display* previewDisplay;
    Fl_Text_Buffer* previewBuffer;

    // Кнопки главного меню
    Fl_Button* btnLibs;
    Fl_Button* btnVars;
    Fl_Button* btnCycles;
    Fl_Button* btnSwitch;
    Fl_Button* btnIf;
    Fl_Button* btnElseIf;
    Fl_Button* btnArray1D;
    Fl_Button* btnArray2D;
    Fl_Button* btnDynArray;
    Fl_Button* btnFunc;
    Fl_Button* btnVector;
    Fl_Button* btnFstream;
    Fl_Button* btnOOP;
    Fl_Button* btnPreview;
    Fl_Button* btnSave;
    Fl_Button* btnExit;

    // Колбэки (статические)
    static void cb_libs(Fl_Widget*, void*);
    static void cb_vars(Fl_Widget*, void*);
    static void cb_cycles(Fl_Widget*, void*);
    static void cb_switch(Fl_Widget*, void*);
    static void cb_if(Fl_Widget*, void*);
    static void cb_elseif(Fl_Widget*, void*);
    static void cb_array1d(Fl_Widget*, void*);
    static void cb_array2d(Fl_Widget*, void*);
    static void cb_dynarray(Fl_Widget*, void*);
    static void cb_func(Fl_Widget*, void*);
    static void cb_vector(Fl_Widget*, void*);
    static void cb_fstream(Fl_Widget*, void*);
    static void cb_oop(Fl_Widget*, void*);
    static void cb_preview(Fl_Widget*, void*);
    static void cb_save(Fl_Widget*, void*);
    static void cb_exit(Fl_Widget*, void*);

    // Диалоги
    void showLibraryDialog();
    void showVariableDialog();
    void showCycleDialog();
    void showSwitchDialog();
    void showIfDialog();
    void showElseIfDialog();
    void showArray1DDialog();
    void showArray2DDialog();
    void showDynamicArrayDialog();
    void showFunctionDialog();
    void showVectorDialog();
    void showFstreamDialog();
    void showOOPDialog();

    // Вспомогательные методы обновления предпросмотра
    void updatePreview();
};

#endif // GUIGENERATOR_HPP
