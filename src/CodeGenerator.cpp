#include "../include/CodeGenerator.hpp"
#include "../include/LibraryList.hpp"
#include <math.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <print>
#include <cstdlib>
#include <algorithm>

// ===== Вспомогательная функция очистки экрана =====
auto CodeGenerator::funcClear() -> void {
#ifdef _WIN32
    system("cls");
#elif defined(__linux__)
    system("clear");
#endif
}

auto CodeGenerator::printMenu() -> void {
    std::print( "|===================== STANDART LIBRARY C++26 =====================|"
                " 1:<algorithm>   2:<array>       3:<atomic>       4:<barrier>      5:<bitset>       6:<bit>          7:<chrono>       8:<complex>"
                " 9:<concepts>   10:<condition_variable> 11:<coroutine>   12:<deque>      13:<exception>   14:<execution>   15:<forward_list> 16:<format>"
                "17:<fstream>    18:<functional> 19:<future>      20:<initializer_list> 21:<iomanip>     22:<ios>         23:<iosfwd>      24:<iostream>"
                "25:<istream>    26:<iterator>   27:<latch>       28:<limits>      29:<list>        30:<locale>      31:<map>         32:<memory>"
                "33:<memory_resource> 34:<mutex>       35:<new>         36:<numeric>     37:<optional>    38:<ostream>     39:<queue>       40:<random>"
                "41:<ranges>     42:<ratio>      43:<regex>       44:<scoped_allocator> 45:<set>         46:<shared_mutex> 47:<sstream>     48:<stack>"
                "49:<stdexcept>  50:<streambuf>  51:<stop_token>  52:<string>      53:<string_view> 54:<system_error> 55:<thread>      56:<tuple>"
                "57:<type_traits> 58:<typeindex>  59:<typeinfo>    60:<unordered_map> 61:<unordered_set> 62:<utility>     63:<valarray>    64:<variant>"
                "65:<vector>     66:<version>    67:<charconv>    68:<compare>     69:<cassert>     70:<cctype>      71:<cerrno>      72:<cfenv>"
                "73:<cfloat>     74:<cinttypes>  75:<ciso646>     76:<climits>     77:<clocale>     78:<cmath>       79:<cstdbool>    80:<cstddef>"
                "81:<cstdint>    82:<cstdio>     83:<cstdlib>     84:<cstring>     85:<ctgmath>     86:<cuchar>      87:<cwchar>      88:<cwctype>"
                "89:<ccomplex>"
                "|=========================================================|"
                "Enter library numbers or name <name> (1-89):");
}

// ===== Конструктор =====
CodeGenerator::CodeGenerator()
    : has_iostream(false), has_string(false), col_switch(-1), col_case(-1), col_if(-1), col_else_if(-1) {}

// ===== Старые методы (консольные) =====
void CodeGenerator::processLibraryInput() {
    has_iostream = false;
    has_string = false;
    printMenu();
    std::cin.ignore(1024, '\n');
    std::string input;
    std::getline(std::cin, input);

    if (!input.empty() && input[0] == '<') {
        vector_library.push_back("#include " + input);
        if (input == "<iostream>") has_iostream = true;
        if (input == "<string>")   has_string = true;
    } else {
        std::stringstream ss_lib(input);
        int lib_num = 0;
        while (ss_lib >> lib_num) {
            if (lib_num >= 1 && lib_num <= static_cast<int>(library.size())) {
                vector_library.push_back("#include " + library[lib_num - 1]);
            }
        }
    }

    for (const auto& inc : vector_library) {
        if (inc == "#include <iostream>") has_iostream = true;
        if (inc == "#include <string>")   has_string = true;
    }

    if (!has_iostream) { vector_library.emplace_back("#include <iostream>"); }
    if (!has_string) { vector_library.emplace_back("#include <string>"); }

    funcClear();
}

auto CodeGenerator::processVariables() -> void {
    int col_variable = 0;
    while (col_variable <= 0) {
        std::println("col variable: ");
        std::cin >> col_variable;
        if (col_variable <= 0) std::println("col_variable incorrected");
    }
    for (int i = 0; i < col_variable; ++i) {
        int type_variable = 0;
        while (type_variable < 1 || type_variable > 6) {
            std::print("type: [1]int [2]double [3]float [4]string [5]bool [6]auto\n(Enter num)\n:_>");
            std::cin >> type_variable;
            if (type_variable < 1 || type_variable > 6) {
                std::println("type error's, return type");
                funcClear();
            }
        }
        std::string name_variable;
        std::print("[{}]-name\n:_> ", i+1);
        std::cin >> name_variable;

        Variable var;
        var.name = name_variable;

        if (type_variable == 1) {
            int val = 0;
            std::print("variable[{}]- {} = meaning[int]? \n :_>", i+1, name_variable);
            std::cin >> val;
            var.type = "int";
            var.value = std::to_string(val);
            variables_variable.push_back(var);
            vector_variable.push_back("int " + name_variable + " = " + std::to_string(val) + ";");
        } else if (type_variable == 2) {
            double val = NAN;
            std::print("variable[{}]- {} = meaning[double]? \n :_>", i+1, name_variable);
            std::cin >> val;
            var.type = "double";
            var.value = std::to_string(val);
            variables_variable.push_back(var);
            vector_variable.push_back("double " + name_variable + " = " + std::to_string(val) + ";");
        } else if (type_variable == 3) {
            float val = NAN;
            std::print("variable[{}]- {} = meaning[float]? \n :_>", i+1, name_variable);
            std::cin >> val;
            var.type = "float";
            var.value = std::to_string(val);
            variables_variable.push_back(var);
            vector_variable.push_back("float " + name_variable + " = " + std::to_string(val) + ";");
        } else if (type_variable == 4) {
            std::string val;
            std::print("variable[{}]- {} = meaning[string]? \n :_>", i+1, name_variable);
            std::cin >> val;
            var.type = "std::string";
            var.value = "\"" + val + "\"";
            variables_variable.push_back(var);
            vector_variable.push_back("std::string " + name_variable + " = \"" + val + "\";");
        } else if (type_variable == 5) {
            int ans = 0;
            std::print("variable[{}]- {} = meaning[bool]? \n :_>", i+1, name_variable);
            std::cin >> ans;
            var.type = "bool";
            if (ans == 1) {
                var.value = "true";
                vector_variable.push_back("bool " + name_variable + " = true;");
            } else {
                var.value = "false";
                vector_variable.push_back("bool " + name_variable + " = false;");
            }
            variables_variable.push_back(var);
        } else if (type_variable == 6) {
            std::string val;
            std::println("variable[{}] - {} = meaning[AUTO]? (if meaning string, writing) \" \" \n :_>", i, name_variable);
            std::cin >> val;
            var.type = "auto";
            var.value = val;
            variables_variable.push_back(var);
            vector_variable.push_back("auto " + name_variable + " = " + val + ";");
        }
    }
    funcClear();
}

auto CodeGenerator::processCycles() -> void {
    std::string answer_cycles;
    std::print("cycles: [1]for [2]while [3]do-while\n:_>");
    std::cin.ignore(1024, '\n');
    std::getline(std::cin, answer_cycles);

    std::vector<int> selected_numbers_cycles;
    std::stringstream ss_cycles(answer_cycles);
    int num = 0;
    while (ss_cycles >> num) {
        if (num > 0 && num <= 3) {
            selected_numbers_cycles.push_back(num);
        }
    }

    for (const size_t sel : selected_numbers_cycles) {
        if (sel == 1) {
            vector_cycles.push_back("for(size_t i = 0; i < ...; i++) {");
            vector_cycles.push_back("    //code_cycles");
            vector_cycles.push_back("}");
        } else if (sel == 2) {
            vector_cycles.push_back("while(/*condition*/) {");
            vector_cycles.push_back("    //what will happen");
            vector_cycles.push_back("}");
        } else if (sel == 3) {
            vector_cycles.push_back("do {");
            vector_cycles.push_back("    //what will happen");
            vector_cycles.push_back("} while(/*condition*/);");
        }
    }
    funcClear();
}

auto CodeGenerator::processSwitchCase() -> void {
    while (col_switch <= 0 || col_case <= 0) {
        std::print("col switch case:\n:_>");
        std::cin >> col_switch;
        if (col_switch < 0) { std::println("col_switch error's"); }
        std::print("col cases?\n:_>");
        std::cin >> col_case;
        if (col_case < 0) { std::println("col_case error's"); }
    }

    for (int i = 0; i < col_switch; ++i)
        vector_switch.push_back("switch() {");

    for (int j = 0; j < col_case; ++j) {
        vector_case.push_back("case " + std::to_string(j+1) + ":");
        vector_case.push_back("    break;");
    }
    vector_default.push_back("default:");
    vector_default.push_back("    break;");
    vector_default.push_back("}");

    funcClear();
}

auto CodeGenerator::processIf() -> void {
    while (col_if <= 0) {
        std::print("col-if() \n _>");
        std::cin >> col_if;
        if (col_if < 0) std::println("col-if error's");
    }
    for (size_t i = 0; i < col_if; i++) {
        vector_if.push_back("if() {");
        vector_if.push_back("    /*Condition*/");
        vector_if.push_back("}");
    }
    funcClear();
}

auto CodeGenerator::processElseIf() -> void {
    while (col_else_if <= 0) {
        std::print("col else-if()\n:_>");
        std::cin >> col_else_if;
        if (col_else_if < 0) {
            std::println("col-else if error's");
            continue;
        }
    }
    for (int i = 0; i < col_else_if; ++i) {
        vector_else_if.push_back("else if() {");
        vector_else_if.push_back("    /*Condition*/");
        vector_else_if.push_back("}");
    }
    funcClear();
}

void CodeGenerator::processArray1D() {
    int col_arr = 0;
    while (col_arr <= 0) {
        std::print("col arr\n:_>");
        std::cin >> col_arr;
        if (col_arr < 0) std::println("col_arr error's");
    }
    for (int i = 0; i < col_arr; ++i) {
        int size_arr = 0;
        while (size_arr <= 0) {
            std::print("size_arr[{}]\n:_>", i);
            std::cin >> size_arr;
            if (size_arr < 0) {
                std::println("size_arr error's");
                continue;
            }
        }
        vector_arr.push_back("int arr" + std::to_string(i) + "[" + std::to_string(size_arr) + "];");
    }
    funcClear();
}

auto CodeGenerator::processArray2D() -> void {
    int col_dimensional_arr = 0;
    while (col_dimensional_arr <= 0) {
        std::print("col arr[][]\n:_>");
        std::cin >> col_dimensional_arr;
        if (col_dimensional_arr <= 0) { 
            std::print("arr[][] incorected");
            continue;
        }
    }
    for (size_t i = 0; i < col_dimensional_arr; ++i) {
        int size_arr_d_1 = 0, size_arr_d_2 = 0;
        while (size_arr_d_1 <= 0 || size_arr_d_2 <= 0) {
            std::print("size[?][?] = ");
            std::cin >> size_arr_d_1 >> size_arr_d_2;
            if (size_arr_d_1 < 0 || size_arr_d_2 < 0) {
                std::println("size_arr[][] incorrected size[?][?]");
                continue;
            }
        }
        vector_dimensional_arr.push_back("int arr_" + std::to_string(i) + "[" + std::to_string(size_arr_d_1) + "][" + std::to_string(size_arr_d_2) + "];");
    }
    funcClear();
}

void CodeGenerator::processDynamicArray() {
    int col_dynamic_arr = 0;
    while (col_dynamic_arr <= 0) {
        std::print("col d_arr :_>");
        std::cin >> col_dynamic_arr;
        if (col_dynamic_arr < 0) { 
            std::println("error's col <= 0");
            continue;
        }
    }
    for (size_t i = 0; i < col_dynamic_arr; ++i) {
        int size_dynamic_arr = 0;
        while (size_dynamic_arr <= 0) {
            std::print("size {} arr = _", i+1);
            std::cin >> size_dynamic_arr;
            if (size_dynamic_arr < 0) std::println("error's size");
        }
        vector_dynamic_arr.push_back("int* arr_d_" + std::to_string(i) + " = new int[" + std::to_string(size_dynamic_arr) + "];");
        delete_dynamic_arr.push_back("delete[] arr_d_" + std::to_string(i) + ";");
    }
    funcClear();
}

auto CodeGenerator::processFunction() -> void {
    std::string ret_type, name, params;
    std::print("return type (void, int, double, float, string, bool): ");
    std::cin.ignore(1024, '\n');
    std::getline(std::cin, ret_type);
    std::print("Function name: ");
    std::getline(std::cin, name);
    std::print("Parameters (e.g., int a, double b): ");
    std::getline(std::cin, params);

    std::string func_code = "\n" + ret_type + " " + name + "(" + params + ") {\n";
    func_code += "    // Function implementation\n";

    if (ret_type != "void" && ret_type != "Void") {
        func_code += "    return ";
        if (ret_type == "int" || ret_type == "Int") func_code += "0";
        else if (ret_type == "double" || ret_type == "Double" || ret_type == "float" || ret_type == "Float") func_code += "0.0";
        else if (ret_type == "bool" || ret_type == "Bool") func_code += "false";
        else if (ret_type == "string" || ret_type == "String") func_code += "\"\"";
        else func_code += "{}";
        func_code += ";\n";
    }
    func_code += "}\n";
    vector_function.push_back(func_code);
    funcClear();
}

auto CodeGenerator::processVector() -> void {
    std::string name_vector, type_vector;
    std::print("name vector :_>");
    std::cin >> name_vector;
    while (type_vector != "int" && type_vector != "float" && type_vector != "double" && type_vector != "string") {
        std::print("type vector = (int, float, double, string)\n:_>");
        std::cin >> type_vector;
        if (type_vector != "int" && type_vector != "float" && type_vector != "double" && type_vector != "string") {
            std::println("writing type error's");
            continue;
        }
    }
    int size_vector = 0;
    while (size_vector <= 0) {
        std::print("size vector:\n:_>");
        std::cin >> size_vector;
        if (size_vector < 0) { 
            std::println("size vector incorrected! \n size vector < 0");
            continue;
        }
    }
    vector_vectorov.push_back("std::vector<" + type_vector + "> " + name_vector + "(" + std::to_string(size_vector) + ");");
    funcClear();
}

auto CodeGenerator::processFstream() -> void {
    bool has_fstream = false;
    for (const auto& inc : vector_library) {
        if (inc == "#include <fstream>") { has_fstream = true; break; }
    }
    if (!has_fstream) { vector_library.push_back("#include <fstream>"); }

    int answer_fstream = 0;
    while (answer_fstream < 1 || answer_fstream > 3) {
        std::print("1.fstream 2.ofstream 3.ifstream\n:_>");
        std::cin >> answer_fstream;
        if (answer_fstream < 1 || answer_fstream > 3) {
            std::cerr << "Enter Error" << std::endl;
            funcClear();
        }
    }
    if (answer_fstream == 1) {
        std::string fstream, fstream_file;
        std::print("write name fstream [...]()\n:_> ");
        std::cin >> fstream;
        std::print("create file? fstream {} (...)? (if no ENTER)\n:_>", fstream);
        std::cin >> fstream_file;
        vector_fstream.push_back("fstream " + fstream + "(" + fstream_file + ");");
    } else if (answer_fstream == 2) {
        std::string stream_ofstream, listing_file_name;
        std::print("write name ofstream [...]()\n:_>");
        std::cin >> stream_ofstream;
        std::print("listing file? (if no ENTER)\n:_>");
        std::cin >> listing_file_name;
        vector_ofstream.push_back("ofstream " + stream_ofstream + "(" + listing_file_name + ");");
    } else if (answer_fstream == 3) {
        std::string listing_ifstream, write_file;
        std::print("write name ifstream [...]() \n :_>");
        std::cin >> listing_ifstream;
        std::print("write file? (if no ENTER)\n:_>");
        std::cin >> write_file;
        vector_ifstream.push_back("ifstream " + listing_ifstream + "(" + write_file + ");");
    }
    funcClear();
}

auto CodeGenerator::processOOP() -> void {
    int answer_OOP = -1;
    while (answer_OOP != 0) {
        std::println("|=======================|#|");
        std::println("|1.class 2.struct 0.exit|#|");
        std::println("|=======================|#|");
        std::println("          answer: ");
        std::cin >> answer_OOP;
        std::cin.ignore(1024, '\n');

        if (answer_OOP == 1) {
            funcClear();
            std::string name_class;
            std::print("class name\n:_>");
            std::cin >> name_class;
            vector_class.push_back("class " + name_class + "{");

            int public_or_private = 0;
            std::print("1.public or 2.private?\n:_>");
            while (public_or_private != 1 && public_or_private != 2) {
                std::cin >> public_or_private;
                if (public_or_private != 1 && public_or_private != 2) {
                    std::cerr << "Enter Error" << std::endl;
                    std::cin.clear();
                }
            }
            if (public_or_private == 1) { vector_class.push_back("public:"); }
            else { vector_class.push_back("private:"); }

            std::cout << "if stop, Enter [STOP]\n";
            std::string anything_class;
            while (true) {
                std::getline(std::cin, anything_class);
                if (anything_class == "STOP") { break; }
                if (!anything_class.empty()) { vector_class.push_back(anything_class); }
            }
            vector_class.push_back("};");
        } else if (answer_OOP == 2) {
            funcClear();
            std::string name_struct;
            std::cout << "struct name\n:_> ";
            std::getline(std::cin, name_struct);
            vector_struct.push_back("struct " + name_struct + " {");

            int public_or_private = 0;
            std::cout << "1.public (default) or 2.private?\n:_> ";
            while (public_or_private != 1 && public_or_private != 2) {
                std::cin >> public_or_private;
                if (public_or_private != 1 && public_or_private != 2) {
                    std::cerr << "Enter Error" << std::endl;
                    std::cin.clear();
                }
            }
            std::cin.ignore(1024, '\n');
            if (public_or_private == 1) { vector_struct.push_back("public:"); }
            else { 
                vector_struct.push_back("private:");
            }
            std::cout << "if stop, Enter [STOP]\n";
            std::string anything_struct;
            while (true) {
                std::getline(std::cin, anything_struct);
                if (anything_struct == "STOP"){ break; }
                if (!anything_struct.empty()) { vector_struct.push_back(anything_struct); }
            }
            vector_struct.push_back("};");
        }
        funcClear();
    }
}

auto CodeGenerator::writeToFile(bool openAfterWrite) -> void {
    std::ofstream out(name_file + ".cpp");
    if (!out.is_open()) {
        std::cerr << "file not opening or creating" << std::endl;
        return;
    }

    for (const auto& line : vector_library) out << line << std::endl;
    for (const auto& line : vector_function) out << line << std::endl;
    for (const auto& line : vector_class)    out << line << std::endl;
    for (const auto& line : vector_struct)   out << line << std::endl;

    out << "int main() {" << std::endl;

    for (const auto& line : vector_variable)       out << "    " << line << std::endl;
    for (const auto& line : vector_cycles)         out << "    " << line << std::endl;
    for (const auto& line : vector_if)             out << "    " << line << std::endl;
    for (const auto& line : vector_else_if)        out << "    " << line << std::endl;
    for (const auto& line : vector_arr)            out << "    " << line << std::endl;
    for (const auto& line : vector_dimensional_arr)out << "    " << line << std::endl;
    for (const auto& line : vector_dynamic_arr)    out << "    " << line << std::endl;
    for (const auto& line : delete_dynamic_arr)    out << "    " << line << std::endl;
    for (const auto& line : vector_vectorov)       out << "    " << line << std::endl;
    for (const auto& line : vector_ifstream)       out << "    " << line << std::endl;
    for (const auto& line : vector_ofstream)       out << "    " << line << std::endl;
    for (const auto& line : vector_fstream)        out << "    " << line << std::endl;

    for (int sw = 0; sw < col_switch; ++sw) {
        if (sw < static_cast<int>(vector_switch.size()))
            out << "    " << vector_switch[sw] << std::endl;
        for (const auto& line : vector_case)    out << "        " << line << std::endl;
        for (const auto& line : vector_default) out << "        " << line << std::endl;
    }

    out << std::endl;
    out << "    return 0;" << std::endl;
    out << "}" << std::endl;
    out.close();

    if (openAfterWrite) {
        std::string command = "start " + name_file + ".cpp";
        system(command.c_str());
    }
}

void CodeGenerator::previewCode() {
    for (const auto& line : vector_library) std::cout << line << std::endl;
    for (const auto& line : vector_function) std::cout << line << std::endl;
    for (const auto& line : vector_class)    std::cout << line << std::endl;
    for (const auto& line : vector_struct)   std::cout << line << std::endl;

    std::cout << "int main() {" << std::endl;

    for (const auto& line : vector_variable)       std::cout << "    " << line << std::endl;
    for (const auto& line : vector_cycles)         std::cout << "    " << line << std::endl;
    for (const auto& line : vector_if)             std::cout << "    " << line << std::endl;
    for (const auto& line : vector_else_if)        std::cout << "    " << line << std::endl;
    for (const auto& line : vector_arr)            std::cout << "    " << line << std::endl;
    for (const auto& line : vector_dimensional_arr)std::cout << "    " << line << std::endl;
    for (const auto& line : vector_dynamic_arr)    std::cout << "    " << line << std::endl;
    for (const auto& line : delete_dynamic_arr)    std::cout << "    " << line << std::endl;
    for (const auto& line : vector_vectorov)       std::cout << "    " << line << std::endl;
    for (const auto& line : vector_ifstream)       std::cout << "    " << line << std::endl;
    for (const auto& line : vector_ofstream)       std::cout << "    " << line << std::endl;
    for (const auto& line : vector_fstream)        std::cout << "    " << line << std::endl;

    for (int sw = 0; sw < col_switch; ++sw) {
        if (sw < static_cast<int>(vector_switch.size()))
            std::cout << "    " << vector_switch[sw] << std::endl;
        for (const auto& line : vector_case)    std::cout << "        " << line << std::endl;
        for (const auto& line : vector_default) std::cout << "        " << line << std::endl;
    }

    std::cout << std::endl;
    std::cout << "    return 0;" << std::endl;
    std::cout << "}" << std::endl;
}

void CodeGenerator::deleteFileAndExit() {
    std::ofstream out(name_file + ".cpp");
    out.close();
    if (remove((name_file + ".cpp").c_str()) == 0)
        std::println("file deleted.");
    else
        std::println("file not deleted or searching");
    std::println("Bye...");
}

void CodeGenerator::run() {
    std::print("name file(don't write .cpp)\n:_>");
    std::getline(std::cin, name_file);

    int answer_Cpp_Craft_Project = -2;
    while (answer_Cpp_Craft_Project != 0 && answer_Cpp_Craft_Project != -1) {
        std::println("  >--------------------------------<  "
                     ">-----Cpp Craft Code By N.Y.RPO3-----<"
                     "  >--------------------------------<  "
                     "____________________________________"
                     "| [1]-libraries   [10]-function    |"
                     "| [2]-variables   [11]-vector      |"
                     "| [3]-cycles      [12]-fstream     |"
                     "| [4]-switch_case [13]-OOP         |"
                     "| [5]-if                           |"
                     "| [6]-else if   [-3]-exit no create|"
                     "| [7]-arr[]     [-2]-check result  "
                     "| [8]-arr[][]   [-1]-save and exit |"
                     "| [9]-d_arr     [ 0]-save and start|"
                     "|-----------------------------------|"
                     "|"
                     "L------------->answer: ");

        std::cin >> answer_Cpp_Craft_Project;
        funcClear();

        switch (answer_Cpp_Craft_Project) {
            case 1:  processLibraryInput(); break;
            case 2:  processVariables();    break;
            case 3:  processCycles();       break;
            case 4:  processSwitchCase();   break;
            case 5:  processIf();           break;
            case 6:  processElseIf();       break;
            case 7:  processArray1D();      break;
            case 8:  processArray2D();      break;
            case 9:  processDynamicArray(); break;
            case 10: processFunction();     break;
            case 11: processVector();       break;
            case 12: processFstream();      break;
            case 13: processOOP();          break;
            case 0:  writeToFile(true);     break;
            case -1: writeToFile(false);    break;
            case -2: previewCode();         break;
            case -3: deleteFileAndExit();   return;
            default: std::cerr << "choice error" << std::endl; break;
        }
        funcClear();
    }
}

// ===== НОВЫЕ МЕТОДЫ ДЛЯ GUI =====

void CodeGenerator::addLibrary(const std::string& includeLine) {
    vector_library.push_back(includeLine);
    if (includeLine == "#include <iostream>") has_iostream = true;
    if (includeLine == "#include <string>")   has_string = true;
}

void CodeGenerator::addVariable(const std::string& type, const std::string& name, const std::string& value) {
    Variable var{type, name, value};
    variables_variable.push_back(var);
    vector_variable.push_back(type + " " + name + " = " + value + ";");
}

void CodeGenerator::addCycle(int type) {
    if (type == 1) {
        vector_cycles.push_back("for(size_t i = 0; i < ...; i++) {");
        vector_cycles.push_back("    //code_cycles");
        vector_cycles.push_back("}");
    } else if (type == 2) {
        vector_cycles.push_back("while(/*condition*/) {");
        vector_cycles.push_back("    //what will happen");
        vector_cycles.push_back("}");
    } else if (type == 3) {
        vector_cycles.push_back("do {");
        vector_cycles.push_back("    //what will happen");
        vector_cycles.push_back("} while(/*condition*/);");
    }
}

void CodeGenerator::addSwitchCase(int switchCount, int caseCount) {
    col_switch = switchCount;
    col_case   = caseCount;
    vector_switch.clear();
    vector_case.clear();
    vector_default.clear();
    for (int i = 0; i < switchCount; ++i)
        vector_switch.push_back("switch() {");
    for (int j = 0; j < caseCount; ++j) {
        vector_case.push_back("case " + std::to_string(j+1) + ":");
        vector_case.push_back("    break;");
    }
    vector_default.push_back("default:");
    vector_default.push_back("    break;");
    vector_default.push_back("}");
}

void CodeGenerator::addIf(int count) {
    col_if = count;
    vector_if.clear();
    for (int i = 0; i < count; ++i) {
        vector_if.push_back("if() {");
        vector_if.push_back("    /*Condition*/");
        vector_if.push_back("}");
    }
}

void CodeGenerator::addElseIf(int count) {
    col_else_if = count;
    vector_else_if.clear();
    for (int i = 0; i < count; ++i) {
        vector_else_if.push_back("else if() {");
        vector_else_if.push_back("    /*Condition*/");
        vector_else_if.push_back("}");
    }
}

void CodeGenerator::addArray1D(int count, int size) {
    for (int i = 0; i < count; ++i)
        vector_arr.push_back("int arr" + std::to_string(i) + "[" + std::to_string(size) + "];");
}

void CodeGenerator::addArray2D(int count, int rows, int cols) {
    for (int i = 0; i < count; ++i)
        vector_dimensional_arr.push_back("int arr_" + std::to_string(i) + "[" + std::to_string(rows) + "][" + std::to_string(cols) + "];");
}

void CodeGenerator::addDynamicArray(int count, int size) {
    for (int i = 0; i < count; ++i) {
        vector_dynamic_arr.push_back("int* arr_d_" + std::to_string(i) + " = new int[" + std::to_string(size) + "];");
        delete_dynamic_arr.push_back("delete[] arr_d_" + std::to_string(i) + ";");
    }
}

void CodeGenerator::addFunction(const std::string& retType, const std::string& name, const std::string& params) {
    std::string func = "\n" + retType + " " + name + "(" + params + ") {\n";
    func += "    // Function implementation\n";
    if (retType != "void") {
        func += "    return ";
        if (retType == "int") func += "0";
        else if (retType == "double" || retType == "float") func += "0.0";
        else if (retType == "bool") func += "false";
        else if (retType == "std::string") func += "\"\"";
        else func += "{}";
        func += ";\n";
    }
    func += "}\n";
    vector_function.push_back(func);
}

void CodeGenerator::addVector(const std::string& name, const std::string& type, int size) {
    vector_vectorov.push_back("std::vector<" + type + "> " + name + "(" + std::to_string(size) + ");");
}

void CodeGenerator::addFstream(int type, const std::string& objName, const std::string& fileName) {
    bool has_fstream = false;
    for (const auto& inc : vector_library) {
        if (inc == "#include <fstream>") { has_fstream = true; break; }
    }
    if (!has_fstream) vector_library.push_back("#include <fstream>");

    if (type == 1) {
        vector_fstream.push_back("fstream " + objName + "(" + fileName + ");");
    } else if (type == 2) {
        vector_ofstream.push_back("ofstream " + objName + "(" + fileName + ");");
    } else if (type == 3) {
        vector_ifstream.push_back("ifstream " + objName + "(" + fileName + ");");
    }
}

void CodeGenerator::addClass(const std::string& className, bool isPublic, const std::vector<std::string>& members) {
    vector_class.push_back("class " + className + " {");
    vector_class.push_back(isPublic ? "public:" : "private:");
    for (const auto& m : members)
        vector_class.push_back("    " + m);
    vector_class.push_back("};");
}

void CodeGenerator::addStruct(const std::string& structName, bool isPublic, const std::vector<std::string>& members) {
    vector_struct.push_back("struct " + structName + " {");
    if (!isPublic) vector_struct.push_back("private:");
    for (const auto& m : members)
        vector_struct.push_back("    " + m);
    vector_struct.push_back("};");
}

std::string CodeGenerator::getCodePreview() const {
    std::ostringstream out;
    for (const auto& line : vector_library) out << line << "\n";
    for (const auto& line : vector_function) out << line << "\n";
    for (const auto& line : vector_class)    out << line << "\n";
    for (const auto& line : vector_struct)   out << line << "\n";

    out << "int main() {\n";
    for (const auto& line : vector_variable)       out << "    " << line << "\n";
    for (const auto& line : vector_cycles)         out << "    " << line << "\n";
    for (const auto& line : vector_if)             out << "    " << line << "\n";
    for (const auto& line : vector_else_if)        out << "    " << line << "\n";
    for (const auto& line : vector_arr)            out << "    " << line << "\n";
    for (const auto& line : vector_dimensional_arr)out << "    " << line << "\n";
    for (const auto& line : vector_dynamic_arr)    out << "    " << line << "\n";
    for (const auto& line : delete_dynamic_arr)    out << "    " << line << "\n";
    for (const auto& line : vector_vectorov)       out << "    " << line << "\n";
    for (const auto& line : vector_ifstream)       out << "    " << line << "\n";
    for (const auto& line : vector_ofstream)       out << "    " << line << "\n";
    for (const auto& line : vector_fstream)        out << "    " << line << "\n";

    for (int sw = 0; sw < col_switch; ++sw) {
        if (sw < static_cast<int>(vector_switch.size()))
            out << "    " << vector_switch[sw] << "\n";
        for (const auto& line : vector_case)    out << "        " << line << "\n";
        for (const auto& line : vector_default) out << "        " << line << "\n";
    }
    out << "\n    return 0;\n}\n";
    return out.str();
}

void CodeGenerator::writeToFile(const std::string& fileName) {
    std::ofstream out(fileName + ".cpp");
    if (!out.is_open()) {
        std::cerr << "Cannot create file " << fileName << ".cpp\n";
        return;
    }
    out << getCodePreview();
    out.close();
    std::cout << "File " << fileName << ".cpp saved.\n";
}
