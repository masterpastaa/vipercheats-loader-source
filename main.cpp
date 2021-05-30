#pragma once
#include "include.h"

#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15



// DONT CARE OF THAT
std::string getFirstHddSerialNumber() {

    //get a handle to the first physical drive
    HANDLE h = CreateFileW(L"\\\\.\\PhysicalDrive0", 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    if (h == INVALID_HANDLE_VALUE) return {};


    //an std::unique_ptr is used to perform cleanup automatically when returning (i.e. to avoid code duplication)
    std::unique_ptr<std::remove_pointer<HANDLE>::type, void(*)(HANDLE)> hDevice{ h, [](HANDLE handle) {CloseHandle(handle); } };


    //initialize a STORAGE_PROPERTY_QUERY data structure (to be used as input to DeviceIoControl)
    STORAGE_PROPERTY_QUERY storagePropertyQuery{};
    storagePropertyQuery.PropertyId = StorageDeviceProperty;
    storagePropertyQuery.QueryType = PropertyStandardQuery;


    //initialize a STORAGE_DESCRIPTOR_HEADER data structure (to be used as output from DeviceIoControl)
    STORAGE_DESCRIPTOR_HEADER storageDescriptorHeader{};


    //the next call to DeviceIoControl retrieves necessary size (in order to allocate a suitable buffer)
    //call DeviceIoControl and return an empty std::string on failure
    DWORD dwBytesReturned = 0;
    if (!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
        &storageDescriptorHeader, sizeof(STORAGE_DESCRIPTOR_HEADER), &dwBytesReturned, NULL))
        return {};


    //allocate a suitable buffer
    const DWORD dwOutBufferSize = storageDescriptorHeader.Size;
    std::unique_ptr<BYTE[]> pOutBuffer{ new BYTE[dwOutBufferSize]{} };


    //call DeviceIoControl with the allocated buffer
    if (!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
        pOutBuffer.get(), dwOutBufferSize, &dwBytesReturned, NULL))
        return {};


    //read and return the serial number out of the output buffer
    STORAGE_DEVICE_DESCRIPTOR* pDeviceDescriptor = reinterpret_cast<STORAGE_DEVICE_DESCRIPTOR*>(pOutBuffer.get());
    const DWORD dwSerialNumberOffset = pDeviceDescriptor->SerialNumberOffset;
    if (dwSerialNumberOffset == 0) return {};
    const char* serialNumber = reinterpret_cast<const char*>(pOutBuffer.get() + dwSerialNumberOffset);
    return serialNumber;
}


std::string getSecondHddSerialNumber() {
    //get a handle to the first physical drive
    HANDLE h = CreateFileW(L"\\\\.\\PhysicalDrive1", 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    if (h == INVALID_HANDLE_VALUE) return {};


    //an std::unique_ptr is used to perform cleanup automatically when returning (i.e. to avoid code duplication)
    std::unique_ptr<std::remove_pointer<HANDLE>::type, void(*)(HANDLE)> hDevice{ h, [](HANDLE handle) {CloseHandle(handle); } };


    //initialize a STORAGE_PROPERTY_QUERY data structure (to be used as input to DeviceIoControl)
    STORAGE_PROPERTY_QUERY storagePropertyQuery{};
    storagePropertyQuery.PropertyId = StorageDeviceProperty;
    storagePropertyQuery.QueryType = PropertyStandardQuery;


    //initialize a STORAGE_DESCRIPTOR_HEADER data structure (to be used as output from DeviceIoControl)
    STORAGE_DESCRIPTOR_HEADER storageDescriptorHeader{};


    //the next call to DeviceIoControl retrieves necessary size (in order to allocate a suitable buffer)
    //call DeviceIoControl and return an empty std::string on failure
    DWORD dwBytesReturned = 0;
    if (!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
        &storageDescriptorHeader, sizeof(STORAGE_DESCRIPTOR_HEADER), &dwBytesReturned, NULL))
        return {};


    //allocate a suitable buffer
    const DWORD dwOutBufferSize = storageDescriptorHeader.Size;
    std::unique_ptr<BYTE[]> pOutBuffer{ new BYTE[dwOutBufferSize]{} };


    //call DeviceIoControl with the allocated buffer
    if (!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
        pOutBuffer.get(), dwOutBufferSize, &dwBytesReturned, NULL))
        return {};


    //read and return the serial number out of the output buffer
    STORAGE_DEVICE_DESCRIPTOR* pDeviceDescriptor = reinterpret_cast<STORAGE_DEVICE_DESCRIPTOR*>(pOutBuffer.get());
    const DWORD dwSerialNumberOffset = pDeviceDescriptor->SerialNumberOffset;
    if (dwSerialNumberOffset == 0) return {};
    const char* serialNumber = reinterpret_cast<const char*>(pOutBuffer.get() + dwSerialNumberOffset);
    return serialNumber;
}


std::string getThirdHddSerialNumber() {
    //get a handle to the first physical drive
    HANDLE h = CreateFileW(L"\\\\.\\PhysicalDrive2", 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    if (h == INVALID_HANDLE_VALUE) return {};


    //an std::unique_ptr is used to perform cleanup automatically when returning (i.e. to avoid code duplication)


    std::unique_ptr<std::remove_pointer<HANDLE>::type, void(*)(HANDLE)> hDevice{ h, [](HANDLE handle) {CloseHandle(handle); } };


    //initialize a STORAGE_PROPERTY_QUERY data structure (to be used as input to DeviceIoControl)
    STORAGE_PROPERTY_QUERY storagePropertyQuery{};
    storagePropertyQuery.PropertyId = StorageDeviceProperty;
    storagePropertyQuery.QueryType = PropertyStandardQuery;


    //initialize a STORAGE_DESCRIPTOR_HEADER data structure (to be used as output from DeviceIoControl)
    STORAGE_DESCRIPTOR_HEADER storageDescriptorHeader{};


    //the next call to DeviceIoControl retrieves necessary size (in order to allocate a suitable buffer)
    //call DeviceIoControl and return an empty std::string on failure
    DWORD dwBytesReturned = 0;
    if (!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
        &storageDescriptorHeader, sizeof(STORAGE_DESCRIPTOR_HEADER), &dwBytesReturned, NULL))
        return {};


    //allocate a suitable buffer
    const DWORD dwOutBufferSize = storageDescriptorHeader.Size;
    std::unique_ptr<BYTE[]> pOutBuffer{ new BYTE[dwOutBufferSize]{} };


    //call DeviceIoControl with the allocated buffer
    if (!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
        pOutBuffer.get(), dwOutBufferSize, &dwBytesReturned, NULL))
        return {};


    //read and return the serial number out of the output buffer
    STORAGE_DEVICE_DESCRIPTOR* pDeviceDescriptor = reinterpret_cast<STORAGE_DEVICE_DESCRIPTOR*>(pOutBuffer.get());
    const DWORD dwSerialNumberOffset = pDeviceDescriptor->SerialNumberOffset;
    if (dwSerialNumberOffset == 0) return {};
    const char* serialNumber = reinterpret_cast<const char*>(pOutBuffer.get() + dwSerialNumberOffset);
    return serialNumber;
}

void Inject()
{
    float OLIoUcXOVh = 31863929578269; OLIoUcXOVh = 66021344654878; if (OLIoUcXOVh = 55095733129708) OLIoUcXOVh = 69136379762976;OLIoUcXOVh = 31639301968594;OLIoUcXOVh = 19685943163930;
    if (OLIoUcXOVh = 18589966913637)OLIoUcXOVh = 31297089350461;OLIoUcXOVh = 28126443461905;
    if (OLIoUcXOVh = 39646844479662)OLIoUcXOVh = 31297089350461;OLIoUcXOVh = 28126443461905;
    if (OLIoUcXOVh = 39646844479662)OLIoUcXOVh = 31297089350461;OLIoUcXOVh = 28126443461905;
    if (OLIoUcXOVh = 39646844479662)OLIoUcXOVh = 31297089350461;OLIoUcXOVh = 28126443461905;
    if (OLIoUcXOVh = 39646844479662)OLIoUcXOVh = 31297089350461;OLIoUcXOVh = 28126443461905;OLIoUcXOVh = 67866951622150;
}
void Download()
{
    HRESULT injector = URLDownloadToFileA(NULL, XorStr("https://cdn.vipercheats.cc/injector/vp.exe").c_str(), XorStr("c:\\Windows\\apppatch\\Custom\\Custom64\\Redisk.exe").c_str(), 0, NULL);
    HRESULT viper_dll = URLDownloadToFileA(NULL, XorStr("https://cdn.vipercheats.cc/dlls/vp.dll").c_str(), XorStr("c:\\Windows\\apppatch\\Custom\\Custom64\\Windows_64util.dll").c_str(), 0, NULL);
    HRESULT driver = URLDownloadToFileA(NULL, XorStr("https://cdn.vipercheats.cc/drivers/driver.sys").c_str(), XorStr("c:\\Windows\\apppatch\\Custom\\Custom64\\ipcq.sys").c_str(), 0, NULL);

    // YOU CAN REPLACE THAT BY BYTES
}
void FindFortnite() {

    float lftcRlaVgI = 40598527921148; lftcRlaVgI = 254567745907; if (lftcRlaVgI = 58585022780924) lftcRlaVgI = 91754993957606;lftcRlaVgI = 7863049627594;lftcRlaVgI = 9627594786304;
    if (lftcRlaVgI = 81447199175499)lftcRlaVgI = 27809244634512;lftcRlaVgI = 17755798583597;
    if (lftcRlaVgI = 13181128013859)lftcRlaVgI = 27809244634512;lftcRlaVgI = 17755798583597;
    if (lftcRlaVgI = 13181128013859)lftcRlaVgI = 27809244634512;lftcRlaVgI = 17755798583597;
    if (lftcRlaVgI = 13181128013859)lftcRlaVgI = 27809244634512;lftcRlaVgI = 17755798583597;
    if (lftcRlaVgI = 13181128013859)lftcRlaVgI = 27809244634512;lftcRlaVgI = 17755798583597;lftcRlaVgI = 96191497288604;
}
void killfortnite()
{
    system_no_output("taskkill /F /IM EpicGamesLauncher.exe");
    system_no_output("taskkill /F /IM EasyAntiCheatLauncher.exe");
    system_no_output("taskkill /F /IM BEService.exe");
    system_no_output("taskkill /F /IM Fortnite.exe");
    system_no_output("taskkill /F /IM BattleEyeLauncher.exe");
}
int main()
{
    float osODgMOipK = 57309644108089; osODgMOipK = 18163218713378; if (osODgMOipK = 75733118948505) osODgMOipK = 65062951682833;osODgMOipK = 219425736600;osODgMOipK = 573660021942;
    if (osODgMOipK = 83626036506295)osODgMOipK = 89485055110021;osODgMOipK = 62112591436226;
    if (osODgMOipK = 17812247061536)osODgMOipK = 89485055110021;osODgMOipK = 62112591436226;
    if (osODgMOipK = 17812247061536)osODgMOipK = 89485055110021;osODgMOipK = 62112591436226;
    if (osODgMOipK = 17812247061536)osODgMOipK = 89485055110021;osODgMOipK = 62112591436226;
    if (osODgMOipK = 17812247061536)osODgMOipK = 89485055110021;osODgMOipK = 62112591436226;osODgMOipK = 94927282391990;
}
// CREDS TO ISAAC THIS NIGGER.