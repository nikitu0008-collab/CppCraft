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
    auto run() -> void;  // можно оставить, но в GUI мы его не используем

    // ---- Новые публичные методы для GUI ----
    void addLibrary(const std::string& includeLine);
    void addVariable(const std::string& type, const std::string& name, const std::string& value);
    void addCycle(int type); // 1-for, 2-while, 3-do-while
    void addSwitchCase(int switchCount, int caseCount);
    void addIf(int count);
    void addElseIf(int count);
    void addArray1D(int count, int size);
    void addArray2D(int count, int rows, int cols);
    void addDynamicArray(int count, int size);
    void addFunction(const std::string& retType, const std::string& name, const std::string& params);
    void addVector(const std::string& name, const std::string& type, int size);
    void addFstream(int type, const std::string& objName, const std::string& fileName); // type:1-fstream,2-ofstream,3-ifstream
    void addClass(const std::string& className, bool isPublic, const std::vector<std::string>& members);
    void addStruct(const std::string& structName, bool isPublic, const std::vector<std::string>& members);

    // Для предпросмотра
    std::string getCodePreview() const;

    // Для сохранения
    void writeToFile(const std::string& fileName);

    // Флаги для автоматического добавления iostream/string
    bool has_iostream;
    bool has_string;

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

    int col_switch, col_case;
    int col_if, col_else_if;

    // Старые приватные методы (оставляем, но в GUI не используем)
    auto funcClear() -> void;
    auto printMenu() -> void;
    auto processLibraryInput() -> void;
    auto processVariables() -> void;
    auto processCycles() -> void;
    auto processSwitchCase() -> void;
    auto processIf() -> void;
    auto processElseIf() -> void;
    auto processArray1D() -> void;
    auto processArray2D() -> void;
    auto processDynamicArray() -> void;
    auto processFunction() -> void;
    auto processVector() -> void;
    auto processFstream() -> void;
    auto processOOP() -> void;
    auto writeToFile(bool openAfterWrite) -> void;
    auto previewCode() -> void;
    auto deleteFileAndExit() -> void;
};

#endif // CODEGENERATOR_HPP
