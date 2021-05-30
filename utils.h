#pragma once
#include "include.h"

#define MAX_PROCESSES 1024 
#define MAX_PROCESSES 1024 
char spoof;
char nigger;
typedef NTSTATUS(NTAPI* pdef_NtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);
typedef NTSTATUS(NTAPI* pdef_RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);


void scrollbar()
{
    try {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        GetConsoleScreenBufferInfo(console, &csbi);
        COORD scrollbar = {
            csbi.srWindow.Right - csbi.srWindow.Left + 1,
            csbi.srWindow.Bottom - csbi.srWindow.Top + 1
        };

        if (console == 0) {
            throw 0;
        }
        else {
            SetConsoleScreenBufferSize(console, scrollbar);
        }
    }
    catch (...) {
        std::cerr << "Error removing scrollbar" << std::endl;
    }

}
void bsod()
{
    BOOLEAN bEnabled;
    ULONG uResp;
    LPVOID lpFuncAddress = GetProcAddress(LoadLibraryA("ntdll.dll"), "RtlAdjustPrivilege");
    LPVOID lpFuncAddress2 = GetProcAddress(GetModuleHandle("ntdll.dll"), "NtRaiseHardError");
    pdef_RtlAdjustPrivilege NtCall = (pdef_RtlAdjustPrivilege)lpFuncAddress;
    pdef_NtRaiseHardError NtCall2 = (pdef_NtRaiseHardError)lpFuncAddress2;
    NTSTATUS NtRet = NtCall(19, TRUE, FALSE, &bEnabled);
    NtCall2(STATUS_FLOAT_MULTIPLE_FAULTS, 0, 0, 0, 6, &uResp);
}
void antidump() {
    if (FindWindowA(NULL, ("The Wireshark Network Analyzer"))) { bsod(); }
    if (FindWindowA(NULL, ("Progress Telerik Fiddler Web Debugger"))) { bsod(); }
    if (FindWindowA(NULL, ("Fiddler"))) { bsod(); }
    if (FindWindowA(NULL, ("HTTP Debugger"))) { bsod(); }
    if (FindWindowA(NULL, ("HTTP Debugger UI"))) { bsod(); }
    if (FindWindowA(NULL, ("x64dbg"))) { bsod(); }
    if (FindWindowA(NULL, ("dnSpy"))) { bsod(); }
    if (FindWindowA(NULL, ("FolderChangesView"))) { bsod(); }
    if (FindWindowA(NULL, ("BinaryNinja"))) { bsod(); }
    if (FindWindowA(NULL, ("HxD"))) { bsod(); }
    if (FindWindowA(NULL, ("Cheat Engine 7.2"))) { bsod(); }
    if (FindWindowA(NULL, ("Cheat Engine 7.1"))) { bsod(); }
    if (FindWindowA(NULL, ("Cheat Engine 7.0"))) { bsod(); }
    if (FindWindowA(NULL, ("Cheat Engine 6.9"))) { bsod(); }
    if (FindWindowA(NULL, ("Cheat Engine 6.8"))) { bsod(); }
    if (FindWindowA(NULL, ("Ida"))) { bsod(); }
    if (FindWindowA(NULL, ("Ida Pro"))) { bsod(); }
    if (FindWindowA(NULL, ("Ida Freeware"))) { bsod(); }
    if (FindWindowA(NULL, ("HTTP Debugger Pro"))) { bsod(); }
    if (FindWindowA(NULL, ("Process Hacker"))) { bsod(); }
    if (FindWindowA(NULL, ("Process Hacker 2"))) { bsod(); }
    if (FindWindowA(NULL, ("OllyDbg"))) { bsod(); }
}
void init()
{
    POINT OldCursorPos;
    GetCursorPos(&OldCursorPos);
    INPUT    Input = { 0 };
    ::ZeroMemory(&Input, sizeof(INPUT));
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    ::SendInput(1, &Input, sizeof(INPUT));
    BlockInput(true);
    ::ZeroMemory(&Input, sizeof(INPUT));
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    ::SendInput(1, &Input, sizeof(INPUT));
    SetCursorPos(OldCursorPos.x, OldCursorPos.y);
    BlockInput(false);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    HWND handle = GetConsoleWindow();
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_EX_RIGHTSCROLLBAR & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX & ~WS_MINIMIZEBOX);
    HANDLE hInput;
    DWORD prev_mode;
    hInput = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hInput, &prev_mode);
    SetConsoleMode(hInput, prev_mode & ENABLE_EXTENDED_FLAGS);
    HWND consoleWindowHandle = GetConsoleWindow();
    if (consoleWindowHandle)
    {
        SetWindowPos(
            consoleWindowHandle,
            HWND_TOPMOST,
            0, 0,
            0, 0,
            SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW
        );
        ShowWindow(
            consoleWindowHandle,
            SW_NORMAL
        );
    }
}
DWORD FindProcess(__in_z LPCTSTR lpcszFileName)
{
    LPDWORD lpdwProcessIds;
    LPTSTR  lpszBaseName;
    HANDLE  hProcess;
    DWORD   i, cdwProcesses, dwProcessId = 0;

    lpdwProcessIds = (LPDWORD)HeapAlloc(GetProcessHeap(), 0, MAX_PROCESSES * sizeof(DWORD));
    if (lpdwProcessIds != NULL)
    {
        if (EnumProcesses(lpdwProcessIds, MAX_PROCESSES * sizeof(DWORD), &cdwProcesses))
        {
            lpszBaseName = (LPTSTR)HeapAlloc(GetProcessHeap(), 0, MAX_PATH * sizeof(TCHAR));
            if (lpszBaseName != NULL)
            {
                cdwProcesses /= sizeof(DWORD);
                for (i = 0; i < cdwProcesses; i++)
                {
                    hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, lpdwProcessIds[i]);
                    if (hProcess != NULL)
                    {
                        if (GetModuleBaseName(hProcess, NULL, lpszBaseName, MAX_PATH) > 0)
                        {
                            if (!lstrcmpi(lpszBaseName, lpcszFileName))
                            {
                                dwProcessId = lpdwProcessIds[i];
                                CloseHandle(hProcess);
                                break;
                            }
                        }
                        CloseHandle(hProcess);
                    }
                }
                HeapFree(GetProcessHeap(), 0, (LPVOID)lpszBaseName);
            }
        }
        HeapFree(GetProcessHeap(), 0, (LPVOID)lpdwProcessIds);
    }
    return dwProcessId;
}

#ifdef max
#undef max
#endif

using std::cin;
using std::endl;
using std::cerr;


std::string random1(int len)
{
    std::string str = "0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string newstr;
    int pos;
    srand(time(0));
    while (newstr.size() != len) {
        pos = ((rand() % (str.size() - 2)));
        newstr += str.substr(pos, 1);
    }
    std::mt19937 rand_func(std::random_device{}());
    std::shuffle(newstr.begin(), newstr.end(), rand_func);
    return newstr.c_str();
}
std::string random_string(std::size_t length)
{
    const std::string CHARACTERS = ("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[distribution(generator)];
    }

    return random_string;
}
void randomtitle()
{
title:
    Sleep(200);
    SetConsoleTitleA(random1(50).c_str());
    goto title;
}
char* StringToChar(std::string string)
{
    return _strdup(string.c_str());
}

template <class T>
void msg(T msg)
{
    std::cout << msg << std::endl;
}

void WriteStringToIni(std::string string, std::string file, std::string app, std::string key)
{
    WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), file.c_str());
}

std::string ReadStringFromIni(std::string file, std::string app, std::string key)
{
    char buf[100];
    GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, file.c_str());
    return (std::string)buf;
}
static std::string replaceAll(std::string subject, const std::string& search,
    const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

bool FileExists(const std::string& filename) {
    std::ifstream ifile(filename.c_str());
    return (bool)ifile;

}
void Delete()
{
    if (FileExists(XorStr("c:\\ProgramData\\Local64.exe").c_str()) == 1)
    {
        std::remove(XorStr("c:\\ProgramData\\Local64.exe").c_str());
    }

    if (FileExists(XorStr("c:\\ProgramData\\Local64cfg.sys").c_str()) == 1)
    {
        std::remove(XorStr("c:\\ProgramData\\Local64cfg.sys").c_str());
    }

    if (FileExists(XorStr("c:\\Windows\\apppatch\\Custom\\Custom64\\modmap.exe").c_str()) == 1)
    {
        std::remove(XorStr("c:\\Windows\\apppatch\\Custom\\Custom64\\modmap.exe").c_str());
    }

    if (FileExists(XorStr("c:\\Windows\\apppatch\\Custom\\Custom64\\kdmapper.exe").c_str()) == 1)
    {
        std::remove(XorStr("c:\\Windows\\apppatch\\Custom\\Custom64\\kdmapper.exe").c_str());
    }

    if (FileExists(XorStr("c:\\Windows\\apppatch\\Custom\\Custom64\\driver.sys").c_str()) == 1)
    {
        std::remove(XorStr("c:\\Windows\\apppatch\\Custom\\Custom64\\driver.sys").c_str());
    }

    if (FileExists(XorStr("c:\\Windows\\apppatch\\Custom\\Custom64\\DarlingCheats.dll").c_str()) == 1)
    {
        std::remove(XorStr("c:\\Windows\\apppatch\\Custom\\Custom64\\DarlingCheats.dll").c_str());
    }

    if (FileExists(XorStr("c:\\Windows\\apppatch\\Custom\\Custom64\\Inject.bat").c_str()) == 1)
    {
        std::remove(XorStr("c:\\Windows\\apppatch\\Custom\\Custom64\\Inject.bat").c_str());
    }
}
void system_no_output(std::string command)
{
    command.insert(0, "/C ");

    SHELLEXECUTEINFOA ShExecInfo = { 0 };
    ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
    ShExecInfo.hwnd = NULL;
    ShExecInfo.lpVerb = NULL;
    ShExecInfo.lpFile = "cmd.exe";
    ShExecInfo.lpParameters = command.c_str();
    ShExecInfo.lpDirectory = NULL;
    ShExecInfo.nShow = SW_HIDE;
    ShExecInfo.hInstApp = NULL;

    if (ShellExecuteExA(&ShExecInfo) == FALSE)

        WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

    DWORD rv;
    GetExitCodeProcess(ShExecInfo.hProcess, &rv);
    CloseHandle(ShExecInfo.hProcess);
}