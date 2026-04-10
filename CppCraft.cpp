#include <iostream>
#include <string>
#include <vector>
#include <print>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <fstream>
#ifdef __WiN32
    system("cls");
#endif
#ifdef __linux
    system("clear");
#endif
auto printMenu() -> void {
    std::println("|===================== STANDART LIBRARY C++26 =====================|");
    std::println(" 1:<algorithm>   2:<array>       3:<atomic>       4:<barrier>      5:<bitset>       6:<bit>          7:<chrono>       8:<complex>");
    std::println(" 9:<concepts>   10:<condition_variable> 11:<coroutine>   12:<deque>      13:<exception>   14:<execution>   15:<forward_list> 16:<format>");
    std::println("17:<fstream>    18:<functional> 19:<future>      20:<initializer_list> 21:<iomanip>     22:<ios>         23:<iosfwd>      24:<iostream>");
    std::println("25:<istream>    26:<iterator>   27:<latch>       28:<limits>      29:<list>        30:<locale>      31:<map>         32:<memory>");
    std::println("33:<memory_resource> 34:<mutex>       35:<new>         36:<numeric>     37:<optional>    38:<ostream>     39:<queue>       40:<random>");
    std::println("41:<ranges>     42:<ratio>      43:<regex>       44:<scoped_allocator> 45:<set>         46:<shared_mutex> 47:<sstream>     48:<stack>");
    std::println("49:<stdexcept>  50:<streambuf>  51:<stop_token>  52:<string>      53:<string_view> 54:<system_error> 55:<thread>      56:<tuple>");
    std::println("57:<type_traits> 58:<typeindex>  59:<typeinfo>    60:<unordered_map> 61:<unordered_set> 62:<utility>     63:<valarray>    64:<variant>");
    std::println("65:<vector>     66:<version>    67:<charconv>    68:<compare>     69:<cassert>     70:<cctype>      71:<cerrno>      72:<cfenv>");
    std::println("73:<cfloat>     74:<cinttypes>  75:<ciso646>     76:<climits>     77:<clocale>     78:<cmath>       79:<cstdbool>    80:<cstddef>");
    std::println("81:<cstdint>    82:<cstdio>     83:<cstdlib>     84:<cstring>     85:<ctgmath>     86:<cuchar>      87:<cwchar>      88:<cwctype>");
    std::println("89:<ccomplex>");
    std::println("|=========================================================|\n");
    std::println("Enter library numbers or name <name> (1-89):");
}
struct Variable {
    std::string type; 
    std::string name; 
    std::string value;
};
auto main() -> int {
    std::string write_file, ssbufer, struct_anything_string, class_struct, fstream_file, listing_file_name;
    std::string anything_class, stream_ofstream, listing_ifstream, anything_struct, stream, fstream, ifstream, ofstream, name_class, name_struct, command, type_vector, name_vector, variable_var, func_code, answer_cycles, numbering, name_variable;
    std::string variable_string, libName, input, name_file, answer, search = "#include <vector>", ret_type, name, params;
    
    int public_or_private = 0, size_vector = 0, answer_bool = 0, col_dynamic_arr = 0, col_dimensional_arr = 0, size_arr_d_1 = 0, size_arr_d_2 = 0, col_arr = 0, size_arr = 0, col_if = -1, col_else_if = -1; 
    int answer_fstream = 0, answer_OOP = -1, col_variable = 0, col_case = -1, col_switch = -1, choice = 0, variable_int = 0, type_variable = 0, answer_Cpp_Craft_Project = -2, num = 0, size_dynamic_arr = 0;
    
    double variable_double = 0;
    float variable_float = 0;
    
    std::stringstream ss_cycles, ss_lib;

    std::vector<std::string> vector_ofstream, vector_ifstream, cycles_for, cycles_while, cycles_do_while, vector_library, vector_switch, vector_case, vector_default, vector_if, vector_else_if;
    std::vector<std::string> vector_fstream, vector_class, vector_struct, vector_arr, vector_dimensional_arr, vector_dynamic_arr, delete_dynamic_arr, vector_function, vector_vectorov, vector_variable, vector_cycles;
    
    const std::vector<std::string> library = {"<algorithm>","<array>","<atomic>","<barrier>","<bitset>","<bit>","<chrono>","<complex>","<concepts>","<condition_variable>","<coroutine>","<deque>","<exception>","<execution>","<forward_list>","<format>","<fstream>","<functional>","<future>","<initializer_list>","<iomanip>","<ios>","<iosfwd>","<iostream>","<istream>","<iterator>","<latch>","<limits>","<list>","<locale>","<map>","<memory>","<memory_resource>","<mutex>","<new>","<numeric>","<optional>","<ostream>","<queue>","<random>","<ranges>","<ratio>","<regex>","<scoped_allocator>","<set>","<shared_mutex>","<sstream>","<stack>","<stdexcept>","<streambuf>","<stop_token>","<string>","<string_view>","<system_error>","<thread>","<tuple>","<type_traits>","<typeindex>","<typeinfo>","<unordered_map>","<unordered_set>","<utility>","<valarray>","<variant>","<vector>","<version>","<charconv>","<compare>","<cassert>","<cctype>","<cerrno>","<cfenv>","<cfloat>","<cinttypes>","<ciso646>","<climits>","<clocale>","<cmath>","<cstdbool>","<cstddef>","<cstdint>","<cstdio>","<cstdlib>","<cstring>","<ctgmath>","<cuchar>","<cwchar>","<cwctype>","<ccomplex>" };
    std::vector<int> selected_numbers_cycles;
    std::vector<Variable> variables_variable;
    
    bool has_iostream = false, has_string = false;
    
    std::println("name file(don't write .cpp)\n:_>");
    std::getline(std::cin, name_file);
    std::ofstream out(name_file + ".cpp"); // creating and open file from writing. 
    if (!out.is_open()) { // checking file opening or not.
        std::cerr << "file not opening or creating" << std::endl;
        return EXIT_FAILURE;
    }
    while (answer_Cpp_Craft_Project != 0 and answer_Cpp_Craft_Project != -1) {
        std::println("  >--------------------------------<  ");
        std::println(">-----Cpp Craft Code By N.Y.RPO3-----<");
        std::println("  >--------------------------------<  ");
        std::println("____________________________________");
        std::println("| [1]-libraries   [10]-function    |");
        std::println("| [2]-variables   [11]-vector      |");
        std::println("| [3]-cycles      [12]-fstream     |");
        std::println("| [4]-switch_case [13]-OOP         |");
        std::println("| [5]-if                           |");
        std::println("| [6]-else if   [-3]-exit no create|");
        std::println("| [7]-arr[]     [-2]-check result  ");
        std::println("| [8]-arr[][]   [-1]-save and exit |");
        std::println("| [9]-d_arr     [ 0]-save and start|");
        std::println("|-----------------------------------|");
        std::println("|");
        std::println("L------------->answer: ");

        std::cin >> answer_Cpp_Craft_Project;
        std::cin.ignore(1024, '\n');
        system("clear");
        switch (answer_Cpp_Craft_Project) {
            case 1: {//Creatig library
                has_iostream = false;
                has_string = false;
                printMenu();
                std::getline(std::cin, input);
    
                if (!input.empty() and input[0] == '<') {
                    vector_library.push_back("#include " + input);
                    if (input == "<iostream>") { has_iostream = true; } 
                    if (input == "<string>") has_string = true;
                    }
                else {
                    std::stringstream ss_lib(input);
                    int lib_num = 0;
                    while (ss_lib >> lib_num) {
                        if (lib_num >= 1 and lib_num <= library.size()) {
                            vector_library.push_back("#include " + library[lib_num - 1]);
                        }
                    }
                }
                for (const auto& i : vector_library) { 
                    if (i == "#include <iostream>") { has_iostream = true; }
                    if (i == "#include <string>") { has_string = true; }
                }

                if (!has_iostream) {
                    vector_library.emplace_back("#include <iostream>");
                }
                if (!has_string) {
                    vector_library.emplace_back("#include <string>");
                }
                system("clear");
                break;
            }
            case 2://Creating variables
                col_variable = 0;
                while (col_variable <= 0) {
                    std::println("col variable: ");
                    std::cin >> col_variable;
                    if (col_variable <= 0) {
                        std::println("col_variable incorrected");
                    }
                }
                for (size_t i = 0; i < col_variable; i++) {
                    type_variable = 0;
                    while(type_variable < 1 or type_variable > 6){
                    std::print("type: [1]int [2]double [3]float [4]string [5]bool [6]auto\n(Enter num)\n:_>");
                    std::cin >> type_variable;
                        if (type_variable < 1 or type_variable > 6) {
                            std::println("type error's, return type");
                            system("clear");
                        }
                    }
                    std::print("[{}]-name\n:_> ", i+1);
                    std::cin >> name_variable;

                    Variable var;
                    var.name = name_variable;

                    if (type_variable == 1) {
                        std::print("variable[{}]- {} = meaning[int]? \n :_>", i+1, name_variable);
                        std::cin >> variable_int;
                        var.type = "int";
                        var.value = std::to_string(variable_int);
                        variables_variable.push_back(var);
                        vector_variable.push_back("int " + name_variable + " = " + std::to_string(variable_int) + ";");
                    }
                    else if (type_variable == 2) {
                        std::print("variable[{}]- {} = meaning[double]? \n :_>", i+1, name_variable);
                        std::cin >> variable_double;
                        var.type = "double";
                        var.value = std::to_string(variable_double);
                        variables_variable.push_back(var);
                        vector_variable.push_back("double " + name_variable + " = " + std::to_string(variable_double) + ";");
                    }
                    else if (type_variable == 3) {
                        std::print("variable[{}]- {} = meaning[float]? \n :_>", i+1, name_variable);
                        std::cin >> variable_float;
                        var.type = "float";
                        var.value = std::to_string(variable_float);
                        variables_variable.push_back(var);
                        vector_variable.push_back("float " + name_variable + " = " + std::to_string(variable_float) + ";");
                    }
                    else if (type_variable == 4) {
                        std::print("variable[{}]- {} = meaning[string]? \n :_>", i+1, name_variable);
                        std::cin >> variable_string;
                        var.type = "std::string";
                        var.value = "\"" + variable_string + "\"";
                        variables_variable.push_back(var);
                        vector_variable.push_back("std::string " + name_variable + " = \"" + variable_string + "\";");
                    }
                    else if (type_variable == 5) {
                        std::print("variable[{}]- {} = meaning[bool]? \n :_>", i+1, name_variable);
                        std::cin >> answer_bool;
                        var.type = "bool";
                        if (answer_bool == 1) {
                            var.value = "true";
                            vector_variable.push_back("bool " + name_variable + " = true;");
                        }
                        if (answer_bool == 2) {
                            var.value = "false";
                            vector_variable.push_back("bool " + name_variable + " = false;");
                        }
                        variables_variable.push_back(var);
                    }
                    else if (type_variable == 6) {
                        std::println("variable[{}] - {} = meaning[AUTO]? (if meaning string, writing) \" \" \n :_>", i, name_variable);
                        std::cin >> variable_var;
                        var.type = "auto";
                        var.value = variable_var;
                        variables_variable.push_back(var);
                        vector_variable.push_back("auto " + name_variable + " = " + variable_var + ";");
                    }
                }
                system("clear");
                break;
            case 3://Creating cycles
                answer_cycles = "";

                std::print("cycles: [1]for [2]while [3]do-while\n:_>");
                std::getline(std::cin, answer_cycles);

                ss_cycles >> answer_cycles;
                while (ss_cycles >> num) {
                    if (num > 0 and num <= 3) {
                        selected_numbers_cycles.push_back(num);
                    }
                }

                for (int selected_numbers_cycle : selected_numbers_cycles) {
                    if (selected_numbers_cycle == 1) {
                        vector_cycles.push_back("for(size_t i = 0; i < ...; i++) {");
                        vector_cycles.push_back("    //code_cycles");
                        vector_cycles.push_back("}");
                    }
                    if (selected_numbers_cycle == 2) {
                        vector_cycles.push_back("while(/*condition*/) {");
                        vector_cycles.push_back("    //what will happen");
                        vector_cycles.push_back("}");
                    }
                    if (selected_numbers_cycle == 3) {
                        vector_cycles.push_back("do {");
                        vector_cycles.push_back("    //what will happen");
                        vector_cycles.push_back("} while(/*condition*/);");
                    }
                }
                system("clear");
                break;

            case 4://Cases creating switch case
                col_switch = -1;
                col_case = -1;
                while (col_switch <= 0 or col_case <= 0) {
                    std::print("col switch case:\n:_>");
                    std::cin >> col_switch;
                    if (col_switch < 0) {
                        std::println("col_switch error's");
                    }
                    std::print("col cases?\n:_>");
                    std::cin >> col_case;
                    if (col_case < 0) {
                        std::println("col_case error's");
                    }
                }

                for (size_t i = 0; i < col_switch; i++) {
                    vector_switch.push_back("switch() {");
                }

                for (int j = 0; j < col_case; j++) {
                    vector_case.push_back("case " + std::to_string(j+1) + ":"); //*j+1
                    vector_case.push_back("    break;");
                }
                vector_default.push_back("default:");
                vector_default.push_back("    break;");
                vector_default.push_back("}");

                system("clear");
                break;
            case 5://Cases creating if()
                col_if = -1;
                while (col_if <= 0) {
                    std::print("col-if() \n _>");
                    std::cin >> col_if;
                    if (col_if < 0) {
                        std::println("col-if error's");
                    }
                }
                for (size_t i = 0; i < col_if; i++) {
                    vector_if.push_back("if() {");
                    vector_if.push_back("    /*Condition*/");
                    vector_if.push_back("}");
                }
                system("clear");
                break;

            case 6://Cases creating else if()
                col_else_if = -1;
                while (col_else_if <= 0) {
                    std::print("col else-if()\n:_>");
                    std::cin >> col_else_if;
                    if (col_else_if < 0) {
                        std::println("col-else if error's");
                    }
                }
                for (size_t i = 0; i < col_else_if; i++) {
                    vector_else_if.push_back("else if() {");
                    vector_else_if.push_back("    /*Condition*/");
                    vector_else_if.push_back("}");
                }
                system("clear");
                break;
            case 7://Cases creating arr
                col_arr = -1;
                while (col_arr <= 0) {
                    std::print("col arr\n:_>");
                    std::cin >> col_arr;
                    if (col_arr < 0) {
                        std::println("col_arr error's");
                    }
                }
                for (size_t i = 0; i < col_arr; i++) {
                    size_arr = 0;
                    while (size_arr <= 0) {
                        std::print("size_arr[{}]\n:_>", i);
                        std::cin >> size_arr;
                        if (size_arr < 0) {
                            std::println("size_arr error's");
                        }
                    }
                    vector_arr.push_back("int arr" + std::to_string(i) + "[" + std::to_string(size_arr) + "];");
                }
                system("clear");
                break;
            case 8://Cases creating dimensional arr
                col_dimensional_arr = -1;
                while (col_dimensional_arr <= 0) {
                    std::print("col arr[][]\n:_>");
                    std::cin >> col_dimensional_arr;
                    if (col_dimensional_arr <= 0) {
                        std::print("arr[][] incorected");
                    }
                }
                for (size_t i = 0; i < col_dimensional_arr; i++) {
                    size_arr_d_1 = 0;
                    size_arr_d_2 = 0;
                    while (size_arr_d_1 <= 0 or size_arr_d_2 <= 0) {
                        std::print("size[?][?] = ");
                        std::cin >> size_arr_d_1 >> size_arr_d_2;
                        if (size_arr_d_1 < 0 or size_arr_d_2 < 0) {
                            std::println("size_arr[][] incorrected size[?][?]");
                        }
                    }
                    vector_dimensional_arr.push_back("int arr_" + std::to_string(i) + "[" + std::to_string(size_arr_d_1) + "]" + "[" + std::to_string(size_arr_d_2) + "];");
                }
                system("clear");
                break;

            case 9://cases creating dynamic arr
                col_dynamic_arr = -1;
                while (col_dynamic_arr <= 0) {
                    std::print("col d_arr :_>");
                    std::cin >> col_dynamic_arr;
                    if (col_dynamic_arr < 0) {
                        std::println("error's col <= 0");
                    }
                }
                for (size_t i = 0; i < col_dynamic_arr; i++) {
                    size_dynamic_arr = 0;
                    while (size_dynamic_arr <= 0) {
                        std::print("size {} arr = _", i+1);
                        std::cin >> size_dynamic_arr;
                        if (size_dynamic_arr < 0) {
                            std::println("error's size");
                        }
                    }
                    vector_dynamic_arr.push_back("int* arr_d_" + std::to_string(i) + " = new int[" + std::to_string(size_dynamic_arr) + "];");
                    delete_dynamic_arr.push_back("delete[] arr_d_" + std::to_string(i) + ";");
                }
                system("clear");
                break;
            case 10://Cases creaint function
                std::print("return type (void, int, double, float, string, bool): ");
                std::cin.ignore(1024, '\n');
                std::getline(std::cin, ret_type);

                std::print("Function name: ");
                std::cin.ignore(1024, '\n');
                std::getline(std::cin, name);

                std::print("Parameters (e.g., int a, double b): ");
                std::cin.ignore(1024, '\n');
                std::getline(std::cin, params);

                func_code = "\n" + ret_type + " " + name + "(" + params + ") {\n";
                func_code += "    // Function implementation\n";

                if (ret_type != "void" and ret_type != "Void") {
                    func_code += "    return ";
                    if (ret_type == "int" or ret_type == "Int"){ func_code += "0"; }
                    else if (ret_type == "double" or ret_type == "Double" or
                        ret_type == "float" or ret_type == "Float"){ func_code += "0.0"; }
                    else if (ret_type == "bool" or ret_type == "Bool"){ func_code += "false"; }
                    else if (ret_type == "string" or ret_type == "String"){ func_code += "\"\""; }
                    else {
                        func_code += "{}";
                    }
                    func_code += ";\n";
                }

                func_code += "}\n";

                vector_function.push_back(func_code);
                system("clear");
                break;

            case 11: //Cases creating vector
                std::print("name vector :_>");
                std::cin >> name_vector;

                type_vector = "";
                while (type_vector != "int" and type_vector != "float" and type_vector != "double" and type_vector != "string") {
                    std::print("type vector = (int, float, double, string)\n:_>");
                    std::cin >> type_vector;
                    if (type_vector != "int" and type_vector != "float" and type_vector != "double" and type_vector != "string") {
                        std::println("writing type error's");
                    }
                }

                size_vector = 0;
                while (size_vector <= 0) {
                    std::print("size vector:\n:_>");
                    std::cin >> size_vector;
                    if (size_vector < 0) {
                        std::println("size vector incorrected! \n size vector < 0");
                    }
                }
                vector_vectorov.push_back("std::vector<" + type_vector + "> " + name_vector + "(" + std::to_string(size_vector) + ");");
                system("clear");
                break;
            case 12:{
            for(size_t i = 0 ; i < vector_library.size() ; i++){
                if(vector_library.at(i) != "#include <fstream>"){
                    vector_library.push_back("#include <fstream>");
                }
            }
                while(answer_fstream < 1 or answer_fstream > 3){
                std::print("1.fstream 2.ofstream 3.ifstream\n:_>");
                std::cin >> answer_fstream;
                if(answer_fstream < 1 or answer_fstream > 3){
                    std::cerr << "Enter Error" << std::endl;
                    system("clear");
                }
            }
            if(answer_fstream == 1){
                std::print("write name fstream [...]()\n:_> ");
                std::cin >> fstream;

                std::print("create file? fstream {} (...)? (if no ENTER)\n:_>", fstream);
                std::cin >> fstream_file;

                vector_fstream.push_back("fstream " + fstream + "(" + fstream_file + ");");
            }
            else if(answer_fstream == 2){
                std::print("write name ofstream [...]()\n:_>");
                std::cin >> stream_ofstream;

                std::print("listing file? (if no ENTER)\n:_>");
                std::cin >> listing_file_name;

                vector_ofstream.push_back("ofstream " + stream_ofstream + "(" + listing_file_name + ");");
            }
            else if(answer_fstream == 3){
                std::print("write name ifstream [...]() \n :_>");
                std::cin >> listing_ifstream;

                std::print("write file? (if no ENTER)\n:_>");
                std::cin >> write_file;

                vector_ifstream.push_back("ifstream " + listing_ifstream + "(" + write_file + ");");
            }
            break;
            }
            case 13:{
            answer_OOP = -1;
            while(answer_OOP != 0){
            std::println("|=======================|#|");
            std::println("|1.class 2.struct 0.exit|#|");
            std::println("|=======================|#|");
            std::println("          answer: ");
            std::cin >> answer_OOP;
            std::cin.ignore(1024, '\n');
            
            switch(answer_OOP){
                case 1:
                system("clear");
                std::print("class name\n:_>");
                std::cin >> name_class;
                vector_class.push_back("class " + name_class + "{");

                std::print("1.public or 2.private?\n:_>");
                public_or_private = 0;                
                while(public_or_private != 1 and public_or_private != 2){
                    std::cin >> public_or_private;
                    if(public_or_private != 1 and public_or_private != 2){
                        std::cerr << "Enter Error" << std::endl;
                        std::cin.clear();
                    }
                }

                if (public_or_private == 1) {
                    vector_class.push_back("public:");
                } else {
                    vector_class.push_back("private:");
                }
                std::cout << "if stop, Enter [STOP]\n";
                anything_class = "";
                while (true) {
                    std::getline(std::cin, anything_class);
                    if (anything_class == "STOP") { break; }
                    if (!anything_class.empty())
                        vector_class.push_back(anything_class);
                }
                vector_class.push_back("};");
                break;
                case 2:{
                system("clear");
                std::cout << "struct name\n:_> ";
                std::getline(std::cin, name_struct);
                vector_struct.push_back("struct " + name_struct + " {");

                std::cout << "1.public (default) or 2.private?\n:_> ";
                public_or_private = 0;
                while (public_or_private != 1 && public_or_private != 2) {
                    std::cin >> public_or_private;
                    if (public_or_private != 1 && public_or_private != 2) {
                        std::cerr << "Enter Error" << std::endl;
                        std::cin.clear();
                    }
                }
                std::cin.ignore(1024, '\n');

                if (public_or_private == 1){
                    vector_struct.push_back("public:");
                }
                else{
                    vector_struct.push_back("private:");
                }
                std::cout << "if stop, Enter [STOP]\n";
                anything_struct = "";
                while (true) {
                    std::getline(std::cin, anything_struct);
                    if (anything_struct == "STOP") break;
                    if (!anything_struct.empty())
                        vector_struct.push_back(anything_struct);
                }
                vector_struct.push_back("};");
                break;
            }
            }
            system("clear");
            break;
            }
            [[fallthrough]]; case 0: {//case creating cpp file and open this file
                for (size_t i = 0; i < vector_library.size(); i++) {
                    out << vector_library.at(i) << std::endl;
                }
                
                for (size_t i = 0; i < vector_function.size(); i++) {
                    out << vector_function.at(i) << std::endl;
                }

                for(size_t i = 0 ; i < vector_class.size() ; i++){
                    out << vector_class.at(i) << std::endl;
                }

                for(size_t i = 0 ; i < vector_struct.size() ; i++){
                    out << vector_struct.at(i) << std::endl;
                }

                out << "int main() {" << std::endl;

                for (size_t i = 0; i < vector_variable.size(); i++) {
                    out << "    " << vector_variable.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_cycles.size(); i++) {
                    out << "    " << vector_cycles.at(i) << std::endl;
                }
                for (int sw = 0; sw < col_switch; sw++) {
                    if (sw < vector_switch.size()) {
                        out << "    " << vector_switch[sw] << std::endl;
                    }

                    for (size_t i = 0; i < vector_case.size(); i++) {
                        out << "        " << vector_case.at(i) << std::endl;
                    }

                    for (size_t i = 0; i < vector_default.size(); i++) {
                        out << "        " << vector_default.at(i) << std::endl;
                    }
                }
                for (size_t i = 0; i < vector_if.size(); i++) {
                    out << "    " << vector_if.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_else_if.size(); i++) {
                    out << "    " << vector_else_if.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_arr.size(); i++) {
                    out << "    " << vector_arr.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_dimensional_arr.size(); i++) {
                    out << "    " << vector_dimensional_arr.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_dynamic_arr.size(); i++) {
                    out << "    " << vector_dynamic_arr.at(i) << std::endl;
                }
                for (size_t i = 0; i < delete_dynamic_arr.size(); i++) {
                    out << "    " << delete_dynamic_arr.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_vectorov.size(); i++) {
                    out << "    " << vector_vectorov.at(i) << std::endl;
                }
                for(size_t i = 0; i < vector_ifstream.size();i++){
                    out << "    " << vector_ifstream.at(i) << std::endl;
                }
                for(size_t i = 0 ; i < vector_ofstream.size();i++){
                    out << "    " << vector_ofstream.at(i) << std::endl;
                }
                for(size_t i = 0 ; i < vector_fstream.size();i++){
                    out << "    " << vector_fstream.at(i) << std::endl;
                }
                out << std::endl;
                out << "    return 0;" << std::endl;
                out << "}" << std::endl;

                out.close();
                
                command = "start " + name_file + ".cpp";
                system(command.c_str());
                break;
            }
            case -1:{//creating cpp file and not opening
                for (size_t i = 0; i < vector_library.size(); i++) {
                    out << vector_library.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_function.size(); i++) {
                    out << vector_function.at(i) << std::endl;
                }
                for(size_t i = 0 ; i < vector_class.size() ; i++){
                    out << vector_class.at(i) << std::endl;
                }

                for(size_t i = 0 ; i < vector_struct.size() ; i++){
                    out << vector_struct.at(i) << std::endl;
                }
                out << "int main() {" << std::endl;
                for (size_t i = 0; i < vector_variable.size(); i++) {
                    out << "    " << vector_variable.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_cycles.size(); i++) {
                    out << "    " << vector_cycles.at(i) << std::endl;
                }
                for (int sw = 0; sw < col_switch; sw++) {
                    if (sw < vector_switch.size()) {
                        out << "    " << vector_switch[sw] << std::endl;
                    }

                    for (size_t i = 0; i < vector_case.size(); i++) {
                        out << "        " << vector_case.at(i) << std::endl;
                    }

                    for (size_t i = 0; i < vector_default.size(); i++) {
                        out << "        " << vector_default.at(i) << std::endl;
                    }
                }

                for (size_t i = 0; i < vector_if.size(); i++) {
                    out << "    " << vector_if.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_else_if.size(); i++) {
                    out << "    " << vector_else_if.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_arr.size(); i++) {
                    out << "    " << vector_arr.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_dimensional_arr.size(); i++) {
                    out << "    " << vector_dimensional_arr.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_dynamic_arr.size(); i++) {
                    out << "    " << vector_dynamic_arr.at(i) << std::endl;
                }
                for (size_t i = 0; i < delete_dynamic_arr.size(); i++) {
                    out << "    " << delete_dynamic_arr.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_vectorov.size(); i++) {
                    out << "    " << vector_vectorov.at(i) << std::endl;
                }

                for(size_t i = 0; i < vector_ifstream.size();i++){
                    out << "    " << vector_ifstream.at(i) << std::endl;
                }
                for(size_t i = 0 ; i < vector_ofstream.size();i++){
                    out << "    " << vector_ofstream.at(i) << std::endl;
                }
                for(size_t i = 0 ; i < vector_fstream.size();i++){
                    out << "    " << vector_fstream.at(i) << std::endl;
                }

                out << std::endl;
                out << "    return 0;" << std::endl;
                out << "}" << std::endl;
                break;
            }
            case -2:{//check result creating
            for (size_t i = 0; i < vector_library.size(); i++) {
                    std::cout << vector_library.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_function.size(); i++) {
                    std::cout << vector_function.at(i) << std::endl;
                }
                for(size_t i = 0 ; i < vector_class.size() ; i++){
                    std::cout << vector_class.at(i) << std::endl;
                }

                for(size_t i = 0 ; i < vector_struct.size() ; i++){
                    std::cout << vector_struct.at(i) << std::endl;
                }
                std::cout << "int main() {" << std::endl;
                for (size_t i = 0; i < vector_variable.size(); i++) {
                    std::cout << "    " << vector_variable.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_cycles.size(); i++) {
                    std::cout << "    " << vector_cycles.at(i) << std::endl;
                }
                for (int sw = 0; sw < col_switch; sw++) {
                    if (sw < vector_switch.size()) {
                        std::cout << "    " << vector_switch[sw] << std::endl;
                    }

                    for (size_t i = 0; i < vector_case.size(); i++) {
                        std::cout << "        " << vector_case.at(i) << std::endl;
                    }

                    for (size_t i = 0; i < vector_default.size(); i++) {
                        std::cout << "        " << vector_default.at(i) << std::endl;
                    }
                }

                for (size_t i = 0; i < vector_if.size(); i++) {
                    std::cout << "    " << vector_if.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_else_if.size(); i++) {
                    std::cout << "    " << vector_else_if.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_arr.size(); i++) {
                    std::cout << "    " << vector_arr.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_dimensional_arr.size(); i++) {
                    std::cout << "    " << vector_dimensional_arr.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_dynamic_arr.size(); i++) {
                    std::cout << "    " << vector_dynamic_arr.at(i) << std::endl;
                }
                for (size_t i = 0; i < delete_dynamic_arr.size(); i++) {
                    std::cout << "    " << delete_dynamic_arr.at(i) << std::endl;
                }
                for (size_t i = 0; i < vector_vectorov.size(); i++) {
                    std::cout << "    " << vector_vectorov.at(i) << std::endl;
                }

                for(size_t i = 0; i < vector_ifstream.size();i++){
                    std::cout << "    " << vector_ifstream.at(i) << std::endl;
                }
                for(size_t i = 0 ; i < vector_ofstream.size();i++){
                    std::cout << "    " << vector_ofstream.at(i) << std::endl;
                }
                for(size_t i = 0 ; i < vector_fstream.size();i++){
                    std::cout << "    " << vector_fstream.at(i) << std::endl;
                }

                std::cout << std::endl;
                std::cout << "    return 0;" << std::endl;
                std::cout << "}" << std::endl;
            break;
            case -3:
                out.close();
                if(remove((name_file + ".cpp").c_str()) == 0){
                    std::println("file deleted.");
                } else{
                    std::println("file not deleted or searching");
                }
                std::println("Bye...");
            break;
            }
            default:
                std::cerr << "choice error" << std::endl;
                break;
            }
        }
        system("clear"); 
        out.close();
        return EXIT_SUCCESS;
    }
}
