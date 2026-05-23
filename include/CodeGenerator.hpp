#ifndef CODEGENERATOR_HPP
#define CODEGENERATOR_HPP

#include <string>
#include <vector>

struct Variable {
    std::string type;
    std::string name;
    std::string value;
};

class CodeGenerator {
public:
    CodeGenerator();
    void run();

private:
    std::string name_file;
    std::vector<std::string> vector_library;
    std::vector<std::string> vector_function;
    std::vector<std::string> vector_class;
    std::vector<std::string> vector_struct;
    std::vector<std::string> vector_variable;
    std::vector<std::string> vector_cycles;
    std::vector<std::string> vector_switch;
    std::vector<std::string> vector_case;
    std::vector<std::string> vector_default;
    std::vector<std::string> vector_if;
    std::vector<std::string> vector_else_if;
    std::vector<std::string> vector_arr;
    std::vector<std::string> vector_dimensional_arr;
    std::vector<std::string> vector_dynamic_arr;
    std::vector<std::string> delete_dynamic_arr;
    std::vector<std::string> vector_vectorov;
    std::vector<std::string> vector_ifstream;
    std::vector<std::string> vector_ofstream;
    std::vector<std::string> vector_fstream;
    std::vector<Variable> variables_variable;

    bool has_iostream;
    bool has_string;

    // Временные переменные (используются при построении)
    int col_switch, col_case;
    int col_if, col_else_if;

    // --- Приватные методы ---
    void funcClear();
    void printMenu();
    void processLibraryInput();
    void processVariables();
    void processCycles();
    void processSwitchCase();
    void processIf();
    void processElseIf();
    void processArray1D();
    void processArray2D();
    void processDynamicArray();
    void processFunction();
    void processVector();
    void processFstream();
    void processOOP();
    void writeToFile(bool openAfterWrite);
    void previewCode();
    void deleteFileAndExit();
};

#endif // CODEGENERATOR_HPP
