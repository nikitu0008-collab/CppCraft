/*
Read file READ ME to learn about the project.
*/

#include <iostream> //*Ввод/Вывод
#include <string> //*Работа со строками
#include <vector> //*Вектор для хранения
#include <cstdlib> //*Для system(...)
#include <sstream> //*Разбиение строк на числа
#include <fstream> //*Запись/Чтение
#include <algorithm> //*Для поиска чего-либо в векторе(в моем случае для поиска библиотек)

//*Обьеденение частей переменных
struct Variable {
    std::string type; 
    std::string name; 
    std::string value;
};
int main() {
    std::string command, type_vector, name_vector, variable_var, func_code, answer_cycles, numbering, name_variable;
    std::string variable_string, libName, input, name_file, answer, search = "#include <vector>", ret_type, name, params;
    
    int size_vector = 0, answer_bool = 0, col_dynamic_arr = 0, col_dimensional_arr = 0, size_arr_d_1 = 0, size_arr_d_2 = 0, col_arr = 0, size_arr = 0, col_if = -1, col_else_if = -1; 
    int col_variable = 0, col_case = -1, col_switch = -1, choice = 0, variable_int = 0, type_variable = 0, answer_Cpp_Craft_Project = -2, num = 0, size_dynamic_arr = 0;
    
    double variable_double = 0;
    float variable_float = 0;
    
    std::stringstream ss_cycles, ss_lib;

    std::vector<std::string> cycles_for, cycles_while, cycles_do_while, vector_library, vector_switch, vector_case, vector_default, vector_if, vector_else_if;
    std::vector<std::string> vector_arr, vector_dimensional_arr, vector_dynamic_arr, delete_dynamic_arr, vector_function, vector_vectorov, vector_variable, vector_cycles;
    
    std::vector<std::string> library = { "<algorithm>","<array>", "<atomic>","<barrier>","<bitset>","<bit>","<chrono>","<complex>","<concepts>","<condition_variable>","<coroutine>","<deque>","<exception>","<execution>","<forward_list>","<format>","<fstream>","<functional>","<future>","<initializer_list>","<iomanip>","<ios>","<iosfwd>","<iostream>","<istream>","<iterator>","<latch>","<limits>","<list>","<locale>","<map>","<memory>","<memory_resource>","<mutex>","<new>","<numeric>","<optional>","<ostream>","<queue>","<random>","<ranges>","<ratio>","<regex>","<scoped_allocator>","<set>","<shared_mutex>","<sstream>","<stack>","<stdexcept>","<streambuf>","<stop_token>","<string>","<string_view>","<system_error>","<thread>","<tuple>","<type_traits>","<typeindex>","<typeinfo>","<unordered_map>","<unordered_set>","<utility>","<valarray>","<variant>","<vector>","<version>","<charconv>","<compare>","<cassert>","<cctype>","<cerrno>","<cfenv>","<cfloat>","<cinttypes>","<ciso646>","<climits>","<clocale>","<cmath>","<cstdbool>","<cstddef>","<cstdint>","<cstdio>","<cstdlib>","<cstring>","<ctgmath>","<cuchar>","<cwchar>","<cwctype>","<ccomplex>" };
    
    std::vector<int> selected_numbers_cycles;
    std::vector<Variable> variables_variable;
    
    bool has_iostream = false, has_string = false;
    
    std::cout << "name file(don't write .cpp)\n:_>";
    std::getline(std::cin, name_file);
    std::ofstream out(name_file + ".cpp"); // creating and open file from writing 
    if (!out.is_open()) {
        std::cerr << "file not opening or creating" << std::endl;
        return EXIT_FAILURE;
    }
    while (answer_Cpp_Craft_Project != 0 && answer_Cpp_Craft_Project != -1) {
        std::cout << "================================" << std::endl;
        std::cout << "| Cpp Craft Code By N.Y.RPO3   |" << std::endl;
        std::cout << "| 1.libraries   10.function    |" << std::endl;
        std::cout << "| 2.variables   11.vector      |" << std::endl;
        std::cout << "| 3.cycles                     |" << std::endl;
        std::cout << "| 4.switch_case                |" << std::endl;
        std::cout << "| 5.if                         |" << std::endl;
        std::cout << "| 6.else if                    |" << std::endl;
        std::cout << "| 7.arr[]                      |" << std::endl;
        std::cout << "| 8.arr[][]   -1.save and exit |" << std::endl;
        std::cout << "| 9.d_arr      0.save and start|" << std::endl;
        std::cout << "|==============================|" << std::endl;
        std::cout << "            answer: ";

        std::cin >> answer_Cpp_Craft_Project;
        std::cin.ignore(1024, '\n');
        system("cls");
        switch (answer_Cpp_Craft_Project) {
            case 1: {//Creatig library
                vector_library.clear();
                has_iostream = false;
                has_string = false;

                std::cout << "|1.  <algorithm>      |2.  <array>         |3.  <atomic>         |4.  <barrier>        |5.  <bitset>        |6.  <bit>           |7.  <chrono>        |8.  <complex>       |9.  <concepts>      |10. <condition_variable>|" << std::endl;
                std::cout << "|11. <coroutine>      |12. <deque>         |13. <exception>      |14. <execution>      |15. <forward_list>  |16. <format>        |17. <fstream>       |18. <functional>    |19. <future>        |20. <initializer_list>  |" << std::endl;
                std::cout << "|21. <iomanip>        |22. <ios>           |23. <iosfwd>         |24. <iostream>       |25. <istream>       |26. <iterator>      |27. <latch>         |28. <limits>        |29. <list>          |30. <locale>            |" << std::endl;
                std::cout << "|31. <map>            |32. <memory>        |33. <memory_resource>|34. <mutex>          |35. <new>           |36. <numeric>       |37. <optional>      |38. <ostream>       |39. <queue>         |40. <random>            |" << std::endl;
                std::cout << "|41. <ranges>         |42. <ratio>         |43. <regex>          |44. <scoped_allocator>|45. <set>          |46. <shared_mutex>  |47. <sstream>       |48. <stack>         |49. <stdexcept>     |50. <streambuf>         |" << std::endl;
                std::cout << "|51. <stop_token>     |52. <string>        |53. <string_view>    |54. <system_error>   |55. <thread>        |56. <tuple>         |57. <type_traits>   |58. <typeindex>     |59. <typeinfo>      |60. <unordered_map>     |" << std::endl;
                std::cout << "|61. <unordered_set>  |62. <utility>       |63. <valarray>       |64. <variant>        |65. <vector>        |66. <version>       |67. <charconv>      |68. <compare>       |69. <cassert>       |70. <cctype>            |" << std::endl;
                std::cout << "|71. <cerrno>         |72. <cfenv>         |73. <cfloat>         |74. <cinttypes>      |75. <ciso646>       |76. <climits>       |77. <clocale>       |78. <cmath>         |79. <cstdbool>      |80. <cstddef>           |" << std::endl;
                std::cout << "|81. <cstdint>        |82. <cstdio>        |83. <cstdlib>        |84. <cstring>        |85. <ctgmath>       |86. <cuchar>        |87. <cwchar>        |88. <cwctype>       |89. <ccomplex>      |" << std::endl;
                std::cout << "|===== ADD LIBRARIES =|====|" << std::endl;

                std::cout << "Enter library numbers or name <name> (1-89):\n _>";
                std::getline(std::cin, input);
    
                if (!input.empty() && input[0] == '<') {
                    vector_library.push_back("#include " + input);
                    if (input == "<iostream>") has_iostream = true;
                    if (input == "<string>") has_string = true;
                    }
                else {
                    std::stringstream ss_lib(input);
                    int lib_num;
                    while (ss_lib >> lib_num) {
                        if (lib_num >= 1 && lib_num <= (int)library.size()) {
                            vector_library.push_back("#include " + library[lib_num - 1]);
                        }
                    }
                }
                for (int i = 0; i < vector_library.size(); i++) { 
                    if (vector_library[i] == "#include <iostream>") has_iostream = true;
                    if (vector_library[i] == "#include <string>") has_string = true;
                }

                if (!has_iostream) {
                    vector_library.push_back("#include <iostream>");
                }
                if (!has_string) {
                    vector_library.push_back("#include <string>");
                }
                system("cls");
                break;
            }
            case 2://Creating variables
                col_variable = 0;
                while (col_variable <= 0) {
                    std::cout << "col variable: " << std::endl;
                    std::cin >> col_variable;
                    if (col_variable <= 0) {
                        std::cout << "col_variable incorrected" << std::endl;
                    }
                }

                for (int i = 0; i < col_variable; i++) {
                    std::cout << "type: 1.int 2.double 3.float 4.string 5.bool 6.auto \n(write number)\n :_>";
                    std::cin >> type_variable;
                        if (type_variable < 1 || type_variable > 6) {
                            std::cout << "type error's, return type" << std::endl;
                            system("cls");
                        }
                    std::cout << "name-[" << i << "] variable \n :_> ";
                    std::cin >> name_variable;

                    Variable var;
                    var.name = name_variable;

                    if (type_variable == 1) {
                        std::cout << "variable[" << i << "]-" << name_variable << " = meaning[INT]? \n :_>";
                        std::cin >> variable_int;
                        var.type = "int";
                        var.value = std::to_string(variable_int);
                        variables_variable.push_back(var);
                        vector_variable.push_back("int " + name_variable + " = " + std::to_string(variable_int) + ";");
                    }
                    else if (type_variable == 2) {
                        std::cout << "variable[" << i << "]-" << name_variable << " = meaning[DOUBLE]? \n :_>";
                        std::cin >> variable_double;
                        var.type = "double";
                        var.value = std::to_string(variable_double);
                        variables_variable.push_back(var);
                        vector_variable.push_back("double " + name_variable + " = " + std::to_string(variable_double) + ";");
                    }
                    else if (type_variable == 3) {
                        std::cout << "variable[" << i << "]-" << name_variable << " = meaning[FLOAT]? \n :_>";
                        std::cin >> variable_float;
                        var.type = "float";
                        var.value = std::to_string(variable_float);
                        variables_variable.push_back(var);
                        vector_variable.push_back("float " + name_variable + " = " + std::to_string(variable_float) + ";");
                    }
                    else if (type_variable == 4) {
                        std::cout << "variable[" << i << "]-" << name_variable << " = meaning[STRING]? (don't write \""")  \n : _>";
                        std::cin >> variable_string;
                        var.type = "std::string";
                        var.value = "\"" + variable_string + "\"";
                        variables_variable.push_back(var);
                        vector_variable.push_back("std::string " + name_variable + " = \"" + variable_string + "\";");
                    }
                    else if (type_variable == 5) {
                        std::cout << "variable[" << i << "]-" << name_variable << " = meaning[BOOL]? 1.true 2.false (WRITING NUMBER 1 or 2)\n :_>";
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
                        std::cout << "variable[" << i << "]-" << name_variable << " = meaning[AUTO]? if meaning string, writing \" \" \n :_>";
                        std::cin >> variable_var;
                        var.type = "auto";
                        var.value = variable_var;
                        variables_variable.push_back(var);
                        vector_variable.push_back("auto " + name_variable + " = " + variable_var + ";");
                    }
                }
                system("cls");
                break;

            case 3://Creating cycles
                answer_cycles = "";

                std::cout << "what using cycles (1.for 2.while 3.do-while) \n :_>";
                std::getline(std::cin, answer_cycles);

                ss_cycles >> answer_cycles;
                while (ss_cycles >> num) {
                    if (num > 0 && num <= 3) {
                        selected_numbers_cycles.push_back(num);
                    }
                }

                for (int i = 0; i < selected_numbers_cycles.size(); i++) {
                    if (selected_numbers_cycles[i] == 1) {
                        vector_cycles.push_back("for(int i = 0; i < ...; i++) {");
                        vector_cycles.push_back("    //code_cycles_1");
                        vector_cycles.push_back("}");
                    }
                    if (selected_numbers_cycles[i] == 2) {
                        vector_cycles.push_back("while(/*condition*/) {");
                        vector_cycles.push_back("    //what will happen");
                        vector_cycles.push_back("}");
                    }
                    if (selected_numbers_cycles[i] == 3) {
                        vector_cycles.push_back("do {");
                        vector_cycles.push_back("    //what will happen");
                        vector_cycles.push_back("} while(/*condition*/);");
                    }
                }
                system("cls");
                break;

            case 4://Cases creating switch case
                col_switch = -1;
                col_case = -1;
                while (col_switch <= 0 || col_case <= 0) {
                    std::cout << "col switch case: \n _>";
                    std::cin >> col_switch;
                    if (col_switch <= 0) {
                        std::cout << "col_switch error's" << std::endl;
                    }
                    std::cout << "col cases? \n _>";
                    std::cin >> col_case;
                    if (col_case <= 0) {
                        std::cout << "col_case error's" << std::endl;
                    }
                }

                for (int i = 0; i < col_switch; i++) {
                    vector_switch.push_back("switch() {");
                }

                for (int j = 0; j < col_case; j++) {
                    vector_case.push_back("case " + std::to_string(j) + ":");
                    vector_case.push_back("    break;");
                }
                vector_default.push_back("default:");
                vector_default.push_back("    break;");
                vector_default.push_back("}");

                system("cls");
                break;
            case 5://Cases creating if()
                vector_if.clear();
                col_if = -1;
                while (col_if <= 0) {
                    std::cout << "col-if() \n _>";
                    std::cin >> col_if;
                    if (col_if <= 0) {
                        std::cout << "col-if error's" << std::endl;
                    }
                }
                for (int i = 0; i < col_if; i++) {
                    vector_if.push_back("if() {");
                    vector_if.push_back("    /*Condition*/");
                    vector_if.push_back("}");
                }
                system("cls");
                break;

            case 6://Cases creating else if()
                vector_else_if.clear();
                col_else_if = -1;
                while (col_else_if <= 0) {
                    std::cout << "col-else if() \n _>";
                    std::cin >> col_else_if;
                    if (col_else_if <= 0) {
                        std::cout << "col-else if error's" << std::endl;
                    }
                }
                for (int i = 0; i < col_else_if; i++) {
                    vector_else_if.push_back("else if() {");
                    vector_else_if.push_back("    /*Condition*/");
                    vector_else_if.push_back("}");
                }
                system("cls");
                break;
            case 7://Cases creating arr
                vector_arr.clear();
                col_arr = -1;
                while (col_arr <= 0) {
                    std::cout << "col arr \n _>";
                    std::cin >> col_arr;
                    if (col_arr <= 0) {
                        std::cout << "col_arr error's" << std::endl;
                    }
                }
                for (int i = 0; i < col_arr; i++) {
                    size_arr = 0;
                    while (size_arr <= 0) {
                        std::cout << "size_arr[" << i << "]\n_>";
                        std::cin >> size_arr;
                        if (size_arr <= 0) {
                            std::cout << "size_arr error's" << std::endl;
                        }
                    }
                    vector_arr.push_back("int arr" + std::to_string(i) + "[" + std::to_string(size_arr) + "];");
                }
                system("cls");
                break;
            case 8://Cases creating dimensional arr
                vector_dimensional_arr.clear();
                col_dimensional_arr = -1;
                while (col_dimensional_arr <= 0) {
                    std::cout << "col arr[][] \n _>";
                    std::cin >> col_dimensional_arr;
                    if (col_dimensional_arr <= 0) {
                        std::cout << "arr[][] incorected" << std::endl;
                    }
                }

                for (int i = 0; i < col_dimensional_arr; i++) {
                    size_arr_d_1 = 0;
                    size_arr_d_2 = 0;
                    while (size_arr_d_1 <= 0 || size_arr_d_2 <= 0) {
                        std::cout << "size[][] = ";
                        std::cin >> size_arr_d_1 >> size_arr_d_2;
                        if (size_arr_d_1 <= 0 || size_arr_d_2 <= 0) {
                            std::cout << "size_arr[][] incorrected size[?][?]" << std::endl;
                        }
                    }
                    vector_dimensional_arr.push_back("int arr_" + std::to_string(i) + "[" + std::to_string(size_arr_d_1) + "]" + "[" + std::to_string(size_arr_d_2) + "];");
                }
                system("cls");
                break;

            case 9://cases creating dynamic arr
                vector_dynamic_arr.clear();
                delete_dynamic_arr.clear();
                col_dynamic_arr = -1;
                while (col_dynamic_arr <= 0) {
                    std::cout << "col d_arr: _>";
                    std::cin >> col_dynamic_arr;
                    if (col_dynamic_arr <= 0) {
                        std::cout << "error's col > 0" << std::endl;
                    }
                }
                for (int i = 0; i < col_dynamic_arr; i++) {
                    size_dynamic_arr = 0;
                    while (size_dynamic_arr <= 0) {
                        std::cout << "size " << i + 1 << " arr = ";
                        std::cin >> size_dynamic_arr;
                        if (size_dynamic_arr <= 0) {
                            std::cout << "error's size" << std::endl;
                        }
                    }
                    vector_dynamic_arr.push_back("int* arr_d_" + std::to_string(i) + " = new int[" + std::to_string(size_dynamic_arr) + "];");
                    delete_dynamic_arr.push_back("delete[] arr_d_" + std::to_string(i) + ";");
                }
                system("cls");
                break;

            case 10://Cases creaint function
                std::cout << "return type (void, int, double, float, string, bool): ";
                std::getline(std::cin, ret_type);

                std::cout << "Function name: ";
                std::getline(std::cin, name);

                std::cout << "Parameters (e.g., int a, double b): ";
                std::getline(std::cin, params);

                func_code = "\n" + ret_type + " " + name + "(" + params + ") {\n";
                func_code += "    // Function implementation\n";

                if (ret_type != "void" && ret_type != "Void") {
                    func_code += "    return ";
                    if (ret_type == "int" || ret_type == "Int") func_code += "0";
                    else if (ret_type == "double" || ret_type == "Double" ||
                        ret_type == "float" || ret_type == "Float") func_code += "0.0";
                    else if (ret_type == "bool" || ret_type == "Bool") func_code += "false";
                    else if (ret_type == "string" || ret_type == "String") func_code += "\"\""; // " " чтобы эти ковычки ИМЕННО ДОБАВЛЯТЬ в файл надо использовать слеши  \ // 
                    else func_code += "{}";
                    func_code += ";\n";
                }

                func_code += "}\n";

                vector_function.push_back(func_code);
                system("cls");
                break;

            case 11: //Cases creating vector
                std::cout << "name vector :_>";
                std::cin >> name_vector;

                type_vector = "";
                while (type_vector != "int" && type_vector != "float" && type_vector != "double" && type_vector != "string") {
                    std::cout << "type vector = (int, float, double, string) \n _>";
                    std::cin >> type_vector;
                    if (type_vector != "int" && type_vector != "float" && type_vector != "double" && type_vector != "string") {
                        std::cout << "writing type error's" << std::endl;
                    }
                }

                size_vector = 0;
                while (size_vector <= 0) {
                    std::cout << "size vector: _>";
                    std::cin >> size_vector;
                    if (size_vector <= 0) {
                        std::cout << "size vector incorrected! \n size vector > 0" << std::endl;
                    }
                }
                vector_vectorov.push_back("std::vector<" + type_vector + "> " + name_vector + "(" + std::to_string(size_vector) + ");");
                system("cls");
                break;

            case 0: {//case creating cpp file and open this file
                for (int i = 0; i < vector_library.size(); i++) {
                    out << vector_library[i] << std::endl;
                }
                
                for (int i = 0; i < vector_function.size(); i++) {
                    out << vector_function[i] << std::endl;
                }

                out << "int main() {" << std::endl;

                for (int i = 0; i < vector_variable.size(); i++) {
                    out << "    " << vector_variable[i] << std::endl;
                }
                for (int i = 0; i < vector_cycles.size(); i++) {
                    out << "    " << vector_cycles[i] << std::endl;
                }
                for (int sw = 0; sw < col_switch; sw++) {
                    if (sw < vector_switch.size()) {
                        out << "    " << vector_switch[sw] << std::endl;
                    }

                    for (int i = 0; i < vector_case.size(); i++) {
                        out << "        " << vector_case[i] << std::endl;
                    }

                    for (int i = 0; i < vector_default.size(); i++) {
                        out << "        " << vector_default[i] << std::endl;
                    }
                }
                for (int i = 0; i < vector_if.size(); i++) {
                    out << "    " << vector_if[i] << std::endl;
                }
                for (int i = 0; i < vector_else_if.size(); i++) {
                    out << "    " << vector_else_if[i] << std::endl;
                }
                for (int i = 0; i < vector_arr.size(); i++) {
                    out << "    " << vector_arr[i] << std::endl;
                }
                for (int i = 0; i < vector_dimensional_arr.size(); i++) {
                    out << "    " << vector_dimensional_arr[i] << std::endl;
                }
                for (int i = 0; i < vector_dynamic_arr.size(); i++) {
                    out << "    " << vector_dynamic_arr[i] << std::endl;
                }
                for (int i = 0; i < delete_dynamic_arr.size(); i++) {
                    out << "    " << delete_dynamic_arr[i] << std::endl;
                }
                for (int i = 0; i < vector_vectorov.size(); i++) {
                    out << "    " << vector_vectorov[i] << std::endl;
                }
                out << std::endl;
                out << "    return 0;" << std::endl;
                out << "}" << std::endl;
                out.close();
                command = "start " + name_file + ".cpp";
                system(command.c_str());
                break;
            case -1://creating cpp file and not opening
                for (int i = 0; i < vector_library.size(); i++) {
                    out << vector_library[i] << std::endl;
                }
                for (int i = 0; i < vector_function.size(); i++) {
                    out << vector_function[i] << std::endl;
                }
                out << "int main() {" << std::endl;
                for (int i = 0; i < vector_variable.size(); i++) {
                    out << "    " << vector_variable[i] << std::endl;
                }
                for (int i = 0; i < vector_cycles.size(); i++) {
                    out << "    " << vector_cycles[i] << std::endl;
                }
                for (int sw = 0; sw < col_switch; sw++) {
                    if (sw < vector_switch.size()) {
                        out << "    " << vector_switch[sw] << std::endl;
                    }

                    for (int i = 0; i < vector_case.size(); i++) {
                        out << "        " << vector_case[i] << std::endl;
                    }

                    for (int i = 0; i < vector_default.size(); i++) {
                        out << "        " << vector_default[i] << std::endl;
                    }
                }

                for (int i = 0; i < vector_if.size(); i++) {
                    out << "    " << vector_if[i] << std::endl;
                }
                for (int i = 0; i < vector_else_if.size(); i++) {
                    out << "    " << vector_else_if[i] << std::endl;
                }
                for (int i = 0; i < vector_arr.size(); i++) {
                    out << "    " << vector_arr[i] << std::endl;
                }
                for (int i = 0; i < vector_dimensional_arr.size(); i++) {
                    out << "    " << vector_dimensional_arr[i] << std::endl;
                }
                for (int i = 0; i < vector_dynamic_arr.size(); i++) {
                    out << "    " << vector_dynamic_arr[i] << std::endl;
                }
                for (int i = 0; i < delete_dynamic_arr.size(); i++) {
                    out << "    " << delete_dynamic_arr[i] << std::endl;
                }
                for (int i = 0; i < vector_vectorov.size(); i++) {
                    out << "    " << vector_vectorov[i] << std::endl;
                }

                out << std::endl;
                out << "    return 0;" << std::endl;
                out << "}" << std::endl;
                break;
            }
            default:
                std::cerr << "choice error" << std::endl;
                break;
            }
        }
        system("cls"); 
        out.close();
        return EXIT_SUCCESS;
}
