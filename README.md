<div align="center">
  
# ⚡ **Cpp Craft Code Generator** ⚡

<img src="https://img.shields.io/badge/C%2B%2B-26-blue?style=for-the-badge&logo=c%2B%2B"/>
<img src="https://img.shields.io/badge/License-Proprietary-red?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Version-3.0-brightgreen?style=for-the-badge"/>

### 🎨 *Интерактивный конструктор кода на C++ с меню-интерфейсом* 🎨

[🚀 Возможности](#-возможности) • [🖥️ Требования](#️-требования) • [📁 Структура](#-структура) • [🔧 Сборка](#-сборка) • [📜 Лицензия](#-лицензия)

---

</div>

## 🌟 **О проекте**

**Cpp Craft** — это мощный инструмент для быстрого прототипирования программ на C++. Забудьте о рутинном написании шаблонного кода! Просто выбирайте нужные компоненты из меню, и программа сама соберет готовый `.cpp` файл.

```cpp
// Вместо того чтобы писать это вручную...
#include <iostream>
#include <vector>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// ...просто выберите пункты меню и получите готовый код!
🚀 Возможности
#	Категория	Описание
1	БИБЛИОТЕКИ	Выбор из 89 STL заголовков (по номеру или имени). Автоматически добавляет <iostream> и <string>.
2	ПЕРЕМЕННЫЕ	Типы: int, double, float, string, bool, auto.
3	ЦИКЛЫ	for, while, do-while с готовыми шаблонами.
4	SWITCH-CASE	Конструкция switch с указанным числом case и default.
5	IF	Блоки if.
6	ELSE IF	Цепочки else if.
7	МАССИВЫ arr[]	Одномерные статические массивы.
8	МАССИВЫ arr[][]	Двумерные массивы.
9	ДИНАМИЧЕСКИЕ МАССИВЫ	Выделение памяти через new + автоматическая генерация delete[].
10	ФУНКЦИИ	Любой возвращаемый тип (void, int, double, string, bool), параметры, тело функции.
11	VECTOR	std::vector с указанием типа и размера.
12	FSTREAM	fstream, ifstream, ofstream для работы с файлами.
13	ООП	Создание class и struct с секциями public/private.
Горячие клавиши
Команда	Действие	Эффект
0	💾 Сохранить и запустить	Создаёт .cpp и открывает в редакторе (Windows: start).
-1	💿 Сохранить без открытия	Просто сохраняет файл.
-2	👁️ Предпросмотр	Показывает сгенерированный код в консоли.
-3	🚪 Выход без сохранения	Удаляет созданный файл.
🖥️ Требования
Требование	Детали
ОС	Linux / macOS / Windows
Компилятор	C++26 (поддержка std::print) – GCC 14+, Clang 18+, MSVC 19.38+
Сборщик	CMake 3.20+ (опционально) или直接用 компилятор
Память	≥ 64 MB RAM
Место	≥ 10 MB на диске
Примечание: Для корректной работы std::print требуется включить стандарт C++26 или новее. На старых компиляторах замените std::print на std::cout.

📁 Структура проекта
text
📦 CppCraft
 ┣ 📂 include/
 ┃  ┣ 📜 CodeGenerator.hpp    # Объявление класса генератора
 ┃  ┗ 📜 LibraryList.hpp      # Список всех STL библиотек (89 шт.)
 ┣ 📂 src/
 ┃  ┣ 📜 CodeGenerator.cpp    # Реализация всех методов генератора
 ┃  ┗ 📜 main.cpp              # Точка входа (создание и запуск CodeGenerator)
 ┣ 📜 README.md                # Этот файл
 ┗ 📂 Generated Files          # (появляется после запуска)
    ┗ 📜 my_program.cpp        # Ваши сгенерированные программы
🔧 Сборка
Вариант 1: ручная компиляция (g++/clang++)
bash
# Убедитесь, что вы находитесь в корневой папке проекта
g++ -std=c++26 -Iinclude src/main.cpp src/CodeGenerator.cpp -o cpp_craft
Вариант 2: MSVC (Windows)
cmd
cl /EHsc /std:c++latest /Iinclude src\main.cpp src\CodeGenerator.cpp /Fe:cpp_craft.exe
Вариант 3: CMake (рекомендуется)
Затем соберите:

bash
mkdir build && cd build
cmake ..
cmake --build .
🎯 Пример использования
bash
name file(don't write .cpp)
:_> my_awesome_program

  >--------------------------------<  
>-----Cpp Craft Code By N.Y.RPO3-----<
  >--------------------------------<  
____________________________________
| [1]-libraries   [10]-function    |
| [2]-variables   [11]-vector      |
| [3]-cycles      [12]-fstream     |
| [4]-switch_case [13]-OOP         |
| [5]-if                           |
| [6]-else if   [-3]-exit no create|
| [7]-arr[]     [-2]-check result  |
| [8]-arr[][]   [-1]-save and exit |
| [9]-d_arr     [ 0]-save and start|
|-----------------------------------|
|
L------------->answer: 1
После выбора элементов и ввода 0 будет создан файл my_awesome_program.cpp:

cpp
#include <iostream>
#include <string>
#include <vector>

int main() {
    int age = 25;
    std::string name = "John";
    
    for(int i = 0; i < 10; i++) {
        // code_cycles
    }
    
    return 0;
}
📜 Лицензия
<div align="center">
© 2025 N.Y.RPO3 (проект Cpp Craft). Все права защищены.

</div>
Данное программное обеспечение и его исходный код являются интеллектуальной собственностью автора.

Запрещается:

· ❌ Копирование, распространение или модификация кода без явного письменного разрешения автора.
· ❌ Использование кода в коммерческих целях.
· ❌ Выдача данного кода за свой собственный.

📧 По вопросам использования обращаться к автору проекта.

🧠 Идеи для доработки
✅ Поддержка system("cls") для Windows (уже реализовано через макросы _WIN32/__linux__).

✅ Модульная архитектура (разделение на .hpp/.cpp).

⬜ Добавление шаблонов для часто используемых алгоритмов.

⬜ Генерация CMakeLists.txt для сгенерированных проектов.

⬜ Экспорт в ZIP-архив.

⬜ Подсветка синтаксиса в предпросмотре.

⬜ Сохранение шаблонов проектов.

<div align="center">
⚡ Cpp Craft — твой код за минуту! ⚡

✨ Просто. Быстро. Эффективно. ✨

</div> ```
