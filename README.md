# Diamond Sheets
Diamond Sheets is a program that is written using C++ and Qt6. It allows you to read and edit spreadsheet format files.
# Features
- Easy, fast and effective application for editing spreadsheets.
- Quickly evaluates expressions and formulas using the ANTLR4 library.
- The application can work not only with local files, but also with files on Google Drive.
- Error detection system in expressions and formulas.
- Dynamic cycles detection.
# Installation
1. Clone this repository: `git clone https://github.com/rostikro/DiamondSheets_v2`
2. Open `CMakeLists.txt` in the root directory and specify path to Qt6 C++ compiler. For example: `set(CMAKE_PREFIX_PATH "C:/Qt/6.6.1/msvc2019_64")`
3. Configure the CMake project.
4. Build the project.
5. In order to work with Google Drive, it is necesary to specify Google credentials in the GoogleApi.h file.
# Release
You can also download fully working Diamond Sheets [release](https://github.com/rostikro/DiamondSheets_v2/releases/tag/release).
