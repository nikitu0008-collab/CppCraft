#include "../include/GuiGenerator.hpp"
#include "../include/LibraryList.hpp" // для списка библиотек
#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Browser.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <sstream>
#include <vector>
#include <string>

#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Check_Button.H>

// ========== Конструктор ==========
GuiGenerator::GuiGenerator() : mainWin(new Fl_Window(800, 500, "Cpp Craft Code Generator (GUI)")) {
    mainWin->begin();

    int y = 10, x = 10, w = 100, h = 30, gap = 10;

    btnLibs   = new Fl_Button(x, y, w, h, "Libs");
    btnVars   = new Fl_Button(x + w + gap, y, w, h, "Variables");
    btnCycles = new Fl_Button(x + 2*(w+gap), y, w, h, "Cycles");
    btnSwitch = new Fl_Button(x + 3*(w+gap), y, w, h, "Switch");
    btnIf     = new Fl_Button(x + 4*(w+gap), y, w, h, "If");
    btnElseIf = new Fl_Button(x + 5*(w+gap), y, w, h, "Else If");

    y += h + gap;
    btnArray1D = new Fl_Button(x, y, w, h, "Array 1D");
    btnArray2D = new Fl_Button(x + w + gap, y, w, h, "Array 2D");
    btnDynArray= new Fl_Button(x + 2*(w+gap), y, w, h, "Dynamic arr");
    btnFunc    = new Fl_Button(x + 3*(w+gap), y, w, h, "Function");
    btnVector  = new Fl_Button(x + 4*(w+gap), y, w, h, "Vector");
    btnFstream = new Fl_Button(x + 5*(w+gap), y, w, h, "Fstream");
    btnOOP     = new Fl_Button(x + 6*(w+gap), y, w, h, "OOP");

    y += h + gap;
    btnPreview = new Fl_Button(x, y, 120, h, "Preview Code");
    btnSave    = new Fl_Button(x + 130, y, 120, h, "Save & Exit");
    btnExit    = new Fl_Button(x + 260, y, 120, h, "Exit (no save)");

    y += h + gap;
    previewBuffer = new Fl_Text_Buffer();
    previewDisplay = new Fl_Text_Display(x, y, 680, 300);
    previewDisplay->buffer(previewBuffer);
    previewDisplay->textfont(FL_COURIER);
    previewDisplay->textsize(12);

    btnLibs->callback(cb_libs, this);
    btnVars->callback(cb_vars, this);
    btnCycles->callback(cb_cycles, this);
    btnSwitch->callback(cb_switch, this);
    btnIf->callback(cb_if, this);
    btnElseIf->callback(cb_elseif, this);
    btnArray1D->callback(cb_array1d, this);
    btnArray2D->callback(cb_array2d, this);
    btnDynArray->callback(cb_dynarray, this);
    btnFunc->callback(cb_func, this);
    btnVector->callback(cb_vector, this);
    btnFstream->callback(cb_fstream, this);
    btnOOP->callback(cb_oop, this);
    btnPreview->callback(cb_preview, this);
    btnSave->callback(cb_save, this);
    btnExit->callback(cb_exit, this);

    mainWin->end();
    mainWin->resizable(mainWin);
}

auto GuiGenerator::run() -> void {
    mainWin->show();
    Fl::run();
}

auto GuiGenerator::updatePreview() -> void {
    std::string code = gen.getCodePreview();
    previewBuffer->text(code.c_str());
}

// ========== Статические колбэки ==========
auto GuiGenerator::cb_libs(Fl_Widget*, void* data) -> void { ((GuiGenerator*)data)->showLibraryDialog(); }
auto GuiGenerator::cb_vars(Fl_Widget*, void* data) -> void { ((GuiGenerator*)data)->showVariableDialog(); }
auto GuiGenerator::cb_cycles(Fl_Widget*, void* data) -> void { ((GuiGenerator*)data)->showCycleDialog(); }
auto GuiGenerator::cb_switch(Fl_Widget*, void* data) -> void { ((GuiGenerator*)data)->showSwitchDialog(); }
auto GuiGenerator::cb_if(Fl_Widget*, void* data) -> void { ((GuiGenerator*)data)->showIfDialog(); }
auto GuiGenerator::cb_elseif(Fl_Widget*, void* data) -> void { ((GuiGenerator*)data)->showElseIfDialog(); }
auto GuiGenerator::cb_array1d(Fl_Widget*, void* data) -> void { ((GuiGenerator*)data)->showArray1DDialog(); }
auto GuiGenerator::cb_array2d(Fl_Widget*, void* data) -> void { ((GuiGenerator*)data)->showArray2DDialog(); }
auto GuiGenerator::cb_dynarray(Fl_Widget*, void* data) -> void { ((GuiGenerator*)data)->showDynamicArrayDialog(); }
auto GuiGenerator::cb_func(Fl_Widget*, void* data) -> void { ((GuiGenerator*)data)->showFunctionDialog(); }
auto GuiGenerator::cb_vector(Fl_Widget*, void* data) -> void { ((GuiGenerator*)data)->showVectorDialog(); }
auto GuiGenerator::cb_fstream(Fl_Widget*, void* data) -> void { ((GuiGenerator*)data)->showFstreamDialog(); }
auto GuiGenerator::cb_oop(Fl_Widget*, void* data) -> void { ((GuiGenerator*)data)->showOOPDialog(); }
auto GuiGenerator::cb_preview(Fl_Widget*, void* data) -> void { ((GuiGenerator*)data)->updatePreview(); }
auto GuiGenerator::cb_save(Fl_Widget*, void* data) -> void {
    auto* gui = (GuiGenerator*)data;
    const char* fname = fl_file_chooser("Save as", "*.cpp", "output.cpp");
    if (fname != nullptr) {
        std::string name = fname;
        if (name.find(".cpp") == std::string::npos) name += ".cpp";
        name = name.substr(0, name.find(".cpp"));
        gui->gen.writeToFile(name);
    }
    gui->mainWin->hide();
    exit(0);
}
auto GuiGenerator::cb_exit(Fl_Widget*, void* data) -> void {
    auto* gui = (GuiGenerator*)data;
    gui->mainWin->hide();
    exit(0);
}

// ========== ДИАЛОГ БИБЛИОТЕК ==========
auto GuiGenerator::showLibraryDialog() -> void {
    Fl_Window* win = new Fl_Window(400, 400, "Выбор библиотек");
    win->begin();

    Fl_Check_Browser* browser = new Fl_Check_Browser(10, 10, 380, 300);
    for (const auto& lib : library) {
        browser->add(lib.c_str());
    }

    Fl_Button* addBtn = new Fl_Button(100, 330, 100, 30, "Добавить");
    Fl_Button* closeBtn = new Fl_Button(220, 330, 100, 30, "Закрыть");

    struct LibData {
        Fl_Check_Browser* browser;
        GuiGenerator* gui;
    };
    auto* data = new LibData{browser, this};

    addBtn->callback([](Fl_Widget*, void* v) {
        auto* d = (LibData*)v;
        for (int i = 1; i <= d->browser->nitems(); ++i) {
            if (d->browser->checked(i)) {
                std::string lib = d->browser->text(i);
                d->gui->gen.addLibrary("#include " + lib);
            }
        }
        if (!d->gui->gen.has_iostream) d->gui->gen.addLibrary("#include <iostream>");
        if (!d->gui->gen.has_string)   d->gui->gen.addLibrary("#include <string>");
        d->gui->updatePreview();
    }, data);

    closeBtn->callback([](Fl_Widget*, void* v) { ((Fl_Window*)v)->hide(); }, win);

    win->end();
    win->set_modal();
    win->show();
}

// ========== ДИАЛОГ ПЕРЕМЕННЫХ ==========
void GuiGenerator::showVariableDialog() {
    Fl_Window* win = new Fl_Window(350, 250, "Добавить переменную");
    win->begin();

    Fl_Input* nameIn = new Fl_Input(120, 20, 200, 25, "Имя:");
    Fl_Choice* typeChoice = new Fl_Choice(120, 60, 200, 25, "Тип:");
    typeChoice->add("int|double|float|std::string|bool|auto");
    Fl_Input* valueIn = new Fl_Input(120, 100, 200, 25, "Значение:");

    Fl_Button* addBtn = new Fl_Button(70, 160, 100, 30, "Добавить");
    Fl_Button* closeBtn = new Fl_Button(190, 160, 100, 30, "Закрыть");

    struct VarData {
        Fl_Input* name;
        Fl_Choice* type;
        Fl_Input* value;
        GuiGenerator* gui;
    };
    auto* data = new VarData{nameIn, typeChoice, valueIn, this};

    addBtn->callback([](Fl_Widget*, void* v) {
        auto* d = (VarData*)v;
        std::string t = d->type->text(), n = d->name->value(), val = d->value->value();
        if (!n.empty()) {
            // Для bool преобразуем "true"/"false" как строки
            if (t == "bool" && val != "true" && val != "false") {
                val = (val == "1" ? "true" : "false");
            }
            d->gui->gen.addVariable(t, n, val);
            d->gui->updatePreview();
        }
    }, data);

    closeBtn->callback([](Fl_Widget*, void* v) { ((Fl_Window*)v)->hide(); }, win);

    win->end();
    win->set_modal();
    win->show();
}

// ========== ДИАЛОГ ЦИКЛОВ ==========
auto GuiGenerator::showCycleDialog() -> void {
    Fl_Window* win = new Fl_Window(300, 220, "Добавить цикл");
    win->begin();

    Fl_Check_Button* chkFor = new Fl_Check_Button(20, 20, 100, 30, "for");
    Fl_Check_Button* chkWhile = new Fl_Check_Button(20, 60, 100, 30, "while");
    Fl_Check_Button* chkDoWhile = new Fl_Check_Button(20, 100, 100, 30, "do-while");

    Fl_Button* addBtn = new Fl_Button(50, 160, 80, 30, "Добавить");
    Fl_Button* closeBtn = new Fl_Button(150, 160, 80, 30, "Закрыть");

    struct CycleData {
        Fl_Check_Button* forBtn;
        Fl_Check_Button* whileBtn;
        Fl_Check_Button* doWhileBtn;
        GuiGenerator* gui;
    };
    auto* data = new CycleData{.forBtn=chkFor, .whileBtn=chkWhile, .doWhileBtn=chkDoWhile, .gui=this};

    addBtn->callback([](Fl_Widget*, void* v) {
        auto* d = static_cast<CycleData*>(v);
        if (d->forBtn->value())      d->gui->gen.addCycle(1);
        if (d->whileBtn->value())    d->gui->gen.addCycle(2);
        if (d->doWhileBtn->value())  d->gui->gen.addCycle(3);
        d->gui->updatePreview();
    }, data);

    closeBtn->callback([](Fl_Widget*, void* v) { (static_cast<Fl_Window*>(v))->hide(); }, win);

    win->end();
    win->set_modal();
    win->show();
}

// ========== ДИАЛОГ SWITCH-CASE ==========
void GuiGenerator::showSwitchDialog() {
    Fl_Window* win = new Fl_Window(300, 180, "Switch-case");
    win->begin();

    Fl_Int_Input* switchCnt = new Fl_Int_Input(150, 20, 100, 25, "Кол-во switch:");
    Fl_Int_Input* caseCnt   = new Fl_Int_Input(150, 60, 100, 25, "Кол-во case:");

    Fl_Button* addBtn = new Fl_Button(60, 120, 80, 30, "Добавить");
    Fl_Button* closeBtn = new Fl_Button(160, 120, 80, 30, "Закрыть");

    struct SwitchData {
        Fl_Int_Input* sw;
        Fl_Int_Input* ca;
        GuiGenerator* gui;
    };
    auto* data = new SwitchData{switchCnt, caseCnt, this};

    addBtn->callback([](Fl_Widget*, void* v) {
        auto* d = (SwitchData*)v;
        int sw = atoi(d->sw->value()), ca = atoi(d->ca->value());
        if (sw > 0 && ca > 0) {
            d->gui->gen.addSwitchCase(sw, ca);
            d->gui->updatePreview();
        }
    }, data);

    closeBtn->callback([](Fl_Widget*, void* v) { ((Fl_Window*)v)->hide(); }, win);

    win->end();
    win->set_modal();
    win->show();
}

// ========== ДИАЛОГ IF ==========
auto GuiGenerator::showIfDialog() -> void {
    Fl_Window* win = new Fl_Window(300, 150, "If");
    win->begin();

    Fl_Int_Input* cntIn = new Fl_Int_Input(150, 20, 100, 25, "Кол-во if:");

    Fl_Button* addBtn = new Fl_Button(60, 80, 80, 30, "Добавить");
    Fl_Button* closeBtn = new Fl_Button(160, 80, 80, 30, "Закрыть");

    struct IfData {
        Fl_Int_Input* cnt;
        GuiGenerator* gui;
    };
    auto* data = new IfData{cntIn, this};

    addBtn->callback([](Fl_Widget*, void* v) {
        auto* d = (IfData*)v;
        int n = atoi(d->cnt->value());
        if (n > 0) {
            d->gui->gen.addIf(n);
            d->gui->updatePreview();
        }
    }, data);

    closeBtn->callback([](Fl_Widget*, void* v) { ((Fl_Window*)v)->hide(); }, win);

    win->end();
    win->set_modal();
    win->show();
}

// ========== ДИАЛОГ ELSE IF ==========
auto GuiGenerator::showElseIfDialog() -> void {
    Fl_Window* win = new Fl_Window(300, 150, "Else If");
    win->begin();

    Fl_Int_Input* cntIn = new Fl_Int_Input(150, 20, 100, 25, "Кол-во else-if:");

    Fl_Button* addBtn = new Fl_Button(60, 80, 80, 30, "Добавить");
    Fl_Button* closeBtn = new Fl_Button(160, 80, 80, 30, "Закрыть");

    struct ElseIfData {
        Fl_Int_Input* cnt;
        GuiGenerator* gui;
    };
    auto* data = new ElseIfData{cntIn, this};

    addBtn->callback([](Fl_Widget*, void* v) {
        auto* d = (ElseIfData*)v;
        int n = atoi(d->cnt->value());
        if (n > 0) {
            d->gui->gen.addElseIf(n);
            d->gui->updatePreview();
        }
    }, data);

    closeBtn->callback([](Fl_Widget*, void* v) { ((Fl_Window*)v)->hide(); }, win);

    win->end();
    win->set_modal();
    win->show();
}

// ========== ДИАЛОГ МАССИВ 1D ==========
auto GuiGenerator::showArray1DDialog() -> void {
    Fl_Window* win = new Fl_Window(300, 180, "Массив 1D");
    win->begin();

    Fl_Int_Input* cntIn = new Fl_Int_Input(150, 20, 100, 25, "Кол-во массивов:");
    Fl_Int_Input* sizeIn = new Fl_Int_Input(150, 60, 100, 25, "Размер:");

    Fl_Button* addBtn = new Fl_Button(60, 120, 80, 30, "Добавить");
    Fl_Button* closeBtn = new Fl_Button(160, 120, 80, 30, "Закрыть");

    struct Arr1DData {
        Fl_Int_Input* cnt;
        Fl_Int_Input* size;
        GuiGenerator* gui;
    };
    auto* data = new Arr1DData{cntIn, sizeIn, this};

    addBtn->callback([](Fl_Widget*, void* v) {
        auto* d = (Arr1DData*)v;
        int cnt = atoi(d->cnt->value()), sz = atoi(d->size->value());
        if (cnt > 0 && sz > 0) {
            d->gui->gen.addArray1D(cnt, sz);
            d->gui->updatePreview();
        }
    }, data);

    closeBtn->callback([](Fl_Widget*, void* v) { ((Fl_Window*)v)->hide(); }, win);

    win->end();
    win->set_modal();
    win->show();
}

// ========== ДИАЛОГ МАССИВ 2D ==========
auto GuiGenerator::showArray2DDialog() -> void {
    Fl_Window* win = new Fl_Window(300, 200, "Массив 2D");
    win->begin();

    Fl_Int_Input* cntIn = new Fl_Int_Input(150, 20, 100, 25, "Кол-во массивов:");
    Fl_Int_Input* rowsIn = new Fl_Int_Input(150, 60, 100, 25, "Строки:");
    Fl_Int_Input* colsIn = new Fl_Int_Input(150, 100, 100, 25, "Столбцы:");

    Fl_Button* addBtn = new Fl_Button(60, 140, 80, 30, "Добавить");
    Fl_Button* closeBtn = new Fl_Button(160, 140, 80, 30, "Закрыть");

    struct Arr2DData {
        Fl_Int_Input* cnt;
        Fl_Int_Input* rows;
        Fl_Int_Input* cols;
        GuiGenerator* gui;
    };
    auto* data = new Arr2DData{cntIn, rowsIn, colsIn, this};

    addBtn->callback([](Fl_Widget*, void* v) {
        auto* d = (Arr2DData*)v;
        int cnt = atoi(d->cnt->value());
        int r = atoi(d->rows->value());
        int c = atoi(d->cols->value());
        if (cnt > 0 && r > 0 && c > 0) {
            d->gui->gen.addArray2D(cnt, r, c);
            d->gui->updatePreview();
        }
    }, data);

    closeBtn->callback([](Fl_Widget*, void* v) { ((Fl_Window*)v)->hide(); }, win);

    win->end();
    win->set_modal();
    win->show();
}

// ========== ДИАЛОГ ДИНАМИЧЕСКИЙ МАССИВ ==========
auto GuiGenerator::showDynamicArrayDialog() -> void {
    Fl_Window* win = new Fl_Window(300, 180, "Динамический массив");
    win->begin();

    Fl_Int_Input* cntIn = new Fl_Int_Input(150, 20, 100, 25, "Кол-во массивов:");
    Fl_Int_Input* sizeIn = new Fl_Int_Input(150, 60, 100, 25, "Размер:");

    Fl_Button* addBtn = new Fl_Button(60, 120, 80, 30, "Добавить");
    Fl_Button* closeBtn = new Fl_Button(160, 120, 80, 30, "Закрыть");

    struct DynArrData {
        Fl_Int_Input* cnt;
        Fl_Int_Input* size;
        GuiGenerator* gui;
    };
    auto* data = new DynArrData{cntIn, sizeIn, this};

    addBtn->callback([](Fl_Widget*, void* v) {
        auto* d = (DynArrData*)v;
        int cnt = atoi(d->cnt->value());
        int sz = atoi(d->size->value());
        if (cnt > 0 && sz > 0) {
            d->gui->gen.addDynamicArray(cnt, sz);
            d->gui->updatePreview();
        }
    }, data);

    closeBtn->callback([](Fl_Widget*, void* v) { ((Fl_Window*)v)->hide(); }, win);

    win->end();
    win->set_modal();
    win->show();
}

// ========== ДИАЛОГ ФУНКЦИИ ==========
auto GuiGenerator::showFunctionDialog() -> void{
    Fl_Window* win = new Fl_Window(400, 250, "Функция");
    win->begin();

    Fl_Choice* retChoice = new Fl_Choice(150, 20, 200, 25, "Тип возврата:");
    retChoice->add("void|int|double|float|bool|std::string");
    Fl_Input* nameIn = new Fl_Input(150, 60, 200, 25, "Имя функции:");
    Fl_Input* paramsIn = new Fl_Input(150, 100, 200, 25, "Параметры (int a, ...):");

    Fl_Button* addBtn = new Fl_Button(80, 160, 100, 30, "Добавить");
    Fl_Button* closeBtn = new Fl_Button(200, 160, 100, 30, "Закрыть");

    struct FuncData {
        Fl_Choice* ret;
        Fl_Input* name;
        Fl_Input* params;
        GuiGenerator* gui;
    };
    auto* data = new FuncData{retChoice, nameIn, paramsIn, this};

    addBtn->callback([](Fl_Widget*, void* v) {
        auto* d = (FuncData*)v;
        std::string ret = d->ret->text();
        std::string name = d->name->value();
        std::string params = d->params->value();
        if (!name.empty()) {
            d->gui->gen.addFunction(ret, name, params);
            d->gui->updatePreview();
        }
    }, data);

    closeBtn->callback([](Fl_Widget*, void* v) { ((Fl_Window*)v)->hide(); }, win);

    win->end();
    win->set_modal();
    win->show();
}

// ========== ДИАЛОГ VECTOR ==========
auto GuiGenerator::showVectorDialog() -> void {
    Fl_Window* win = new Fl_Window(350, 200, "std::vector");
    win->begin();

    Fl_Input* nameIn = new Fl_Input(120, 20, 200, 25, "Имя вектора:");
    Fl_Choice* typeChoice = new Fl_Choice(120, 60, 200, 25, "Тип:");
    typeChoice->add("int|double|float|std::string");
    Fl_Int_Input* sizeIn = new Fl_Int_Input(120, 100, 200, 25, "Размер:");

    Fl_Button* addBtn = new Fl_Button(70, 150, 80, 30, "Добавить");
    Fl_Button* closeBtn = new Fl_Button(170, 150, 80, 30, "Закрыть");

    struct VecData {
        Fl_Input* name;
        Fl_Choice* type;
        Fl_Int_Input* size;
        GuiGenerator* gui;
    };
    auto* data = new VecData{nameIn, typeChoice, sizeIn, this};

    addBtn->callback([](Fl_Widget*, void* v) {
        auto* d = (VecData*)v;
        std::string name = d->name->value();
        std::string type = d->type->text();
        int sz = atoi(d->size->value());
        if (!name.empty() && sz > 0) {
            d->gui->gen.addVector(name, type, sz);
            d->gui->updatePreview();
        }
    }, data);

    closeBtn->callback([](Fl_Widget*, void* v) { ((Fl_Window*)v)->hide(); }, win);

    win->end();
    win->set_modal();
    win->show();
}

// ========== ДИАЛОГ FSTREAM ==========
auto GuiGenerator::showFstreamDialog() -> void {
    Fl_Window* win = new Fl_Window(400, 220, "Fstream");
    win->begin();

    Fl_Choice* typeChoice = new Fl_Choice(150, 20, 200, 25, "Тип:");
    typeChoice->add("fstream|ofstream|ifstream");
    Fl_Input* objIn = new Fl_Input(150, 60, 200, 25, "Имя объекта:");
    Fl_Input* fileIn = new Fl_Input(150, 100, 200, 25, "Имя файла:");

    Fl_Button* addBtn = new Fl_Button(80, 150, 100, 30, "Добавить");
    Fl_Button* closeBtn = new Fl_Button(200, 150, 100, 30, "Закрыть");

    struct FstreamData {
        Fl_Choice* type;
        Fl_Input* obj;
        Fl_Input* file;
        GuiGenerator* gui;
    };
    auto* data = new FstreamData{typeChoice, objIn, fileIn, this};

    addBtn->callback([](Fl_Widget*, void* v) {
        auto* d = (FstreamData*)v;
        std::string type = d->type->text();
        std::string obj = d->obj->value();
        std::string file = d->file->value();
        if (!obj.empty()) {
            int t = (type == "fstream") ? 1 : (type == "ofstream" ? 2 : 3);
            d->gui->gen.addFstream(t, obj, file);
            d->gui->updatePreview();
        }
    }, data);

    closeBtn->callback([](Fl_Widget*, void* v) { ((Fl_Window*)v)->hide(); }, win);

    win->end();
    win->set_modal();
    win->show();
}

// ========== ДИАЛОГ ООП (CLASS / STRUCT) ==========
auto GuiGenerator::showOOPDialog() -> void {
    Fl_Window* win = new Fl_Window(500, 400, "ООП (Class / Struct)");
    win->begin();

    Fl_Choice* kindChoice = new Fl_Choice(150, 20, 200, 25, "Тип:");
    kindChoice->add("class|struct");
    Fl_Input* nameIn = new Fl_Input(150, 60, 200, 25, "Имя:");
    Fl_Choice* accessChoice = new Fl_Choice(150, 100, 200, 25, "Доступ (по умолч.)");
    accessChoice->add("public|private");
    Fl_Text_Editor* membersEditor = new Fl_Text_Editor(50, 150, 400, 150);
    membersEditor->buffer(new Fl_Text_Buffer());
    membersEditor->textfont(FL_COURIER);
    membersEditor->textsize(12);
    Fl_Box* hint = new Fl_Box(50, 310, 400, 25, "Введите члены (каждый с новой строки)");

    Fl_Button* addBtn = new Fl_Button(120, 350, 100, 30, "Добавить");
    Fl_Button* closeBtn = new Fl_Button(280, 350, 100, 30, "Закрыть");

    struct OOPData {
        Fl_Choice* kind;
        Fl_Input* name;
        Fl_Choice* access;
        Fl_Text_Editor* members;
        GuiGenerator* gui;
    };
    auto* data = new OOPData{kindChoice, nameIn, accessChoice, membersEditor, this};

    addBtn->callback([](Fl_Widget*, void* v) {
        auto* d = (OOPData*)v;
        std::string kind = d->kind->text();
        std::string name = d->name->value();
        std::string access = d->access->text();
        if (name.empty()) return;

        // Разбиваем текст на строки
        std::string text = d->members->buffer()->text();
        std::vector<std::string> lines;
        std::istringstream iss(text);
        std::string line;
        while (std::getline(iss, line)) {
            if (!line.empty()) lines.push_back(line);
        }

        bool isPublic = (access == "public");
        if (kind == "class") {
            d->gui->gen.addClass(name, isPublic, lines);
        } else {
            d->gui->gen.addStruct(name, isPublic, lines);
        }
        d->gui->updatePreview();
    }, data);

    closeBtn->callback([](Fl_Widget*, void* v) { ((Fl_Window*)v)->hide(); }, win);

    win->end();
    win->set_modal();
    win->show();
}
